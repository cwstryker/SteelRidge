################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Commands/climbfast.cpp \
../src/Commands/climbslow.cpp \
../src/Commands/climbstop.cpp \
../src/Commands/driveauto.cpp \
../src/Commands/drivewithjoysticks.cpp \
../src/Commands/geardown.cpp \
../src/Commands/gearpunch.cpp \
../src/Commands/gearretract.cpp \
../src/Commands/gearup.cpp 

OBJS += \
./src/Commands/climbfast.o \
./src/Commands/climbslow.o \
./src/Commands/climbstop.o \
./src/Commands/driveauto.o \
./src/Commands/drivewithjoysticks.o \
./src/Commands/geardown.o \
./src/Commands/gearpunch.o \
./src/Commands/gearretract.o \
./src/Commands/gearup.o 

CPP_DEPS += \
./src/Commands/climbfast.d \
./src/Commands/climbslow.d \
./src/Commands/climbstop.d \
./src/Commands/driveauto.d \
./src/Commands/drivewithjoysticks.d \
./src/Commands/geardown.d \
./src/Commands/gearpunch.d \
./src/Commands/gearretract.d \
./src/Commands/gearup.d 


# Each subdirectory must supply rules for building sources it contributes
src/Commands/%.o: ../src/Commands/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"C:\Users\steve.rinard\workspaceneon/SteelRidgeCompetitionBot/src" -Ic:/users/steve.rinard/wpilib/cpp/current/sim/include -I/usr/include -I/usr/include/gazebo-5.0 -I/usr/include/sdformat-2.3 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


