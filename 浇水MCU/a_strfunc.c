
 //	2017-01-12

//#include "reg52.h"
#include "STDIO.H"
#include "STDLIB.H"
#include "INTRINS.H"
#include "STRING.H"
#include "a_strfunc.h"




/*------------------------------------------------
���ֱ��ִ������ֻ�ܴ���9����Ч��
����
NumNum 0x72 �������ָ���7�����㲹ǰ0��С��������2
����ֵ=4��    ����0x03�����0.004
����ֵ=12345������0x01, ���1234.5
------------------------------------------------*/
#if 0
void myltoa( unsigned char * szOut, unsigned long i, unsigned char NumNum )  
{
	unsigned char c = 0;
	unsigned char flag = 0;
	unsigned char wei;
	unsigned long a10 = 1;

	if( i == 0 )
		*(szOut++) = '0';
	
	for( wei = 9 ; wei > 0; wei -- )
	{
		a10 = 1;
		for( c = 0; c < wei-1; c++ ) a10 *= 10;
		c = (i/a10) % 10;

		if( wei == ( NumNum & 0x0F ) )
		{
			if( flag == 0 )  *(szOut++) = '0';
			flag = 1;
			*(szOut++) = '.';
		}

		if( flag || c == 0 && ( NumNum >> 4 ) >= wei || c !=0 ) 
		{
			flag = 1;
			*(szOut++) = c + '0';
		}
	}

	*szOut = 0;
}
#endif







/*------------------------------------------------
����䴫������
// [0] ��.m_is_busy 
// [1]��.m_is_hot 
------------------------------------------------*/
#if 0

void sharedata_interrupt_ready( U8 *tWork, U8 *t0, U8 *t1, int len )
{
	tWork[0] = 0;	// [0] ��.m_is_busy = 0;
	tWork[1] = 1;   // [1] ��.m_is_hot = 1;

	if( !(t0[0]) ) memcpy( t0, tWork, len ) ;
	if( !(t1[0]) ) memcpy( t1, tWork, len ) ;
}

void sharedata_main_followrefresh( U8 *t0, U8 *t1, U8 *t2, int len ) 
{
	t0[0] = 1;	
	if( t0[1] ) memcpy( t2, t0, len ) ;
	t0[1] = 0;	
	t0[0] = 0;	
	 
	t1[0] = 1;	
	if( t1[1] ) memcpy( t2, t1, len ) ;
	t1[1] = 0;	
	t1[0] = 0;		 
}

#endif






/*------------------------------------------------
����ͷ��ɾ��һ���֡�����
------------------------------------------------*/
#if 0
U16 buf_del_head( U8 *p, U16 qlen, U16 headlen )
{
	U16 iread = headlen;
	U16 iwrite = 0;
	
	for( ; iread < qlen; iread++ )
	{
		p[iwrite] = p[iread];
		iwrite++;
	}
	return iwrite;
}
#endif





/*------------------------------------------------
���� 0xaa , �������2�ֽ� "AA"
------------------------------------------------*/
#if 0
void bs_9_A( unsigned char c, unsigned char *p_dest ) 
{
	unsigned char i;

	i = c;
	i >>= 4;
	if( i >= 0 && i <= 9 ) p_dest[0] = '0' + i; else p_dest[0] = 'A' + ( i - 10 );
		
	i = c & 0x0F;
	if( i >= 0 && i <= 9 ) p_dest[1] = '0' + i; else p_dest[1] = 'A' + ( i - 10 );
}
#endif




/*------------------------------------------------
���� "AA" , һ�δ���2�ֽڣ��������1�ֽ� 0xAA
------------------------------------------------*/
#if 0
unsigned char bs_A_9( unsigned char *p_src )
{
	unsigned char _tempbuf[2];

	_tempbuf[0] = p_src[0];
	if( _tempbuf[0] >= '0' && _tempbuf[0] <= '9' ) _tempbuf[0] -= '0'; else _tempbuf[0] -= 'A' - 10;
		
	_tempbuf[1] = p_src[1];
	if( _tempbuf[1] >= '0' && _tempbuf[1] <= '9' ) _tempbuf[1] -= '0'; else _tempbuf[1] -= 'A' - 10;

	return _tempbuf[0] * 16 + _tempbuf[1];
}
#endif



