
#include "__FuncGenModules.h"


SignedRampGen::SignedRampGen()
{
	val=0;
	SetPointsPerPeriod(100);
}

void SignedRampGen::SetPointsPerPeriod(float aPoints)
{
	_inc = 2.0f/aPoints;
}

void SignedRampGen::SetFrequ(float aFrequ)
{
	SetPointsPerPeriod(1.0f/aFrequ);
}

void SignedRampGen::CalcOneStep()
{
	val = val + _inc;
	if( val>1.0f )
    val = -1.0f + (val - 1.0f); 
}



RectGen::RectGen()
{
	val=0; _phase=0; _thrs=0;
	SetPointsPerPeriod(100);
}

void RectGen::SetPointsPerPeriod(float aPoints)
{
	_inc = 2.0f/aPoints;
}

void RectGen::SetFrequ(float aFrequ)
{
	SetPointsPerPeriod(1.0f/aFrequ);
}

void RectGen::CalcOneStep()
{
	_phase = _phase + _inc;
	if( _phase>1.0f )
    _phase = -1.0f + (_phase - 1.0f);
	
	if( _phase<_thrs )
		val = -1;
	else
		val = +1;
}


TriangleGen::TriangleGen()
{
  val=_phase=0;
  SetPointsPerPeriod(100);
}

void TriangleGen::SetPointsPerPeriod(float aPoints)
{
  _inc = 4.0f/aPoints;
}

void TriangleGen::SetFrequ(float aFrequ)
{
  SetPointsPerPeriod(1.0f/aFrequ);
}

void TriangleGen::CalcOneStep()
{
  _phase = _phase + _inc;
  if( _phase>1.0f ) {
    _phase = -1 + (_phase - 1.0f);
    if( _state==1 )
      _state=2;
    else
      _state=1;
  }
  if( _state==1 )
    val = _phase;
  else
    val = -_phase;
}


















