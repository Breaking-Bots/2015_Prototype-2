#ifndef ELEVATOR_5428_H
#define ELEVATOR_5428_H

#include <Commands/Subsystem.h>
#include <WPILib.h>
#include "../Typedefs_5428.h"
#include <DigitalInput.h>
#include <Counter.h>

class Victor;

class Elevator: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Victor* m_victor;
	DigitalInput* m_limitSwitch;
	Counter* m_counter;
public:
	Elevator();
	void InitDefaultCommand();
	INLINEFORCE void ResetSwitch(){ m_counter->Reset();}
	INLINEFORCE U32 GetCount() const{ return m_counter->Get();}
	INLINEFORCE B8 SwitchStatus() const{ return m_counter->Get();}

	void Elevate(F32 mgntd);

	~Elevator();
};

#endif
