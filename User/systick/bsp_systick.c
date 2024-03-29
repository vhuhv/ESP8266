#include "bsp_systick.h"


static __IO u32 TimingDelay;

void SysTick_Init(void)
{
			/* SystemFrequency / 1000    1ms中断一次
			 * SystemFrequency / 100000	 10us中断一次
			 * SystemFrequency / 1000000 1us中断一次
			 */
			if(SysTick_Config(SystemCoreClock/1000000))
			{
					while(1);
			}
			//关闭滴答定时器
			SysTick->CTRL &=~SysTick_CTRL_ENABLE_Msk;
}

//  1us延时函数
void Delay_us(__IO u32 nTime)
{
			TimingDelay=nTime;
			//使能滴答定时器
			SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
			while(TimingDelay != 0);
}

//获取us滴答中断，每1us中断一次
void TimingDelay_Decrement(void)
{
			if(TimingDelay != 0x00)
			{
					TimingDelay--;
			}
}