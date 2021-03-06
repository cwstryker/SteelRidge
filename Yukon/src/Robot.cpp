// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Robot.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<Drivetrain> Robot::drivetrain;
std::shared_ptr<Gearcage> Robot::gearcage;
std::shared_ptr<Climber> Robot::climber;
std::shared_ptr<Gearpuncher> Robot::gearpuncher;
std::unique_ptr<OI> Robot::oi;
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION

void Robot::RobotInit() {
	RobotMap::init();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    drivetrain.reset(new Drivetrain());
    gearcage.reset(new Gearcage());
    climber.reset(new Climber());
    gearpuncher.reset(new Gearpuncher());
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi.reset(new OI());

	// instantiate the command used for the autonomous period
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	autonomousCommand.reset(new driveauto());
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS

	cs::UsbCamera camera1 = CameraServer::GetInstance()->StartAutomaticCapture(1);
	cs::UsbCamera camera0 = CameraServer::GetInstance()->StartAutomaticCapture(0);
	camera1.SetResolution(320,240);
	camera1.SetFPS(15);
	camera0.SetResolution(320,240);
	camera0.SetFPS(15);
  }

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Start();

	//Remove robotdrive safety feature to remove timout errors
	RobotMap::drivetrainRobotDrive21->SetSafetyEnabled(false);

	//Enable talons
	RobotMap::drivetrainfrontleft->EnableControl();
	RobotMap::drivetrainfrontright->EnableControl();

	//Set Talons to avoid timouts
	RobotMap::drivetrainfrontleft->Set(0.0);
	RobotMap::drivetrainfrontright->Set(0.0);


	//Zero the encoders when Autonomous initializes
	RobotMap::drivetrainfrontleft->SetPosition(0.0);
	RobotMap::drivetrainfrontright->SetPosition(0.0);

}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();

	/* Output some values to the smartdashboard when we're in Teleop */
	//SmartDashboard::PutNumber("Left Encoder Position with GetEncPosition", RobotMap::drivetrainfrontleft->GetEncPosition()); //Get left encoder position. Which one works?
	SmartDashboard::PutNumber("Left Encoder Position with GetPosition", RobotMap::drivetrainfrontleft->GetPosition()); //Get left encoder position. Which one works?

	//SmartDashboard::PutNumber("Right Encoder Position with GetEncPosition", RobotMap::drivetrainfrontright->GetEncPosition()); //Get right encoder position. Which one works?
	SmartDashboard::PutNumber("Right Encoder Position with GetPosition", RobotMap::drivetrainfrontright->GetPosition()); //Get right encoder position. Which one works?
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Cancel();

	//Change control modes
	RobotMap::drivetrainfrontleft->SetControlMode(CANTalon::kPercentVbus);
	RobotMap::drivetrainfrontright->SetControlMode(CANTalon::kPercentVbus);

	//Enable talons
	RobotMap::drivetrainfrontleft->EnableControl();
	RobotMap::drivetrainfrontright->EnableControl();

	//Set Talons to avoid timeouts
	RobotMap::drivetrainfrontleft->Set(0.0);
	RobotMap::drivetrainfrontright->Set(0.0);

	//Zero the encoders when Teleop initializes
	RobotMap::drivetrainfrontleft->SetPosition(0.0);
	RobotMap::drivetrainfrontright->SetPosition(0.0);

	//Re-enable safety features
	RobotMap::drivetrainRobotDrive21->SetSafetyEnabled(true);

}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();

	/* Output some values to the smartdashboard when we're in Teleop */
	//SmartDashboard::PutNumber("Left Encoder Position with GetEncPosition", RobotMap::drivetrainfrontleft->GetEncPosition()); //Get left encoder position. Which one works?
	SmartDashboard::PutNumber("Left Encoder Position with GetPosition", RobotMap::drivetrainfrontleft->GetPosition()); //Get left encoder position. Which one works?

	//SmartDashboard::PutNumber("Right Encoder Position with GetEncPosition", RobotMap::drivetrainfrontright->GetEncPosition()); //Get right encoder position. Which one works?
	SmartDashboard::PutNumber("Right Encoder Position with GetPosition", RobotMap::drivetrainfrontright->GetPosition()); //Get right encoder position. Which one works?

}

void Robot::TestPeriodic() {
	lw->Run();

}

START_ROBOT_CLASS(Robot);

