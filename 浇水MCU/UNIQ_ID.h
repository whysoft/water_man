#ifndef ___UNIQ_ID_H
#define ___UNIQ_ID_H


//2016-12-10
 
 
#ifndef __STC15F2K_H__
#define __STC15F2K_H__
//包含本头文件后,不用另外再包含"REG51.H"
//内核特殊功能寄存器        // 复位值   描述
sfr ACC         =   0xE0;   //0000,0000 累加器Accumulator
sfr B           =   0xF0;   //0000,0000 B寄存器
sfr PSW         =   0xD0;   //0000,0000 程序状态字
sbit CY         =   PSW^7;
sbit AC         =   PSW^6;
sbit F0         =   PSW^5;
sbit RS1        =   PSW^4;
sbit RS0        =   PSW^3;
sbit OV         =   PSW^2;
sbit P          =   PSW^0;
sfr SP          =   0x81;   //0000,0111 堆栈指针
sfr DPL         =   0x82;   //0000,0000 数据指针低字节
sfr DPH         =   0x83;   //0000,0000 数据指针高字节
//I/O 口特殊功能寄存器
sfr P0          =   0x80;   //1111,1111 端口0
sbit P00        =   P0^0;
sbit P01        =   P0^1;
sbit P02        =   P0^2;
sbit P03        =   P0^3;
sbit P04        =   P0^4;
sbit P05        =   P0^5;
sbit P06        =   P0^6;
sbit P07        =   P0^7;
sfr P1          =   0x90;   //1111,1111 端口1
sbit P10        =   P1^0;
sbit P11        =   P1^1;
sbit P12        =   P1^2;
sbit P13        =   P1^3;
sbit P14        =   P1^4;
sbit P15        =   P1^5;
sbit P16        =   P1^6;
sbit P17        =   P1^7;
sfr P2          =   0xA0;   //1111,1111 端口2
sbit P20        =   P2^0;
sbit P21        =   P2^1;
sbit P22        =   P2^2;
sbit P23        =   P2^3;
sbit P24        =   P2^4;
sbit P25        =   P2^5;
sbit P26        =   P2^6;
sbit P27        =   P2^7;
sfr P3          =   0xB0;   //1111,1111 端口3
sbit P30        =   P3^0;
sbit P31        =   P3^1;
sbit P32        =   P3^2;
sbit P33        =   P3^3;
sbit P34        =   P3^4;
sbit P35        =   P3^5;
sbit P36        =   P3^6;
sbit P37        =   P3^7;
sfr P4          =   0xC0;   //1111,1111 端口4
sbit P40        =   P4^0;
sbit P41        =   P4^1;
sbit P42        =   P4^2;
sbit P43        =   P4^3;
sbit P44        =   P4^4;
sbit P45        =   P4^5;
sbit P46        =   P4^6;
sbit P47        =   P4^7;
sfr P5          =   0xC8;   //xxxx,1111 端口5
sbit P50        =   P5^0;
sbit P51        =   P5^1;
sbit P52        =   P5^2;
sbit P53        =   P5^3;
sbit P54        =   P5^4;
sbit P55        =   P5^5;
sbit P56        =   P5^6;
sbit P57        =   P5^7;
sfr P6          =   0xE8;   //0000,0000 端口6
sbit P60        =   P6^0;
sbit P61        =   P6^1;
sbit P62        =   P6^2;
sbit P63        =   P6^3;
sbit P64        =   P6^4;
sbit P65        =   P6^5;
sbit P66        =   P6^6;
sbit P67        =   P6^7;
sfr P7          =   0xF8;   //0000,0000 端口7
sbit P70        =   P7^0;
sbit P71        =   P7^1;
sbit P72        =   P7^2;
sbit P73        =   P7^3;
sbit P74        =   P7^4;
sbit P75        =   P7^5;
sbit P76        =   P7^6;
sbit P77        =   P7^7;
sfr P0M0        =   0x94;   //0000,0000 端口0模式寄存器0
sfr P0M1        =   0x93;   //0000,0000 端口0模式寄存器1
sfr P1M0        =   0x92;   //0000,0000 端口1模式寄存器0
sfr P1M1        =   0x91;   //0000,0000 端口1模式寄存器1
sfr P2M0        =   0x96;   //0000,0000 端口2模式寄存器0
sfr P2M1        =   0x95;   //0000,0000 端口2模式寄存器1
sfr P3M0        =   0xB2;   //0000,0000 端口3模式寄存器0
sfr P3M1        =   0xB1;   //0000,0000 端口3模式寄存器1
sfr P4M0        =   0xB4;   //0000,0000 端口4模式寄存器0
sfr P4M1        =   0xB3;   //0000,0000 端口4模式寄存器1
sfr P5M0        =   0xCA;   //0000,0000 端口5模式寄存器0
sfr P5M1        =   0xC9;   //0000,0000 端口5模式寄存器1
sfr P6M0        =   0xCC;   //0000,0000 端口6模式寄存器0
sfr P6M1        =   0xCB;   //0000,0000 端口6模式寄存器1
sfr P7M0        =   0xE2;   //0000,0000 端口7模式寄存器0
sfr P7M1        =   0xE1;   //0000,0000 端口7模式寄存器1
//系统管理特殊功能寄存器
sfr PCON        =   0x87;   //0001,0000 电源控制寄存器


