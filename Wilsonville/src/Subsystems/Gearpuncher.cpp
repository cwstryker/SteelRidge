


#include "LiveWindow/LiveWindow.h"
#include "Gearpuncher.h"


Gearpuncher::Gearpuncher() : frc::Subsystem("Gearpuncher") {
    // DECLARATIONS
	LiveWindow::GetInstance()->AddActuator("Gearpuncher", "punchersolenoid", &punchersolenoid);

}

void Gearpuncher::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());

}

void Gearpuncher::punch(){
	//When the command "movegearup" is called on, the gearsolenoid will open.
	punchersolenoid.Set(DoubleSolenoid::kForward);
}

void Gearpuncher::retract(){
	//When the command "movegeardown" is called on, the gearsolenoid will close.
	punchersolenoid.Set(DoubleSolenoid::kReverse);
}