/*------------------------------------------------
���� iterator-end-idx���൱��len
------------------------------------------------*/
#if 0
unsigned int bs_decode( unsigned char *p_src_dest )
{
	unsigned int i_write = 0;
	unsigned int i_read;
	 
	for( i_read = 0; p_src_dest[i_read]; i_read++ )
	{
		if( p_src_dest[i_read] == '%' )
		{
			i_read++;

			p_src_dest[i_write] = bs_A_9( p_src_dest+i_read );	// using bs_A_9

			i_read++;
			i_write++;
		}
		else
		{
			if( i_write != i_read) 
				p_src_dest[i_write] = p_src_dest[i_read];
			i_write++;
		}
	}
	
	p_src_dest[i_write] = 0;

	return i_write;
}
#endif





#if 0
U8 *pick_strarr2( U8 idx, U8 *s0, U8 *s1 )
{
	if( idx == 0 ) return s0;
	return s1;
}
#endif





/*------------------------------------------------
  7������ܣ���ģ 
------------------------------------------------*/

#if 0

    static unsigned code LEDtable[] =
	//���� 
	// 0     1      2     3     4     5     6    7      8     9     10   11     12    13    14   15     16    17    18    19   20    21     22    23
	//"0    "1"     2"    3"   4"     5   "6"    "7    "8    9      A    B      C     D     E    F      H     L     n     u     P     o"   "-"  Ϩ��
	{ 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, 0x76, 0x38, 0x37, 0x3E, 0x73, 0x5C, 0x40, 0x00 };
	//���� 
	//..0.....1....2......3.....4.....5.....6......7....8.....9.....A ....b.....C.....d..... E ....F... - ....��...............
	//{ 0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0x88, 0x83, 0xc6, 0xa1, 0x86, 0x8e, 0xbf, 0xff };	
    static unsigned code LEDtable1[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'H', 'L', 'N', 'U', 'P', 'O', '-', \0 };
    static unsigned code LEDtable2[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'h', 'l', 'n', 'u', 'p', 'o', '-', \0 };

unsigned char GetLED( unsigned char s )
{
	unsigned char c1;
	unsigned char j;

	if( s <= 9 )
	{
		//ֱ���������� 
		c1 = LEDtable[s];
	}
	else
	{
		for( j = 0; LEDtable1[j]; j++ )
		{
			if( s == LEDtable1[j] || s == LEDtable2[j] ) break;
		}
		c1 = LEDtable[j];
	}
	
	//return c1;	//���� 
	return ~c1;	 //����
}

#endif


 




#if 0
void mk_busycode( unsigned char src, unsigned char *pDest )
{
	unsigned char mask;
	unsigned char i;

	//pDest[0] = 0xff;
	//pDest[1] = 0xff; ��������ֵ����	

	mask = 0x80;
	for( i = 0; i < 8; i++ )
	{
		if( src & mask ) // 1 -> 01
		{
			pDest[i/4] <<= 1;
			pDest[i/4] &= 0xfe;

			pDest[i/4] <<= 1;
			pDest[i/4] |= 1;
		}
		else
		{
			pDest[i/4] <<= 1;
			pDest[i/4] |= 1;

			pDest[i/4] <<= 1;
			pDest[i/4] &= 0xfe;
		}
		mask >>= 1;
	}
}
#endif




#if 0
unsigned char chk_busycode( unsigned char *p )
{
	unsigned char i;
	unsigned char c;

	//c = 0xff; ��������ֵ����	

	for( i = 0; i < 8; i++ )
	{
		if( p[i/4] & 0x80 )
		{
			c <<= 1;
			c &= 0xfe;
		}
		else
		{
			c <<= 1;
			c |= 1;
		}
		 
		p[i/4] <<= 1;
		p[i/4] <<= 1;
	}
	return c;
}
#endif






#if 0

//signed char mycompare( unsigned char *a1, unsigned char *a2, int datablocklen )
//{
//	if( *a1 > *a2 ) return 1;
//	if( *a1 == *a2 ) return 0;
//	/*if( *a1 < *a2 )*/ return -1;
//}
//signed char mycompare( unsigned char *a1, unsigned char *a2, int datablocklen )
//{
//	if( *(int*)a1 > *(int*)a2 ) return 1;
//	if( *(int*)a1 == *(int*)a2 ) return 0;
//	/*if( *a1 < *a2 )*/ return -1;
//}
signed char mycompare( unsigned char *a1, unsigned char *a2 ) reentrant
{
	if( *(unsigned long*)a1 > *(unsigned long*)a2 ) return 1;
	if( *(unsigned long*)a1 == *(unsigned long*)a2 ) return 0;
	/*if( *a1 < *a2 )*/ return -1;
}

