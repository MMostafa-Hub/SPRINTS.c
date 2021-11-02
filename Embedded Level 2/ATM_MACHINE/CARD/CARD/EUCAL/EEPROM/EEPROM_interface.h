#ifndef			EEPROM_INTERFACE_H_
#define			EEPROM_INTERFACE_H_

#include "../../LIB/BIT_MATH/BIT_MATH.h"
#include "../../LIB/STD_TYPES/STD_TYPES.h"

void EUEEPROM_voidEEPROMInit (void);
void EUEEPROM_voidEEPROMWriteData (u16 copy_u16Address , u8 copy_u8Data);
u8 	 EUEEPROM_u8EEPROMReadData	  (u16 copy_u16Address);


#endif