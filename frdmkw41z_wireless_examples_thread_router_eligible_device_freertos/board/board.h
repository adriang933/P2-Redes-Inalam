/*
* Copyright (c) 2015, Freescale Semiconductor, Inc.
* Copyright 2016-2017 NXP
* All rights reserved.
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef _BOARD_H_
#define _BOARD_H_

#include "fsl_gpio.h"
#include "clock_config.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* The board name */
#define MANUFACTURER_NAME               "NXP"
#define BOARD_NAME                      "FRDM-KW41Z"

#define BOARD_XTAL0_CLK_HZ    32000000U
#define BOARD_XTAL32K_CLK_HZ  32768U

#define CORE_CLOCK_FREQ 47972352U

/* Connectivity */
#ifndef APP_SERIAL_INTERFACE_TYPE
#define APP_SERIAL_INTERFACE_TYPE (gSerialMgrLpuart_c)
#endif

#ifndef APP_SERIAL_INTERFACE_INSTANCE
#define APP_SERIAL_INTERFACE_INSTANCE (0)
#endif

#ifndef APP_SERIAL_INTERFACE_SPEED
#define APP_SERIAL_INTERFACE_SPEED (115200)
#endif

/* EEPROM type used */
#ifndef gEepromType_d
#define gEepromType_d gEepromDevice_AT45DB041E_c
#endif

/* DCDC driver default mode */
#ifndef APP_DCDC_MODE
#define APP_DCDC_MODE    (gDCDC_Mode_Buck_c)
#endif
   
/* Vbat monitor Interval in Ms */
#ifndef APP_DCDC_VBAT_MONITOR_INTERVAL
#define APP_DCDC_VBAT_MONITOR_INTERVAL    (50000)
#endif
   
/* 1<<x to enable PINx as wakup source in LLWU */
#define BOARD_LLWU_PIN_ENABLE_BITMAP ( 1<<12 | 1<<13 )

/*! @brief TSI electrodes count */
#ifndef gKBD_TsiElectdCount_c
#define gKBD_TsiElectdCount_c 0U
#endif
/*! @brief TSI electrodes mapping: 1<<x to mark KBD pin as TSI */
#define gKBD_SwTypeMapping_d ( 1<<0 | 1<<3 )
/*! @brief TSI electrodes pins */
#define gKBD_TsiElecList_d {4U, 7U}

/* The PWM channels used for RGB LED */
#ifndef BOARD_USE_PWM_FOR_RGB_LED
#define BOARD_USE_PWM_FOR_RGB_LED       1
#endif

#ifndef gStackTimerInstance_c
#define gStackTimerInstance_c           1
#endif
#ifndef gRedLedPwmTimerInstance_c
#define gRedLedPwmTimerInstance_c       0
#endif
#ifndef gGreenLedPwmTimerInstance_c
#define gGreenLedPwmTimerInstance_c     2
#endif
#ifndef gBlueLedPwmTimerInstance_c
#define gBlueLedPwmTimerInstance_c      2
#endif

#ifndef gRedLedPwmTimerChannel_c
#define gRedLedPwmTimerChannel_c        2
#endif
#ifndef gGreenLedPwmTimerChannel_c
#define gGreenLedPwmTimerChannel_c      1
#endif
#ifndef gBlueLedPwmTimerChannel_c
#define gBlueLedPwmTimerChannel_c       0
#endif
/* Index into the ledPins[] array */
#ifndef gRedLedIdx_c
#define gRedLedIdx_c                    1
#endif
#ifndef gGreenLedIdx_c
#define gGreenLedIdx_c                  2
#endif
#ifndef gBlueLedIdx_c
#define gBlueLedIdx_c                   3
#endif

#define gADC16_ReferenceVoltageSource_d kADC16_ReferenceVoltageSourceValt

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/************************************************************************************
*************************************************************************************
* Public prototypes
*************************************************************************************
************************************************************************************/
#define BOARD_NAME "FRDM-KW41Z"

/*! @brief The UART to use for debug messages. */
#define BOARD_USE_LPUART
#define BOARD_DEBUG_UART_TYPE DEBUG_CONSOLE_DEVICE_TYPE_LPUART
#define BOARD_DEBUG_UART_BASEADDR (uint32_t) LPUART0
#define BOARD_DEBUG_UART_CLKSRC kCLOCK_Osc0ErClk
#define BOARD_DEBUG_UART_CLK_FREQ CLOCK_GetOsc0ErClkFreq()
#define BOARD_UART_IRQ LPUART0_IRQn
#define BOARD_UART_IRQ_HANDLER LPUART0_IRQHandler
#define BOARD_DEBUG_UART_BAUDRATE 115200
#define BOARD_ACCEL_I2C_BASEADDR I2C1

void hardware_init(void);

/* Function to initialize ADC on board configuration. */
void BOARD_InitAdc(void);

/* Function to initialize DCDC on board configuration. */
void BOARD_DCDCInit(void);

/* Function to read battery level on board configuration. */
uint8_t BOARD_GetBatteryLevel(void);

