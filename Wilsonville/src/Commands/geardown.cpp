
#include "geardown.h"

//Call on the commands from the constructor of the header file.

geardown::geardown(): Command() {
        // Declare what subsystem the command depends on.
	Requires(Robot::gears.get());

}


// Called just before this Command runs the first time
void geardown::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void geardown::Execute() {
	//Calls on the movegeardown method declared in the Gears.h and Gears.cpp file
	Robot::gears->movegeardown();
}

// Make this return true when this Command no longer needs to run execute()
bool geardown::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void geardown::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void geardown::Interrupted() {

}
