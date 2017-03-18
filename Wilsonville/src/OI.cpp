


#include "OI.h"


#include "SmartDashboard/SmartDashboard.h"
#include "Commands/climbup.h"
#include "Commands/climbupslow.h"
#include "Commands/drivewithjoystick.h"
#include "Commands/geardown.h"
#include "Commands/gearup.h"
#include "Commands/gearpunch.h"
#include "Commands/gearretract.h"
#include "Commands/stopclimb.h"
#include "Subsystems/Climber.h"
#include "Subsystems/Drivetrain.h"
#include "Subsystems/Gearpuncher.h"
#include "Subsystems/Gears.h"



OI::OI() {
    // Process operator interface input here.
	RightThumb.WhenPressed(new gearretract());

	LeftThumb.WhenPressed(new gearpunch());

	L1.WhenPressed(new stopclimb());

    y.WhenPressed(new climbupslow());

    x.WhenPressed(new climbup());

    b.WhenPressed(new geardown());
    
    a.WhenPressed(new gearup());

    // SmartDashboard Buttons
    frc::SmartDashboard::PutData("gearretract", new gearretract());
    frc::SmartDashboard::PutData("gearpunch", new gearpunch());
    frc::SmartDashboard::PutData("stopclimb", new stopclimb());
    frc::SmartDashboard::PutData("climbslow", new climbupslow());
    frc::SmartDashboard::PutData("climbup", new climbup());
    frc::SmartDashboard::PutData("geardown", new geardown());
    frc::SmartDashboard::PutData("gearup", new gearup());
    frc::SmartDashboard::PutData("drivewithjoystick", new drivewithjoystick());

}

// Give the initialized function something to do.

frc::Joystick* OI::getlogitech() {
   return &logitech;
}