/* Function to read potentiometer level on board configuration. */
uint16_t BOARD_GetPotentiometerLevel(void);

/* Function to read temperature level on board configuration. */
int32_t BOARD_GetTemperature(void);

/* Function to install callbacks for actions before and after entering low power. */
extern void BOARD_InstallLowPowerCallbacks(void);

/* Function called by low power module prior to entering low power. */
extern void BOARD_EnterLowPowerCb(void);

/* Function called by low power module after exiting low power. */
extern void BOARD_ExitLowPowerCb(void);

/* Function called by the BLE connection manager to generate PER MCU keys */
extern void BOARD_GetMCUUid(uint8_t* aOutUid16B, uint8_t* pOutLen);

/* Functions used to determine the frequency of a module's input clock. */
uint32_t BOARD_GetLpuartClock(uint32_t instance);
uint32_t BOARD_GetTpmClock(uint32_t instance);
uint32_t BOARD_GetSpiClock(uint32_t instance);
uint32_t BOARD_GetI2cClock(uint32_t instance);
void BOARD_BLPEtoBLPI(void);
void BOARD_BLPItoBLPE(void);

/* Board led color mapping */
#define LOGIC_LED_ON 0U
#define LOGIC_LED_OFF 1U
#define BOARD_LED_RED_GPIO GPIOC
#define BOARD_LED_RED_GPIO_PORT PORTC
#define BOARD_LED_RED_GPIO_PIN 1U
#define BOARD_LED_GREEN_GPIO GPIOA
#define BOARD_LED_GREEN_GPIO_PORT PORTA
#define BOARD_LED_GREEN_GPIO_PIN 19U
#define BOARD_LED_BLUE_GPIO GPIOA
#define BOARD_LED_BLUE_GPIO_PORT PORTA
#define BOARD_LED_BLUE_GPIO_PIN 18U

#define LED_RED_INIT(output)                                  \
    GPIO_WritePinOutput(BOARD_LED_RED_GPIO, BOARD_LED_RED_GPIO_PIN, output);\
    BOARD_LED_RED_GPIO->PDDR |= (1U << BOARD_LED_RED_GPIO_PIN)  /*!< Enable target LED_RED */
#define LED_RED_ON() \
    GPIO_ClearPinsOutput(BOARD_LED_RED_GPIO, 1U << BOARD_LED_RED_GPIO_PIN) /*!< Turn on target LED_RED */
#define LED_RED_OFF() \
    GPIO_SetPinsOutput(BOARD_LED_RED_GPIO, 1U << BOARD_LED_RED_GPIO_PIN) /*!< Turn off target LED_RED */
#define LED_RED_TOGGLE() \
    GPIO_TogglePinsOutput(BOARD_LED_RED_GPIO, 1U << BOARD_LED_RED_GPIO_PIN) /*!< Toggle on target LED_RED */

#define LED_GREEN_INIT(output)                                  \
    GPIO_WritePinOutput(BOARD_LED_GREEN_GPIO, BOARD_LED_GREEN_GPIO_PIN, output);\
    BOARD_LED_GREEN_GPIO->PDDR |= (1U << BOARD_LED_GREEN_GPIO_PIN)  /*!< Enable target LED_GREEN */
#define LED_GREEN_ON() \
    GPIO_ClearPinsOutput(BOARD_LED_GREEN_GPIO, 1U << BOARD_LED_GREEN_GPIO_PIN) /*!< Turn on target LED_GREEN */
#define LED_GREEN_OFF() \
    GPIO_SetPinsOutput(BOARD_LED_GREEN_GPIO, 1U << BOARD_LED_GREEN_GPIO_PIN) /*!< Turn off target LED_GREEN */
#define LED_GREEN_TOGGLE() \
    GPIO_TogglePinsOutput(BOARD_LED_GREEN_GPIO, 1U << BOARD_LED_GREEN_GPIO_PIN) /*!< Toggle on target LED_GREEN */

#define LED_BLUE_INIT(output)                                  \
    GPIO_WritePinOutput(BOARD_LED_BLUE_GPIO, BOARD_LED_BLUE_GPIO_PIN, output);\
    BOARD_LED_BLUE_GPIO->PDDR |= (1U << BOARD_LED_BLUE_GPIO_PIN)  /*!< Enable target LED_BLUE */
#define LED_BLUE_ON() \
    GPIO_ClearPinsOutput(BOARD_LED_BLUE_GPIO, 1U << BOARD_LED_BLUE_GPIO_PIN) /*!< Turn on target LED_BLUE */
#define LED_BLUE_OFF() \
    GPIO_SetPinsOutput(BOARD_LED_BLUE_GPIO, 1U << BOARD_LED_BLUE_GPIO_PIN) /*!< Turn off target LED_BLUE */
#define LED_BLUE_TOGGLE() \
    GPIO_TogglePinsOutput(BOARD_LED_BLUE_GPIO, 1U << BOARD_LED_BLUE_GPIO_PIN) /*!< Toggle on target LED_BLUE */

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* __BOARD_H__ */
