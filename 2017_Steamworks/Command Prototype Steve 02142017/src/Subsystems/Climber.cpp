
#include "Climber.h"
#include "LiveWindow/LiveWindow.h"



Climber::Climber() : frc::Subsystem("Climber") {
    // DECLARATIONS
	frc::LiveWindow::GetInstance()->AddActuator("Climber", "climbermotor", &climbermotor);

}

void Climber::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());

}

void Climber::Start() {
	//Calls on method and declaration from header file to run the climber motor.
	climbermotor.Set(-0.5);
}

void Climber::Stop() {
	//Calls on method and declaration from header file to stop the climber motor.
	climbermotor.Set(0.0);
}




