################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../build/CMakeFiles/3.24.2/CompilerIdCXX/CMakeCXXCompilerId.cpp 

CPP_DEPS += \
./build/CMakeFiles/3.24.2/CompilerIdCXX/CMakeCXXCompilerId.d 

OBJS += \
./build/CMakeFiles/3.24.2/CompilerIdCXX/CMakeCXXCompilerId.o 


# Each subdirectory must supply rules for building sources it contributes
build/CMakeFiles/3.24.2/CompilerIdCXX/%.o: ../build/CMakeFiles/3.24.2/CompilerIdCXX/%.cpp build/CMakeFiles/3.24.2/CompilerIdCXX/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-build-2f-CMakeFiles-2f-3-2e-24-2e-2-2f-CompilerIdCXX

clean-build-2f-CMakeFiles-2f-3-2e-24-2e-2-2f-CompilerIdCXX:
	-$(RM) ./build/CMakeFiles/3.24.2/CompilerIdCXX/CMakeCXXCompilerId.d ./build/CMakeFiles/3.24.2/CompilerIdCXX/CMakeCXXCompilerId.o

.PHONY: clean-build-2f-CMakeFiles-2f-3-2e-24-2e-2-2f-CompilerIdCXX

