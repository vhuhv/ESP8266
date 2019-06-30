#ifndef __BSP_DHT11_H
#define __BSP_DHT11_H

#include "stm32f10x.h"
#include "bsp_systick.h"

typedef struct
{
			uint8_t	humi_int;//湿度整数部分
			uint8_t humi_deci;//湿度小数部分
			uint8_t temp_int;//温度整数部分
			uint8_t temp_deci;//温度小数部分
			uint8_t check_sum;//校验和
}DHT11_Data_TypeDef;


#define   DHT11_GPIO_CLK				RCC_APB2Periph_GPIOC
#define   DHT11_GPIO_PORT				GPIOC
#define   DHT11_GPIO_PIN				GPIO_Pin_13

#define   DHT11_OUT_0						GPIO_ResetBits(DHT11_GPIO_PORT,DHT11_GPIO_PIN)	
#define 	DHT11_OUT_1						GPIO_SetBits(DHT11_GPIO_PORT,DHT11_GPIO_PIN)

#define   DHT11_IN()							GPIO_ReadInputDataBit(DHT11_GPIO_PORT,DHT11_GPIO_PIN)

void			DHT11_Init(void);
uint8_t 	DHT11_Read_TempAndhumi(DHT11_Data_TypeDef *DHT11_Data);

#endif


