
#include "UNIQ_ID.h"
#include "mainioport.h"




void mainioport_init(void)
{
	SET_PORT_POWER_0( P0, 7 );
	SET_PORT_POWER_0( P0, 1 );

	SET_PORT_POWER_0( P1, 5 );

	SET_PORT_POWER_1( P2, 2 );  
}




