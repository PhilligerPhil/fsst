//#ifndef FuncGenAll_h
#define FuncGenAll_h

class SignedRampGen {
public:
	float value_1;
private:
	float _increment;

public:
	SignedRampGen();

	void setpointsperperiodram(float aPoints);

	void setFrequenzyram(float aFrequ);

	void Calconestepram();
};



class TriangleGen {
public:
	float value_1;
	float _v1;
	float _thr;
private:
	float _increment;


public:
	TriangleGen();

	void setpointsperperiodtri(float aPoints);

	void setFrequenzytri(float aFrequ);

	void Calconesteptri();
};



class RectGen {
public:
	float value_1, v_1;
private:
	float _increment;
	int _thr = 0;

public:
	RectGen();
	
	void setpointsperperiodrec(float aPoints);

	void setFrequenzyrec(float aFrequ);

	void Calconesteprec();
};