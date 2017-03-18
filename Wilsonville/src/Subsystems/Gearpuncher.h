


#ifndef GEARPUNCHER_H
#define GEARPUNCHER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "DoubleSolenoid.h"


/**
 * This is the header file for the Gears Subsystem.
 */
class Gearpuncher: public frc::Subsystem {
private:

	// DECLARATIONS

	frc::DoubleSolenoid punchersolenoid {0, 2, 3 };


public:


	Gearpuncher();


	void InitDefaultCommand() override;


	void punch(); //Create a method for the gear to punch in.

	void retract(); //Create a method for the gear to retract.

};

#endif
