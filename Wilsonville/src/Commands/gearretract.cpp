
#include "gearretract.h"

//Call on the commands from the constructor of the header file.

gearretract::gearretract(): Command() {
        // Declare what subsystem the command depends on.
	Requires(Robot::gearpuncher.get());
}


// Called just before this Command runs the first time
void gearretract::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void gearretract::Execute() {
	//Calls on the retract method declared in the Gearpuncher.h and Gearpuncher.cpp file
	Robot::gearpuncher->retract();

}

// Make this return true when this Command no longer needs to run execute()
bool gearretract::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void gearretract::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void gearretract::Interrupted() {

}
