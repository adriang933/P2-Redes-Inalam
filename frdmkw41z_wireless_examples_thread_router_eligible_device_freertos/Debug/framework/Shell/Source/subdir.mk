################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../framework/Shell/Source/shell.c \
../framework/Shell/Source/shell_autocomplete.c \
../framework/Shell/Source/shell_cmdhelp.c \
../framework/Shell/Source/shell_cmdhist.c 

C_DEPS += \
./framework/Shell/Source/shell.d \
./framework/Shell/Source/shell_autocomplete.d \
./framework/Shell/Source/shell_cmdhelp.d \
./framework/Shell/Source/shell_cmdhist.d 

OBJS += \
./framework/Shell/Source/shell.o \
./framework/Shell/Source/shell_autocomplete.o \
./framework/Shell/Source/shell_cmdhelp.o \
./framework/Shell/Source/shell_cmdhist.o 


# Each subdirectory must supply rules for building sources it contributes
framework/Shell/Source/%.o: ../framework/Shell/Source/%.c framework/Shell/Source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MKW41Z512VHT4 -DCPU_MKW41Z512VHT4_cm0plus -D__SEMIHOST_HARDFAULT_DISABLE=1 -DFSL_RTOS_FREE_RTOS -DFRDM_KW41Z -DFREEDOM -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\source" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\OSAbstraction\Interface" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\freertos" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\ieee_802.15.4\mac\source\App" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\ieee_802.15.4\mac\interface" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\ieee_802.15.4\phy\interface" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\GPIO" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\Keyboard\Interface" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\LED\Interface" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\SerialManager\Source\SPI_Adapter" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\SerialManager\Source\UART_Adapter" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\SerialManager\Source\I2C_Adapter" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\Flash\Internal" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\common" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\MemManager\Interface" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\Messaging\Interface" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\Panic\Interface" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\RNG\Interface" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\SerialManager\Interface" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\TimersManager\Interface" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\TimersManager\Source" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\SecLib" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\Lists" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\FunctionLib" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\ModuleInfo" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\MWSCoexistence\Interface" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\Shell\Interface" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\NVM\Interface" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\NVM\Source" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\FSCI\Interface" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\FSCI\Source" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\LowPower\Interface\MKW41Z" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\LowPower\Source\MKW41Z" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\nwk_ip\core\interface" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\nwk_ip\core\interface\modules" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\nwk_ip\core\interface\thread" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\nwk_ip\base\interface" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\nwk_ip\core\interface\http" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\nwk_ip\app\config" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\nwk_ip\app\common" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\drivers" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\DCDC\Interface" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\framework\XCVR\MKW41Z4" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\ieee_802.15.4\phy\source\MKW41Z" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\CMSIS" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\utilities" -I"S:\Workspace\Inalambrico\practicas\p2\P2-Redes-Inalam\frdmkw41z_wireless_examples_thread_router_eligible_device_freertos\board" -Og -fno-common -g -gdwarf-4 -Wall -Wno-missing-braces  -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -imacros "S:/Workspace/Inalambrico/practicas/p2/P2-Redes-Inalam/frdmkw41z_wireless_examples_thread_router_eligible_device_freertos/source/config.h" -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-framework-2f-Shell-2f-Source

clean-framework-2f-Shell-2f-Source:
	-$(RM) ./framework/Shell/Source/shell.d ./framework/Shell/Source/shell.o ./framework/Shell/Source/shell_autocomplete.d ./framework/Shell/Source/shell_autocomplete.o ./framework/Shell/Source/shell_cmdhelp.d ./framework/Shell/Source/shell_cmdhelp.o ./framework/Shell/Source/shell_cmdhist.d ./framework/Shell/Source/shell_cmdhist.o

.PHONY: clean-framework-2f-Shell-2f-Source

