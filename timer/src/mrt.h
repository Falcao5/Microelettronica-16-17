/*
 * mrt.h
 *
 *  Created on: 04 gen 2017
 *  Author: ssalvatori.altervista.org
 *
 * @brief Function for MRT manage
 *
 * 1st revision: MRT channel 0 in one-shot mode IRQ
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

#ifndef SRC_MRT_H_
#define SRC_MRT_H_

#include "board.h"

#define SCLK 30000000

/**
 * @brief	Delay routine in ms uses MRT CH0 in one-shot interrupt mode
 * 			ISR for MRT signals interrupt event setting 'elapsedtime' flag
 * @return	Nothing
 */
void InitMRT0_oneshot(void);

/**
 * @brief	Delay routine in ms uses MRT CH0 in one-shot interrupt mode
 * 			ISR for MRT signals interrupt event setting 'elapsedtime' flag
 * @return	Nothing
 */
void DelayMs(uint32_t delayinms);

/**
 * @brief	Delay routine in us uses MRT CH0 in one-shot interrupt mode
 * 			ISR for MRT signals interrupt event setting 'elapsedtime' flag
 * @return	Nothing
 */
void DelayUs(uint32_t delayinus);

/**
 * @brief	Handle interrupt from MRT
 * @return	Nothing
 */
void MRT_IRQHandler(void);

#endif /* SRC_MRT_H_ */
