################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../startup/startup_MKW41Z4.S 

OBJS += \
./startup/startup_MKW41Z4.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.S startup/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU Assembler'
	arm-none-eabi-gcc -c -x assembler-with-cpp -D__REDLIB__ -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\source" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\OSAbstraction\Interface" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\freertos" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\ieee_802.15.4\mac\source\App" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\ieee_802.15.4\mac\interface" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\ieee_802.15.4\phy\interface" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\GPIO" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\Keyboard\Interface" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\LED\Interface" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\SerialManager\Source\SPI_Adapter" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\SerialManager\Source\UART_Adapter" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\SerialManager\Source\I2C_Adapter" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\Flash\Internal" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\common" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\MemManager\Interface" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\Messaging\Interface" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\Panic\Interface" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\RNG\Interface" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\SerialManager\Interface" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\TimersManager\Interface" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\TimersManager\Source" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\SecLib" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\Lists" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\FunctionLib" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\ModuleInfo" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\MWSCoexistence\Interface" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\Shell\Interface" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\NVM\Interface" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\NVM\Source" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\FSCI\Interface" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\FSCI\Source" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\LowPower\Interface\MKW41Z" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\LowPower\Source\MKW41Z" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\nwk_ip\core\interface" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\nwk_ip\core\interface\modules" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\nwk_ip\core\interface\thread" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\nwk_ip\base\interface" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\nwk_ip\core\interface\http" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\nwk_ip\app\config" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\nwk_ip\app\common" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\drivers" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\DCDC\Interface" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\XCVR\MKW41Z4" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\ieee_802.15.4\phy\source\MKW41Z" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\CMSIS" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\utilities" -I"C:\Users\adrgm\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Thread\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\board" -g3 -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -specs=redlib.specs -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-startup

clean-startup:
	-$(RM) ./startup/startup_MKW41Z4.o

.PHONY: clean-startup
