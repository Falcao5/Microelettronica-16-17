/*
 * @brief I/O example: ten leds light effects
 *
 * @note
 * Author ssalvatori.altervista.org, 2016
 * Libraries: by NXP Semiconductors
 *
 * @par
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * LPC products.  This software is supplied "AS IS" without any warranties of
 * any kind, and the author disclaims any and all warranties, express or implied,
 * including all implied warranties of merchantability, fitness for a particular
 * purpose and non-infringement of intellectual property rights.
 * Author assumes no responsibility or liability for the use of the software,
 * conveys no license or rights under any patent, copyright, mask work right,
 * or any other intellectual property rights in or to any products.
 * Author reserves the right to make changes in the software without notification.
 * Author also makes no representation or warranty that such application will be
 * suitable for the specified use without further testing or modification.
 *
 * @par
 * Permission to use, copy, modify, and distribute this software and its
 * documentation is hereby granted, under author and his licensor's relevant
 * copyrights in the software, without fee, provided that it
 * is used in conjunction with NXP Semiconductors microcontrollers.  This
 * copyright, permission, and disclaimer notice must appear in all copies of
 * this code.
 */

#include "board.h"
#include <stdio.h>
#include "mrt.h"
#include "HD44780_824.h"

/* 'OscRateIn' and 'ExtRateIn' definitions are located in "board.c" file.
 * Remove if Board_Init() is called
 */

const uint32_t OscRateIn = 12000000;
const uint32_t ExtRateIn = 0;

/**
 * @brief	main routine for die example
 * @return	Function should not exit.
 */
int main(void)
{
	int seconds=0;
	int minutes=0;

	SystemCoreClockUpdate();

	InitMRT0_oneshot(); //MRT usato per delay secondo le specifiche dell'LCD

	InitLCD(); 			//initialize LCD

	/* Loop forever */
	while (1)
	{
		DelayMs(1000);											// Ritardo di un secondo

		if(seconds == 59){										// Incrementa i minuti e reimposta i secondi
			minutes++;
			seconds = 0;
		}

		WriteWord((uint_8*)minutes + (uint_8*)":" + (uint_8*)seconds);	// Scrivi su LCD

		seconds++;												// Incrementa i secondi
	}
}