sfr AUXR        =   0x8E;   //0000,0000 辅助寄存器
//sfr AUXR = 0x8e;	//	定时器 


sfr AUXR1       =   0xA2;   //0000,0000 辅助寄存器1
sfr P_SW1       =   0xA2;   //0000,0000 外设端口切换寄存器1
sfr CLK_DIV     =   0x97;   //0000,0000 时钟分频控制寄存器
sfr BUS_SPEED   =   0xA1;   //xx10,x011 总线速度控制寄存器
sfr P1ASF       =   0x9D;   //0000,0000 端口1模拟功能配置寄存器
sfr P_SW2       =   0xBA;   //xxxx,x000 外设端口切换寄存器
//中断特殊功能寄存器
sfr IE          =   0xA8;   //0000,0000 中断控制寄存器
sbit EA         =   IE^7;
sbit ELVD       =   IE^6;
sbit EADC       =   IE^5;
sbit ES         =   IE^4;
sbit ET1        =   IE^3;
sbit EX1        =   IE^2;
sbit ET0        =   IE^1;
sbit EX0        =   IE^0;
sfr IP          =   0xB8;   //0000,0000 中断优先级寄存器
sbit PPCA       =   IP^7;
sbit PLVD       =   IP^6;
sbit PADC       =   IP^5;
sbit PS         =   IP^4;
sbit PT1        =   IP^3;
sbit PX1        =   IP^2;
sbit PT0        =   IP^1;
sbit PX0        =   IP^0;
sfr IE2         =   0xAF;   //0000,0000 中断控制寄存器2
sfr IP2         =   0xB5;   //xxxx,xx00 中断优先级寄存器2


sfr INT_CLKO    =   0x8F;   //0000,0000 外部中断与时钟输出控制寄存器
//sfr INT_CLKO = 0x8f;
//sbit EX2	= INT_CLKO ^4;	不能位寻址地址，可以用这个办法： INT_CLKO |= ( (unsigned char)1 << 4 ) ;  ////EX2=1;//开启外部中断2//INT_CLKO|=((unsignedchar)1<<4);////EX3=1;//开启外部中断3//INT_CLKO|=((unsignedchar)1<<5);
//sbit EX3	= INT_CLKO ^5;	 
//sbit EX4	= INT_CLKO ^6;	 


