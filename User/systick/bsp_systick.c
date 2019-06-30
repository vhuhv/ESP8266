#include "bsp_systick.h"


static __IO u32 TimingDelay;

void SysTick_Init(void)
{
			/* SystemFrequency / 1000    1ms�ж�һ��
			 * SystemFrequency / 100000	 10us�ж�һ��
			 * SystemFrequency / 1000000 1us�ж�һ��
			 */
			if(SysTick_Config(SystemCoreClock/1000000))
			{
					while(1);
			}
			//�رյδ�ʱ��
			SysTick->CTRL &=~SysTick_CTRL_ENABLE_Msk;
}

//  1us��ʱ����
void Delay_us(__IO u32 nTime)
{
			TimingDelay=nTime;
			//ʹ�ܵδ�ʱ��
			SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
			while(TimingDelay != 0);
}

//��ȡus�δ��жϣ�ÿ1us�ж�һ��
void TimingDelay_Decrement(void)
{
			if(TimingDelay != 0x00)
			{
					TimingDelay--;
			}
}