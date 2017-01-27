#include "WPILib.h"
#include "Math.h"

/*
 * This is a our tank drive program. It calls on the Joystick and TalonSRX classes
 * which are a part of the WPILib header file. The Math header file is necessary in
 * or to use the fabs (float absolute value) command.
 *
 * A joystick is given the variable name controller and this is used to drive the
 * robot. It is assigned 0 according to the usb port that it needs in the driver
 * station.
 *
 * Each motor controller is assigned a variable to match its orientation of the
 * motor. The wiring on the robot must match the arguments given.
 *
 */
class Robot: public SampleRobot
{

	Joystick controller; // left/right drive joystick
	TalonSRX FLeft;
	TalonSRX RLeft;
	TalonSRX FRight;
	TalonSRX RRight;


public:
	Robot():

		/*
		* Assign each variable to its port/location on the robot
		*/
			controller(0), //drive controller must be usb 0 in driver station
			FLeft(0), //Front left motor attaches to TalonSRX 0.
			RLeft(2), //Rear left motor attaches to TalonSRX 2.
			FRight(1), //Front Right motor attaches to TalonSRX 1.
			RRight(3) //Rear Right motor attaches to TalonSRX 3.

/*
* Set up a safety net for the motors to stop if there is no communications.
*/
	{

		FLeft.SetExpiration(0.1),
		FRight.SetExpiration(0.1),
		RLeft.SetExpiration(0.1),
		RRight.SetExpiration(0.1);
	}


/**
* Run the motors with tank steering.
*/

void OperatorControl()
	{
		while (IsOperatorControl())
		{
		/*
		 * grab the correct axis from controller for the left joystick
		 * and sense changes. The 0.2 is to keep very small changes in
		 * stick movement from moving robot.
		 */
			if(fabs(controller.GetRawAxis(1)) > 0.2)

			{
			/*
			 * left joystick, forward & back at 50% max of motors.
			 */
			   FLeft.Set(controller.GetRawAxis(1) * -.5);
			   RLeft.Set(controller.GetRawAxis(1) * -.5);
			}
			else
			{
			/*
			 * If no movement of left joystick set motors to 0%.
			 */

			   FLeft.Set(0);
			   RLeft.Set(0);
			 }
		/*
		 * grab the correct axis from controller for the right joystick
		 * and sense changes. The 0.2 is to keep very small changes in
		 * stick movement from moving robot.
		 */
			if(fabs(controller.GetRawAxis(5)) > 0.2)
			{
			/*
			 * right joystick, forward & back at 50% max of motors.
			 */
			   FRight.Set(controller.GetRawAxis(5) * .5);
			   RRight.Set(controller.GetRawAxis(5) * .5);
			}
			else
			{
			/*
			 * If no movement of right joystick set motors to 0%.
			 */
			 FRight.Set(0);
			 RRight.Set(0);
			 }
		Wait(0.005);    // wait 0.005 seconds before repeating loop
		}

	}

};

START_ROBOT_CLASS(Robot)
