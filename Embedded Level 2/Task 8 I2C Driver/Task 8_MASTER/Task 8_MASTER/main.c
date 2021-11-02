
#include "app.h"

int main(void)
{
	
	TWI_init();
	TWI_start();
	TWI_writeByte(0x02);
	TWI_writeByte(0x11);
	TWI_stop();
	
	return 0;
}
