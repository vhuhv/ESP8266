#include "stm32f10x.h"
#include "bsp_systick.h"
#include "bsp_dht11.h"
#include "bsp_usart.h"


int main(void)
{
			DHT11_Data_TypeDef	DHT11_Data;
			SysTick_Init();
			USART_Config();
			printf("温湿度实验测试");
			DHT11_Init();
			while (1)
			{
						if(DHT11_Read_TempAndhumi(&DHT11_Data)==1)
							printf("\r\n读取DHT11成功!\r\n\r\n湿度为%d.%d ％RH ，温度为 %d.%d℃ \r\n",\
											DHT11_Data.humi_int,DHT11_Data.humi_deci,DHT11_Data.temp_int,DHT11_Data.temp_deci);
						else
							printf("read dht11 error \r\n");
						Delay_ms(1000);
			}	
}



