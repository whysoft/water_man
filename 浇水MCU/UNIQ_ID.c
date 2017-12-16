//#include "reg51.h"
#include "intrins.h"
#include "UNIQ_ID.h"

 
//2016-12-10


typedef unsigned char BYTE;
typedef unsigned int WORD;


#define ID_ADDR_RAM 0xf1   //ID�ŵĴ����RAM���ĵ�ַΪ0F1H

//ID�ŵĴ���ڳ������ĵ�ַΪ����ռ�����7�ֽ�
//#define ID_ADDR_ROM 0x03f9 //1K����ռ��MCU(��STC15F201EA, STC15F101EA)
//#define ID_ADDR_ROM 0x07f9 //2K����ռ��MCU(��STC15F402EACS, STC15F202EA, STC15F102EA)
//#define ID_ADDR_ROM 0x0bf9 //3K����ռ��MCU(��STC15F203EA, STC15F103EA)
//#define ID_ADDR_ROM 0x0ff9 //4K����ռ��MCU(��STC15F804EACS, STC15F404EACS, STC15F204EA, STC15F104EA)
//#define ID_ADDR_ROM 0x13f9 //5K����ռ��MCU(��STC15F205EA, STC15F105EA)
#define ID_ADDR_ROM 0x1ff9 //8K����ռ��MCU(��STC15F2K08S2,  STC15F808EACS, STC15F408EACS)
//#define ID_ADDR_ROM 0x27f9 //10K����ռ��MCU(��    STC15F410EACS)
//#define ID_ADDR_ROM 0x2ff9 //12K����ռ��MCU(��    STC15F812EACS, STC15F412EACS)
//#define ID_ADDR_ROM 0x3ff9 //16K����ռ��MCU(��STC15F2K16S2, STC15F816EACS)
//#define ID_ADDR_ROM 0x4ff9 //20K����ռ��MCU(��STC15F2K20S2, STC15F820EACS)
//#define ID_ADDR_ROM 0x5ff9 //24K����ռ��MCU(��    STC15F824EACS)
//#define ID_ADDR_ROM 0x6ff9 //28K����ռ��MCU(��    STC15F828EACS)
//#define ID_ADDR_ROM 0x7ff9 //32K����ռ��MCU(��STC15F2K32S2)
//#define ID_ADDR_ROM 0x9ff9 //40K����ռ��MCU(��STC15F2K40S2)
//#define ID_ADDR_ROM 0xbff9 //48K����ռ��MCU(��STC15F2K48S2)
//#define ID_ADDR_ROM 0xcff9 //52K����ռ��MCU(��STC15F2K52S2)
//#define ID_ADDR_ROM 0xdff9 //56K����ռ��MCU(��STC15F2K56S2)
//#define ID_ADDR_ROM 0xeff9 //60K����ռ��MCU(��STC15F2K60S2)




#if 0 
void get_uniq_id_rom( unsigned char *pBuf )
{
    BYTE code *cptr;
    BYTE i;

    cptr = ID_ADDR_ROM;         //�ӳ�������ȡID��
    for (i=0; i<7; i++)         //��7���ֽ�
    {
		*pBuf = (*cptr++);
		pBuf++;
    }
}
#endif



#if 0 
void get_uniq_id_ram( unsigned char *pBuf )
{
    BYTE idata *iptr;
    BYTE i;

	iptr = ID_ADDR_RAM;         //��RAM����ȡID��
	for (i=0; i<7; i++)         //��7���ֽ�
	{
		*pBuf = (*iptr++);
		pBuf++;
	}
}
#endif




#if 0 
void get_uniq_id( unsigned char *pBuf, unsigned char itype )
{
    BYTE idata *iptr;
    BYTE code *cptr;
    BYTE i;

	if( itype == 0 )
	{
		iptr = ID_ADDR_RAM;         //��RAM����ȡID��
		for (i=0; i<7; i++)         //��7���ֽ�
		{
			//SendUart(*iptr++);      //����ID������

			*pBuf = (*iptr++);
			pBuf++;
		}

		return;
	}
    
    cptr = ID_ADDR_ROM;         //�ӳ�������ȡID��
    for (i=0; i<7; i++)         //��7���ֽ�
    {
        //SendUart(*cptr++);      //����ID������
		
		*pBuf = (*cptr++);
		pBuf++;
    }
}
#endif








