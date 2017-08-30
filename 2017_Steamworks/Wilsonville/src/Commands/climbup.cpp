
#include "climbup.h"

//Call on the commands from the constructor of the header file.

climbup::climbup(): Command() {
	// Declare what subsystem the command depends on.
	Requires(Robot::climber.get());

}


// Called just before this Command runs the first time
void climbup::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void climbup::Execute() {
	//Calls on the Start method declared in the Climber.h and Climber.cpp file
	Robot::climber->StartFast();
}

// Make this return true when this Command no longer needs to run execute()
bool climbup::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void climbup::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void climbup::Interrupted() {

}
