################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../build/CMakeFiles/3.24.2/CompilerIdC/CMakeCCompilerId.c 

C_DEPS += \
./build/CMakeFiles/3.24.2/CompilerIdC/CMakeCCompilerId.d 

OBJS += \
./build/CMakeFiles/3.24.2/CompilerIdC/CMakeCCompilerId.o 


# Each subdirectory must supply rules for building sources it contributes
build/CMakeFiles/3.24.2/CompilerIdC/%.o: ../build/CMakeFiles/3.24.2/CompilerIdC/%.c build/CMakeFiles/3.24.2/CompilerIdC/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-build-2f-CMakeFiles-2f-3-2e-24-2e-2-2f-CompilerIdC

clean-build-2f-CMakeFiles-2f-3-2e-24-2e-2-2f-CompilerIdC:
	-$(RM) ./build/CMakeFiles/3.24.2/CompilerIdC/CMakeCCompilerId.d ./build/CMakeFiles/3.24.2/CompilerIdC/CMakeCCompilerId.o

.PHONY: clean-build-2f-CMakeFiles-2f-3-2e-24-2e-2-2f-CompilerIdC

