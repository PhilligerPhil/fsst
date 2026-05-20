#ifndef FuncGenAll_h
#define FuncGenAll_h

class RampGen {
private:
	float _increment;
public:
	float _v1;

	RampGen();

	void SetFrequ(float cfrequ);

	void SetPointsPerPeriod(float cpoints);

	void CalcOneStep();
};


class RectGen {
private:
	float _increment;
	float _thr;
	float _signal;
public:
	float _v1;
	RectGen();

	void SetFrequ(float cfrequ);

	void SetPointsPerPeriod(float cpoints);

	void setPulseWidth(float cduty);

	void CalcOneStep();
};
#endif
