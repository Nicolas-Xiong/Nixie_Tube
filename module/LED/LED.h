#ifndef __LED_H
#define __LED_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ���������ɣ��������������κ���;
//ALIENTEKս��STM32������
//LED��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/2
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) �������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 

#define  LED1  PAout(8)
#define  LED2  PAout(9)
#define  LED3  PAout(10)
#define  LED4  PAout(11)

#define no_dot 0
#define dot  1

void LED_Init(void);//��ʼ��
void yima(int a,int i);//����
void clear(void);//���
void display(float m);//��ʾ
void show_time(float m);//ʱ����ʾ

		 				    
#endif


