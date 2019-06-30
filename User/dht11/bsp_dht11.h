#ifndef __BSP_DHT11_H
#define __BSP_DHT11_H

#include "stm32f10x.h"
#include "bsp_systick.h"

typedef struct
{
			uint8_t	humi_int;//ʪ����������
			uint8_t humi_deci;//ʪ��С������
			uint8_t temp_int;//�¶���������
			uint8_t temp_deci;//�¶�С������
			uint8_t check_sum;//У���
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


