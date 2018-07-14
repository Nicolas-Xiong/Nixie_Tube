#include "usart.h"
#include "sys.h"
#include "LED.h"


#define TIMER  (timer*0.01+TIM2->CNT/100000.)

int timer=0;


//适用于STM32C8T6*****************************************
//有显示数字及计时功能************************************




//四个LED的接法 *******************************************
//     正向
//12 11 10 9  8  7 
//o  o  o  o  o  o
//o  o  o  o  o  o
//1  2  3  4  5  6


//数字对应片选*********************************************
//     正向   
// 12  9   8   6


//数字对应位置 ********************************************
// ----
//| 11 |
//|10  |7
// ----
//|  5 |
//|1   |4
// ---- .
//   2   3



//无点时的编码 ********************************************
//  1 2 3 4 5 7 1011 0x20
//0 o o   o   o o o  0xD7
//1       o   o      0x14
//2 o o     o o   o  0xCD
//3   o   o o o   o  0x5D
//4       o o o o    0x1E
//5   o   o o   o o  0x5B
//6 o o   o o   o o  0xDB
//7       o   o   o  0x15
//8 o o   o o o o o  0xDF
//9   o   o o o o o  0x5F


//有点时的编码**********************************************
//  1 2 3 4 5 7 1011 0x20
//0 o o o o   o o o  0xF7
//1     o o   o      0x34
//2 o o o   o o   o  0xED
//3   o o o o o   o  0x7D
//4     o o o o o    0x3E
//5   o o o o   o o  0x7B
//6 o o o o o   o o  0xFB
//7     o o   o   o  0x35
//8 o o o o o o o o  0xFF
//9   o o o o o o o  0x7F



//PA0---PA7  点灯
//PA8---PA11 片选


int main(void)
{
	int i=0;
	delay_init();
	uart_init(115200);
	LED_Init();
	TIM3_Int_Init(999,71);   //0.1MHz的计数频率，计数到1000为10ms 
	TIM2_Int_Init(999,719);	//用于计时1S  100次
	while(1)
 	{
//正常时间进制的时间
		show_time(TIMER);
		
		

//以秒为单位的时钟
 //     display(TIMER);
		
		
		

//调试用代码***********************************************************			
//		 for(i=0;i<10;i++)
//		 {
//		   yima(no_dot,i);
//		   LED1=1;  		 LED2=0;  		 LED3=0;     		 LED4=0;
//			 delay_ms(1000); 
//		 }
	}
}


