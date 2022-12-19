################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../lib/tinyxml2.cpp 

CPP_DEPS += \
./lib/tinyxml2.d 

OBJS += \
./lib/tinyxml2.o 


# Each subdirectory must supply rules for building sources it contributes
lib/%.o: ../lib/%.cpp lib/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-lib

clean-lib:
	-$(RM) ./lib/tinyxml2.d ./lib/tinyxml2.o

.PHONY: clean-lib

