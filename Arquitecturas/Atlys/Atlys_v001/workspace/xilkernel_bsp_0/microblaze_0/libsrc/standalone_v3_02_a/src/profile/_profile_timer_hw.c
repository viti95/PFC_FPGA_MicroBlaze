//////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2004-2010 Xilinx, Inc.  All rights reserved.
// Xilinx, Inc.
//
// XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS" AS A
// COURTESY TO YOU.  BY PROVIDING THIS DESIGN, CODE, OR INFORMATION AS
// ONE POSSIBLE   IMPLEMENTATION OF THIS FEATURE, APPLICATION OR
// STANDARD, XILINX IS MAKING NO REPRESENTATION THAT THIS IMPLEMENTATION
// IS FREE FROM ANY CLAIMS OF INFRINGEMENT, AND YOU ARE RESPONSIBLE
// FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE FOR YOUR IMPLEMENTATION.
// XILINX EXPRESSLY DISCLAIMS ANY WARRANTY WHATSOEVER WITH RESPECT TO
// THE ADEQUACY OF THE IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO
// ANY WARRANTIES OR REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE
// FROM CLAIMS OF INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY
// AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $Id: _profile_timer_hw.c,v 1.1.2.1 2011/01/20 04:20:41 sadanan Exp $
//
// _program_timer_hw.c:
//	Timer related functions
//
//////////////////////////////////////////////////////////////////////

#include "profile.h"
#include "_profile_timer_hw.h"

#include "xil_exception.h"

#ifdef PROC_PPC
#include "xtime_l.h"
#include "xpseudo_asm.h"
#endif

#ifdef TIMER_CONNECT_INTC
#include "xintc_l.h"
#include "xintc.h"
#endif	// TIMER_CONNECT_INTC

#ifndef PPC_PIT_INTERRUPT
#include "xtmrctr_l.h"
#endif

extern unsigned int timer_clk_ticks ;

//--------------------------------------------------------------------
// PowerPC Target - Timer related functions
//--------------------------------------------------------------------
#ifdef PROC_PPC405


//--------------------------------------------------------------------
// PowerPC PIT Timer Init.
//	Defined only if PIT Timer is used for Profiling
//
//--------------------------------------------------------------------
#ifdef PPC_PIT_INTERRUPT
int ppc_pit_init( void )
{
	// 1. Register Profile_intr_handler as Interrupt handler
	// 2. Set PIT Timer Interrupt and Enable it.
	Xil_ExceptionRegisterHandler( XIL_EXCEPTION_ID_PIT_INT,
			    (Xil_ExceptionHandler)profile_intr_handler,(void *)0);
	XTime_PITSetInterval( timer_clk_ticks ) ;
	XTime_PITEnableAutoReload() ;
	return 0;
}
#endif


//--------------------------------------------------------------------
// PowerPC Timer Initialization functions.
//	For PowerPC, PIT and opb_timer can be used for Profiling. This
//	is selected by the user in standalone BSP
//
//--------------------------------------------------------------------
int powerpc405_init()
{
	Xil_ExceptionInit() ;
	Xil_ExceptionDisableMask( XIL_EXCEPTION_NON_CRITICAL ) ;

	// Initialize the Timer.
	// 1. If PowerPC PIT Timer has to be used, initialize PIT timer.
	// 2. Else use opb_timer. It can be directly connected or thru intc to PowerPC
#ifdef PPC_PIT_INTERRUPT
	ppc_pit_init();
#else
#ifdef TIMER_CONNECT_INTC
	Xil_ExceptionRegisterHandler( XIL_EXCEPTION_ID_NON_CRITICAL_INT,
			      (Xil_ExceptionHandler)XIntc_DeviceInterruptHandler,(void *)0);
	XIntc_RegisterHandler( INTC_BASEADDR, PROFILE_TIMER_INTR_ID,
			     (XInterruptHandler)profile_intr_handler,(void*)0);
#else
	Xil_ExceptionRegisterHandler( XIL_EXCEPTION_ID_NON_CRITICAL_INT,
			      (Xil_ExceptionHandler)profile_intr_handler,(void *)0);
#endif
	// Initialize the timer with Timer Ticks
	opb_timer_init() ;
#endif

	// Enable Interrupts in the System, if Profile Timer is the only Interrupt
	// in the System.
#ifdef ENABLE_SYS_INTR
#ifdef PPC_PIT_INTERRUPT
	XTime_PITEnableInterrupt() ;
#elif TIMER_CONNECT_INTC
	XIntc_MasterEnable( INTC_BASEADDR );
	XIntc_SetIntrSvcOption( INTC_BASEADDR, XIN_SVC_ALL_ISRS_OPTION);
	XIntc_EnableIntr( INTC_BASEADDR, PROFILE_TIMER_INTR_MASK );
#endif
	Xil_ExceptionEnableMask( XIL_EXCEPTION_NON_CRITICAL ) ;
#endif
	return 0;
}

#endif	// PROC_PPC



//--------------------------------------------------------------------
// PowerPC440 Target - Timer related functions
//--------------------------------------------------------------------
#ifdef PROC_PPC440


//--------------------------------------------------------------------
// PowerPC DEC Timer Init.
//	Defined only if DEC Timer is used for Profiling
//
//--------------------------------------------------------------------
#ifdef PPC_PIT_INTERRUPT
int ppc_dec_init( void )
{
	// 1. Register Profile_intr_handler as Interrupt handler
	// 2. Set DEC Timer Interrupt and Enable it.
	Xil_ExceptionRegisterHandler( XIL_EXCEPTION_ID_DEC_INT,
			    (Xil_ExceptionHandler)profile_intr_handler,(void *)0);
	XTime_DECSetInterval( timer_clk_ticks ) ;
	XTime_DECEnableAutoReload() ;
	return 0;
}
#endif