#if 0

//	p_bit: 7.6.5.4.3.2.1.0������λ	
//		power_type: 0=��ͳ51�� 1=���죬 2=��©	
void set_px_power( unsigned char p_x, unsigned char p_bit, unsigned char power_type )
{
	unsigned char c;
	unsigned char c1;

	if( p_x == 5 && power_type == 0 )
	{
		//P5M1 = 0; P5M0 = 0;
		c = 0xff;
		c1 =((unsigned char)1);
		c1 <<= p_bit;
		c ^= c1;
		P5M0 &= c; // ���趨M0���Ա����ʱ��������	
		P5M1 &= c;
	}
	if( p_x == 5 && power_type == 1 )
	{
		//P5M1 = 0; P5M0 = 1;
		c = 0x00;
		c1 =((unsigned char)1);
		c1 <<= p_bit;
		c ^= c1;
		P5M0 |= c;

		c = 0xff;
		c1 =((unsigned char)1);
		c1 <<= p_bit;
		c ^= c1;
		P5M1 &= c;
	}
	if( p_x == 5 && power_type == 2 )
	{
		//P5M1 = 1; P5M0 = 1;
		c = 0x00;
		c1 =((unsigned char)1);
		c1 <<= p_bit;
		c ^= c1;
		P5M1 |= c; // ���趨M1���Ա����ʱ��������	

		c = 0x00;
		c1 =((unsigned char)1);
		c1 <<= p_bit;
		c ^= c1;
		P5M0 |= c;
	}


	if( p_x == 4 && power_type == 0 )
	{
		//P4M1 = 0; P4M0 = 0;
		c = 0xff;
		c1 =((unsigned char)1);
		c1 <<= p_bit;
		c ^= c1;
		P4M0 &= c; // ���趨M0���Ա����ʱ��������	
		P4M1 &= c;
	}
	if( p_x == 4 && power_type == 1 )
	{
		//P4M1 = 0; P4M0 = 1;
		c = 0x00;
		c1 =((unsigned char)1);
		c1 <<= p_bit;
		c ^= c1;
		P4M0 |= c;

		c = 0xff;
		c1 =((unsigned char)1);
		c1 <<= p_bit;
		c ^= c1;
		P4M1 &= c;
	}
	if( p_x == 4 && power_type == 2 )
	{
		//P4M1 = 1; P4M0 = 1;
		c = 0x00;
		c1 =((unsigned char)1);
		c1 <<= p_bit;
		c ^= c1;
		P4M1 |= c; // ���趨M1���Ա����ʱ��������	

		c = 0x00;
		c1 =((unsigned char)1);
		c1 <<= p_bit;
		c ^= c1;
		P4M0 |= c;
	}


	if( p_x == 3 && power_type == 0 )
	{
		//P3M1 = 0; P3M0 = 0;
		c = 0xff;
		c1 =((unsigned char)1);
		c1 <<= p_bit;
		c ^= c1;
		P3M0 &= c; // ���趨M0���Ա����ʱ��������	
		P3M1 &= c;
	}
	if( p_x == 3 && power_type == 1 )
	{
		//P3M1 = 0; P3M0 = 1;
		c = 0x00;
		c1 =((unsigned char)1);
		c1 <<= p_bit;
		c ^= c1;
		P3M0 |= c;

		c = 0xff;
		c1 =((unsigned char)1);
		c1 <<= p_bit;
		c ^= c1;
		P3M1 &= c;
	}
	if( p_x == 3 && power_type == 2 )
	{
		//P3M1 = 1; P3M0 = 1;
		c = 0x00;
		c1 =((unsigned char)1);
		c1 <<= p_bit;
		c ^= c1;
		P3M1 |= c; // ���趨M1���Ա����ʱ��������	

		c = 0x00;
		c1 =((unsigned char)1);
		c1 <<= p_bit;
		c ^= c1;
		P3M0 |= c;
	}


	if( p_x == 2 && power_type == 0 )
	{
		//P2M1 = 0; P2M0 = 0;
		c = 0xff;
		c1 =((unsigned char)1);
		c1 <<= p_bit;
		c ^= c1;
		P2M0 &= c; // ���趨M0���Ա����ʱ��������	
		P2M1 &= c;
	}
	if( p_x == 2 && power_type == 1 )
	{
		//P2M1 = 0; P2M0 = 1;
		c = 0x00;
		c1 =((unsigned char)1);
		c1 <<= p_bit;
		c ^= c1;
		P2M0 |= c;

		c = 0xff;
		c1 =((unsigned char)1);
		c1 <<= p_bit;
		c ^= c1;
		P2M1 &= c;
	}
	if( p_x == 2 && power_type == 2 )
	{
		//P2M1 = 1; P2M0 = 1;
		c = 0x00;
		c1 =((unsigned char)1);
		c1 <<= p_bit;
		c ^= c1;
		P2M1 |= c; // ���趨M1���Ա����ʱ��������	

		c = 0x00;
		c1 =((unsigned char)1);
		c1 <<= p_bit;
		c ^= c1;
		P2M0 |= c;
	}


	if( p_x == 1 && power_type == 0 )
	{
		//P1M1 = 0; P1M0 = 0;
		c = 0xff;
		c1 =((unsigned char)1);
		c1 <<= p_bit;
		c ^= c1;
		P1M0 &= c; // ���趨M0���Ա����ʱ��������	
		P1M1 &= c;
	}
	if( p_x == 1 && power_type == 1 )
	{
		//P1M1 = 0; P1M0 = 1;
		c = 0x00;
		c1 =((unsigned char)1);
		c1 <<= p_bit;
		c ^= c1;
		P1M0 |= c;

		c = 0xff;
		c1 =((unsigned char)1);
		c1 <<= p_bit;
		c ^= c1;
		P1M1 &= c;
	}
	if( p_x == 1 && power_type == 2 )
	{
		//P1M1 = 1; P1M0 = 1;
		c = 0x00;
		c1 =((unsigned char)1);
		c1 <<= p_bit;
		c ^= c1;
		P1M1 |= c; // ���趨M1���Ա����ʱ��������	

		c = 0x00;
		c1 =((unsigned char)1);
		c1 <<= p_bit;
		c ^= c1;
		P1M0 |= c;
	}


	if( p_x == 0 && power_type == 0 )
	{
		//P0M1 = 0; P0M0 = 0;
		c = 0xff;
		c1 =((unsigned char)1);
		c1 <<= p_bit;
		c ^= c1;
		P0M0 &= c; // ���趨M0���Ա����ʱ��������	
		P0M1 &= c;
	}
	if( p_x == 0 && power_type == 1 )
	{
		//P0M1 = 0; P0M0 = 1;
		c = 0x00;
		c1 =((unsigned char)1);
		c1 <<= p_bit;
		c ^= c1;
		P0M0 |= c;

		c = 0xff;
		c1 =((unsigned char)1);
		c1 <<= p_bit;
		c ^= c1;
		P0M1 &= c;
	}
	if( p_x == 0 && power_type == 2 )
	{
		//P0M1 = 1; P0M0 = 1;
		c = 0x00;
		c1 =((unsigned char)1);
		c1 <<= p_bit;
		c ^= c1;
		P0M1 |= c; // ���趨M1���Ա����ʱ��������	

		c = 0x00;
		c1 =((unsigned char)1);
		c1 <<= p_bit;
		c ^= c1;
		P0M0 |= c;
	}
}

#endif






#if 0 
void set_mcu_power_down(void)
{
    MCU_POWER_DOWN;	  //�Ƭ�����ڵ���ģʽ������STC15,��4�� _nop_(); �����һ���ʱ����ҪMCU_CLEAR_POF
	_nop_();                //����ģʽ�����Ѻ�,����ִ�д����,Ȼ���ٽ����жϷ������
	_nop_();
	_nop_();
	_nop_();
}
#endif



#if 0 
void set_mcu_power_idle( void )
{
	MCU_IDLE;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
}
#endif



#if 0 
void set_mcu_power_clear_pof( void )
{
	MCU_CLEAR_POF;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
}
#endif





