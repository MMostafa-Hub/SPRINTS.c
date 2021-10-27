
#include "app.h"

int main(void)
{
	app_init();
	
	/* Send a Byte to MC2 */
	SPI_sendReceiveByte('B');
	
    while(1)
    {
		
    }
}


