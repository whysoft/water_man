
#ifndef ___MAINIO_H_H
#define ___MAINIO_H_H

 
 
sbit LED4	= P0 ^ 7;	

sbit LIGHT1	= P0 ^ 1;	 

sbit WETBOOL	= P1 ^ 5;	


sbit BEEP = P2 ^ 2;	


extern void mainioport_init(void);



#define LET_LED4_ON		LED4 = 0 
#define LET_LED4_OFF	LED4 = 1  


#define LET_LIGHT1_ON		LIGHT1 = 0 
#define LET_LIGHT1_OFF		LIGHT1 = 1   



#define LET_BEEP_ON	    	BEEP = 1 
#define LET_BEEP_OFF		BEEP = 0 
#define LET_BEEP_NOT		BEEP = ~BEEP 



#endif




