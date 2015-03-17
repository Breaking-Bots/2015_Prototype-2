#include "AutoLift.h"

AutoLift::AutoLift(F32 time, F32 speed):m_time(time), m_speed(speed), m_isRising(false)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(elevator);
}

// Called just before this Command runs the first time
void AutoLift::Initialize()
{
	SetTimeout(m_time);
	if(m_speed >= 0) m_isRising = true;
	else elevator->ResetSwitch();
}

// Called repeatedly when this Command is scheduled to run
void AutoLift::Execute()
{
	elevator->Elevate(-m_speed);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoLift::IsFinished()
{
	return IsTimedOut() || (m_isRising && elevator->SwitchStatus());
}

// Called once after isFinished returns true
void AutoLift::End()
{
	elevator->Elevate(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoLift::Interrupted()
{
	elevator->Elevate(0);
}
