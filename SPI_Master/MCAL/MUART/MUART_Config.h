/*
 * MUART_Config.h
 *
 *  Created on: Feb 26, 2022
 *      Author: Dell
 */

#ifndef MCAL_MUART_MUART_CONFIG_H_
#define MCAL_MUART_MUART_CONFIG_H_
/*Size of data bit Send
 * 1-CHAR_5Bit
 * 2-CHAR_6Bit
 * 3-CHAR_7Bit
 * 4-CHAR_8Bit
 * 5-CHAR_9Bit
 * */
#define UART_NUMBEROFDATA_BIT  CHAR_8Bit
/*Stop Bit Option
 * 1-ONE_BIT
 * 2-TWO_BIT*/
#define UART_STOPBIT  ONE_BIT

/*UART Mode Option
 * 1-UART_ASYNCHRONOUS
 * 2-UART_SYNCHRONOUS*/
#define UART_SELECTMODE  UART_ASYNCHRONOUS

/*Parity Check Option
 * 1-PARTIYCHECK_DISABLED
 * 2-PARTIYCHECK_ENABLED_EVEN
 * 3-PARTIYCHECK_ENABLED_ODD*/
#define UART_PARITYCHECK_MODE   PARTIYCHECK_DISABLED

#define UART_BAUDRATE    103
#endif /* MCAL_MUART_MUART_CONFIG_H_ */
