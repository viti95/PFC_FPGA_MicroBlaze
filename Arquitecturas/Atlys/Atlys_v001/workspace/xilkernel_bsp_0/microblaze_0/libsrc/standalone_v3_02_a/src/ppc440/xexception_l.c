/* $Id: xexception_l.c,v 1.1.2.1 2011/01/20 04:20:41 sadanan Exp $ */
/*****************************************************************************
*
* Copyright (c) 2004 Xilinx, Inc.  All rights reserved. 
* 
* Xilinx, Inc. 
* XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS" AS A 
* COURTESY TO YOU.  BY PROVIDING THIS DESIGN, CODE, OR INFORMATION AS 
* ONE POSSIBLE   IMPLEMENTATION OF THIS FEATURE, APPLICATION OR 
* STANDARD, XILINX IS MAKING NO REPRESENTATION THAT THIS IMPLEMENTATION 
* IS FREE FROM ANY CLAIMS OF INFRINGEMENT, AND YOU ARE RESPONSIBLE 
* FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE FOR YOUR IMPLEMENTATION. 
* XILINX EXPRESSLY DISCLAIMS ANY WARRANTY WHATSOEVER WITH RESPECT TO 
* THE ADEQUACY OF THE IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO 
* ANY WARRANTIES OR REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE 
* FROM CLAIMS OF INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY 
* AND FITNESS FOR A PARTICULAR PURPOSE.
*
*****************************************************************************/
/****************************************************************************/
/**
*
* @file xexception_l.c
*
* This file contains low-level driver functions for the PowerPC exception
* handler.
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver   Who  Date     Changes
* ----- ---- -------- -----------------------------------------------
* 1.00a ch   06/18/02 First release
* </pre>
*
*****************************************************************************/

/***************************** Include Files ********************************/

#include "xbasic_types.h"
#include "xexception_l.h"
#include "xpseudo_asm.h"

/************************** Constant Definitions ****************************/

/**************************** Type Definitions ******************************/

/***************** Macros (Inline Functions) Definitions ********************/

/************************** Function Prototypes *****************************/

/************************** Variable Definitions *****************************/

/*
 * Exception vector table to store handlers for each exception vector.
 */
XExc_VectorTableEntry XExc_VectorTable[XEXC_ID_LAST + 1];

/*****************************************************************************/

/****************************************************************************/
/**
*
* This function is a stub handler that is the default handler that gets called
* if the application has not setup a handler for a specific  exception. The 
* function interface has to match the interface specified for a handler even 
* though none of the arguments are used.
*
* @param    DataPtr is unused by this function.
*
* @return
*
* None.
*
* @note
*
* None.
*
*****************************************************************************/
static void NullHandler(void *DataPtr)
{
}

/****************************************************************************/
/**
*
* Initialize exception handling for the PowerPC. The exception vector table
* is setup with the stub handler for all exceptions.
*
* @param    None.
*
* @return   None.
*
* @note     
*
* None.
*
*****************************************************************************/
void XExc_Init(void)
{
   unsigned short index;
   void (*vectorbase)() = (void (*)()) _vectorbase;
   /*
    * Store the offset of the beginning of the exception handling code
    * (xvectors.S) in the IVPR register (Interrupt Vector Prefix Register).
    * Also uses inline assembly defined in "xpseudo_asm.h".
    */
   mtivpr(vectorbase);

   /* 
    * Initialize interrupt vector offset registers to vectorbase + 0x10, 0x20, 
    * ... 0xf0. Each offset is 16 bytes apart.
    */
   mtivor0(vectorbase);
   mtivor1(vectorbase + 0x10);
   mtivor2(vectorbase + 0x20);
   mtivor3(vectorbase + 0x30);
   mtivor4(vectorbase + 0x40);
   mtivor5(vectorbase + 0x50);
   mtivor6(vectorbase + 0x60);
   mtivor7(vectorbase + 0x70);
   mtivor8(vectorbase + 0x80);
   mtivor9(vectorbase + 0x90);
   mtivor10(vectorbase + 0xa0);
   mtivor11(vectorbase + 0xb0);
   mtivor12(vectorbase + 0xc0);
   mtivor13(vectorbase + 0xd0);
   mtivor14(vectorbase + 0xe0);
   mtivor15(vectorbase + 0xf0);

   /*
    * Initialize the vector table. Register the stub handler for each exception
    * Initialize the IVOR registers
    */
   for(index = XEXC_ID_FIRST; index <= XEXC_ID_LAST; index++)
   {
      XExc_RegisterHandler(index, (XExceptionHandler)NullHandler, XNULL);
   }
}

/*****************************************************************************/
/**
*
* Makes the connection between the Id of the exception source and the
* associated handler that is to run when the exception is recognized. The
* argument provided in this call as the DataPtr is used as the argument
* for the handler when it is called.
*
* @param    Exception Id contains the ID of the exception source and should 
*           be in the range of 0 to XEXC_ID_LAST. See xexception_l.h for
            further information.
* @param    Handler to the handler for that exception.
* @param    DataPtr is a reference to data that will be passed to the handler
*           when it gets called.*

* @return   None.
*
* @note
*
* None.
*
****************************************************************************/
void XExc_RegisterHandler(Xuint8 ExceptionId, XExceptionHandler Handler,
                          void *DataPtr)
{
   XExc_VectorTable[ExceptionId].Handler = Handler;
   XExc_VectorTable[ExceptionId].DataPtr = DataPtr;
   XExc_VectorTable[ExceptionId].ReadOnlySDA = (void *)mfgpr(XREG_GPR2);
   XExc_VectorTable[ExceptionId].ReadWriteSDA = (void *)mfgpr(XREG_GPR13);
}

/*****************************************************************************/
/**
*
* Removes the handler for a specific exception Id. The stub handler is then
* registered for this exception Id.
*
* @param    Exception Id contains the ID of the exception source and should 
*           be in the range of 0 to XEXC_ID_LAST. See xexception_l.h for
            further information.

* @return   None.
*
* @note
*
* None.
*
****************************************************************************/
void XExc_RemoveHandler(Xuint8 ExceptionId)
{
   XExc_RegisterHandler(ExceptionId, (XExceptionHandler)NullHandler, XNULL);
}
