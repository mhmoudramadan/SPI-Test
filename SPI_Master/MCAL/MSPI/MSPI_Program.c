/*
 * MSPI_Program.c
 *
 *  Created on: Feb 26, 2022
 *      Author: Dell
 */
#include"../../LIB/LSTD_TYPES.h"
#include"../../LIB/LBIT_MATH.h"
#include"../MDIO/MDIO_Interface.h"
#include"MSPI_Private.h"
#include"MSPI_Config.h"

void (*MSPI_CALLBACK)(void);

void MSPI_VidMasterInit(void)
{
	/*Set Data Order */
#if MSPI_DATAORDER == MSPI_LSB_DATAORDER
	SET_BIT(SPCR,5);
#elif MSPI_DATAORDER == MSPI_MSB_DATAORDER
	CLR_BIT(SPCR,5);
#else
#error"Data Order Option Is Not Valid.."
#endif
	/*Set Clock Polarity And Phase*/
#if MSPI_SETCLOCKPOLARIT == MSPI_RISING_POLARITY
	CLR_BIT(SPCR,3);
#elif MSPI_SETCLOCKPOLARIT == MSPI_FALLING_POLARITY
	SET_BIT(SPCR,3);
#else
#error"Clock Polarity Option Is Not Valid.."
#endif

#if MSPI_SETCLOCKPHASE == MSPI_SETUP_PHASE
	SET_BIT(SPCR,2);
#elif MSPI_SETCLOCKPOLARIT == MSPI_SAMPLE_PHASE
	CLR_BIT(SPCR,2);
#else
#error"Clock Phase Option Is Not Valid.."
#endif
	/*Set Double Speed*/
#if MSPI_SETDOUBLESPEED == MSPI_DOUBLESPEED
	SET_BIT(SPSR,0);
#elif MSPI_SETDOUBLESPEED == MSPI_NO_DOUBLESPEED
	CLR_BIT(SPSR,0);
#else
#error"Double Speed Option Is Not Valid.."
#endif
	       /*Set PreScaler */
	SPCR&=0x3F;
	SPCR|=MSPI_PRESCALER;
	      /*SET as Master*/
	SET_BIT(SPCR,4);
	      /*Enable SPI*/
	SET_BIT(SPCR,6);
	/*Enable SPI interrupt*/
	SET_BIT(SPCR,7);
}
void MSPI_VidSalveInit(void)
{
	/*Set Data Order */
#if MSPI_DATAORDER == MSPI_LSB_DATAORDER
	SET_BIT(SPCR,5);
#elif MSPI_DATAORDER == MSPI_MSB_DATAORDER
	CLR_BIT(SPCR,5);
#else
#error"Data Order Option Is Not Valid.."
#endif
	/*Set Clock Polarity And Phase*/
#if MSPI_SETCLOCKPOLARIT == MSPI_RISING_POLARITY
	CLR_BIT(SPCR,3);
#elif MSPI_SETCLOCKPOLARIT == MSPI_FALLING_POLARITY
	SET_BIT(SPCR,3);
#else
#error"Clock Polarity Option Is Not Valid.."
#endif

#if MSPI_SETCLOCKPHASE == MSPI_SETUP_PHASE
	SET_BIT(SPCR,2);
#elif MSPI_SETCLOCKPOLARIT == MSPI_SAMPLE_PHASE
	CLR_BIT(SPCR,2);
#else
#error"Clock Phase Option Is Not Valid.."
#endif

	       /*SET as Salve*/
	CLR_BIT(SPCR,4);
	       /*Enable SPI*/
	SET_BIT(SPCR,6);
	      /*Enable SPI interrupt*/
	SET_BIT(SPCR,7);

}
uint8 MSPI_uint8SendReceiveChar(uint8 copy_uint8Char)
{
	SPDR=copy_uint8Char;
	/*check on flag*/
	while(GET_BIT(SPSR,7)==0);
	/*clear interrupt flag*/
	SET_BIT(SPSR, 7);
	return SPDR;
}
void MSPI_VidSendData(uint8 copy_uint8Data)
{

	SPDR=copy_uint8Data;
	/*check on flag*/
	while(GET_BIT(SPSR,7)==0);
//	/*Check on Write COllision*/
//	while(GET_BIT(SPSR,6)==0);
//	/*clear interrupt flag*/
	SET_BIT(SPSR, 7);

}
uint8 MSPI_uint8ReceiveData(void)
{
	uint8 Loc_uint8Dummy=0;
	SPDR=Loc_uint8Dummy;
//	/*check on flag until receive complete*/
	while(GET_BIT(SPSR,7)==0);
//	/*clear interrupt flag*/
	SET_BIT(SPSR, 7);
	return SPDR;
}
void MSPI_VidChip_SS_Select(uint8 copy_uint8mode)
{
	switch(copy_uint8mode)
	{
	case 0:
		{
			MDIO_Errorstate_SetPinValue(MDIO_PORTB,PIN4,PIN_LOW);
			break;
		}
	case 1:
	{
		MDIO_Errorstate_SetPinValue(MDIO_PORTB,PIN4,PIN_HIGH);
		break;
	}
	default:
		break;
	}

}
uint8 MSPI_uint8ExchangeDataBlock(uint8 copy_uint8Data)
{
	SPDR=copy_uint8Data;
	/*Check on transmit complete*/
	while(GET_BIT(SPSR,7)==0);
	return SPDR;
}
void MSPI_VidSPI_SetCallBack(void(*PtrToFun)(void))
{
	MSPI_CALLBACK=PtrToFun;
}
void __vector_12(void)    __attribute__((signal));
void __vector_12(void)
{
	MSPI_CALLBACK();
}
