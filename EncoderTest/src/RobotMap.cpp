// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "CANTalon.h"

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "WPILib.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
std::shared_ptr<CANTalon> RobotMap::drivetrainfl;
std::shared_ptr<CANTalon> RobotMap::drivetrainrl;
std::shared_ptr<CANTalon> RobotMap::drivetrainfr;
std::shared_ptr<CANTalon> RobotMap::drivetrainrr;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

void RobotMap::init() {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    LiveWindow *lw = LiveWindow::GetInstance();

    drivetrainfl.reset(new CANTalon(0));
    lw->AddActuator("Drivetrain", "fl", drivetrainfl);
    
    drivetrainrl.reset(new CANTalon(1));
    lw->AddActuator("Drivetrain", "rl", drivetrainrl);
    
    drivetrainfr.reset(new CANTalon(2));
    lw->AddActuator("Drivetrain", "fr", drivetrainfr);
    
    drivetrainrr.reset(new CANTalon(3));
    lw->AddActuator("Drivetrain", "rr", drivetrainrr);
    


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

    /*Set up rear talons to follow front talons */
    drivetrainrl->SetControlMode(CANTalon::kFollower); //Set rear left as a follower talon
    drivetrainrl->Set(0); //Make rear left follow front left

    drivetrainrr->SetControlMode(CANTalon::kFollower); //Set rear right as a follower talon
    drivetrainrr->Set(2); //Make rear right follow front right

    /*Set up Encoders*/
    //left encoder
    drivetrainfl->SetFeedbackDevice(CANTalon::QuadEncoder); //CIMcoder is a quad encoder
    drivetrainfl->ConfigEncoderCodesPerRev(80); //20 ppr * 4 (quadrature) = 80 CPR
    drivetrainfl->SetSensorDirection(true); //reverse sensor so motor and sensor are in phase
    drivetrainfl->SetPID(3.5,0.001,.35,1.514); //Set values for Proportional, Integral, Derivative and Feed Forward
    drivetrainfl->SetAllowableClosedLoopErr(1000); //Sets the allowable error in closed loop to 10% of 1 revolution (320)
    drivetrainfl->SetIzone(10);
    //right encoder
    drivetrainfr->SetInverted(true); //reverse the motor for the right bank of motors
    drivetrainfr->SetFeedbackDevice(CANTalon::QuadEncoder); //CIMcoder is a quad encoder
    drivetrainfr->ConfigEncoderCodesPerRev(80); //20 ppr * 4 (quadrature) = 80 CPR
    drivetrainfr->SetSensorDirection(true); //reverse sensor so motor and sensor are in phase
    drivetrainfr->SetPID(0.0,0.0,0.0,1.619); //Set values for Proportional, Integral, Derivative and Feed Forward
    drivetrainfr->SetAllowableClosedLoopErr(1000); //Sets the allowable error in closed loop to 10% of 1 revolution (320)
}
