/*******************/
//#include <reg52.h>
#include "STDIO.H"
#include "STDLIB.H"
#include "INTRINS.H"
#include "STRING.H"
#include "Delay_12M.h"
#include "UNIQ_ID.h"
#include "a_strfunc.h"
#include "a_comfunc.h"
#include "a_timerfunc.h"
//#include "lcd_12864.h"
//#include "PCF8591_IIC.h"
#include "mainioport.h"
//#include "EEPROM.h"
#include "stc12_adc.h"
//#include "a_ll1func.h"


unsigned char idata g_ctrl_timer[2];
unsigned int idata * idata g_p_ctrl_timer;

#define    IAP_ADDRE   0x0000

#define    FIRMWAREVER   "V1.01"

#define S2_S0 0x01              //P_SW2.0




#include "main1.xpp"
//#include "main2.xpp"
//




void Timer0Init(void)		//1����@24.000MHz
{
	AUXR |= 0x80;		//��ʱ��ʱ��1Tģʽ
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TL0 = 0x40;		//���ö�ʱ��ֵ
	TH0 = 0xA2;		//���ö�ʱ��ֵ
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
}




void UartInit(void)		//57600bps@24.000MHz
{
	PCON &= 0x7F;		//�����ʲ�����
	SCON = 0x50;		//8λ����,�ɱ䲨����
	AUXR |= 0x40;		//��ʱ��1ʱ��ΪFosc,��1T
	AUXR &= 0xFE;		//����1ѡ��ʱ��1Ϊ�����ʷ�����
	TMOD &= 0x0F;		//�����ʱ��1ģʽλ
	TMOD |= 0x20;		//�趨��ʱ��1Ϊ8λ�Զ���װ��ʽ
	TL1 = 0xF3;		//�趨��ʱ��ֵ
	TH1 = 0xF3;		//�趨��ʱ����װֵ
	ET1 = 0;		//��ֹ��ʱ��1�ж�
	TR1 = 1;		//������ʱ��1
}



void Uart2AInit(void)		//115200bps@24.000MHz
{
	S2CON = 0x50;		//8λ����,�ɱ䲨����
	AUXR |= 0x04;		//��ʱ��2ʱ��ΪFosc,��1T
	T2L = 0xCC;		//�趨��ʱ��ֵ
	T2H = 0xFF;		//�趨��ʱ��ֵ
	AUXR |= 0x10;		//������ʱ��2
}




		  

/*------------------------------------------------
�����жϳ���
------------------------------------------------*/
void UART_SER() interrupt 4 //�����жϷ������
{
	if(RI)      //�ж��ǽ����жϲ���
	{
		//RI=0;     //��־λ����

		//ta1comrecv( &ta1comrecv_state );
	}

	if(TI)    //����Ƿ��ͱ�־λ������
	{
		TI=0;
		Com1_TI_flag = 1; //�������ڷ���û��������һ��flag
	}
}
		



#define S2RI  0x01              //S2CON.0
#define S2TI  0x02              //S2CON.1

/*----------------------------
UART2 �жϷ������
-----------------------------*/
void Uart2() interrupt 8  
{
    if (S2CON & S2RI)      //�ж��ǽ����жϲ���
    {
        S2CON &= ~S2RI;         //���S2RIλ
	
		//ta32com2( &ta32com2_state );
    }

    if (S2CON & S2TI)    //����Ƿ��ͱ�־λ������
    {
        S2CON &= ~S2TI;         //���S2TIλ 
		Com2_TI_flag = 1; //�������ڷ���û��������һ��flag
    }
		
}




