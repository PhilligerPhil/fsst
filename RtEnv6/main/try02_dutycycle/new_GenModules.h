#ifndef GenModules_h
#define GenModules_h

//---------------------------------------------------------------
//---------------------------------------------------------------

class Sawtooth
{
public:
	float v1;
private:
	float _increment;
public:
	Sawtooth();
	
	void setpointsperperiod(float cpoints);

	void setFrequenzy(float cfrequ);

	void Calconestep();
};


class SawRect
{
public:
	float v1;
private:
	float _increment;
public:
	SawRect();

	void setpointsperperiod(float cpoints);

	void setFrequenzy(float cfrequ);

	void Calconestep();
};
//---------------------------------------------------------------
//---------------------------------------------------------------

class RectGen
{
public:
	float v1;
private:
	float _thr;
	float _signal;
	float _increment;
	float _dutyc;
	float _periodt;
public:
	RectGen();

	void setpointsperperiod(float cpoints);

	void setFrequenzy(float cfrequ);

	void setDutycycle(float cpercent);

	void Calconestep();
};

//---------------------------------------------------------------
//---------------------------------------------------------------

class TriangleGen 
{
public:
	float v1;
private:
	int _thr;
	float _signal;
	float _increment;
public:
	TriangleGen();

	void setpointsperperiod(float cpoints);

	void setFrequenzy(float cfrequ);

	void Calconestep();
};

//---------------------------------------------------------------
//---------------------------------------------------------------

/*
class SineGen
{
public:
	float v1[360];
private:
	float _amplitude;
	float _freq;
	float _increment;
	float _phi;
public:
	SineGen();

	void setamplitude(float campl);

	void setFrequenzy(float cfrequ);

	void Calconestep();
};*/
#endif