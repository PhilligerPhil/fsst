
#ifndef SineGen_h
#define SineGen_h

#include "math.h"

class Complex {
  public:
    float re, im;
  public:
    Complex()
      { re=0; im=0; }
    
    void SetPolar(float aR, float aPhi)
      { re = aR*cos(aPhi); im = aR*sin(aPhi); }

    Complex Mult(Complex aB)
    {
      Complex prod;
      prod.re = re*aB.re - im*aB.im;
      prod.im = im*aB.re + re*aB.im;
      return prod;
    }
};


class SineGen {
  public:
    Complex _inc;
  public:
    Complex val;
  public:
    SineGen()
			{ Init(); }
	
		void Init()
			{ Reset(); SetPointsPerPeriod(100.0); }
    
    void Reset()
      { val.SetPolar(1.0,0.0); }
    
    void SetPointsPerPeriod(float aPoints)
      { _inc.SetPolar(1.0, (2*M_PI)/aPoints); }

    void SetFrequ(float aFrequ)
      { SetPointsPerPeriod(1.0f/aFrequ); }

    void CalcOneStep()
    { 
      val = val.Mult(_inc);
    }
};


// Rechteck aus Oberschwingungen zusammenbauen
class RectHarm {
  public:
    float val;
  private:
    SineGen fg1, fg3, fg5;
  public:
    float ampl[3];
  public:
    RectHarm() 
    {
      ampl[0] = 1; ampl[1] = (1.0 / 3.0); ampl[2] = (1.0 / 5.0);
      SetFrequ(0.005); 
    }
    
    void SetFrequ(float aFrequ)
      { fg1.SetFrequ(aFrequ); fg3.SetFrequ(3.0f*aFrequ); fg5.SetFrequ(5.0f*aFrequ); }

    void CalcOneStep()
    {
      fg1.CalcOneStep(); fg3.CalcOneStep(); fg5.CalcOneStep();
      val = ampl[0]*fg1.val.im + ampl[1]*fg3.val.im + ampl[2]*fg5.val.im;
    }
};


#endif

