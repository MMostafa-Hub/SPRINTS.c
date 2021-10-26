/************************************************************************************/
/* Author     : Mohamed Mostafa                                                     */
/* Date       : 12 10 2021		                                                    */
/************************************************************************************/

#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "../../LIB/BIT_MATH/BIT_MATH.h"
#include "../../MCAL/DIO/MDIO_interface.h"
#include "Keybad_interface.h"
#include "Keybad_config.h"

#ifndef F_CPU
#define F_CPU 1000000UL //1MHz Clock frequency
#endif
										
const u8 keypad_buttons [4][4] =	{
										{'7'	,'8'	,'9'	,INVALID},
										{'4'	,'5'	,'6'	,INVALID},
										{'1'	,'2'	,'3'	,INVALID},
										{INVALID,'0'	,ENTER	,INVALID}
									};

u8 col [8] = {Col0,Col1,Col2,Col3};
u8 row [8] = {Row0,Row1,Row2,Row3};


/*
Description  : initialize PortC from pin0 -> 3 as output and pin4 -> 7 as input for the Keypad
Input  args  : none
Output args  : none
Return value : none
*/
void EUKeypad_voidKeypadInit (void)
{
	// Make Columns as Output Pins
	MDIO_voidSetPinDirection(Col0, OUTPUT);
	MDIO_voidSetPinDirection(Col1, OUTPUT);
	MDIO_voidSetPinDirection(Col2, OUTPUT);
	MDIO_voidSetPinDirection(Col3, OUTPUT);
	
	// Make Rows as Input Pins
	MDIO_voidSetPinDirection(Row0, INPUT);
	MDIO_voidSetPinDirection(Row1, INPUT);
	MDIO_voidSetPinDirection(Row2, INPUT);
	MDIO_voidSetPinDirection(Row3, INPUT);
	
	// Send High Voltage To Columns
	MDIO_voidSetPinValue(Col0, HIGH);
	MDIO_voidSetPinValue(Col1, HIGH);
	MDIO_voidSetPinValue(Col2, HIGH);
	MDIO_voidSetPinValue(Col3, HIGH);
	
	// Make Rows As Pull Up Resistors
	MDIO_voidSetPinValue(Row0, HIGH);
	MDIO_voidSetPinValue(Row1, HIGH);
	MDIO_voidSetPinValue(Row2, HIGH);
	MDIO_voidSetPinValue(Row3, HIGH);
}

u8 EUKeypad_voidKeyPressed (void)
{
		
	for (u8 c = 0; c < 4; ++c)
	{
		MDIO_voidSetPinValue(col[c * 2], col[c * 2 + 1], LOW); // alternating low on the column pins (pinC0 -> pinC3)
	
		for (u8 r = 0; r < 4; ++r)
		{
			if (!MDIO_voidGetPinValue(row[r * 2], row[r * 2 + 1]))
			{
				while (!MDIO_voidGetPinValue(row[r * 2], row[r * 2 + 1])); // Prevent the long presses
				
				if(keypad_buttons [r][c] != INVALID) // if the user pressed on a valid value
					return keypad_buttons [r][c];

			}
		}
		MDIO_voidSetPinValue(col[c * 2],col[c * 2 + 1], HIGH);
	}
	return NONE;
}