//
//������ ��ں���:
void main()
{
	g_p_ctrl_timer = (unsigned int*)g_ctrl_timer;
	*g_p_ctrl_timer = 65535L - 59999;
	
	//��ʼ��
	EA=0;		// ���ж�
 
	Timer0Init();
	g_ctrl_timer[0] = TH0;
	g_ctrl_timer[1] = TL0;
	//TH0 = g_ctrl_timer[0];
	//TL0 = g_ctrl_timer[1];
	ET0=1;		//������ʱ��0�ж�
	TR0=1;		//������ʱ��0

	UartInit();
    ES    = 1;        // 1=�򿪴����ж� 

	Uart2AInit();
	//P_SW2 &= ~S2_S0;     //S2_S0=0 (P1.0/RxD2, P1.1/TxD2)
	IE2 = 0x01;			 //ʹ�ܴ���2�ж�
	
	////�л����ȼ�
	//PT0 = 0;
	//PS = 1;
	//IP2 |= 1;

	EA  = 1;          //�����ж� 


	LET_BEEP_OFF;
	LET_LIGHT1_OFF;

	DelayS(1);

	//�û���ʼ�� 

	//load_M1_EEdata( &M1 );
	//load_M6_default( &M6do );
	tm_init( &music_tm ); 

	mainioport_init();
	InitADC( 0x40 ); // 0100-0000	
	
	LET_LIGHT1_OFF;
	LET_LED4_OFF;


	DelayMs(666);
		

L_VeryBegin:;

	while(EA)
	{
		//����5�ֽ����� 
		Com1Recv(); if( Com1Recv_rc == 1 ) buf1[0] = Com1Recv_c; else goto L_VeryBegin;
		Com1Recv(); if( Com1Recv_rc == 1 ) buf1[1] = Com1Recv_c; else goto L_VeryBegin;
		Com1Recv(); if( Com1Recv_rc == 1 ) buf1[2] = Com1Recv_c; else goto L_VeryBegin;
		Com1Recv(); if( Com1Recv_rc == 1 ) buf1[3] = Com1Recv_c; else goto L_VeryBegin;
		Com1Recv(); if( Com1Recv_rc == 1 ) buf1[4] = Com1Recv_c; else goto L_VeryBegin;

		//���� c0 <freq_high> <freq_low> <delay_high> <delay_low>
		if( buf1[0] == 0xc0 )
		{
			u1 = buf1[1];
			u1 <<= 8;
			u1 += buf1[2];

			u2 = buf1[3];
			u2 <<= 8;
			u2 += buf1[4];

			tm_rst( &music_tm , u2 ); 

			while(1)
			{
				for( u3 = 0; u3 < u1; u3++ )
				{
				}
				LET_BEEP_NOT;
				if( music_tm.overflow_flag ) break;
			}

			Com1SendU8ss( "OK\r\n" );

			tm_mainfollow( &music_tm ); 

			LET_BEEP_OFF;

			goto L_VeryBegin;
		}


		//���� c1 00 00 00 00
		if( buf1[0] == 0xc1 )
		{
			LET_LIGHT1_ON;
			Com1SendU8ss( "OK\r\n" );

			goto L_VeryBegin;
		}


		//���� c2 00 00 00 00
		if( buf1[0] == 0xc2 )
		{
			LET_LIGHT1_OFF;
			Com1SendU8ss( "OK\r\n" );

			goto L_VeryBegin;
		}

		//���� c3 00 00 00 00
		if( buf1[0] == 0xc3 )
		{
			val = GetADCResult( 6 );
			u2 = WETBOOL;
			
			sprintf( buf1, "%u,%u\r\n", val, u2 );
			Com1SendU8ss( buf1 );

			goto L_VeryBegin;
		}
	}




	//while(!EA)
	{
		DelayMs(2);
		LET_BEEP_NOT;
	}

	LET_BEEP_OFF;
	LET_LIGHT1_OFF;


 

	while(1)
	{

//BEGIN_L:

		LET_LIGHT1_OFF;
		
		DelayS(1);

		
		LET_LIGHT1_ON;

		DelayS(1);
		 
	}
		 
}	


	
//
void timer() interrupt 1  
{
	//TH0 = g_ctrl_timer[0];
	//TL0 = g_ctrl_timer[1];

	tm_tk( &music_tm );
}


