#ifndef AUTO_BASIC_RUSH_5428_H
#define AUTO_BASIC_RUSH_5428_H

#include "../CommandBase.h"
#include "../Typedefs_5428.h"

class AutoBasicRush: public CommandBase
{
private:
	F32 m_time;
	F32 m_speed;
public:
	AutoBasicRush(F32 time, F32 speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
