/********************************************
 * acc_cfg.c
 *
 *  Created on: 12 nov. 2024
 *      Author: sonny
 *
 *******************************************/
/* ------------------ Includes ------------------------------*/
#include "fsl_debug_console.h"
#include "board.h"
#include "math.h"
#include "fsl_fxos.h"
#include "fsl_i2c.h"
#include "fsl_tpm.h"

#include "clock_config.h"
#include "pin_mux.h"
#include "fsl_gpio.h"
#include "fsl_port.h"

/* ------------------ Definitions ---------------------------*/
/* The TPM instance/channel used for board */
#define BOARD_TIMER_BASEADDR TPM2
#define BOARD_FIRST_TIMER_CHANNEL 0U
#define BOARD_SECOND_TIMER_CHANNEL 1U
#define BOARD_THIRD_TIMER_CHANNEL 2U
/* Get source clock for TPM driver */
#define BOARD_TIMER_SOURCE_CLOCK CLOCK_GetFreq(kCLOCK_Osc0ErClk)
#define TIMER_CLOCK_MODE 1U
/* I2C source clock */
#define ACCEL_I2C_CLK_SRC I2C1_CLK_SRC
#define I2C_BAUDRATE 100000U

#define I2C_RELEASE_SDA_PORT PORTC
#define I2C_RELEASE_SCL_PORT PORTC
#define I2C_RELEASE_SDA_GPIO GPIOC
#define I2C_RELEASE_SDA_PIN 3U
#define I2C_RELEASE_SCL_GPIO GPIOC
#define I2C_RELEASE_SCL_PIN 2U
#define I2C_RELEASE_BUS_COUNT 100U
/* Upper bound and lower bound angle values */
#define ANGLE_UPPER_BOUND 85U
#define ANGLE_LOWER_BOUND 5U

/* ------------------- Prototypes --------------------------- */
void BOARD_I2C_ReleaseBus(void);

/* ------------------- Variables ----------------------------*/
i2c_master_handle_t g_MasterHandle;
const uint8_t g_accel_address[] = {0x1CU, 0x1DU, 0x1EU, 0x1FU};
uint8_t dataScale = 0;
uint16_t xData, yData, zData;
int16_t xAngle, yAngle, zAngle;

/* ------------------ Functions -----------------------------*/
static void i2c_release_bus_delay(void) {
    uint32_t i = 0;
    for (i = 0; i < I2C_RELEASE_BUS_COUNT; i++) {
        __NOP();
    }
}

void BOARD_I2C_ReleaseBus(void) {
    uint8_t i = 0;
    gpio_pin_config_t pin_config;
    port_pin_config_t i2c_pin_config = {0};
    i2c_pin_config.pullSelect = kPORT_PullUp;
    i2c_pin_config.mux = kPORT_MuxAsGpio;
    pin_config.pinDirection = kGPIO_DigitalOutput;
    pin_config.outputLogic = 1U;
    CLOCK_EnableClock(kCLOCK_PortC);
    PORT_SetPinConfig(I2C_RELEASE_SCL_PORT, I2C_RELEASE_SCL_PIN, &i2c_pin_config);
    PORT_SetPinConfig(I2C_RELEASE_SDA_PORT, I2C_RELEASE_SDA_PIN, &i2c_pin_config);
    GPIO_PinInit(I2C_RELEASE_SCL_GPIO, I2C_RELEASE_SCL_PIN, &pin_config);
    GPIO_PinInit(I2C_RELEASE_SDA_GPIO, I2C_RELEASE_SDA_PIN, &pin_config);

    GPIO_WritePinOutput(I2C_RELEASE_SDA_GPIO, I2C_RELEASE_SDA_PIN, 0U);
    i2c_release_bus_delay();

    for (i = 0; i < 9; i++) {
        GPIO_WritePinOutput(I2C_RELEASE_SCL_GPIO, I2C_RELEASE_SCL_PIN, 0U);
        i2c_release_bus_delay();

        GPIO_WritePinOutput(I2C_RELEASE_SDA_GPIO, I2C_RELEASE_SDA_PIN, 1U);
        i2c_release_bus_delay();

        GPIO_WritePinOutput(I2C_RELEASE_SCL_GPIO, I2C_RELEASE_SCL_PIN, 1U);
        i2c_release_bus_delay();
        i2c_release_bus_delay();
    }

    GPIO_WritePinOutput(I2C_RELEASE_SCL_GPIO, I2C_RELEASE_SCL_PIN, 0U);
    i2c_release_bus_delay();

    GPIO_WritePinOutput(I2C_RELEASE_SDA_GPIO, I2C_RELEASE_SDA_PIN, 0U);
    i2c_release_bus_delay();

    GPIO_WritePinOutput(I2C_RELEASE_SCL_GPIO, I2C_RELEASE_SCL_PIN, 1U);
    i2c_release_bus_delay();

    GPIO_WritePinOutput(I2C_RELEASE_SDA_GPIO, I2C_RELEASE_SDA_PIN, 1U);
    i2c_release_bus_delay();
}

