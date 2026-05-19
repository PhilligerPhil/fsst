
#include "RTEnvHL.h"
#include "EmptyTp1Ord.h"
#include "SvProtocol3.h"
#include "EmptyFuncGenModules.h"
// #include "SineGenLsg.h"

SvProtocol3 ua0;

SignedRampGen saege01;
RectGen rechte01;
TriangleGen tri01;
Tp1Ord TP_1;

void setFrequ(float frequ);
void setAlpha(float koeffa);

float v1 = 0;
float y1 = 0;
float ampl1 = 1.0;
int swt = 1;

void CommandLoop()
{
  int cmd;
  while (1)
  {
      cmd = ua0.GetCommand();
      if (cmd == 2)
      {
          setFrequ(ua0.ReadF());
          ua0.SvMessage("Set Frequency");
      }
      if (cmd == 3)
      {
          swt = ua0.ReadI16();
          ua0.SvMessage("set Curve");
      }
      if (cmd == 4)
      {
          setAlpha(ua0.ReadF());
          ua0.SvMessage("set koeffizient a");
      }
  }
}


void setFrequ(float frequ)
  {
      saege01.setFrequenzyram(frequ);
      rechte01.setFrequenzyrec(frequ);
      tri01.setFrequenzytri(frequ);
  }


void setAlpha(float koeffa)
{
    TP_1.setkoeff_a(koeffa);
}


void ExecSignalChain()
{
    saege01.Calconestepram();
    rechte01.Calconesteprec();
    tri01.Calconesteptri();
    

    switch (swt)
    {
    case 1: v1 = saege01.value_1; break;
    case 2: v1 = rechte01.value_1; break;
    case 3: v1 = tri01.value_1; break;
    }

    y1 = v1 * ampl1;
    TP_1.Calconestepfilt(y1);
}


void Monitor(void* arg)
{
  while (1) {
    vTaskDelay(1); // 100Hz
    ExecSignalChain();
    if (ua0.acqON) {
      ua0.WriteSvF(1, v1);
      ua0.WriteSvF(2, TP_1.y);
      ua0.Flush();
    }
  }
}


extern "C" void app_main(void)
{
  printf("EmptyMain\n");
  InitRtEnvHL(false); 
  InitUart(UART_NUM_0, 500000);
  createTask(Monitor, "Monitor", 2048, 10);
  CommandLoop();
}
