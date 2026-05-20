
#include "Bsp1_GenModules.h"

RampGen::RampGen()
{
	_v1 = 0;
	//SetPointsPerPeriod(100);
};

void RampGen::SetFrequ(float cfrequ)
{
	SetPointsPerPeriod(1.0f / cfrequ);
};

void RampGen::SetPointsPerPeriod(float cpoints)
{
	_increment = 2.0f / cpoints;
};

void RampGen::CalcOneStep()
{
	_v1 = _v1 + _increment;
	if (_v1 > 1)
		_v1 = -1.0f + (_v1 - 1.0f);
};




RectGen::RectGen()
{
	_v1 = 0;
	_thr = 0;
	//SetPointsPerPeriod(100);
};

void RectGen::SetFrequ(float cfrequ)
{
	SetPointsPerPeriod(1.0f / cfrequ);
};

void RectGen::SetPointsPerPeriod(float cpoints)
{
	_increment = 2.0f / cpoints;
};

void RectGen::setPulseWidth(float cduty)
{
	_thr = cduty;
};

void RectGen::CalcOneStep()
{
	_signal = _signal + _increment;
	if (_signal > 1)
		_signal = -1.0f + (_signal - 1.0f);

	if (_signal > _thr)
		_v1 = -1;
	else
		_v1 = 1;
};