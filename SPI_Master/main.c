/*
 * main.c
 *
 *  Created on: Mar 11, 2022
 *      Author: Dell
 */
#include"LIB/LSTD_TYPES.h"
#include"MCAL/MDIO/MDIO_Interface.h"
#include"MCAL/MGIE/MGIE_Interface.h"
#include"MCAL/MSPI/MSPI_Interface.h"
#include"HAL/HCLCD/HCLCD_Config.h"
#include"HAL/HCLCD/HCLCD_Interface.h"
#include<stdio.h>
#include<string.h>
#include"HAL/HLED/HLED_Interface.h"

#define F_CPU 16000000UL
#include<util/delay.h>

int main(void)
{
	/*LCD initialize*/
	/*LCD Pins Initialization*/
	MDIO_Errorstate_SetPinDirection(HCLCD_ControlPort,RS_PIN,PIN_OUTPUT);
	MDIO_Errorstate_SetPinDirection(HCLCD_ControlPort,RW_PIN,PIN_OUTPUT);
	MDIO_Errorstate_SetPinDirection(HCLCD_ControlPort,E_PIN,PIN_OUTPUT);
	MDIO_Errorstate_SetPinDirection(HCLCD_DataPort,PIN4,PIN_OUTPUT);
	MDIO_Errorstate_SetPinDirection(HCLCD_DataPort,PIN5,PIN_OUTPUT);
	MDIO_Errorstate_SetPinDirection(HCLCD_DataPort,PIN6,PIN_OUTPUT);
	MDIO_Errorstate_SetPinDirection(HCLCD_DataPort,PIN7,PIN_OUTPUT);

	/*LCD Initialization*/
	HAL_VidHCLCD_4BitModeInit();
	HAL_VidHCLCD_4BitModeSetPosition(1,0);
	HAL_VidHCLCD_4BitModeWriteString((uint8*)"Master Send");
	HAL_VidHCLCD_4BitModeSetPosition(2,0);
	HAL_VidHCLCD_4BitModeWriteString((uint8*)"Send=");

	/*ss and MOSI and scl*/
	MDIO_Errorstate_SetPinDirection(MDIO_PORTB,PIN4,PIN_OUTPUT);
	MDIO_Errorstate_SetPinDirection(MDIO_PORTB,PIN5,PIN_OUTPUT);
	MDIO_Errorstate_SetPinDirection(MDIO_PORTB,PIN7,PIN_OUTPUT);
	/*set ss pin high*/
	MSPI_VidChip_SS_Select(1);
    /*MISO*/
	MDIO_Errorstate_SetPinDirection(MDIO_PORTB,PIN6,PIN_INPUT);
	/*initialize master*/
	MSPI_VidMasterInit();


	uint8 count=0;
	uint8 buffer[5];

	while(1)
	{
	MSPI_VidSendData(count);
	sprintf(buffer,"%d ",count);
	HAL_VidHCLCD_4BitModeSetPosition(2,6);
	HAL_VidHCLCD_4BitModeWriteString(buffer);
	count++;
	_delay_ms(500);
	}
	return 0;
}

