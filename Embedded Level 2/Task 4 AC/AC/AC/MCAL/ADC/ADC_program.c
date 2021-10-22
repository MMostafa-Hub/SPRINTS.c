/************************************************************************************/
/* Author     : Mohamed Mostafa                                                     */
/* Date       : 12 10 2021		                                                    */
/************************************************************************************/

#include 	"ADC_interface.h"

/*
Description  : initialize Port A to work as ADC
Input  args  : none
Output args  : none
Return value : none
*/
void MADC_voidInit(void)
{
	// Select Voltage Reference
	if (VOLTAGE_REF == AREF)
	{
		ADCMUX &= ~(1<<REFS1) & ~((1<<REFS0));
	}
	else if (VOLTAGE_REF == AVCC)
	{
		ADCMUX &= ~(1<<REFS1);
		ADCMUX |= (1<<REFS0);
	}
	else if (VOLTAGE_REF == INTERNAL_2_HALF_VOLT)
	{
		ADCMUX |= (1<<REFS1) | (1<<REFS0);
	}

	ADCSRA |= ADC_PRE_SCALER; // select Pre-Scalaer
	ADCSRA |= (1<<ADEN); // Enable ADC
	ADCSRA |= (1<<ADSC); // Start Conversion
		
}
/*
Description	  : reads the ADC signal
Input  args   : ADC Channel pin (ADC0,ADC1,ADC2,.....)
Output args   : none
Return value  : integer value from the ADC
*/
u16 MADC_u16Read(u8 copy_u8ChannelId )
{
	ADCMUX &= 0xf0; // Clear Channel Number
	ADCMUX |= copy_u8ChannelId; // Choose Channel ID
	ADCSRA |= (1<<ADSC); // Start Conversion
	while (ADCSRA & (1<<ADSC)); // Waiting For The Conversation To Finish

	return ADC;  //Get The Digital Value form ADCL and ADCH Registers
}