static void Timer_Init(void) {
    
    tpm_config_t tpmInfo;
    tpm_chnl_pwm_signal_param_t tpmParam[3];

    tpmParam[0].chnlNumber = (tpm_chnl_t)BOARD_FIRST_TIMER_CHANNEL;
    tpmParam[0].level = kTPM_LowTrue;
    tpmParam[0].dutyCyclePercent = 0U;

    tpmParam[1].chnlNumber = (tpm_chnl_t)BOARD_SECOND_TIMER_CHANNEL;
    tpmParam[1].level = kTPM_LowTrue;
    tpmParam[1].dutyCyclePercent = 0U;

    tpmParam[2].chnlNumber = (tpm_chnl_t)BOARD_THIRD_TIMER_CHANNEL;
    tpmParam[2].level = kTPM_LowTrue;
    tpmParam[2].dutyCyclePercent = 0U;


    TPM_GetDefaultConfig(&tpmInfo);
    TPM_Init(BOARD_TIMER_BASEADDR, &tpmInfo);

    CLOCK_SetTpmClock(TIMER_CLOCK_MODE);

    TPM_SetupPwm(BOARD_TIMER_BASEADDR, tpmParam, 3U, kTPM_CombinedPwm, 24000U, BOARD_TIMER_SOURCE_CLOCK);
    TPM_StartTimer(BOARD_TIMER_BASEADDR, kTPM_SystemClock);
}

static void Board_UpdatePwm(uint16_t x, uint16_t y, uint16_t z) {
    TPM_UpdatePwmDutycycle(BOARD_TIMER_BASEADDR, (tpm_chnl_t)BOARD_FIRST_TIMER_CHANNEL, kTPM_CombinedPwm, x);
    TPM_UpdatePwmDutycycle(BOARD_TIMER_BASEADDR, (tpm_chnl_t)BOARD_SECOND_TIMER_CHANNEL, kTPM_CombinedPwm, y);
    TPM_UpdatePwmDutycycle(BOARD_TIMER_BASEADDR, (tpm_chnl_t)BOARD_THIRD_TIMER_CHANNEL, kTPM_CombinedPwm, z);
}

/* ------------ Inicializa acelerometro, llamarla en la aplicacion ------------------ */
void accl_init(void){
	    i2c_master_config_t i2cConfig;
	    uint8_t sensorRange = 0;
	    uint8_t dataScale = 0;
	    uint32_t i2cSourceClock;
	    int16_t xData, yData;
	    int16_t xAngle, yAngle;
	    uint8_t i = 0;
	    uint8_t regResult = 0;
	    uint8_t array_addr_size = 0;
	    bool foundDevice = false;

	    /* Board pin, clock, debug console init */
	    BOARD_InitPins();
	    BOARD_BootClockRUN();
	    BOARD_I2C_ReleaseBus();
	    BOARD_I2C_ConfigurePins();
	    BOARD_InitDebugConsole();

	    i2cSourceClock = CLOCK_GetFreq(ACCEL_I2C_CLK_SRC);

	    I2C_MasterGetDefaultConfig(&i2cConfig);
	    I2C_MasterInit(BOARD_ACCEL_I2C_BASEADDR, &i2cConfig, i2cSourceClock);
	    I2C_MasterTransferCreateHandle(BOARD_ACCEL_I2C_BASEADDR, &g_MasterHandle, NULL, NULL);

	    /* Find sensor devices */
	    Timer_Init();
}

