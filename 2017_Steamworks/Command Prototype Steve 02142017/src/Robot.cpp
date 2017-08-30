
#include "Robot.h"
#include "SmartDashboard/SmartDashboard.h"

std::shared_ptr<Gears> Robot::gears;
std::shared_ptr<Drivetrain> Robot::drivetrain;
std::shared_ptr<Climber> Robot::climber;
std::unique_ptr<OI> Robot::oi;


void Robot::RobotInit() {

	//Constructors
    gears.reset(new Gears());
    drivetrain.reset(new Drivetrain());
    climber.reset(new Climber());

	oi.reset(new OI());

	frc::SmartDashboard::PutData(gears.get());
	frc::SmartDashboard::PutData(drivetrain.get());
	frc::SmartDashboard::PutData(climber.get());

	//Instantiate autonomous command. I've left it out for now.
	//autonomousCommand.reset(new autonomousCommand());

  }

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){
	if (autonomousCommand != nullptr)
		{
			delete autonomousCommand;
		}
}

void Robot::DisabledPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	if (autonomousCommand != nullptr)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();

}

void Robot::TeleopInit() {

	if (autonomousCommand != nullptr)
		autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);

