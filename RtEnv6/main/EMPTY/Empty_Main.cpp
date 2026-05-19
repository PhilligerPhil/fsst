
#include "RTEnvHL.h"
#include "SvProtocol3.h"
// #include "Empty_GenModules.h"
// #include "SineGenLsg.h"
// #include "Empty_Tp1Ord.h"

SvProtocol3 ua0;



void CommandLoop()
{
  int cmd;
  while (1) 
  {
    cmd = ua0.GetCommand();
    if (cmd = 1)
    {
        Set
    }
    if (cmd = 2)
    {

    }
    if (cmd = 3)
    {

    }

  }
}

void ExecSignalChain()
{
}

void Monitor(void* arg)
{
  while (1) {
    vTaskDelay(1); // 100Hz
    ExecSignalChain();
    if (ua0.acqON) {
      ua0.Flush();
    }
  }
}

extern "C" void app_main(void)
{
  printf("FuncGenLsg_1\n");
  InitRtEnvHL(); 
  InitUart(UART_NUM_0, 500000);
  createTask(Monitor, "Monitor", 2048, 10);
  CommandLoop();
}
