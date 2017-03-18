
#ifndef GEARDOWN_H
#define GEARDOWN_H


#include "Commands/Subsystem.h"
#include "../Robot.h"


/**
 * This is the header file for the gearup command.
 */

class geardown: public frc::Command {
public:
	// Initialize the constructor
	geardown();


	virtual void Initialize() override;
	virtual void Execute() override;
	virtual bool IsFinished() override;
	virtual void End() override;
	virtual void Interrupted() override;

private:
	// Add any new variables needed here.
};

#endif
