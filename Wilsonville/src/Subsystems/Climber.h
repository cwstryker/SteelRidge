
#ifndef CLIMBER_H
#define CLIMBER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "TalonSRX.h"

/**
 * This is the header for the Climber Subsystem.
 */
class Climber: public frc::Subsystem {
private:
	// DECLARATIONS
	frc::TalonSRX climbermotor { 4 };

public:



	Climber();
	void InitDefaultCommand() override;

	void StartFast(); //Create a method to start the climber motor.

	void StartSlow();

	void Stop(); //Create a method to stop the climber motor.

};

#endif