//定时器特殊功能寄存器
sfr TCON        =   0x88;   //0000,0000 T0/T1控制寄存器
sbit TF1        =   TCON^7;
sbit TR1        =   TCON^6;
sbit TF0        =   TCON^5;
sbit TR0        =   TCON^4;
sbit IE1        =   TCON^3;
sbit IT1        =   TCON^2;
sbit IE0        =   TCON^1;
sbit IT0        =   TCON^0;
sfr TMOD        =   0x89;   //0000,0000 T0/T1模式寄存器
sfr TL0         =   0x8A;   //0000,0000 T0低字节
sfr TL1         =   0x8B;   //0000,0000 T1低字节
sfr TH0         =   0x8C;   //0000,0000 T0高字节
sfr TH1         =   0x8D;   //0000,0000 T1高字节
sfr T4T3M       =   0xD1;   //0000,0000 T3/T4模式寄存器
sfr T3T4M       =   0xD1;   //0000,0000 T3/T4模式寄存器
sfr T4H         =   0xD2;   //0000,0000 T4高字节
sfr T4L         =   0xD3;   //0000,0000 T4低字节
sfr T3H         =   0xD4;   //0000,0000 T3高字节
sfr T3L         =   0xD5;   //0000,0000 T3低字节
sfr T2H         =   0xD6;   //0000,0000 T2高字节
sfr T2L         =   0xD7;   //0000,0000 T2低字节
sfr WKTCL       =   0xAA;   //0000,0000 掉电唤醒定时器低字节
sfr WKTCH       =   0xAB;   //0000,0000 掉电唤醒定时器高字节
sfr WDT_CONTR   =   0xC1;   //0000,0000 看门狗控制寄存器
//串行口特殊功能寄存器
sfr SCON        =   0x98;   //0000,0000 串口1控制寄存器
sbit SM0        =   SCON^7;
sbit SM1        =   SCON^6;
sbit SM2        =   SCON^5;
sbit REN        =   SCON^4;
sbit TB8        =   SCON^3;
sbit RB8        =   SCON^2;
sbit TI         =   SCON^1;
sbit RI         =   SCON^0;
sfr SBUF        =   0x99;   //xxxx,xxxx 串口1数据寄存器
sfr S2CON       =   0x9A;   //0000,0000 串口2控制寄存器
sfr S2BUF       =   0x9B;   //xxxx,xxxx 串口2数据寄存器
sfr S3CON       =   0xAC;   //0000,0000 串口3控制寄存器
sfr S3BUF       =   0xAD;   //xxxx,xxxx 串口3数据寄存器
sfr S4CON       =   0x84;   //0000,0000 串口4控制寄存器
sfr S4BUF       =   0x85;   //xxxx,xxxx 串口4数据寄存器
sfr SADDR       =   0xA9;   //0000,0000 从机地址寄存器
sfr SADEN       =   0xB9;   //0000,0000 从机地址屏蔽寄存器
//ADC 特殊功能寄存器
sfr ADC_CONTR   =   0xBC;   //0000,0000 A/D转换控制寄存器
sfr ADC_RES     =   0xBD;   //0000,0000 A/D转换结果高8位
sfr ADC_RESL    =   0xBE;   //0000,0000 A/D转换结果低2位
//SPI 特殊功能寄存器
sfr SPSTAT      =   0xCD;   //00xx,xxxx SPI状态寄存器
sfr SPCTL       =   0xCE;   //0000,0100 SPI控制寄存器
sfr SPDAT       =   0xCF;   //0000,0000 SPI数据寄存器
//IAP/ISP 特殊功能寄存器
sfr IAP_DATA    =   0xC2;   //0000,0000 EEPROM数据寄存器
sfr IAP_ADDRH   =   0xC3;   //0000,0000 EEPROM地址高字节
sfr IAP_ADDRL   =   0xC4;   //0000,0000 EEPROM地址第字节
sfr IAP_CMD     =   0xC5;   //xxxx,xx00 EEPROM命令寄存器
sfr IAP_TRIG    =   0xC6;   //0000,0000 EEPRPM命令触发寄存器
sfr IAP_CONTR   =   0xC7;   //0000,x000 EEPROM控制寄存器
//PCA/PWM 特殊功能寄存器
sfr CCON        =   0xD8;   //00xx,xx00 PCA控制寄存器
sbit CF         =   CCON^7;
sbit CR         =   CCON^6;
sbit CCF2       =   CCON^2;
sbit CCF1       =   CCON^1;
sbit CCF0       =   CCON^0;
sfr CMOD        =   0xD9;   //0xxx,x000 PCA 工作模式寄存器
sfr CL          =   0xE9;   //0000,0000 PCA计数器低字节
sfr CH          =   0xF9;   //0000,0000 PCA计数器高字节
sfr CCAPM0      =   0xDA;   //0000,0000 PCA模块0的PWM寄存器
sfr CCAPM1      =   0xDB;   //0000,0000 PCA模块1的PWM寄存器
sfr CCAPM2      =   0xDC;   //0000,0000 PCA模块2的PWM 寄存器
sfr CCAP0L      =   0xEA;   //0000,0000 PCA模块0的捕捉/比较寄存器低字节
sfr CCAP1L      =   0xEB;   //0000,0000 PCA模块1的捕捉/比较寄存器低字节
sfr CCAP2L      =   0xEC;   //0000,0000 PCA模块2的捕捉/比较寄存器低字节
sfr PCA_PWM0    =   0xF2;   //xxxx,xx00 PCA模块0的PWM寄存器
sfr PCA_PWM1    =   0xF3;   //xxxx,xx00 PCA模块1的PWM寄存器
sfr PCA_PWM2    =   0xF4;   //xxxx,xx00 PCA模块1的PWM寄存器
sfr CCAP0H      =   0xFA;   //0000,0000 PCA模块0的捕捉/比较寄存器高字节
sfr CCAP1H      =   0xFB;   //0000,0000 PCA模块1的捕捉/比较寄存器高字节
sfr CCAP2H      =   0xFC;   //0000,0000 PCA模块2的捕捉/比较寄存器高字节
#endif






