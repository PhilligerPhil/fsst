
#include "RTEnvHL.h"
#include "SvProtocol3.h"
#include "new_GenModules.h"
// #include "SineGenLsg.h"
#include "new_Tp1Ord.h"

SvProtocol3 ua0;
Sawtooth swt01;
new_Tp1Ord tpf01;
new_Hp1Ord hpf01;
new01_Hp1Ord hpf02;
RectGen rec01;
TriangleGen tri01;
SawRect srect01;
//SineGen sin01;

float Signalvalue_01 = 0;
float ampl = 1.0;
int swt = 1;



void setFrequenzy(float frequ);
void setAlpha(float alpha);


void CommandLoop()
{
  int cmd;
  while (1) 
  {
    cmd = ua0.GetCommand();
    if (cmd == 2)
    {
        ampl = ua0.ReadF();
        ua0.SvMessage("Set Amplitude");
    }
    if (cmd == 3)
    {
        setFrequenzy(ua0.ReadF());
        ua0.SvMessage("Set Periodtime");
    }
    if (cmd == 4)
    {
        setAlpha(ua0.ReadF());
        ua0.SvMessage("Set Filter");
    }
    if (cmd == 5)
    {
        swt = ua0.ReadI16();
        ua0.SvMessage("Set Curve Type");
    }
    if (cmd == 6)
    {
        rec01.setDutycycle(ua0.ReadF());
        ua0.SvMessage("Set Dutycycle");
    }
  }
}

void setFrequenzy(float frequ)
{
    swt01.setFrequenzy(frequ);
    rec01.setFrequenzy(frequ);
    tri01.setFrequenzy(frequ);
    //sin01.setFrequenzy(frequ);
}


void setAlpha(float alpha)
{
    tpf01.setAlpha(alpha);
    hpf01.setAlpha(alpha);
}

/*
void setAmplitude(float ampl)
{
    sin01.setamplitude(ampl);
}
*/

void ExecSignalChain()
{
    swt01.Calconestep();
    rec01.Calconestep();
    tri01.Calconestep();
    //sin01.Calconestep();
    srect01.Calconestep();

    switch (swt)
    {
    case 1:Signalvalue_01 = swt01.v1 * ampl; break;
    case 2:Signalvalue_01 = rec01.v1 * ampl; break;
    case 3:Signalvalue_01 = tri01.v1 * ampl; break;
    //case 4:Signalvalue_01 = sin01.v1 * ampl; break;
    case 5:Signalvalue_01 = srect01.v1 * ampl; break;
    }

    tpf01.Calconestep(Signalvalue_01);
    hpf01.Calconestep(Signalvalue_01);
    hpf02.Calconestep(Signalvalue_01, tpf01.y);
}

void Monitor(void* arg)
{
  while (1) {
    vTaskDelay(1); // 100Hz
    ExecSignalChain();
    if (ua0.acqON) {
        ua0.WriteSvF(1, Signalvalue_01);
        //ua0.WriteSvF(2, hpf01.y);
        //ua0.WriteSvF(3, hpf02.y);
      ua0.Flush();
    }
  }
}

extern "C" void app_main(void)
{
  printf("new_Main\n");
  InitRtEnvHL(); 
  InitUart(UART_NUM_0, 500000);
  createTask(Monitor, "Monitor", 2048, 10);
  CommandLoop();
}
