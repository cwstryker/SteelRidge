
#include "gearpunch.h"

//Call on the commands from the constructor of the header file.

gearpunch::gearpunch(): Command() {
	// Declare what subsystem the command depends on.
	Requires(Robot::gearpuncher.get());

}


// Called just before this Command runs the first time
void gearpunch::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void gearpunch::Execute() {
	//Calls on the gearpunch method declared in the Gearpuncher.h and Gearpuncher.cpp file
	Robot::gearpuncher->punch();
}

// Make this return true when this Command no longer needs to run execute()
bool gearpunch::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void gearpunch::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void gearpunch::Interrupted() {

}
