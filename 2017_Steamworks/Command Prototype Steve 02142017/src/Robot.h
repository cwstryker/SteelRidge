
#ifndef _ROBOT_H
#define _ROBOT_H

#include "WPILib.h"
#include "Commands/Command.h"
#include "LiveWindow/LiveWindow.h"
//#include "Commands/AutonomousCommand.h"
#include "Commands/climbup.h"
#include "Commands/drivewithjoystick.h"
#include "Commands/gearup.h"
#include "Commands/geardown.h"
#include "Commands/stopclimb.h"
#include "Subsystems/Climber.h"
#include "Subsystems/Drivetrain.h"
#include "Subsystems/Gears.h"
#include "OI.h"

class Robot : public IterativeRobot {
public:
	//std::unique_ptr<Command> autonomousCommand; //I've left out autonomous for now.
	static std::unique_ptr<OI> oi;
	LiveWindow *lw = LiveWindow::GetInstance();
	static std::shared_ptr<Gears> gears;
    static std::shared_ptr<Drivetrain> drivetrain;
    static std::shared_ptr<Climber> climber;


private:

    frc::Command* autonomousCommand;
    virtual void RobotInit() override;
	virtual void DisabledInit() override;
	virtual void DisabledPeriodic() override;
	virtual void AutonomousInit() override;
	virtual void AutonomousPeriodic() override;
	virtual void TeleopInit() override;
	virtual void TeleopPeriodic() override;
	virtual void TestPeriodic() override;
};
#endif
