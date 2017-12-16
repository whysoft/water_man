
 //	2017-02-10

//#include "reg52.h"
#include "string.h"
#include "a_strfunc.h"
#include "a_timerfunc.h"


//����stc89c52Ϊ0xe7��stc125a60s2Ϊ0xc7; 

sfr IAP_CONTR=0xc7;



#if 1



// e.g.
//struct	TM_t	tm_grind1;
//struct	TM_t	tm_pause1;
//struct	TM_t	tm_dim;
//struct	TM_t	tm_total;




/* ֧�ֵ����ȼ��ǣ���timer����tk�� ��main��rst
	����main����tk��rst	*/



//0=��timer����tk�� ��main��rst
//1=��main����tk��rst
#define TM_PRIORITY_MODE  0



//0=tkƵ����rst��Ƶ��
//1=tk������rstƵ��
#define TM_OFTEN_MODE  0





//
void tm_init( struct TM_t *t )
{
	//t->rst_cmd = 0;
	//t->rst_value = 0;
	//t->inter_counter = 0;
	//t->overflow_flag = 0;
	//t->pause_cmd = 0;
	//t->ex_is_busy0 = 0;
	//t->ex_is_busy1 = 0;
	//t->ex_is_hot0 = 0;
	//t->ex_is_hot1 = 0;
	//t->ex_counter0 = 0;
	//t->ex_counter1 = 0;
	//t->ex_counter2 = 0;


	memset( t, 0, sizeof(struct TM_t) );		
}



//ÿ��tk����һ�μ�1
void tm_tk( struct TM_t *t )
{
	if( t->rst_cmd ) 
	{
		t->inter_counter = t->rst_value;

		t->overflow_flag = 0;
 

#if TM_PRIORITY_MODE == 0  
		t->rst_cmd = 0;
#else 
 
	//���tkƵ����tk��Ӧ��--�����rstƵ����tk��Ӧ��ֱ����0
	#if TM_OFTEN_MODE == 0
			t->rst_cmd --;
	#else 
			t->rst_cmd = 0;
	#endif
   
#endif

	}


	do{

		if( t->inter_counter == 0 )
		{
			t->overflow_flag = 1;
			break;
		}

		if( t->pause_cmd ) break;

		t->inter_counter --;
	
		if( t->inter_counter == 0 )
		{
			t->overflow_flag = 1;
			break;
		}

	}while(0);

	if( !t->ex_is_busy0 )
	{
		t->ex_counter0 = t->inter_counter;
		t->ex_is_hot0 = 1;
	}

	if( !t->ex_is_busy1 )
	{
		t->ex_counter1 = t->inter_counter;
		t->ex_is_hot1 = 1;
	}
}




#if 0
//ÿ�δ������ܾ���n��tk��Ҫ��n
void tm_tk_n( struct TM_t *t, unsigned char t1, unsigned char t2 )
{
	for( ; t1 != t2 ; t1++ )
		tm_tk( t );
}
#endif



//
void tm_mainfollow( struct TM_t *t )
{
	t->ex_is_busy0 = 1;
	if( t->ex_is_hot0 )
	{
		t->ex_counter2 = t->ex_counter0;
	}
	t->ex_is_hot0 = 0;
	t->ex_is_busy0 = 0;

	t->ex_is_busy1 = 1;
	if( t->ex_is_hot1 )
	{
		t->ex_counter2 = t->ex_counter1;
	}
	t->ex_is_hot1 = 0;
	t->ex_is_busy1 = 0;
}






//Ƶ��rst������������ ����Ӱ�쵽��ʼֵ��	
//���tkƵ����tk��Ӧ��--�����rstƵ����tk��Ӧ��ֱ����0
void tm_rst( struct TM_t *t, U32 rst_value ) 
{
	//rst_cmd�������һ��busy flag�������ⲿ�ж�busy_flag������ʱ�����Ѿ���busy_flag��������ȫ����busy_flag��ǡ�

#if TM_PRIORITY_MODE == 0  
	if( t->rst_cmd ) return;
#else              
	if( t->rst_cmd > 200 ) return;
#endif

	t->rst_value = rst_value;//����value����cmd��ɷ�ͬ������

	t->overflow_flag = 0;


#if TM_PRIORITY_MODE == 0  
		t->rst_cmd = 1;
#else              
		if( t->rst_cmd < 200 ) t->rst_cmd ++;
#endif
}


#endif






#if 0

void tm_rst1( struct TM_t *t, U32 rst_value )
{
#if TM_PRIORITY_MODE == 0  
	if( t->rst_cmd ) return;
#else              
	if( t->rst_cmd > 200 ) return;
#endif

	t->rst_value = rst_value;//����value����cmd��ɷ�ͬ������
	t->overflow_flag = 0;

#if TM_PRIORITY_MODE == 0  
		t->rst_cmd = 1;
#else              
		if( t->rst_cmd < 200 ) t->rst_cmd ++;
#endif
}

#endif





#if 0

void tm_rst2( struct TM_t *t, U32 rst_value )
{
#if TM_PRIORITY_MODE == 0  
	if( t->rst_cmd ) return;
#else              
	if( t->rst_cmd > 200 ) return;
#endif

	t->rst_value = rst_value;//����value����cmd��ɷ�ͬ������
	t->overflow_flag = 0;

#if TM_PRIORITY_MODE == 0  
		t->rst_cmd = 1;
#else              
		if( t->rst_cmd < 200 ) t->rst_cmd ++;
#endif
}

#endif











//============= tk ���ͣ�ͳһ�Ǽ��ƶ�	

#if 0


struct TMRTKALL_t
{
	struct TM_t		*m_ptm;		
};


static struct TMRTKALL_t  tmrtkall_ws[4];
static	U8				  tmrtkall_end = 0; //�൱��stl�е�end������ЧԪ��			



void tmtkall_reg( struct TM_t *t ) 		//�ǼǺͳ�ʼ��
{
	if( tmrtkall_end >= 4 )
	{
		IAP_CONTR |= 1<<5; 

		IAP_CONTR = 0x60; /////////////////��������������鳤��һ��////
	}

	tmrtkall_ws[tmrtkall_end].m_ptm = t;

	tm_init( t ); //�ȳ�ʼ�����������Ĵ��ڣ�����tk �����⡣
	//tm_rst( t, 0 );

	tmrtkall_end++; // ���������Ĵ���	
}


void tmtkall_tk()
{
	U8 i;
	for( i = 0; i < tmrtkall_end; i++ )
	{
		tm_tk( tmrtkall_ws[i].m_ptm );
	}
}


void tmtkall_mainfollow()
{
	U8 i;
	for( i = 0; i < tmrtkall_end; i++ )
	{
		tm_mainfollow( tmrtkall_ws[i].m_ptm );
	}
}




#endif



