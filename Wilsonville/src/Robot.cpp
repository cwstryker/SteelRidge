
#include "Robot.h"
#include "SmartDashboard/SmartDashboard.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
std::shared_ptr<Gears> Robot::gears;
std::shared_ptr<Gearpuncher> Robot::gearpuncher;
std::shared_ptr<Drivetrain> Robot::drivetrain;
std::shared_ptr<Climber> Robot::climber;
std::unique_ptr<OI> Robot::oi;


void Robot::RobotInit() {

	//Constructors
    gears.reset(new Gears());
    gearpuncher.reset(new Gearpuncher());
    drivetrain.reset(new Drivetrain());
    climber.reset(new Climber());

	oi.reset(new OI());

	frc::SmartDashboard::PutData(gears.get());
	frc::SmartDashboard::PutData(gearpuncher.get());
	frc::SmartDashboard::PutData(drivetrain.get());
	frc::SmartDashboard::PutData(climber.get());

	cs::UsbCamera camera1 = CameraServer::GetInstance()->StartAutomaticCapture(1);
	cs::UsbCamera camera0 = CameraServer::GetInstance()->StartAutomaticCapture(0);
	camera1.SetResolution(320,240);
	camera1.SetFPS(15);
	camera0.SetResolution(320,240);
	camera0.SetFPS(15);



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
	Robot::drivetrain->autoDrive();


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

