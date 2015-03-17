#ifndef GAMEPAD_5428_H
#define GAMEPAD_5428_H

#include "Typedefs_5428.h"
#include <GenericHID.h>
#include <DriverStation.h>
#include "Elon.h"

enum AXIS{
	LX,
	LY,
	LT,
	RT,
	RX,
	RY,

	AXIS_COUNT
};

class ControllerButton: public Button{
private:
	GenericHID* m_controller; //TODO: possibly remove
	U32 m_map;
public:
	ControllerButton():m_controller(nullptr), m_map(0){
	}
	ControllerButton(GenericHID* controller, U32 map):m_controller(controller), m_map(map){
	}

	INLINEFORCE bool Get(){return m_controller->GetRawButton(m_map);}

	INLINEFORCE void Tapped(Command* cmmd){WhenPressed(cmmd);}
	INLINEFORCE void Held(Command* cmmd){WhileHeld(cmmd);}
	INLINEFORCE void Released(Command* cmmd){WhenReleased(cmmd);}

	~ControllerButton(){
		if(m_controller) delete m_controller; //TODO: study this

		m_controller = nullptr;
	}
};

enum BTTN{
	A = 1,
	B,
	X,
	Y,
	LB,
	RB,
	BACK,
	START,
	L3,
	R3,

	BTTN_COUNT
};

class Gamepad: public GenericHID {
protected:
	DriverStation* m_ds;
public:
	U32 m_port;
	ControllerButton* m_bttns;
	F32 m_deadzone;
	explicit Gamepad(U32 port):m_port(port), m_deadzone(DEADZONE_GMPD()){
		m_ds = DriverStation::GetInstance();
		m_bttns = new ControllerButton[BTTN::BTTN_COUNT - BTTN::A];
		for(I32 i = BTTN::A; i < BTTN_COUNT; i++) m_bttns[i] = ControllerButton(this, i);
	}

	INLINEFORCE F32 CheckDeadzone(F32 value) const{
		I32 sign = (0.0f < value) - (value < 0.0f);
		return (sign * value > m_deadzone)? (value - m_deadzone*sign)/(1.0f - m_deadzone): 0;
	}

	I32 GetPOV(U32 pov = 0){
		return m_ds->GetStickPOV(m_port, pov);
	}

	F32 GetRawAxis(U32 axis){
		return m_ds->GetStickAxis(m_port, axis);
	}

	INLINEFORCE F32 LX(){ return CheckDeadzone(GetRawAxis(AXIS::LX));}
	INLINEFORCE F32 LY(){ return CheckDeadzone(GetRawAxis(AXIS::LY));}
	INLINEFORCE F32 RX(){ return CheckDeadzone(GetRawAxis(AXIS::RX));}
	INLINEFORCE F32 RY(){ return CheckDeadzone(GetRawAxis(AXIS::RY));}

	F32 GetX(JoystickHand hand){
		if(hand == 0) return CheckDeadzone(GetRawAxis(AXIS::LX));
		else if(hand == 1) return CheckDeadzone(GetRawAxis(AXIS::RX));
		return 0.0f;
	}
	F32 GetY(JoystickHand hand){
		if(hand == 0) return CheckDeadzone(GetRawAxis(AXIS::LY));
		else if(hand == 1) return CheckDeadzone(GetRawAxis(AXIS::RY));
		return 0.0f;
	}
	F32 GetZ(){return 0.0f;}

	INLINEFORCE F32 T(){return GetRawAxis(AXIS::RT) - GetRawAxis(AXIS::LT);}
	INLINEFORCE F32 LT(){return GetRawAxis(AXIS::LT);}
	INLINEFORCE F32 RT(){return GetRawAxis(AXIS::RT);}

	bool GetTrigger(JoystickHand hand){
		if(hand == 0) return (GetRawAxis(AXIS::LT) > 0);
		else if(hand == 1) return (GetRawAxis(AXIS::RT) > 0);
		return false;
	}

	F32 GetThrottle(){ return T();}
	F32 GetTwist(){ return RX();}

	bool GetTop(JoystickHand hand) {
		if(hand == 0) return m_bttns[BTTN::L3].Get();
		else if(hand == 1) return m_bttns[BTTN::R3].Get();
		return false;
	}

	bool GetBumper(JoystickHand hand){
		if(hand == 0) return m_bttns[BTTN::LB].Get();
		else if(hand == 1) return m_bttns[BTTN::RB].Get();
		return false;
	}

	bool GetRawButton(U32 bttn){
		return m_ds->GetStickButton(m_port, bttn);
	}

	~Gamepad(){
		if(m_bttns) delete[] m_bttns;
		if(m_ds) delete m_ds; //TODO: study this

		m_bttns = nullptr;
		m_ds = nullptr;
	}
};

#endif
