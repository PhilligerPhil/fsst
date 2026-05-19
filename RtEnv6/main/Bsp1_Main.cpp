
#include "RTEnvHL.h"
#include "SvProtocol3.h"
#include "Bsp1_GenModules.h"
// #include "SineGenLsg.h"
// #include "Empty_Tp1Ord.h"

SvProtocol3 ua0;
RampGen ram01;
RectGen rec01;

float ampl = 1;
float signal;
int swt = 1;

void setFrequency(float frequ);


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
        setFrequency(ua0.ReadF());
        ua0.SvMessage("Set Frequency");
    }
    if (cmd == 4)
    {
        swt = ua0.ReadI16();
        ua0.SvMessage("Set Curve");
    }
    if (cmd == 5)
    {
        rec01.setPulseWidth(ua0.ReadF());
        ua0.SvMessage("Set Dutycycle");
    }
  }
}


void setFrequency(float frequ)
{
    ram01.SetFrequ(frequ);
    rec01.SetFrequ(frequ);
}


void ExecSignalChain()
{
    ram01.CalcOneStep();
    rec01.CalcOneStep();

    switch (swt)
    {
    case 1: signal = ram01._v1 * ampl; break;
    case 2: signal = rec01._v1 * ampl; break;
    }
}

void Monitor(void* arg)
{
  while (1) {
    vTaskDelay(1); // 100Hz
    ExecSignalChain();
    if (ua0.acqON) {
        ua0.WriteSvF(1, signal);
      ua0.Flush();
    }
  }
}

extern "C" void app_main(void)
{
  printf("Bsp1_Main\n");
  InitRtEnvHL(); 
  InitUart(UART_NUM_0, 500000);
  createTask(Monitor, "Monitor", 2048, 10);
  CommandLoop();
}
