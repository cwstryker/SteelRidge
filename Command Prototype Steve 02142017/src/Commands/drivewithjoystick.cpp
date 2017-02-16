
#include "drivewithjoystick.h"
#include "../Robot.h"

//Call on the commands from the constructor of the header file.

drivewithjoystick::drivewithjoystick(): Command() {
	 // Declare what subsystem the command depends on.
	Requires(Robot::drivetrain.get());

}


// Called just before this Command runs the first time
void drivewithjoystick::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void drivewithjoystick::Execute() {
	//Calls on the drivewithjoystick method declared in the Drivetrain.h and Drivetrain.cpp file
	Robot::drivetrain->TankDrive(Robot::oi->getlogitech());
}

// Make this return true when this Command no longer needs to run execute()
bool drivewithjoystick::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void drivewithjoystick::End() {
	//Calls on the Stop method declared in the Drivetrain.h and Drivetrain.cpp file
	Robot::drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void drivewithjoystick::Interrupted() {
}
