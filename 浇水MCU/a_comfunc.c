
// 2016-10-02	

#include "a_strfunc.h"
#include "UNIQ_ID.h"

#include "a_comfunc.h"

 

//=====================================COM1	

#if 1
unsigned char Com1_TI_flag = 1;
#endif



#if 1
void Com1SendU8( unsigned char c )
{
	while(!Com1_TI_flag); Com1_TI_flag = 0; 
	SBUF = c;
}
#endif



#if 1
void Com1SendU8ss( unsigned char * s )
{
	for(;;)
	{
		if( *s == 0 ) break;
		Com1SendU8( *s ); 
		s++;
	}
}
#endif



#if 0
void Com1SendU8is( unsigned long i, unsigned char * buf )
{
	myltoa( buf, i, 0x00 );
	Com1SendU8ss( buf );
}
#endif

//
//void send_struct( unsigned char * buf, unsigned char iBufLen )
//{
//	U8 i; 
//	
//	for( i = 0; i < iBufLen; i++ )
//	{
//		Com1SendU8( buf[i] );
//	}
//}
		//	//send_struct( M2do.m_buf[0], 18 );
		//	//send_struct( M2do.m_buf[1], 18 );





// Com1 ���� 
#if 1

U8  Com1Recv_rc;
U8  Com1Recv_c;

U16	Com1Recv_TimeOutLmt = 32345;

static U16 Com1Recv_TimeOutCounter;


void Com1Recv()
{
	Com1Recv_TimeOutCounter = 0;
	while(1)
	{
		if(RI) 
		{ 
			RI=0; 
			Com1Recv_c = SBUF;
			Com1Recv_rc = 1;
			return;
		} 
		else 
		{ 
			Com1Recv_TimeOutCounter++; 
			if( Com1Recv_TimeOutCounter > Com1Recv_TimeOutLmt ) 
			{ 
				Com1Recv_rc = 0;
				return;
			} 
		} 
	}
}
#endif







//=====================================COM2	


#if 1
unsigned char Com2_TI_flag = 1;
#endif



#if 0
void Com2SendU8( unsigned char c )
{
	while(!Com2_TI_flag); Com2_TI_flag = 0; 
	S2BUF = c;
}
#endif



#if 0
void Com2SendU8ss( unsigned char * s )
{
	for(;;)
	{
		if( *s == 0 ) break;
		Com2SendU8( *s ); 
		s++;
	}
}
#endif



#if 0
void Com2SendU8is( unsigned long i, unsigned char * buf )
{
	myltoa( buf, i, 0x00 );
	Com2SendU8ss( buf );
}
#endif








//===============================�������ӣ�
#if 0 

/*------------------------------------------------
�����жϳ���
------------------------------------------------*/
void UART_SER() interrupt 4 //�����жϷ������
{
	if(RI)      //�ж��ǽ����жϲ���
	{
		RI=0;     //��־λ����

		ta63com1( &ta63com1_state );
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
        //P0 = S2BUF;             //P0��ʾ��������
        //P2 = (S2CON & S2RB8);   //P2.2��ʾУ��λ

    }

    if (S2CON & S2TI)    //����Ƿ��ͱ�־λ������
    {
        S2CON &= ~S2TI;         //���S2TIλ 
		Com2_TI_flag = 1; //�������ڷ���û��������һ��flag
    }
		
}






/*------------------------------------------------
�����жϳ���
------------------------------------------------*/
void UART_SER() interrupt 4 //�����жϷ������
{
	if(RI)      //�ж��ǽ����жϲ���
	{
		RI=0;     //��־λ����
		
		ta33com1( &ta33com1_state );
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
	
		ta32com2( &ta32com2_state );
    }

    if (S2CON & S2TI)    //����Ƿ��ͱ�־λ������
    {
        S2CON &= ~S2TI;         //���S2TIλ 
		Com2_TI_flag = 1; //�������ڷ���û��������һ��flag
    }
		
}



#endif