#endif



#if 0
void a_sortf( unsigned char *x, int datablocknum, int datablocklen, pf_compare_t pf_comp )
{
	int a,b,c;

	for( a = 0; a < datablocknum - 1; a ++ ) 
	{
		for( b = a + 1; b < datablocknum; b++ )   
		{
			//if( (*pf_comp)( x+a*datablocklen, x+b*datablocklen, datablocklen ) > 0 )       
			if( (*pf_comp)( x+a*datablocklen, x+b*datablocklen ) > 0 )       
			{
				for( c = 0; c < datablocklen; c++ )
				{
					*(x+a*datablocklen + c) ^=	*(x+b*datablocklen + c);
					*(x+b*datablocklen + c) ^=	*(x+a*datablocklen + c);
					*(x+a*datablocklen + c) ^=	*(x+b*datablocklen + c);
				}
			} 
		}
	}
}
#endif

//�÷���
//void test_sort()
//{
//	int x[4]={ 5990, 9991, 772, 7723 };
//
//	a_sortf( (unsigned char*)x, 4, 4, mycompare );

//////a_sortf( (unsigned char*)(&()), 4, 4, mycompare );
//
//	for( int i = 0; i < 4; i++ )
//	{
//		printf( "%d %d\n", i, x[i] );
//	}
//}



// ֱ��ʵ�֣�
//void a_sortf( unsigned char *x, int datablocknum, int datablocklen )
//{
//	int a,b,c;
//	unsigned char *a1;
//	unsigned char *a2;
//
//	for( a = 0; a < datablocknum - 1; a ++ ) 
//	{
//		for( b = a + 1; b < datablocknum; b++ )   
//		{
//			a1 = x+a*datablocklen;
//			a2 = x+b*datablocklen;
//			if( *(unsigned long*)a1 > *(unsigned long*)a2 )       
//			{
//				for( c = 0; c < datablocklen; c++ )
//				{
//					*(x+a*datablocklen + c) ^=	*(x+b*datablocklen + c);
//					*(x+b*datablocklen + c) ^=	*(x+a*datablocklen + c);
//					*(x+a*datablocklen + c) ^=	*(x+b*datablocklen + c);
//				}
//			} 
//		}
//	}
//}








/*------------------------------------------------
 һ��У�� 
------------------------------------------------*/
 	
/////////==============�汾1	��ͳ����

#if 0
void mk_chksumU8( unsigned char * sz1, unsigned int iLen )// �Ի��������һ���ֽ�дУ������	
{
	unsigned char c1 = 0;
	unsigned int j;
	
	//��� ��c1
	for( j = 0 ; j < iLen - 1; j ++ )
		c1 += sz1[j];  

	sz1[iLen-1] = c1;
}
#endif


#if 0
unsigned char chk_chksumU8( unsigned char * sz1, unsigned int iLen ) //��黺�������һ�ֽ��Ƿ�ԡ�	
{
	unsigned char c1 = 0;
	unsigned int j;
	
	//��� ��c1
	for( j = 0 ; j < iLen - 1; j ++ )
		c1 += sz1[j];  

	if( sz1[iLen-1] == c1 ) 
		return 1;
	else
		return 0;
}
#endif





//////////=======�汾2	��λ����Ϣ
//2016-08-12�����c1 ^= ( sz1[j] + (unsigned char)j );  ò�Ʋ�����,�����ֵ̫����	

#if 0
void mk_chk2sumU8( unsigned char * sz1, unsigned int iLen )
{
	unsigned char c1 = 0;
	unsigned int j;
	
	//��� ��c1
	for( j = 0 ; j < iLen - 1; j ++ )
		c1 += ( sz1[j] ^ (unsigned char)j );  

	if( c1 == 0 || c1 == 255 ) c1 = 1;

	sz1[iLen-1] = c1;
}
#endif



#if 0
unsigned char chk_chk2sumU8( unsigned char * sz1, unsigned int iLen )
{
	unsigned char c1 = 0;
	unsigned int j;
	
	//��� ��c1
	for( j = 0 ; j < iLen - 1; j ++ )
		c1 += ( sz1[j] ^ (unsigned char)j );  

	if( c1 == 0 || c1 == 255 ) c1 = 1;

	if( sz1[iLen-1] == c1 ) 
		return 1;
	else
		return 0;
}
#endif






