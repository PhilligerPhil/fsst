
#include "EmptyFuncGenModules.h"


SignedRampGen::SignedRampGen()
{
	value_1 = 0;
	setpointsperperiodram(100);
}

void SignedRampGen::setpointsperperiodram(float aPoints)
{
	_increment = 2.0f / aPoints;
}

void SignedRampGen::setFrequenzyram(float aFrequ)
{
	setpointsperperiodram(1.0f / aFrequ);
}

void SignedRampGen::Calconestepram()
{
	value_1 = value_1 + _increment;
	if (value_1 > 1.0f)
		value_1 = -1.0f + (value_1 - 1.0f);
}




RectGen::RectGen()
{
	value_1 = 0;
	setpointsperperiodrec(100);
}

void RectGen::setpointsperperiodrec(float aPoints)
{
	_increment = 2.0f / aPoints;
}

void RectGen::setFrequenzyrec(float aFrequ)
{
	setpointsperperiodrec(1.0f / aFrequ);
}

void RectGen::Calconesteprec()
{
	v_1 = v_1 + _increment;
	if (v_1 > 1.0f)
		v_1 = -1.0f + (v_1 - 1.0f);


	if (v_1 < _thr)
	{
		value_1 = -1;
	}
	else if (_increment > _thr)
	{
		value_1 = 1;
	}
}




TriangleGen::TriangleGen()
{
	value_1 = _v1 = 0;
	setpointsperperiodtri(100);
}

void TriangleGen::setpointsperperiodtri(float aPoints)
{
	_increment = 2.0f / aPoints;
}

void TriangleGen::setFrequenzytri(float aFrequ)
{
	setpointsperperiodtri( 1.0f / _increment);
}

void TriangleGen::Calconesteptri()
{
	_v1 = _v1 + _increment;
	if (_v1 > 1.0f)
	{
		_v1 = -1.0f + (_v1 - 1.0f);
		if (_thr == 1)
			_thr = 2;
		else
			_thr = 1;
	}
	if (_thr == 1)
		value_1 = _v1;
	else
		value_1 = -_v1;
}
