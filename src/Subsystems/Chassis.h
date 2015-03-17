#ifndef CHASSIS_5428_H
#define CHASSIS_5428_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Typedefs_5428.h"
#include <Talon.h>
#include <Gyro.h>
#include <RobotDrive.h>

class Chassis: public Subsystem
{
private:
	Talon* m_frontLeft;
	Talon* m_backLeft;
	Talon* m_frontRight;
	Talon* m_backRight;
	RobotDrive* m_drive;
	Gyro* m_gyro;

	B8 m_squaredInput;
	F32 m_zLinear;
	F32 m_xLinear;
	B8 m_PIDControl;
public:
	Chassis();

	void ElonDrive(F32 fwd, F32 turn, F32 mgntd);
	void EnhancedDrive(F32 fwd, F32 gturn, F32 lturn, F32 mgntd);
	void RawDrive(F32 speed, F32 curve);

	void InitDefaultCommand();

	INLINEFORCE void SetSquaredInput(B8 squaredInput){m_squaredInput = squaredInput;}
	F32 GetGyro() const;
	void ResetGyro();

	void Update();

	INLINEFORCE void EnablePID(){  m_PIDControl = true;}
	INLINEFORCE void DisablePID(){ m_PIDControl = false;}

	~Chassis();
};

#endif
