#include "LED.h"


int codetab[10]=    {0xD7,0x14,0xCD,0x5D,0x1E,0x5B,0xDB,0x15,0xDF,0x5F};    //不带点编码
int codetab_dot[10]={0xF7,0x34,0xED,0x7D,0x3E,0x7B,0xFB,0x35,0xFF,0x7F};    //带点编码

int STA=1;   //记录灯的片选


 
//初始化PB5和PE5为输出口.并使能这两个口的时钟		    
//LED IO初始化
void LED_Init(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//使能PB,PE端口时钟
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;				 //LED0-->PA.ALL 端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);					 //根据设定参数初始化GPIOA.ALL
 GPIO_SetBits(GPIOA,GPIO_Pin_All);						 //PB.5 输出高


}
 
//译码
void yima(int a,int i)
{
	 if(i>=0&&i<10)
	 {
	 if (a==no_dot)
	 {
	 GPIO_SetBits(GPIOA,0xFF);
	 GPIO_ResetBits(GPIOA,codetab[i]);
	 }
	 else
	 {
	 GPIO_SetBits(GPIOA,0xFF);
	 GPIO_ResetBits(GPIOA,codetab_dot[i]);
	 }
	 }
}

//清空显示
void clear()
{
		 GPIO_SetBits(GPIOA,0xFF);
}

//显示数字,最多四位
void display(float m)
{
     int a=0,b=0,c=0,d=0;
	   int a_dot=0,b_dot=0,c_dot=0,d_dot=0;
	   int intger=0;
	    
	   intger=(int)m;
	
 //分解数字*******************************************************	
	   if(intger/1000!=0)      
		 {
			 d=intger%10;
			 c=(intger-d)/10%10;
			 b=(intger-c*10-d)/100%10;
			 a=(intger-b*100-c*10-d)/1000%10;
		 }
		 else if(intger/100!=0)
		 {
			 c_dot=dot;
			 c=intger%10;
			 b=(intger-c)/10%10;
			 a=intger/100;
			 d=(int)((m-intger)*10);
		 }
		 else if(intger/10!=0)
		 {
			 b_dot=dot;
			 b=intger%10;
			 a=intger/10;
			 c=(int)((m-intger)*10);
			 d=((int)((m-intger)*100))%10;
		 }
		 else
		 {
			 a_dot=dot;
			 a=intger;
			 b=(int)((m-intger)*10);
			 c=((int)((m-intger)*100))%10;
			 d=((int)((m-intger)*1000))%10;
		 }

		 
//显示数字***************************************************************	 
	   if (STA==1)    
		 {  clear();  LED1=1; LED2=0; LED3=0; LED4=0;	     yima(a_dot,a); }
		 if (STA==2)     
		 {  clear();  LED1=0; LED2=1; LED3=0; LED4=0;      yima(b_dot,b); }
  	 if (STA==3)     
		 {  clear();  LED1=0; LED2=0; LED3=1; LED4=0;      yima(c_dot,c); }     
		 if (STA==4)     
		 {  clear();  LED1=0; LED2=0; LED3=0; LED4=1;      yima(d_dot,d); }   

//调试代码*****************************************************************
//		 if (STA==1)    
//		 {  clear();  LED1=1; LED2=0; LED3=0; LED4=0;	     yima(no_dot,5); }
//		 if (STA==2)     
//		 {  clear();  LED1=0; LED2=1; LED3=0; LED4=0;      yima(no_dot,1); }
//  	 if (STA==3)     
//		 {  clear();  LED1=0; LED2=0; LED3=1; LED4=0;      yima(no_dot,2); }     
//		 if (STA==4)     
//		 {  clear();  LED1=0; LED2=0; LED3=0; LED4=1;      yima(no_dot,2); }  
}


//时间显示函数
void show_time(float m)
{
	   int HOUR=0,MINUTE=0,SECOND=0;
	   int a=0,b=0,c=0,d=0;
	   int a_dot=0,b_dot=0,c_dot=0,d_dot=0;
	   long int intger=0;
	   
     if (m >=86400.0)	
	      m=0;
	
	   intger=(long int)m;
	
 //分解数字*******************************************************	
	   if(intger/3600!=0)      
		 {
			 SECOND=intger%60;
			 MINUTE=(intger-SECOND)/60%60;
			 HOUR=(intger-MINUTE*60-SECOND)/3600;
			 if(HOUR<=9)
			 {
			  a=HOUR;
				a_dot=dot;
				c=MINUTE%10;
				b=MINUTE/10;
				c_dot=dot;
				d=SECOND/10;
			 }
			 else
			 {
				 b=HOUR%10;
				 a=HOUR/10;
				 b_dot=dot;
				 d=MINUTE%10;
				 c=MINUTE/10;
			 }
		 }
		 else if(intger/60!=0)
		 {
			 SECOND=intger%60;
			 MINUTE=intger/60;
			 if(MINUTE<=9)
			 {
			 a=MINUTE;
			 a_dot=dot;
			 c=SECOND%10;
			 b=SECOND/10;
			 c_dot=dot;
			 d=(int)((m-intger)*10);
			 }
			 else 
			 {
			  b=MINUTE%10;
				a=MINUTE/10;
				b_dot=dot;
				d=SECOND%10;
        c=SECOND/10;				 
			 }
		 }
		 else
		 {
			 SECOND=intger;
			 if(SECOND<=9)
			 {
			 a=SECOND;
			 a_dot=dot;
			 b=(int)((m-intger)*10);
			 c=((int)((m-intger)*100))%10;
			 d=((int)((m-intger)*1000))%10;
			 }
			 else 
			 {
			  b=SECOND%10;
				a=SECOND/10;
				b_dot=dot;
		    c=(int)((m-intger)*10);
			  d=((int)((m-intger)*100))%10;				 
			 }
		 }

		 
//显示数字***************************************************************	 
	   if (STA==1)    
		 {  clear();  LED1=1; LED2=0; LED3=0; LED4=0;	     yima(a_dot,a); }
		 if (STA==2)     
		 {  clear();  LED1=0; LED2=1; LED3=0; LED4=0;      yima(b_dot,b); }
  	 if (STA==3)     
		 {  clear();  LED1=0; LED2=0; LED3=1; LED4=0;      yima(c_dot,c); }     
		 if (STA==4)     
		 {  clear();  LED1=0; LED2=0; LED3=0; LED4=1;      yima(d_dot,d); }   

}



