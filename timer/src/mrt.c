/*
 * mrt.c
 *
 *  Created on: 04 gen 2017
 *      Author: stefo
 */

#include "mrt.h"

uint8_t elapsedtime = 0; // MRT ISR sets the flag if an interrupt event occurs

/**
 * @brief	Delay routine in ms uses MRT CH0 in one-shot interrupt mode
 * 			ISR for MRT signals interrupt event setting 'elapsedtime' flag
 * @return	Nothing
 */
void InitMRT0_oneshot(void)
{
	LPC_SYSCTL->SYSAHBCLKCTRL |= (1<<10);	// enable clock for MRT

	LPC_SYSCTL->PRESETCTRL &= ~(1<<7);		// reset MRT
	LPC_SYSCTL->PRESETCTRL |= (1<<7);		// deassert reset of MRT

	LPC_MRT_CH0->CTRL &= ~7;				// disable interrupt, clear MODE bits
	LPC_MRT_CH0->CTRL |= 3;					// enable interrupt, one-shot interrupt mode

	NVIC_EnableIRQ(MRT_IRQn);				// Enable interrupt for MRT

	LPC_MRT_CH0->INTVAL = 0;				// a 0 value puts MRT0 in the idle condition

	LPC_MRT_CH0->STAT |= 1;					// clear interrupt request

	elapsedtime=0;							// set MRT ISR flag to 0
}

/**
 * @brief	Delay routine in ms uses MRT CH0 in one-shot interrupt mode
 * 			ISR for MRT signals interrupt event setting 'elapsedtime' flag
 * @return	Nothing
 */
void DelayMs(uint32_t delayinms)
{
	LPC_MRT_CH0->INTVAL = delayinms*(SCLK/1000); // load MRT value

	while(elapsedtime==0);		// wait for interrupt event

	elapsedtime=0;				// clear MRT ISR flag
}

/**
 * @brief	Delay routine in us uses MRT CH0 in one-shot interrupt mode
 * 			ISR for MRT signals interrupt event setting 'elapsedtime' flag
 * @return	Nothing
 */
void DelayUs(uint32_t delayinus)
{
	LPC_MRT_CH0->INTVAL = delayinus*(SCLK/1000000); // load MRT value

	while(elapsedtime==0);		// wait for interrupt event

	elapsedtime=0;				// clear MRT ISR flag
}

/**
 * @brief	Handle interrupt from MRT
 * @return	Nothing
 */
void MRT_IRQHandler(void)
{
	if(LPC_MRT_CH0->STAT == 1)		// IRQ pending for MRT_CH0
	{
		LPC_MRT->IRQ_FLAG |= 1;		// clear pending IRQ for MRT0
//		LPC_MRT_CH0->STAT |= 1;		// clear interrupt request
		elapsedtime = 1;			// set interrupt flag
	}
}


