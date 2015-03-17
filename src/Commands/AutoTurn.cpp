#include "AutoTurn.h"
#include "../MathUtil.h"


AutoTurn::AutoTurn(F32 angle, F32 speed):m_angle(angle), m_speed(speed)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(chassis);
}

// Called just before this Command runs the first time
void AutoTurn::Initialize()
{
	SetTimeout(4.0f); //safety
	m_angle0 = chassis->GetGyro();
	m_speed *= (0.0f < m_speed) - (m_speed < 0.0f);
}

// Called repeatedly when this Command is scheduled to run
void AutoTurn::Execute()
{
	chassis->RawDrive(0.0f, m_speed);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoTurn::IsFinished()
{
	return EpsilonEquals(chassis->GetGyro(), m_angle - m_angle0, 0.01f) || IsTimedOut();
}

// Called once after isFinished returns true
void AutoTurn::End()
{
	chassis->RawDrive(0.0f, 0.0f);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoTurn::Interrupted()
{
	chassis->RawDrive(0.0f, 0.0f);
}
