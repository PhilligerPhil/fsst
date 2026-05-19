
#include "RTEnvHL.h"
#include "SvProtocol3.h"
#include "__FuncGenModules.h"
#include "__SineGenLsg.h"
#include "__Tp1Ord.h"

SvProtocol3 ua0;

SignedRampGen fg1; RectGen fg2;
TriangleGen fg3; SineGen fg4; RectHarm fg5;
Tp1Ord tp1;

float ampl1 = 1.0;
float v1 = 0, v2 = 0;

int swt = 1; // 1..switch auf fg1 2..switch auf fg2

void SetFrequ(float frequ);

void CommandLoop()
{
  int cmd;
  while (1) {
    cmd = ua0.GetCommand();
    if (cmd == 2) {
      SetFrequ(ua0.ReadF());
      ua0.SvMessage("Set Frequ");
    }
    if (cmd == 3) {
      ampl1 = ua0.ReadF();
      ua0.SvMessage("Set Ampl");
    }
    if (cmd == 4) {
      tp1.SetAlpha(ua0.ReadF());
      ua0.SvMessage("Set alpha(fg)");
    }
    if (cmd == 5) {
      swt = ua0.ReadI16();
      ua0.SvMessage("switch curves");
    }
    if (cmd == 6) {
      fg2.SetPulsWidth(ua0.ReadF());
      ua0.SvMessage("set Thrs");
    }
    if (cmd == 7) {
      for (int i = 0; i < 3; i++)
        fg5.ampl[i] = ua0.ReadF();
      ua0.SvMessage("over tones");
    }
  }
}

void SetFrequ(float frequ)
{
  fg1.SetFrequ(frequ); fg2.SetFrequ(frequ);
  fg3.SetFrequ(frequ); fg4.SetFrequ(frequ);
}

void ExecSignalChain()
{
  fg1.CalcOneStep(); fg2.CalcOneStep();
  fg3.CalcOneStep(); fg4.CalcOneStep();
  fg5.CalcOneStep();

  switch (swt) {
    case 1: v1 = fg1.val; break;
    case 2: v1 = fg2.val; break;
    case 3: v1 = fg3.val; break;
    case 4: v1 = fg4.val.im; break;
    case 5: v1 = fg5.val; break;
  }
  
  v2 = v1 * ampl1;
  tp1.CalcOneStep(v2);
  // gefilterter Wert ist auf tp1.y
}

void Monitor(void* arg)
{
  while (1) {
    vTaskDelay(1); // 100Hz
    ExecSignalChain();
    if (ua0.acqON) {
      ua0.WriteSvF(1, v2);
      ua0.WriteSvF(2, tp1.y);
      ua0.Flush();
    }
  }
}

extern "C" void app_main(void)
{
  printf("FuncGenLsg_1\n");
  InitRtEnvHL(false); 
  InitUart(UART_NUM_0, 500000);
  // InitSoftAp("sepp", 5);
  createTask(Monitor, "Monitor", 2048, 10);
  CommandLoop();
}
