#include "RaiseElevator.h"

RaiseElevator::RaiseElevator()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(elevator);
}

// Called just before this Command runs the first time
void RaiseElevator::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void RaiseElevator::Execute()
{
	elevator->Elevate(oi->ElvRt());
}

// Make this return true when this Command no longer needs to run execute()
bool RaiseElevator::IsFinished()
{
	return elevator->SwitchStatus() || IsCanceled();
}

// Called once after isFinished returns true
void RaiseElevator::End()
{
	elevator->Elevate(0.0f);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RaiseElevator::Interrupted()
{
	elevator->Elevate(0.0f);
}
