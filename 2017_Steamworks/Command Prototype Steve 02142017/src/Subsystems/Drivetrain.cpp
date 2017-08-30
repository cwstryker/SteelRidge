


#include "Drivetrain.h"
#include "Joystick.h"
#include "LiveWindow/LiveWindow.h"



#include "../Commands/drivewithjoystick.h"


Drivetrain::Drivetrain() : frc::Subsystem("Drivetrain") {
    // DECLARATIONS

	frc::LiveWindow::GetInstance()->AddActuator("Drivetrain", "frontleft", &frontleft);


	frc::LiveWindow::GetInstance()->AddActuator("Drivetrain", "frontright", &frontright);


	frc::LiveWindow::GetInstance()->AddActuator("Drivetrain", "rearleft", &rearleft);


	frc::LiveWindow::GetInstance()->AddActuator("Drivetrain", "rearright", &rearright);


	drive.SetSafetyEnabled(false);
	drive.SetExpiration(0.1);
	drive.SetSensitivity(0.5);
	drive.SetMaxOutput(1.0);
	//drive.SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
	//drive.SetInvertedMotor(RobotDrive::kRearLeftMotor, true);



}

void Drivetrain::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());

        SetDefaultCommand(new drivewithjoystick());

}

void Drivetrain::TankDrive(Joystick* logitech) {
	//Calls on method and drive declaration from Drivetrain.h and assigns left and right axes to
	//left/right motors.
	drive.TankDrive(-logitech->GetRawAxis(1), -logitech->GetRawAxis(5));
}

void Drivetrain::TankDrive(double leftAxis, double rightAxis) {
	//Calls on method and drive declaration from Drivetrain.h and assigns left and right axes to
	//left/right motors.
	drive.TankDrive(leftAxis, rightAxis);
}

void Drivetrain::Stop() {
	//Stops the drivetrain when called upon.
	drive.TankDrive(0.0, 0.0);
}



