#include "stm32f10x.h"  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "Key.h"
#include "IN1In2.h"

int main(void)
{
	OLED_Init();
	OLED_ShowString(1,1,"Speed: ");
	Pwm_Init();
	In_Init();
	Key_Init();
//	LED_Init();
//	LED2_OFF();

	
	while(1)
	{
			if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_4)==0)
				OLED_ShowChar(1,7,' ');
			else
				OLED_ShowChar(1,7,'-');
			OLED_ShowNum(1,8,Key_get(),3);
			Key_Move1();
	}
}