/* ------------ Cambiar color de Led de acuerdo a XYZ ----------------------------*/
void Angle_update (void) {
//	while(1){
    fxos_handle_t fxosHandle;
    fxos_data_t sensorData;
	fxosHandle.base = BOARD_ACCEL_I2C_BASEADDR;
    fxosHandle.i2cHandle = &g_MasterHandle;
    uint8_t array_addr_size = 0;
    uint8_t i = 0;
    bool foundDevice = false;
    uint8_t regResult = 0;
    uint8_t sensorRange = 0;
    array_addr_size = sizeof(g_accel_address) / sizeof(g_accel_address[0]);
    	    for (i = 0; i < array_addr_size; i++)
    	    {
    	        fxosHandle.xfer.slaveAddress = g_accel_address[i];
    	        if (FXOS_ReadReg(&fxosHandle, WHO_AM_I_REG, &regResult, 1) == kStatus_Success)
    	        {
    	            foundDevice = true;
    	            break;
    	        }
    	        if ((i == (array_addr_size - 1)) && (!foundDevice))
    	        {
    	            PRINTF("\r\nDo not found sensor device\r\n");
    	            while (1)
    	            {
    	            };
    	        }
    	    }

    	    /* Init accelerometer sensor */
    	    if (FXOS_Init(&fxosHandle) != kStatus_Success)
    	    {
    	        return -1;
    	    }
    	    /* Get sensor range */
    	    if (FXOS_ReadReg(&fxosHandle, XYZ_DATA_CFG_REG, &sensorRange, 1) != kStatus_Success)
    	    {
    	        return -1;
    	    }
    	    if (sensorRange == 0x00)
    	    {
    	        dataScale = 2U;
    	    }
    	    else if (sensorRange == 0x01)
    	    {
    	        dataScale = 4U;
    	    }
    	    else if (sensorRange == 0x10)
    	    {
    	        dataScale = 8U;
    	    }
    	    else
    	    {
    	    }
	FXOS_ReadSensorData(&fxosHandle, &sensorData);

	xData = (int16_t)((uint16_t)((uint16_t)sensorData.accelXMSB << 8) | (uint16_t)sensorData.accelXLSB) / 4U;

	yData = (int16_t)((uint16_t)((uint16_t)sensorData.accelYMSB << 8) | (uint16_t)sensorData.accelYLSB) / 4U;

	zData = (int16_t)((uint16_t)((uint16_t)sensorData.accelZMSB << 8) | (uint16_t)sensorData.accelZLSB) / 4U;

		xAngle = (int16_t)floor((double)xData * (double)dataScale * 90 / 8192);
		if (xAngle < 0) {
			xAngle *= -1;
		}
		if (xAngle > ANGLE_UPPER_BOUND) {
		    xAngle = 100;
		}
        if (xAngle < ANGLE_LOWER_BOUND) {
            xAngle = 0;
        }

		yAngle = (int16_t)floor((double)yData * (double)dataScale * 90 / 8192);
		if (yAngle < 0) {
			yAngle *= -1;
		}
		if (yAngle > ANGLE_UPPER_BOUND) {
		    yAngle = 100;
		}
        if (yAngle < ANGLE_LOWER_BOUND) {
            yAngle = 0;
        }

		zAngle = (int16_t)floor((double)zData * (double)dataScale * 90 / 8192);
		if (zAngle < 0) {
			zAngle *= -1;
		}
		if (zAngle > ANGLE_UPPER_BOUND) {
		    zAngle = 100;
		}
        if (zAngle < ANGLE_LOWER_BOUND) {
            zAngle = 0;
        }
       // Board_UpdatePwm(xAngle, yAngle, zAngle);
	//}
}

uint16_t RetX(void)
{
	return(xAngle);
}

uint16_t RetY(void)
{
	return(yAngle);
}

uint16_t RetZ(void)
{
	return(zAngle);
}

