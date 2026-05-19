
#include "new_GenModules.h"
#include "math.h"

//---------------------------------------------------------------
//---------------------------------------------------------------

Sawtooth::Sawtooth()
{
	v1 = 0;
	setpointsperperiod(100);
}

void Sawtooth::setpointsperperiod(float cpoints)
{
	_increment = 2.0f / cpoints;
}

void Sawtooth::setFrequenzy(float cfrequ)
{
	setpointsperperiod(1.0f / cfrequ);
}

void Sawtooth::Calconestep()
{
	v1 = v1 + _increment;
	if (v1 > 1) {
		v1 = -1.0f + (v1 - 1.0f);
	}
}

SawRect::SawRect()
{
	v1 = 0;
	setpointsperperiod(100);
}

void SawRect::setpointsperperiod(float cpoints)
{
	_increment = 2.0f / cpoints;
}

void SawRect::setFrequenzy(float cfrequ)
{
	setpointsperperiod(cfrequ);
}

void SawRect::Calconestep()
{
	v1 = v1 + _increment;
	if (v1 > 1.0f)
		v1 = 0.0f + (v1 - 1.0f);
}


//---------------------------------------------------------------
//---------------------------------------------------------------

RectGen::RectGen()
{
	v1 = 0;
	_thr = 0.5;
	setpointsperperiod(100);
}

void RectGen::setpointsperperiod(float cpoints)
{
	_increment = 2.0f / cpoints;
}

void RectGen::setFrequenzy(float cfrequ)
{
	setpointsperperiod(1.0f / cfrequ);
}

void RectGen::setDutycycle(float cpercent)
{
	_thr = cpercent;
}

void RectGen::Calconestep()
{
	_signal = _signal + _increment;
	if (_signal > 1)
	{
		_signal = 0.0f +(_signal - 1.0f);
	}

	if (_signal > _thr)
		v1 = 1;
	else
		v1 = 0;
}

//---------------------------------------------------------------
//---------------------------------------------------------------

TriangleGen::TriangleGen()
{
	v1 = 0;
	_signal = 0;

	setpointsperperiod(100);
}

void TriangleGen::setpointsperperiod(float cpoints)
{
	_increment = 2.0f / cpoints;
}

void TriangleGen::setFrequenzy(float cfrequ)
{
	setpointsperperiod(1.0f / cfrequ);
}

void TriangleGen::Calconestep()
{
	_signal = _signal + _increment;
	if (_signal > 1.0f)
	{
		_signal = -1.0f + (_signal - 1.0f);

		if (_thr == 1)
			_thr = 2;
		else
			_thr = 1;
	}

	if (_thr == 1)
		v1 = _signal;
	else
		v1 = -_signal;
}

//---------------------------------------------------------------
//---------------------------------------------------------------

/*
SineGen::SineGen()
{
	v1[0] = 0;
	_freq = 1.0f;
	_phi = 0;
}

void SineGen::setamplitude(float campl)
{
	_amplitude = campl;
}

void SineGen::setFrequenzy(float cfrequ)
{
	_increment = cfrequ;
	_freq = 1.0f/cfrequ;
}

void SineGen::Calconestep()
{
	v1 = _amplitude * sin(2*M_PI*_freq*(i*M_PI/360)+_phi);
}*/
