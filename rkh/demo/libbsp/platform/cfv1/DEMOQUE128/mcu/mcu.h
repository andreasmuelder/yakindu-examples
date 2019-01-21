/*
** ###################################################################
**     This code is generated by the Device Initialization Tool.
**     It is overwritten during code generation.
**     USER MODIFICATION ARE NOT PRESERVED IN THIS FILE.
**
**     Project   : s08qe128
**     Processor : MCF51QE128CLK
**     Version   : Bean 01.001, Driver 01.03, CPU db: 3.00.000
**     Datasheet : MCF51QE128RM Rev. 1.0 Draft F
**     Date/Time : 06/03/2009, 10:04 a.m.
**     Abstract  :
**         This module contains device initialization code 
**         for selected on-chip peripherals.
**     Contents  :
**         Function "MCU_init" initializes selected peripherals
**
**     (c) Copyright UNIS, spol. s r.o. 1997-2006
**     UNIS, spol s r.o.
**     Jundrovska 33
**     624 00 Brno
**     Czech Republic
**     http      : www.processorexpert.com
**     mail      : info@processorexpert.com
** ###################################################################
*/


#include "derivative.h"

#define MCU_XTAL_CLK		8192000
#define MCU_REF_CLK_DIVIDER	256
#define MCU_REF_CLK			(MCU_XTAL_CLK/MCU_REF_CLK_DIVIDER)
#define MCU_FLL_OUT			(MCU_REF_CLK*1536)

#define MCU_BUSCLK			(MCU_FLL_OUT/2)

#define RTI_TICK			1				/* Real Time Interrupt [ms] */
#define RTI_MS(x)		(x/RTI_TICK)		/* Tick Base to ms */

#define reset_now()	asm( "HALT" )

void mcu_init( unsigned char tick_ms );

unsigned long get_ts( void );
