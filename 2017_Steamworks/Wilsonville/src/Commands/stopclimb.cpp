

#include "stopclimb.h"

//Call on the commands from the constructor of the header file.

stopclimb::stopclimb(): Command() {

    // Declare what subsystem the command depends on.
	Requires(Robot::climber.get());

}


// Called just before this Command runs the first time
void stopclimb::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void stopclimb::Execute() {
	//Calls on the Stop method declared in the Climber.h and Climber.cpp file
	Robot::climber->Stop();
}

// Make this return true when this Command no longer needs to run execute()
bool stopclimb::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void stopclimb::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void stopclimb::Interrupted() {

}
