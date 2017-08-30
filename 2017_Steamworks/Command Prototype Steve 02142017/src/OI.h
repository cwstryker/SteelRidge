
#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "Buttons/JoystickButton.h"
#include "Joystick.h"

class OI {
private:
	//Declare Operator Interface items and their ports.
	frc::Joystick logitech { 5 };
	frc::Joystick xbox { 0 };

	frc::JoystickButton y { &xbox, 4};
	frc::JoystickButton x { &xbox, 3 };
	frc::JoystickButton b { &xbox, 2 };
	frc::JoystickButton a { &xbox, 1 };

public:
	OI();

	//Initialize a function.

	frc::Joystick* getlogitech();



};

#endif
