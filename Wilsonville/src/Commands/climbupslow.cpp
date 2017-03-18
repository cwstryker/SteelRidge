
#include "climbupslow.h"

//Call on the commands from the constructor of the header file.

climbupslow::climbupslow(): Command() {
	// Declare what subsystem the command depends on.
	Requires(Robot::climber.get());

}


// Called just before this Command runs the first time
void climbupslow::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void climbupslow::Execute() {
	//Calls on the Start method declared in the Climber.h and Climber.cpp file
	Robot::climber->StartSlow();
}

// Make this return true when this Command no longer needs to run execute()
bool climbupslow::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void climbupslow::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void climbupslow::Interrupted() {

}
