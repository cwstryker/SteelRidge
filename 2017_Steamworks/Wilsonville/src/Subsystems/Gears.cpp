


#include "Gears.h"
#include "LiveWindow/LiveWindow.h"


Gears::Gears() : frc::Subsystem("Gears") {
    // DECLARATIONS
	LiveWindow::GetInstance()->AddActuator("Gears", "gearactuator", &gearactuator);

}

void Gears::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());

}

void Gears::movegearup(){
	//When the command "movegearup" is called on, the gearsolenoid will open.
	gearactuator.Set(DoubleSolenoid::kForward);
}

void Gears::movegeardown(){
	//When the command "movegeardown" is called on, the gearsolenoid will close.
	gearactuator.Set(DoubleSolenoid::kReverse);
}




