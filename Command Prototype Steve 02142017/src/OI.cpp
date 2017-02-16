


#include "OI.h"


#include "SmartDashboard/SmartDashboard.h"
#include "Commands/climbup.h"
#include "Commands/drivewithjoystick.h"
#include "Commands/geardown.h"
#include "Commands/gearup.h"
#include "Commands/stopclimb.h"
#include "Subsystems/Climber.h"
#include "Subsystems/Drivetrain.h"
#include "Subsystems/Gears.h"



OI::OI() {
    // Process operator interface input here.




    y.WhenPressed(new stopclimb());

    x.WhenPressed(new climbup());

    b.WhenPressed(new geardown());
    
    a.WhenPressed(new gearup());

    // SmartDashboard Buttons
    frc::SmartDashboard::PutData("stopclimb", new stopclimb());
    frc::SmartDashboard::PutData("climbup", new climbup());
    frc::SmartDashboard::PutData("geardown", new geardown());
    frc::SmartDashboard::PutData("gearup", new gearup());
    frc::SmartDashboard::PutData("drivewithjoystick", new drivewithjoystick());

}

// Give the initialized function something to do.

frc::Joystick* OI::getlogitech() {
   return &logitech;
}




