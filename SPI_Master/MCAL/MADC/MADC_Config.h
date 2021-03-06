/*
 * MADC_Config.h
 *
 *  Created on: Feb 5, 2022
 *      Author: Dell
 */

#ifndef MCAL_MADC_MADC_CONFIG_H_
#define MCAL_MADC_MADC_CONFIG_H_

/*ADC Reference Volt Option
 * 1-MADC_Vref_AVCC
 * 2-MADC_Vref_INTERNAL_2_56 */

#define MADC_SET_REFERENCVOLT MADC_Vref_AVCC

/*Select Adjustment result option
 * 1-MADC_RIGHT_ADJUST
 * 2-MADC_LEFT_ADJUST */
#define MADC_SET_ADJUSTRESULT  MADC_RIGHT_ADJUST

/* ADC PRESCALER Option
 * 1-ADC_PRESCALER_2
 * 2-ADC_PRESCALER_4
 * 3-ADC_PRESCALER_8
 * 4-ADC_PRESCALER_16
 * 5-ADC_PRESCALER_32
 * 6-ADC_PRESCALER_64
 * 7-ADC_PRESCALER_128*/

#define ADC_SET_PRESCALER ADC_PRESCALER_128

/*ADC AUto Trigger Source Selection
 * 1-MADC_FREERUNNING
 * 2-MADC_ANALOGCOMPARATOR
 * 3-MADC_EXTI0
 * 4-MADC_TIMER_COUNTER0_COMPAREMATCH
 * 5-MADC_TIMER_COUNTER0_OVERFLOW
 * 6-MADC_TIMER_COUNTER0_COMPAREMATCH_B
 * 7-MADC_TIMER_COUNTER1_OVERFLOW
 * 8-MADC_TIMER_COUNTER1_CAPTUREEVENT
 * */
#define MADC_SET_AUTO_TRIGGER_SOURCE MADC_FREERUNNING

/*Analog Channel
 * 1-MADC_SINGLEENDED_CHANNEL
 * 2-MADC_DIFFERENTIAL_CHANNEL*/
#define MADC_SET_ANALOGCHANNEL MADC_SINGLEENDED_CHANNEL

#endif /* MCAL_MADC_MADC_CONFIG_H_ */
