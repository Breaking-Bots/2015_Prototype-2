#include "AutoBasicRush.h"

AutoBasicRush::AutoBasicRush():m_time(0), m_speed(0), m_reinit(true){
	Requires(chassis);
}

AutoBasicRush::AutoBasicRush(F32 time, F32 speed):m_time(time), m_speed(speed), m_reinit(false)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(chassis);
}

// Called just before this Command runs the first time
void AutoBasicRush::Initialize()
{
	if(m_reinit){
		m_time = AUTO_DRV_TIME();
		m_speed = 0.3f;
		m_reinit = false;
	}
	SetTimeout(m_time);
	chassis->EnablePID();
}

// Called repeatedly when this Command is scheduled to run
void AutoBasicRush::Execute()
{
	chassis->RawDrive(m_speed, 0.0f);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoBasicRush::IsFinished()
{
	return IsTimedOut() || IsCanceled();
}

// Called once after isFinished returns true
void AutoBasicRush::End()
{
	chassis->RawDrive(0.0f, 0.0f);
	chassis->DisablePID();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoBasicRush::Interrupted()
{
	chassis->RawDrive(0.0f, 0.0f);
	chassis->DisablePID();
}
