
#ifndef __H_STRFUNC_H_H
#define __H_STRFUNC_H_H
 
// 2017-01-12


//typedef unsigned char  U8;       /* defined for unsigned 8-bits integer variable 	  �޷���8λ���ͱ���  */
//typedef signed   char  S8;       /* defined for signed 8-bits integer variable		  �з���8λ���ͱ���  */
//typedef unsigned int   U16;      /* defined for unsigned 16-bits integer variable 	  �޷���16λ���ͱ��� */
//typedef signed   int   S16;      /* defined for signed 16-bits integer variable 	  �з���16λ���ͱ��� */
//typedef unsigned long  U32;      /* defined for unsigned 32-bits integer variable 	  �޷���32λ���ͱ��� */
//typedef signed   long  S32;      /* defined for signed 32-bits integer variable 	  �з���32λ���ͱ��� */
//typedef float          F32;      /* single precision floating point variable (32bits) �����ȸ�������32λ���ȣ� */
//typedef double         F64;      /* double precision floating point variable (64bits) ˫���ȸ�������64λ���ȣ� */



typedef unsigned char  U8;       /* defined for unsigned 8-bits integer variable 	  �޷���8λ���ͱ���  */
typedef signed   char  I8;       /* defined for signed 8-bits integer variable		  �з���8λ���ͱ���  */
typedef unsigned int   U16;      /* defined for unsigned 16-bits integer variable 	  �޷���16λ���ͱ��� */
typedef signed   int   I16;      /* defined for signed 16-bits integer variable 	  �з���16λ���ͱ��� */
typedef unsigned long  U32;      /* defined for unsigned 32-bits integer variable 	  �޷���32λ���ͱ��� */
typedef signed   long  I32;      /* defined for signed 32-bits integer variable 	  �з���32λ���ͱ��� */ 



typedef		char					tint8;
typedef		unsigned char			tuint8;
typedef		int						tint16;
typedef		unsigned int			tuint16;
typedef		long					tint32;
typedef		unsigned long			tuint32;



extern void myltoa( unsigned char * szOut, unsigned long i, unsigned char NumNum );


void sharedata_interrupt_ready( U8 *tWork, U8 *t0, U8 *t1, int len );
void sharedata_main_followrefresh( U8 *t0, U8 *t1, U8 *t2, int len );


U16 buf_del_head( U8 *p, U16 qlen, U16 headlen );


void		  bs_9_A( unsigned char c, unsigned char *p_dest );
unsigned char bs_A_9( unsigned char *p_src );
unsigned int bs_decode( unsigned char *p_src_dest );



U8 *pick_strarr2( U8 idx, U8 *s0, U8 *s1 );



extern GetLED( unsigned char s );



extern void mk_busycode( unsigned char src, unsigned char *pDest );	//��ʼ��=���32	������=33	
extern unsigned char chk_busycode( unsigned char *p );




//extern signed char mycompare( unsigned char *a1, unsigned char *a2 ) reentrant;

//typedef signed char (*pf_compare_t)( unsigned char *a1, unsigned char *a2 ) reentrant;
//extern void a_sortf( unsigned char *x, int datablocknum, int datablocklen, pf_compare_t pf_comp );
//




extern void mk_chksumU8( unsigned char * sz1, unsigned int iLen );
extern unsigned char chk_chksumU8( unsigned char * sz1, unsigned int iLen );


extern void mk_chk2sumU8( unsigned char * sz1, unsigned int iLen );
extern unsigned char chk_chk2sumU8( unsigned char * sz1, unsigned int iLen );


extern void mk_chk3sumU8( unsigned char * sz1, unsigned int iLen );
extern unsigned char chk_chk3sumU8( unsigned char * sz1, unsigned int iLen );


extern void mk_chk4sumU8( unsigned char * sz1, unsigned int iBufLen, unsigned char iChkLen );
extern unsigned char chk_chk4sumU8( unsigned char * sz1, unsigned int iBufLen, unsigned char iChkLen );


extern void mk_chk5sumU8( unsigned char * sz1, unsigned int iBufLen, unsigned char iChkLen );
extern unsigned char chk_chk5sumU8( unsigned char * sz1, unsigned int iBufLen, unsigned char iChkLen );




#endif












