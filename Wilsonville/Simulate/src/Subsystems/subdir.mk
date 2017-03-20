################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Subsystems/climber.cpp \
../src/Subsystems/drivetrain.cpp \
../src/Subsystems/gearloader.cpp \
../src/Subsystems/gearpuncher.cpp 

OBJS += \
./src/Subsystems/climber.o \
./src/Subsystems/drivetrain.o \
./src/Subsystems/gearloader.o \
./src/Subsystems/gearpuncher.o 

CPP_DEPS += \
./src/Subsystems/climber.d \
./src/Subsystems/drivetrain.d \
./src/Subsystems/gearloader.d \
./src/Subsystems/gearpuncher.d 


# Each subdirectory must supply rules for building sources it contributes
src/Subsystems/%.o: ../src/Subsystems/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"C:\Users\steve.rinard\workspaceneon/SteelRidgeCompetitionBot/src" -Ic:/users/steve.rinard/wpilib/cpp/current/sim/include -I/usr/include -I/usr/include/gazebo-5.0 -I/usr/include/sdformat-2.3 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


