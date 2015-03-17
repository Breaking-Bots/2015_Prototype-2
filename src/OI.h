#ifndef OI_5428_H
#define OI_5428_H

#include "WPILib.h"
#include "Typedefs_5428.h"
#include "Gamepad.h"

class OI
{
private:
	OI();
	intern OI* m_instance;
	F32 m_magnitude;
	F32 m_elevatorRate;
	B8 m_disable; //TODO: disable this disable

public:
	Gamepad* driverCtrl;
	Gamepad* systemCtrl;

	INLINEFORCE glob OI* GetInstance(){ return (m_instance?m_instance: new OI());}

	void Init();

	void Update();

	INLINEFORCE F32 SysMgntd() const{ return m_magnitude;}
	INLINEFORCE F32 ElvRt() const{ return m_elevatorRate;} //Elevator rate

	INLINEFORCE void Disable(){ m_disable = true;}
	INLINEFORCE void Enable(){ m_disable = false;}

};

#endif
