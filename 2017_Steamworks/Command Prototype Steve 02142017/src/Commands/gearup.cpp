
#include "gearup.h"

//Call on the commands from the constructor of the header file.

gearup::gearup(): Command() {
	// Declare what subsystem the command depends on.
	Requires(Robot::gears.get());

}


// Called just before this Command runs the first time
void gearup::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void gearup::Execute() {
	//Calls on the movegearup method declared in the Gears.h and Gears.cpp file
	Robot::gears->movegearup();
}

// Make this return true when this Command no longer needs to run execute()
bool gearup::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void gearup::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void gearup::Interrupted() {

}
