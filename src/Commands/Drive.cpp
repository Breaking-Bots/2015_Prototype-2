#include "Drive.h"

Drive::Drive()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(chassis);
	SetInterruptible(true);
}

// Called just before this Command runs the first time
void Drive::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute()
{
	chassis->ElonDrive(-oi->driverCtrl->LY(), -oi->driverCtrl->RX(), oi->SysMgntd());
}

// Make this return true when this Command no longer needs to run execute()
bool Drive::IsFinished()
{
	return IsCanceled();
}

// Called once after isFinished returns true
void Drive::End()
{
	chassis->RawDrive(0.0f, 0.0f);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive::Interrupted()
{
	chassis->RawDrive(0.0f, 0.0f);
}
