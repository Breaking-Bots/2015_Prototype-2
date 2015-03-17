#include "AutoIdle.h"

AutoIdle::AutoIdle()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(chassis);
}

// Called just before this Command runs the first time
void AutoIdle::Initialize()
{
	SetTimeout(1.0f);
}

// Called repeatedly when this Command is scheduled to run
void AutoIdle::Execute()
{
	chassis->RawDrive(0.0f, 0.0f);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoIdle::IsFinished()
{
	return IsTimedOut() || IsCanceled();
}

// Called once after isFinished returns true
void AutoIdle::End()
{
	chassis->RawDrive(0.0f, 0.0f);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoIdle::Interrupted()
{
	chassis->RawDrive(0.0f, 0.0f);
}