//////////=======�汾3	���ϳ���

#if 0
void mk_chk3sumU8( unsigned char * sz1, unsigned int iLen )// �Ի��������һ���ֽ�дУ������	
{
	unsigned char c1 = 0;
	unsigned int j;
	
	//��� ��c1
	for( j = 0 ; j < iLen - 1; j ++ )
		c1 += sz1[j];  

	sz1[iLen-1] = c1 + iLen;
}
#endif


#if 0
unsigned char chk_chk3sumU8( unsigned char * sz1, unsigned int iLen ) //��黺�������һ�ֽ��Ƿ�ԡ�	
{
	unsigned char c1 = 0;
	unsigned int j;
	
	//��� ��c1
	for( j = 0 ; j < iLen - 1; j ++ )
		c1 += sz1[j];  

	if( sz1[iLen-1] == ( c1+iLen ) ) 
		return 1;
	else
		return 0;
}
#endif






//////
//////=======�汾4	���ֽ�У����

#if 0
	void mk_chk2sumU8_internal_for_chk4( unsigned char * sz1, unsigned int iLen )
	{
		unsigned char c1 = 0;
		unsigned int j;
		
		//��� ��c1
		for( j = 0 ; j < iLen - 1; j ++ )
			c1 += ( sz1[j] ^ (unsigned char)j );  

		if( c1 == 0 || c1 == 255 ) c1 = 1;

		sz1[iLen-1] = c1;
	}


void mk_chk4sumU8( unsigned char * sz1, unsigned int iBufLen, unsigned char iChkLen )
{
	unsigned char chklen;
	
	for( chklen = 1; chklen <= iChkLen; chklen++ )
	{
		mk_chk2sumU8_internal_for_chk4( sz1, iBufLen - iChkLen + chklen );
	}
}
#endif



#if 0
	unsigned char chk_chk2sumU8_internal_for_chk4( unsigned char * sz1, unsigned int iLen )
	{
		unsigned char c1 = 0;
		unsigned int j;
		
		//��� ��c1
		for( j = 0 ; j < iLen - 1; j ++ )
			c1 += ( sz1[j] ^ (unsigned char)j );  

		if( c1 == 0 || c1 == 255 ) c1 = 1;

		if( sz1[iLen-1] == c1 ) 
			return 1;
		else
			return 0;
	}

unsigned char chk_chk4sumU8( unsigned char * sz1, unsigned int iBufLen, unsigned char iChkLen )
{
	unsigned char chklen;
	
	for( chklen = 1; chklen <= iChkLen; chklen++ )
	{
		if( !chk_chk2sumU8_internal_for_chk4( sz1, iBufLen - iChkLen + chklen ) ) return 0;
	}
	 
	return 1;
}
#endif






//////============
//////=======�汾5	���ֽڣ��Ҽ��ݴ�ͳ�ӷ�BCC
//////

#if 0
	void mk_chksumU8_internal_for_ck5( unsigned char * sz1, unsigned int iLen ) 
	{
		unsigned char c1 = 0;
		unsigned int j;
		
		//��� ��c1
		for( j = 0 ; j < iLen - 1; j ++ )
			c1 += sz1[j];  

		sz1[iLen-1] = c1;
	}


void mk_chk5sumU8( unsigned char * sz1, unsigned int iBufLen, unsigned char iChkLen )
{
	unsigned char chklen;
	
	for( chklen = 1; chklen <= iChkLen; chklen++ )
	{
		mk_chksumU8_internal_for_ck5( sz1, iBufLen - iChkLen + chklen );
	}
}
#endif




#if 0
	unsigned char chk_chksumU8_internal_for_ck5( unsigned char * sz1, unsigned int iLen )  
	{
		unsigned char c1 = 0;
		unsigned int j;
		
		//��� ��c1
		for( j = 0 ; j < iLen - 1; j ++ )
			c1 += sz1[j];  

		if( sz1[iLen-1] == c1 ) 
			return 1;
		else
			return 0;
	}


unsigned char chk_chk5sumU8( unsigned char * sz1, unsigned int iBufLen, unsigned char iChkLen )
{
	unsigned char chklen;
	
	for( chklen = 1; chklen <= iChkLen; chklen++ )
	{
		if( !chk_chksumU8_internal_for_ck5( sz1, iBufLen - iChkLen + chklen ) ) return 0;
	}
	 
	return 1;
}
#endif