//--------------------------------------------------------------------
// PowerPC Timer Initialization functions.
//	For PowerPC, DEC and opb_timer can be used for Profiling. This
//	is selected by the user in standalone BSP
//
//--------------------------------------------------------------------
int powerpc405_init(void)
{
	Xil_ExceptionInit();
	Xil_ExceptionDisableMask( XIL_EXCEPTION_NON_CRITICAL ) ;

	// Initialize the Timer.
	// 1. If PowerPC DEC Timer has to be used, initialize DEC timer.
	// 2. Else use opb_timer. It can be directly connected or thru intc to PowerPC
#ifdef PPC_PIT_INTERRUPT
	ppc_dec_init();
#else
#ifdef TIMER_CONNECT_INTC
	Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_NON_CRITICAL_INT,
				     (Xil_ExceptionHandler)XIntc_DeviceInterruptHandler,(void *)0);

	XIntc_RegisterHandler( INTC_BASEADDR, PROFILE_TIMER_INTR_ID,
			     (XInterruptHandler)profile_intr_handler,(void*)0);
#else
	Xil_ExceptionRegisterHandler( XIL_EXCEPTION_ID_NON_CRITICAL_INT,
			      (Xil_ExceptionHandler)profile_intr_handler,(void *)0);
	Xil_ExceptionRegisterHandler( XIL_EXCEPTION_ID_NON_CRITICAL_INT,
			      (Xil_ExceptionHandler)profile_intr_handler,(void *)0);
#endif
	// Initialize the timer with Timer Ticks
	opb_timer_init() ;
#endif

	// Enable Interrupts in the System, if Profile Timer is the only Interrupt
	// in the System.
#ifdef ENABLE_SYS_INTR
#ifdef PPC_PIT_INTERRUPT
	XTime_DECEnableInterrupt() ;
#elif TIMER_CONNECT_INTC
	XIntc_MasterEnable( INTC_BASEADDR );
	XIntc_SetIntrSvcOption( INTC_BASEADDR, XIN_SVC_ALL_ISRS_OPTION);
	XIntc_EnableIntr( INTC_BASEADDR, PROFILE_TIMER_INTR_MASK );
#endif
	Xil_ExceptionEnableMask( XEXC_NON_CRITICAL ) ;
#endif
	return 0;
}

#endif	// PROC_PPC440

//--------------------------------------------------------------------
// opb_timer Initialization for PowerPC and MicroBlaze. This function
// is not needed if DEC timer is used in PowerPC
//
//--------------------------------------------------------------------
#ifndef PPC_PIT_INTERRUPT
int opb_timer_init( void )
{
	// set the number of cycles the timer counts before interrupting
	XTmrCtr_SetLoadReg(PROFILE_TIMER_BASEADDR, 0, timer_clk_ticks);

	// reset the timers, and clear interrupts
	XTmrCtr_SetControlStatusReg(PROFILE_TIMER_BASEADDR, 0,
				     XTC_CSR_INT_OCCURED_MASK | XTC_CSR_LOAD_MASK );

	// start the timers
	XTmrCtr_SetControlStatusReg(PROFILE_TIMER_BASEADDR, 0, XTC_CSR_ENABLE_TMR_MASK
			     | XTC_CSR_ENABLE_INT_MASK | XTC_CSR_AUTO_RELOAD_MASK | XTC_CSR_DOWN_COUNT_MASK);
	return 0;
}
#endif


//--------------------------------------------------------------------
// MicroBlaze Target - Timer related functions
//--------------------------------------------------------------------
#ifdef PROC_MICROBLAZE

//--------------------------------------------------------------------
// Initialize the Profile Timer for MicroBlaze Target.
//	For MicroBlaze, opb_timer is used. The opb_timer can be directly
//	connected to MicroBlaze or connected through Interrupt Controller.
//
//--------------------------------------------------------------------
int microblaze_init(void)
{
	// Register profile_intr_handler
	// 1. If timer is connected to Interrupt Controller, register the handler
	//    to Interrupt Controllers vector table.
	// 2. If timer is directly connected to MicroBlaze, register the handler
	//    as Interrupt handler
	Xil_ExceptionInit();

#ifdef TIMER_CONNECT_INTC
	XIntc_RegisterHandler( INTC_BASEADDR, PROFILE_TIMER_INTR_ID,
			     (XInterruptHandler)profile_intr_handler,(void*)0);
#else
	Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_INT,
				     (Xil_ExceptionHandler)profile_intr_handler,
				     (void *)0) ;
#endif

	// Initialize the timer with Timer Ticks
	opb_timer_init() ;

	// Enable Interrupts in the System, if Profile Timer is the only Interrupt
	// in the System.
#ifdef ENABLE_SYS_INTR
#ifdef TIMER_CONNECT_INTC
	XIntc_MasterEnable( INTC_BASEADDR );
	XIntc_SetIntrSvcOption( INTC_BASEADDR, XIN_SVC_ALL_ISRS_OPTION);
	XIntc_EnableIntr( INTC_BASEADDR, PROFILE_TIMER_INTR_MASK );
	Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_INT,
				     (Xil_ExceptionHandler)XIntc_DeviceInterruptHandler,(void *)0);
#endif

#endif

	Xil_ExceptionEnable();

	return 0;

}

#endif	// PROC_MICROBLAZE
