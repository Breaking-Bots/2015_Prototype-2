#include "Chassis.h"
#include "../RobotMap.h"
#include <SmartDashboard/SmartDashboard.h>
#include <LiveWindow/LiveWindow.h>
#include "../Elon.h"
#include "../RobotMap.h"
#include "../Console.h"
#include "../Commands/Drive.h"

Chassis::Chassis() :
		Subsystem("Chassis"),
		m_squaredInput(false), m_zLinear(0), m_xLinear(0), m_PIDControl(false)
{
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.

	m_frontLeft = new Talon(DT_FRONTLEFT);
	m_backLeft = new Talon(DT_BACKLEFT);
	m_frontRight = new Talon(DT_FRONTRIGHT);
	m_backRight = new Talon(DT_BACKRIGHT);
	m_gyro = new Gyro(DT_GYRO);
	m_gyro->SetSensitivity(0.006);
	m_gyro->StartLiveWindowMode();

	m_drive = new RobotDrive(m_frontLeft, m_backLeft, m_frontRight, m_backRight);
	C::Out("Chassis Initialized");
}

void Chassis::ElonDrive(F32 fwd, F32 turn, F32 mgntd) {
	m_zLinear = mgntd * fwd;
	m_xLinear = mgntd * turn;
}

void Chassis::EnhancedDrive(F32 fwd, F32 gturn, F32 lturn, F32 mgntd) {
	m_zLinear = mgntd * fwd;
	m_xLinear = mgntd * ((gturn * (1.0f - DEADZONE_GMPD())) + (lturn * DEADZONE_GMPD()));
}

void Chassis::RawDrive(F32 speed, F32 curve) {
	m_drive->ArcadeDrive(speed, curve, m_squaredInput);
}

void Chassis::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new Drive());
}

F32 Chassis::GetGyro() const {
	return m_gyro->GetAngle();
}

void Chassis::ResetGyro(){
	m_gyro->Reset();
}

void Chassis::Update() {
	if(m_PIDControl){
		m_drive->ArcadeDrive(m_zLinear, -m_gyro->PIDGet() * DRIVE_TRAIN_P(), m_squaredInput);
	}else{
		m_drive->ArcadeDrive(m_zLinear, m_xLinear - (DRIVE_TRAIN_A()/DRIVE_TRAIN_K()) * m_zLinear, m_squaredInput);
	}
}

Chassis::~Chassis() {
	if(m_drive) delete m_drive;
	if(m_gyro) delete m_gyro;
	if(m_backRight) delete m_backRight;
	if(m_frontRight) delete m_frontRight;
	if(m_backLeft) delete m_backLeft;
	if(m_frontLeft) delete m_frontLeft;
}
