

#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "RobotDrive.h"
#include "Victor.h"


namespace frc {
class Joystick;
}
/**
 * This is the header for the Drivetrain Subsytem.
 */
class Drivetrain: public frc::Subsystem {
private:
	//DECLARATIONS
	frc::VictorSP frontleft { 0 };
	frc::VictorSP frontright { 2 };
	frc::VictorSP rearleft { 1 };
	frc::VictorSP rearright { 3 };
	frc::RobotDrive drive {frontleft, rearleft, frontright, rearright};

public:
	Drivetrain();
	void InitDefaultCommand();

	void TankDrive(frc::Joystick* logitech); //Create a method that calls on the Joystick to run.

	void TankDrive(double leftAxis, double rightAxis); //Create a method that runs the motors using TankDrive from the RobotDrive Class.

	void Stop();

};

#endif
