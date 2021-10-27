/*
 * spi.c
 *
 * Created: 20/10/2021 2:35:20 PM
 *  Author: OWNER
 */ 

#include "spi.h"

/*
 * Description : Initialize the SPI device as Master
 */
void SPI_initMaster(void) 
{
	/*************  SPI Master Pins **************
	 * SS(PB4)   --> Output
	 * MOSI(PB5) --> Output 
	 * MISO(PB6) --> Input
	 * SCK(PB7) --> Output
	 ********************************************/
	DIO_setupPinDirection(PORTB_ID,PIN4_ID,PIN_OUTPUT);
	DIO_setupPinDirection(PORTB_ID,PIN5_ID,PIN_OUTPUT);
	DIO_setupPinDirection(PORTB_ID,PIN6_ID,PIN_INPUT);
	DIO_setupPinDirection(PORTB_ID,PIN7_ID,PIN_OUTPUT);
	
    /************************** SPCR Description **************************
     * SPIE    = 0 Disable SPI Interrupt
     * SPE     = 1 Enable SPI Driver
     * DORD    = 0 Transmit the MSB first
     * MSTR    = 1 Enable Master
     * CPOL    = 0 SCK is low when idle
     * CPHA    = 0 Sample Data with the raising edge
     * SPR1:0  = 00 Choose SPI clock = Fosc/4
     ***********************************************************************/
	SPCR = (1<<SPE) | (1<<MSTR);

	/* Clear the SPI2X bit in SPSR to Choose SPI clock = Fosc/4 */
	SPSR &= ~(1<<SPI2X);
}

/*
 * Description : Initialize the SPI device as Slave
 */
void SPI_initSlave(void)
{ 
	/******** Configure SPI Slave Pins *********
	 * SS(PB4)   --> Input
	 * MOSI(PB5) --> Input
	 * MISO(PB6) --> Output
	 * SCK(PB7) --> Input
	 ********************************************/
	DIO_setupPinDirection(PORTB_ID,PIN4_ID,PIN_INPUT);
	DIO_setupPinDirection(PORTB_ID,PIN5_ID,PIN_INPUT);
	DIO_setupPinDirection(PORTB_ID,PIN6_ID,PIN_OUTPUT);
	DIO_setupPinDirection(PORTB_ID,PIN7_ID,PIN_INPUT);

	/************************** SPCR Description **************************
	 * SPIE    = 0 Disable SPI Interrupt
	 * SPE     = 1 Enable SPI Driver
	 * DORD    = 0 Transmit the MSB first
	 * MSTR    = 0 Disable Master
	 * CPOL    = 0 SCK is low when idle
	 * CPHA    = 0 Sample Data with the raising edge
	 * SPR1:0  = 00 Choose SPI clock = Fosc/4
	 ***********************************************************************/
	SPCR = (1<<SPE);

	/* Clear the SPI2X bit in SPSR to Choose SPI clock = Fosc/4 */
	SPSR &= ~(1<<SPI2X);
}

/*
 *	Description : Send the required data through SPI to the other SPI device
 *	In the same time data will be received from the other device
 */
uint8 SPI_sendReceiveByte(uint8 data)
{
	/*	Initiate the communication and send data by SPI */
	/*	
	*	In case of receiving data 
	*	Since writing to SPDR generates SCK for transmission, write dummy data in the SPDR register
	*/
	SPDR = data;

	/*	Wait until SPI interrupt flag SPIF = 1 (data has been sent/received correctly) */
	while(BIT_IS_CLEAR(SPSR,SPIF));

	return SPDR;
}

/*
 * Description : Send the required string through SPI to the other SPI device
 */
void SPI_sendString(const uint8 *str)
{
	uint8 i = 0;
	uint8 received_data = 0;

	/* Send the whole string */
	while(str[i] != '\0')
	{
		/*
		 * received_data contains the received data from the other device.
		 * It is a dummy data variable as we just need to send the string to other device.
		 */
		received_data = SPI_sendReceiveByte(str[i]);
		i++;
	}
}

/*
 * Description : Receive the required string until the '\r' symbol through SPI from the other SPI device
 */
void SPI_receiveString(uint8 *str)
{
	uint8 i = 0;

	/* Receive the first byte */
	str[i] = SPI_sendReceiveByte(SPI_DEFAULT_DATA_VALUE);

	/* Receive the whole string until the '\r' ENTER is pressed */
	while(str[i] != '\r')
	{
		i++;
		str[i] = SPI_sendReceiveByte(SPI_DEFAULT_DATA_VALUE);
	}

	/* After receiving the whole string plus the '\r', replace the 'r' with '\0' */
	str[i] = '\0';
}
