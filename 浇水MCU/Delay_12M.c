
 //20161126.201824	

#include "reg52.h"
#include "Delay_12M.h"
#include  <INTRINS.H> //Keil library  


/*------------------------------------------------
 ����24M��1T��Ƭ��
------------------------------------------------*/
#if 1
void DelayUs2x(unsigned char t)
{   
	unsigned int i;
	i =t * 1;
	do{
		for( t = 0; t < 5; t++ );
		i--;
	}while(i);
}
#endif


/*------------------------------------------------
 ����12M��1T��Ƭ��
------------------------------------------------*/
#if 0
void DelayUs2x(unsigned char t)
{   
	unsigned int i;
	i =t * 2;
	do{
		//_nop_();	 
		//t++;		t--;
		i--;
	}while(i);
}
#endif


/*------------------------------------------------
 ����12M��12T��Ƭ��   ������ʱ�������� T=tx2+5 uS 
------------------------------------------------*/
#if 0
void DelayUs2x(unsigned char t)
{   
	 while(--t);
}
#endif


/*------------------------------------------------
 ����33M��1T��Ƭ��
------------------------------------------------*/
#if 0
void DelayUs2x(unsigned char t)
{
	unsigned int i = 5 * t;

	while(--i);
}
#endif




//==========================================================



/*------------------------------------------------
 mS��ʱ����������������� unsigned char t���޷���ֵ
 unsigned char �Ƕ����޷����ַ���������ֵ�ķ�Χ��
 0~255 ����ʹ�þ���12M����ȷ��ʱ��ʹ�û��
------------------------------------------------*/
void DelayMs_small(unsigned char t)
{
 while(t--)
 {
     //������ʱ1mS
     DelayUs2x(245);
	 DelayUs2x(245);
 }
}


void DelayMs(unsigned int t)
{
	char i,j;

	i = t / 251;
	j = t % 251;

	while(i--)
	{
		DelayMs_small(251);
	}

	DelayMs_small(j);
}



//���ã�����ʱ���� 
#if 1
void DelayS(unsigned char t)
{
 while(t--)
 {
	DelayMs(250);
	DelayMs(250);
	DelayMs(250);
	DelayMs(250);
 }
}
#endif


