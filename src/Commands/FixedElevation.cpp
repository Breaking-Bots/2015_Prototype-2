#include "FixedElevation.h"
#include "../Elon.h"

FixedElevation::FixedElevation()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(elevator);
}

// Called just before this Command runs the first time
void FixedElevation::Initialize()
{
	SetTimeout(ELEVATOR_TIME());
}

// Called repeatedly when this Command is scheduled to run
void FixedElevation::Execute()
{
	elevator->Elevate(1);
}

// Make this return true when this Command no longer needs to run execute()
bool FixedElevation::IsFinished()
{
	return elevator->SwitchStatus() ||IsTimedOut() || IsCanceled();
}

// Called once after isFinished returns true
void FixedElevation::End()
{
	elevator->Elevate(0.0f);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FixedElevation::Interrupted()
{
	elevator->Elevate(0.0f);
}
