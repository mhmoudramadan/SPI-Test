/*
 * MSPI_Interface.h
 *
 *  Created on: Feb 26, 2022
 *      Author: Dell
 */

#ifndef MCAL_MSPI_MSPI_INTERFACE_H_
#define MCAL_MSPI_MSPI_INTERFACE_H_

void MSPI_VidMasterInit(void);
void MSPI_VidSalveInit(void);
uint8 MSPI_uint8SendReceiveChar(uint8 copy_uint8Char);
void MSPI_VidSPI_SetCallBack(void(*PtrToFun)(void));
void MSPI_VidChip_SS_Select(uint8 copy_uint8mode);
uint8 MSPI_uint8ExchangeDataBlock(uint8 copy_uint8Data);
void MSPI_VidSendData(uint8 copy_uint8Data);
uint8 MSPI_uint8ReceiveData(void);

#endif /* MCAL_MSPI_MSPI_INTERFACE_H_ */
