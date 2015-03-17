#ifndef AUTO_TURN_5428_H
#define AUTO_TURN_5428_H

#include "../CommandBase.h"
#include "../Typedefs_5428.h"

class AutoTurn: public CommandBase
{
private:
	F32 m_angle;
	F32 m_angle0;
	F32 m_speed;
public:
	AutoTurn(F32 angle, F32 speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
