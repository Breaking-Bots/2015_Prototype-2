#ifndef CAMERA_5428_H
#define CAMERA_5428_H

#include <Commands/Subsystem.h>
#include <WPILib.h>
#include <Servo.h>
#include "../Typedefs_5428.h"

class Camera: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Servo* m_servo;
public:
	Camera();
	void InitDefaultCommand();
	INLINEFORCE void Orient(F32 angle){ m_servo->SetAngle(m_servo->GetAngle() + angle);}
	INLINEFORCE void SetPos(F32 pos){m_servo->Set(pos);}
	INLINEFORCE F32 Pos(){return m_servo->Get();}
	~Camera();
};

#endif
