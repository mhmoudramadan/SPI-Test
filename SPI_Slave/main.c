/*
 * main.c
 *
 *  Created on: Mar 11, 2022
 *      Author: Dell
 */
#include"LIB/LSTD_TYPES.h"
#include"MCAL/MDIO/MDIO_Interface.h"
#include"MCAL/MGIE/MGIE_Interface.h"
#include"HAL/HCLCD/HCLCD_Config.h"
#include"HAL/HCLCD/HCLCD_Interface.h"
#include"MCAL/MSPI/MSPI_Interface.h"
#include"HAL/HLED/HLED_Interface.h"
#include<string.h>
#include<stdio.h>
#define F_CPU 16000000UL
#include<util/delay.h>
LED_T led1={MDIO_PORTC,PIN7,ACTIVE_HIGH};

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
	HAL_VidHCLCD_4BitModeWriteString((uint8*)"salve receive");
	HAL_VidHCLCD_4BitModeSetPosition(2,0);
	HAL_VidHCLCD_4BitModeWriteString((uint8*)"receive=");


	/*ss and MOSI and scl*/
	MDIO_Errorstate_SetPinDirection(MDIO_PORTB,PIN4,PIN_INPUT);
	MDIO_Errorstate_SetPinDirection(MDIO_PORTB,PIN5,PIN_INPUT);
	MDIO_Errorstate_SetPinDirection(MDIO_PORTB,PIN7,PIN_INPUT);

    /*MISO*/
	MDIO_Errorstate_SetPinDirection(MDIO_PORTB,PIN6,PIN_OUTPUT);
	HLED_Errorstate_Led_Init(&led1);

	/*salve Initialize*/
	MSPI_VidSalveInit();
	uint8 data;
	uint8 buffer[5];
	while(1)
	{
		data=MSPI_uint8ReceiveData();
		sprintf(buffer,"%d",data);
		HAL_VidHCLCD_4BitModeSetPosition(2,9);
		HAL_VidHCLCD_4BitModeWriteString(buffer);


	}
	return 0;
}

