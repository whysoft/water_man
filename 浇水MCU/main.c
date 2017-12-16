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




void Timer0Init(void)		//1毫秒@24.000MHz
{
	AUXR |= 0x80;		//定时器时钟1T模式
	TMOD &= 0xF0;		//设置定时器模式
	TL0 = 0x40;		//设置定时初值
	TH0 = 0xA2;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
}




void UartInit(void)		//57600bps@24.000MHz
{
	PCON &= 0x7F;		//波特率不倍速
	SCON = 0x50;		//8位数据,可变波特率
	AUXR |= 0x40;		//定时器1时钟为Fosc,即1T
	AUXR &= 0xFE;		//串口1选择定时器1为波特率发生器
	TMOD &= 0x0F;		//清除定时器1模式位
	TMOD |= 0x20;		//设定定时器1为8位自动重装方式
	TL1 = 0xF3;		//设定定时初值
	TH1 = 0xF3;		//设定定时器重装值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//启动定时器1
}



void Uart2AInit(void)		//115200bps@24.000MHz
{
	S2CON = 0x50;		//8位数据,可变波特率
	AUXR |= 0x04;		//定时器2时钟为Fosc,即1T
	T2L = 0xCC;		//设定定时初值
	T2H = 0xFF;		//设定定时初值
	AUXR |= 0x10;		//启动定时器2
}




		  

/*------------------------------------------------
串口中断程序
------------------------------------------------*/
void UART_SER() interrupt 4 //串行中断服务程序
{
	if(RI)      //判断是接收中断产生
	{
		//RI=0;     //标志位清零

		//ta1comrecv( &ta1comrecv_state );
	}

	if(TI)    //如果是发送标志位，清零
	{
		TI=0;
		Com1_TI_flag = 1; //这样等于发送没做，另找一个flag
	}
}
		



#define S2RI  0x01              //S2CON.0
#define S2TI  0x02              //S2CON.1

/*----------------------------
UART2 中断服务程序
-----------------------------*/
void Uart2() interrupt 8  
{
    if (S2CON & S2RI)      //判断是接收中断产生
    {
        S2CON &= ~S2RI;         //清除S2RI位
	
		//ta32com2( &ta32com2_state );
    }

    if (S2CON & S2TI)    //如果是发送标志位，清零
    {
        S2CON &= ~S2TI;         //清除S2TI位 
		Com2_TI_flag = 1; //这样等于发送没做，另找一个flag
    }
		
}




//
//主函数 入口函数:
void main()
{
	g_p_ctrl_timer = (unsigned int*)g_ctrl_timer;
	*g_p_ctrl_timer = 65535L - 59999;
	
	//初始化
	EA=0;		// 总中断
 
	Timer0Init();
	g_ctrl_timer[0] = TH0;
	g_ctrl_timer[1] = TL0;
	//TH0 = g_ctrl_timer[0];
	//TL0 = g_ctrl_timer[1];
	ET0=1;		//开启定时器0中断
	TR0=1;		//启动定时器0

	UartInit();
    ES    = 1;        // 1=打开串口中断 

	Uart2AInit();
	//P_SW2 &= ~S2_S0;     //S2_S0=0 (P1.0/RxD2, P1.1/TxD2)
	IE2 = 0x01;			 //使能串口2中断
	
	////切换优先级
	//PT0 = 0;
	//PS = 1;
	//IP2 |= 1;

	EA  = 1;          //打开总中断 


	LET_BEEP_OFF;
	LET_LIGHT1_OFF;

	DelayS(1);

	//用户初始化 

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
		//接收5字节命令 
		Com1Recv(); if( Com1Recv_rc == 1 ) buf1[0] = Com1Recv_c; else goto L_VeryBegin;
		Com1Recv(); if( Com1Recv_rc == 1 ) buf1[1] = Com1Recv_c; else goto L_VeryBegin;
		Com1Recv(); if( Com1Recv_rc == 1 ) buf1[2] = Com1Recv_c; else goto L_VeryBegin;
		Com1Recv(); if( Com1Recv_rc == 1 ) buf1[3] = Com1Recv_c; else goto L_VeryBegin;
		Com1Recv(); if( Com1Recv_rc == 1 ) buf1[4] = Com1Recv_c; else goto L_VeryBegin;

		//认领 c0 <freq_high> <freq_low> <delay_high> <delay_low>
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


		//认领 c1 00 00 00 00
		if( buf1[0] == 0xc1 )
		{
			LET_LIGHT1_ON;
			Com1SendU8ss( "OK\r\n" );

			goto L_VeryBegin;
		}


		//认领 c2 00 00 00 00
		if( buf1[0] == 0xc2 )
		{
			LET_LIGHT1_OFF;
			Com1SendU8ss( "OK\r\n" );

			goto L_VeryBegin;
		}

		//认领 c3 00 00 00 00
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


