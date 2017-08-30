


#ifndef GEARS_H
#define GEARS_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "DoubleSolenoid.h"


/**
 * This is the header file for the Gears Subsystem.
 */
class Gears: public frc::Subsystem {
private:

	// DECLARATIONS

	frc::DoubleSolenoid gearactuator {0, 0, 1 };


public:


	Gears();


	void InitDefaultCommand() override;


	void movegearup(); //Create a method for the gear system to move up.

	void movegeardown(); //Create a method for the gear system to move down.

};

#endif
