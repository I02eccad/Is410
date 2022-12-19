################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Curso.cpp \
../src/Estadistica.cpp \
../src/SistemaDeGestionDeCursos.cpp \
../src/Usuario.cpp \
../src/main.cpp 

CPP_DEPS += \
./src/Curso.d \
./src/Estadistica.d \
./src/SistemaDeGestionDeCursos.d \
./src/Usuario.d \
./src/main.d 

OBJS += \
./src/Curso.o \
./src/Estadistica.o \
./src/SistemaDeGestionDeCursos.o \
./src/Usuario.o \
./src/main.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Curso.d ./src/Curso.o ./src/Estadistica.d ./src/Estadistica.o ./src/SistemaDeGestionDeCursos.d ./src/SistemaDeGestionDeCursos.o ./src/Usuario.d ./src/Usuario.o ./src/main.d ./src/main.o

.PHONY: clean-src

