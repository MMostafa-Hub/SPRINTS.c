/*
 * spi.h
 *
 * Created: 20/10/2021 2:36:05 PM
 *  Author: OWNER
 */

#ifndef SPI_H_
#define SPI_H_

#include "../std_types.h"
#include "../DIO/dio.h" 
#include "../common_macros.h" /* To use the macros like SET_BIT */
#include <avr/io.h> /* To use the SPI Registers */

/*
 * Default SPI data value used in case we need to receive a byte from the other device,
 * without need to send a data to it
 */
#define SPI_DEFAULT_DATA_VALUE 0xFF

void SPI_initMaster(void); 
void SPI_initSlave(void);
uint8 SPI_sendReceiveByte(uint8 data);
void SPI_sendString(const uint8 *str);
void SPI_receiveString(uint8 *str);

#endif
