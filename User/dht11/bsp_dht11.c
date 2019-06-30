#include "bsp_dht11.h"

//��̬��������
static void DHT11_Config(void);
static void DHT11_Mode_IPU(void);
static void DHT11_Mode_Out_PP(void);
static uint8_t DHT11_ReadByte(void);

//DHT11��ʼ������
void DHT11_Init(void)
{
			DHT11_Config();
			DHT11_OUT_1;
}
//DHT11������ʼ����
static void DHT11_Config(void)
{
			GPIO_InitTypeDef     GPIO_InitStructure;
	
			RCC_APB2PeriphClockCmd(DHT11_GPIO_CLK,ENABLE);
	
			GPIO_InitStructure.GPIO_Pin=DHT11_GPIO_PIN;
			GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
			GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
			GPIO_Init(DHT11_GPIO_PORT,&GPIO_InitStructure);		
}



//GPIO����Ϊ��������ģʽ
static void DHT11_Mode_IPU(void)
{
			GPIO_InitTypeDef     GPIO_InitStructure;
	
			RCC_APB2PeriphClockCmd(DHT11_GPIO_CLK,ENABLE);
	
			GPIO_InitStructure.GPIO_Pin=DHT11_GPIO_PIN;
			GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	
			GPIO_Init(DHT11_GPIO_PORT,&GPIO_InitStructure);	
}
//GPIO����Ϊ�������ģʽ
static void DHT11_Mode_Out_PP(void)
{
			GPIO_InitTypeDef     GPIO_InitStructure;
	
			RCC_APB2PeriphClockCmd(DHT11_GPIO_CLK,ENABLE);
	
			GPIO_InitStructure.GPIO_Pin=DHT11_GPIO_PIN;
			GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
			GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
			GPIO_Init(DHT11_GPIO_PORT,&GPIO_InitStructure);		
			
}
//DHT11�ֽڶ�ȡ����
static uint8_t DHT11_ReadByte(void)
{
			uint8_t i,temp=0;
			for(i=0;i<8;i++)
			{
						while(DHT11_IN()==0);
						Delay_us(40);
						if(DHT11_IN()==1)
						{
								while(DHT11_IN()==1);
								temp |=(uint8_t)(0x01<<(7-i));
						}
						else
						{
								temp &=(uint8_t)~(0x01<<(7-i));
						}	
			}
			return  temp;
}

//DHT11������ȡ����
uint8_t	DHT11_Read_TempAndhumi(DHT11_Data_TypeDef *DHT11_Data)
{
			DHT11_Mode_Out_PP();
			DHT11_OUT_0;
			Delay_ms(18);
			
			DHT11_OUT_1;
			Delay_us(30);
			
			DHT11_Mode_IPU();
			
			if(DHT11_IN()==0)
			{
						while(DHT11_IN()==0);
						while(DHT11_IN()==1);
						DHT11_Data->humi_int=DHT11_ReadByte();
						DHT11_Data->humi_deci=DHT11_ReadByte();
						DHT11_Data->temp_int=DHT11_ReadByte();
						DHT11_Data->temp_deci=DHT11_ReadByte();
						DHT11_Data->check_sum=DHT11_ReadByte();
						DHT11_Mode_Out_PP();
						DHT11_OUT_1;
						if(DHT11_Data->check_sum==DHT11_Data->humi_int+DHT11_Data->humi_deci+DHT11_Data->temp_int+DHT11_Data->temp_deci)
						{
										return 1;
						}
						else
						{
										return 0;
						}
			}	
			else
					return  0;
}