#define MCU_POWER_DOWN     PCON |= 0x02   //令单片机处于掉电模式。对于STC15,加4句 _nop_(); ，而且唤醒时不需要MCU_CLEAR_POF
#define MCU_IDLE        PCON |= 0x01   //令单片机处于空闲模式
#define MCU_CLEAR_POF    PCON &= 0xEF   //上电复位标志位清零	


 



extern void get_uniq_id_rom( unsigned char *pBuf );
extern void get_uniq_id_ram( unsigned char *pBuf );
extern void get_uniq_id( unsigned char *pBuf, unsigned char itype );
 



#define SET_BIT_VALUE_0( x, b ) 	 (x) &= ( ( (unsigned char)0xff ) ^ ( ((unsigned char)1) << (b) ) )
#define SET_BIT_VALUE_1( x, b ) 	 (x) |= ( ( (unsigned char)0x00 ) ^ ( ((unsigned char)1) << (b) ) )
#define SET_BIT_VALUE_X( x, b, V ) 	 if(V) SET_BIT_VALUE_1( (x), (b) ) else SET_BIT_VALUE_0( (x), (b) )          

#define GET_BIT_VALUE( x, b ) 	( ( (x) & ( ((unsigned char)1) << (b) ) ) ? 1 : 0 )  


// 0=传统51， 1=推挽， 2=开漏		
// 例如：	SET_PX_POWER_1( 3, 7 ); P37推挽式。	
#define SET_PX_POWER_0( x, b ) 	   SET_BIT_VALUE_0( P ## x ## M0, b ); SET_BIT_VALUE_0( P ## x ## M1, b );
#define SET_PX_POWER_1( x, b ) 	   SET_BIT_VALUE_1( P ## x ## M0, b ); SET_BIT_VALUE_0( P ## x ## M1, b );
#define SET_PX_POWER_2( x, b ) 	   SET_BIT_VALUE_1( P ## x ## M1, b ); SET_BIT_VALUE_1( P ## x ## M0, b );


// 0=传统51， 1=推挽， 2=开漏	
// 例如：	SET_PORT_POWER_1( P3, 7 ); P37推挽式。	推荐使用这个直观一些。	
#define SET_PORT_POWER_0( Px, b ) 	   SET_BIT_VALUE_0( Px ## M0, b ); SET_BIT_VALUE_0( Px ## M1, b );
#define SET_PORT_POWER_1( Px, b ) 	   SET_BIT_VALUE_1( Px ## M0, b ); SET_BIT_VALUE_0( Px ## M1, b );
#define SET_PORT_POWER_2( Px, b ) 	   SET_BIT_VALUE_1( Px ## M1, b ); SET_BIT_VALUE_1( Px ## M0, b );



//
extern void set_px_power( unsigned char p_x, unsigned char p_bit, unsigned char power_type ); // 

extern void set_mcu_power_down( void );   
extern void set_mcu_power_idle( void );   
extern void set_mcu_power_clear_pof( void );   





#endif




