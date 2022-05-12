
/*******************************************************************
*
* CAUTION: This file is automatically generated by libgen.
* Version: Xilinx EDK 13.3 EDK_O.76xd
* DO NOT EDIT.
*
* Copyright (c) 1995-2011 Xilinx, Inc.  All rights reserved.

* 
* Description: Driver parameters
*
*******************************************************************/

#define STDIN_BASEADDRESS 0x84000000
#define STDOUT_BASEADDRESS 0x84000000
/* Definitions for driver GPIO */
#define XPAR_XGPIO_NUM_INSTANCES 3

/* Definitions for peripheral DIP_SWITCHES_8BITS */
#define XPAR_DIP_SWITCHES_8BITS_BASEADDR 0x81440000
#define XPAR_DIP_SWITCHES_8BITS_HIGHADDR 0x8144FFFF
#define XPAR_DIP_SWITCHES_8BITS_DEVICE_ID 0
#define XPAR_DIP_SWITCHES_8BITS_INTERRUPT_PRESENT 0
#define XPAR_DIP_SWITCHES_8BITS_IS_DUAL 0


/* Definitions for peripheral LEDS_8BITS */
#define XPAR_LEDS_8BITS_BASEADDR 0x81420000
#define XPAR_LEDS_8BITS_HIGHADDR 0x8142FFFF
#define XPAR_LEDS_8BITS_DEVICE_ID 1
#define XPAR_LEDS_8BITS_INTERRUPT_PRESENT 0
#define XPAR_LEDS_8BITS_IS_DUAL 0


/* Definitions for peripheral PUSH_BUTTONS_5BITS */
#define XPAR_PUSH_BUTTONS_5BITS_BASEADDR 0x81400000
#define XPAR_PUSH_BUTTONS_5BITS_HIGHADDR 0x8140FFFF
#define XPAR_PUSH_BUTTONS_5BITS_DEVICE_ID 2
#define XPAR_PUSH_BUTTONS_5BITS_INTERRUPT_PRESENT 0
#define XPAR_PUSH_BUTTONS_5BITS_IS_DUAL 0


/******************************************************************/


/* Definitions for peripheral DIGILENT_QUADSPI_CNTLR */
#define XPAR_DIGILENT_QUADSPI_CNTLR_BASEADDR 0xCE400000
#define XPAR_DIGILENT_QUADSPI_CNTLR_HIGHADDR 0xCE40FFFF


/******************************************************************/

/* Definitions for driver MPMC */
#define XPAR_XMPMC_NUM_INSTANCES 1

/* Definitions for peripheral MCB_DDR2 */
#define XPAR_MCB_DDR2_DEVICE_ID 0
#define XPAR_MCB_DDR2_MPMC_CTRL_BASEADDR 0xFFFFFFFF
#define XPAR_MCB_DDR2_INCLUDE_ECC_SUPPORT 0
#define XPAR_MCB_DDR2_USE_STATIC_PHY 0
#define XPAR_MCB_DDR2_PM_ENABLE 0
#define XPAR_MCB_DDR2_NUM_PORTS 1
#define XPAR_MCB_DDR2_MEM_DATA_WIDTH 16
#define XPAR_MCB_DDR2_MEM_PART_NUM_BANK_BITS 3
#define XPAR_MCB_DDR2_MEM_PART_NUM_ROW_BITS 13
#define XPAR_MCB_DDR2_MEM_PART_NUM_COL_BITS 10
#define XPAR_MCB_DDR2_MEM_TYPE DDR2
#define XPAR_MCB_DDR2_ECC_SEC_THRESHOLD 1
#define XPAR_MCB_DDR2_ECC_DEC_THRESHOLD 1
#define XPAR_MCB_DDR2_ECC_PEC_THRESHOLD 1
#define XPAR_MCB_DDR2_MEM_DQS_WIDTH 2
#define XPAR_MCB_DDR2_MPMC_CLK0_PERIOD_PS 15000


/******************************************************************/


/* Definitions for peripheral MCB_DDR2 */
#define XPAR_MCB_DDR2_MPMC_BASEADDR 0x48000000
#define XPAR_MCB_DDR2_MPMC_HIGHADDR 0x4FFFFFFF
#define XPAR_MCB_DDR2_BASEADDR_CTRL0 0x000
#define XPAR_MCB_DDR2_HIGHADDR_CTRL0 0x00d
#define XPAR_MCB_DDR2_BASEADDR_CTRL2 0x018
#define XPAR_MCB_DDR2_HIGHADDR_CTRL2 0x025
#define XPAR_MCB_DDR2_BASEADDR_CTRL3 0x026
#define XPAR_MCB_DDR2_HIGHADDR_CTRL3 0x02f
#define XPAR_MCB_DDR2_BASEADDR_CTRL4 0x030
#define XPAR_MCB_DDR2_HIGHADDR_CTRL4 0x03d
#define XPAR_MCB_DDR2_BASEADDR_CTRL5 0x03e
#define XPAR_MCB_DDR2_HIGHADDR_CTRL5 0x047
#define XPAR_MCB_DDR2_BASEADDR_CTRL6 0x048
#define XPAR_MCB_DDR2_HIGHADDR_CTRL6 0x05b
#define XPAR_MCB_DDR2_BASEADDR_CTRL7 0x05c
#define XPAR_MCB_DDR2_HIGHADDR_CTRL7 0x06a
#define XPAR_MCB_DDR2_BASEADDR_CTRL8 0x06b
#define XPAR_MCB_DDR2_HIGHADDR_CTRL8 0x086
#define XPAR_MCB_DDR2_BASEADDR_CTRL9 0x087
#define XPAR_MCB_DDR2_HIGHADDR_CTRL9 0x09d
#define XPAR_MCB_DDR2_BASEADDR_CTRL10 0x09e
#define XPAR_MCB_DDR2_HIGHADDR_CTRL10 0x0a5
#define XPAR_MCB_DDR2_BASEADDR_CTRL11 0x0a6
#define XPAR_MCB_DDR2_HIGHADDR_CTRL11 0x0ad
#define XPAR_MCB_DDR2_BASEADDR_CTRL12 0x0ae
#define XPAR_MCB_DDR2_HIGHADDR_CTRL12 0x0b5
#define XPAR_MCB_DDR2_BASEADDR_CTRL13 0x0b6
#define XPAR_MCB_DDR2_HIGHADDR_CTRL13 0x0bd
#define XPAR_MCB_DDR2_BASEADDR_CTRL14 0x0be
#define XPAR_MCB_DDR2_HIGHADDR_CTRL14 0x0d0
#define XPAR_MCB_DDR2_BASEADDR_CTRL15 0x0d1
#define XPAR_MCB_DDR2_HIGHADDR_CTRL15 0x0d8
#define XPAR_MCB_DDR2_BASEADDR_CTRL16 0x0d9
#define XPAR_MCB_DDR2_HIGHADDR_CTRL16 0x0da


/******************************************************************/

/* Canonical definitions for peripheral MCB_DDR2 */
#define XPAR_MPMC_0_DEVICE_ID XPAR_MCB_DDR2_DEVICE_ID
#define XPAR_MPMC_0_MPMC_BASEADDR 0x48000000
#define XPAR_MPMC_0_MPMC_HIGHADDR 0x4FFFFFFF
#define XPAR_MPMC_0_MPMC_CTRL_BASEADDR 0xFFFFFFFF
#define XPAR_MPMC_0_INCLUDE_ECC_SUPPORT 0
#define XPAR_MPMC_0_USE_STATIC_PHY 0
#define XPAR_MPMC_0_PM_ENABLE 0
#define XPAR_MPMC_0_NUM_PORTS 1
#define XPAR_MPMC_0_MEM_DATA_WIDTH 16
#define XPAR_MPMC_0_MEM_PART_NUM_BANK_BITS 3
#define XPAR_MPMC_0_MEM_PART_NUM_ROW_BITS 13
#define XPAR_MPMC_0_MEM_PART_NUM_COL_BITS 10
#define XPAR_MPMC_0_MEM_TYPE DDR2
#define XPAR_MPMC_0_ECC_SEC_THRESHOLD 1
#define XPAR_MPMC_0_ECC_DEC_THRESHOLD 1
#define XPAR_MPMC_0_ECC_PEC_THRESHOLD 1
#define XPAR_MPMC_0_MEM_DQS_WIDTH 2
#define XPAR_MPMC_0_MPMC_CLK0_PERIOD_PS 15000


/******************************************************************/

/* Definitions for driver PS2 */
#define XPAR_XPS2_NUM_INSTANCES 2

/* Definitions for peripheral PS2_KEYBOARD_MOUSE Device 0 */
#define XPAR_PS2_KEYBOARD_MOUSE_0_DEVICE_ID 0
#define XPAR_PS2_KEYBOARD_MOUSE_0_BASEADDR 0x86a00000
#define XPAR_PS2_KEYBOARD_MOUSE_0_HIGHADDR 0x86A00FFF

/* Canonical definitions for peripheral PS2_KEYBOARD_MOUSE Device 0 */
#define XPAR_PS2_0_DEVICE_ID 0
#define XPAR_PS2_0_BASEADDR 0x86a00000
#define XPAR_PS2_0_HIGHADDR 0x86A00FFF


/* Definitions for peripheral PS2_KEYBOARD_MOUSE Device 1 */
#define XPAR_PS2_KEYBOARD_MOUSE_1_DEVICE_ID 1
#define XPAR_PS2_KEYBOARD_MOUSE_1_BASEADDR 0x86A01000
#define XPAR_PS2_KEYBOARD_MOUSE_1_HIGHADDR 0x86A01FFF

/* Canonical definitions for peripheral PS2_KEYBOARD_MOUSE Device 1 */
#define XPAR_PS2_1_DEVICE_ID 1
#define XPAR_PS2_1_BASEADDR 0x86A01000
#define XPAR_PS2_1_HIGHADDR 0x86A01FFF



/******************************************************************/

/* Definitions for driver UARTLITE */
#define XPAR_XUARTLITE_NUM_INSTANCES 2

/* Definitions for peripheral MDM_0 */
#define XPAR_MDM_0_BASEADDR 0x84400000
#define XPAR_MDM_0_HIGHADDR 0x8440FFFF
#define XPAR_MDM_0_DEVICE_ID 0
#define XPAR_MDM_0_BAUDRATE 0
#define XPAR_MDM_0_USE_PARITY 0
#define XPAR_MDM_0_ODD_PARITY 0
#define XPAR_MDM_0_DATA_BITS 0


/* Definitions for peripheral RS232_UART_1 */
#define XPAR_RS232_UART_1_BASEADDR 0x84000000
#define XPAR_RS232_UART_1_HIGHADDR 0x8400FFFF
#define XPAR_RS232_UART_1_DEVICE_ID 1
#define XPAR_RS232_UART_1_BAUDRATE 115200
#define XPAR_RS232_UART_1_USE_PARITY 0
#define XPAR_RS232_UART_1_ODD_PARITY 0
#define XPAR_RS232_UART_1_DATA_BITS 8


/******************************************************************/

/* Canonical definitions for peripheral MDM_0 */
#define XPAR_UARTLITE_0_DEVICE_ID XPAR_MDM_0_DEVICE_ID
#define XPAR_UARTLITE_0_BASEADDR 0x84400000
#define XPAR_UARTLITE_0_HIGHADDR 0x8440FFFF
#define XPAR_UARTLITE_0_BAUDRATE 0
#define XPAR_UARTLITE_0_USE_PARITY 0
#define XPAR_UARTLITE_0_ODD_PARITY 0
#define XPAR_UARTLITE_0_DATA_BITS 0
#define XPAR_UARTLITE_0_SIO_CHAN -1

/* Canonical definitions for peripheral RS232_UART_1 */
#define XPAR_UARTLITE_1_DEVICE_ID XPAR_RS232_UART_1_DEVICE_ID
#define XPAR_UARTLITE_1_BASEADDR 0x84000000
#define XPAR_UARTLITE_1_HIGHADDR 0x8400FFFF
#define XPAR_UARTLITE_1_BAUDRATE 115200
#define XPAR_UARTLITE_1_USE_PARITY 0
#define XPAR_UARTLITE_1_ODD_PARITY 0
#define XPAR_UARTLITE_1_DATA_BITS 8
#define XPAR_UARTLITE_1_SIO_CHAN 0


/******************************************************************/

/* Definitions for driver BRAM */
#define XPAR_XBRAM_NUM_INSTANCES 2

/* Definitions for peripheral DLMB_CNTLR */
#define XPAR_DLMB_CNTLR_DEVICE_ID 0
#define XPAR_DLMB_CNTLR_DATA_WIDTH 32
#define XPAR_DLMB_CNTLR_ECC 0
#define XPAR_DLMB_CNTLR_FAULT_INJECT 0
#define XPAR_DLMB_CNTLR_CE_FAILING_REGISTERS 0
#define XPAR_DLMB_CNTLR_UE_FAILING_REGISTERS 0
#define XPAR_DLMB_CNTLR_ECC_STATUS_REGISTERS 0
#define XPAR_DLMB_CNTLR_CE_COUNTER_WIDTH 0
#define XPAR_DLMB_CNTLR_ECC_ONOFF_REGISTER 0
#define XPAR_DLMB_CNTLR_ECC_ONOFF_RESET_VALUE 1
#define XPAR_DLMB_CNTLR_WRITE_ACCESS 2
#define XPAR_DLMB_CNTLR_BASEADDR 0x00000000
#define XPAR_DLMB_CNTLR_HIGHADDR 0x00001FFF


/* Definitions for peripheral ILMB_CNTLR */
#define XPAR_ILMB_CNTLR_DEVICE_ID 1
#define XPAR_ILMB_CNTLR_DATA_WIDTH 32
#define XPAR_ILMB_CNTLR_ECC 0
#define XPAR_ILMB_CNTLR_FAULT_INJECT 0
#define XPAR_ILMB_CNTLR_CE_FAILING_REGISTERS 0
#define XPAR_ILMB_CNTLR_UE_FAILING_REGISTERS 0
#define XPAR_ILMB_CNTLR_ECC_STATUS_REGISTERS 0
#define XPAR_ILMB_CNTLR_CE_COUNTER_WIDTH 0
#define XPAR_ILMB_CNTLR_ECC_ONOFF_REGISTER 0
#define XPAR_ILMB_CNTLR_ECC_ONOFF_RESET_VALUE 1
#define XPAR_ILMB_CNTLR_WRITE_ACCESS 2
#define XPAR_ILMB_CNTLR_BASEADDR 0x00000000
#define XPAR_ILMB_CNTLR_HIGHADDR 0x00001FFF


/******************************************************************/

/* Canonical definitions for peripheral DLMB_CNTLR */
#define XPAR_BRAM_0_DEVICE_ID XPAR_DLMB_CNTLR_DEVICE_ID
#define XPAR_BRAM_0_DATA_WIDTH 32
#define XPAR_BRAM_0_ECC 0
#define XPAR_BRAM_0_FAULT_INJECT 0
#define XPAR_BRAM_0_CE_FAILING_REGISTERS 0
#define XPAR_BRAM_0_UE_FAILING_REGISTERS 0
#define XPAR_BRAM_0_ECC_STATUS_REGISTERS 0
#define XPAR_BRAM_0_CE_COUNTER_WIDTH 0
#define XPAR_BRAM_0_ECC_ONOFF_REGISTER 0
#define XPAR_BRAM_0_ECC_ONOFF_RESET_VALUE 1
#define XPAR_BRAM_0_WRITE_ACCESS 2
#define XPAR_BRAM_0_BASEADDR 0x00000000
#define XPAR_BRAM_0_HIGHADDR 0x00001FFF

/* Canonical definitions for peripheral ILMB_CNTLR */
#define XPAR_BRAM_1_DEVICE_ID XPAR_ILMB_CNTLR_DEVICE_ID
#define XPAR_BRAM_1_DATA_WIDTH 32
#define XPAR_BRAM_1_ECC 0
#define XPAR_BRAM_1_FAULT_INJECT 0
#define XPAR_BRAM_1_CE_FAILING_REGISTERS 0
#define XPAR_BRAM_1_UE_FAILING_REGISTERS 0
#define XPAR_BRAM_1_ECC_STATUS_REGISTERS 0
#define XPAR_BRAM_1_CE_COUNTER_WIDTH 0
#define XPAR_BRAM_1_ECC_ONOFF_REGISTER 0
#define XPAR_BRAM_1_ECC_ONOFF_RESET_VALUE 1
#define XPAR_BRAM_1_WRITE_ACCESS 2
#define XPAR_BRAM_1_BASEADDR 0x00000000
#define XPAR_BRAM_1_HIGHADDR 0x00001FFF


/******************************************************************/

#define XPAR_INTC_MAX_NUM_INTR_INPUTS 1
#define XPAR_XINTC_HAS_IPR 1
#define XPAR_XINTC_HAS_SIE 1
#define XPAR_XINTC_HAS_CIE 1
#define XPAR_XINTC_HAS_IVR 1
#define XPAR_XINTC_USE_DCR 0
/* Definitions for driver INTC */
#define XPAR_XINTC_NUM_INSTANCES 1

/* Definitions for peripheral XPS_INTC_0 */
#define XPAR_XPS_INTC_0_DEVICE_ID 0
#define XPAR_XPS_INTC_0_BASEADDR 0x81800000
#define XPAR_XPS_INTC_0_HIGHADDR 0x8180FFFF
#define XPAR_XPS_INTC_0_KIND_OF_INTR 0xFFFFFFFF


/******************************************************************/

#define XPAR_INTC_SINGLE_BASEADDR 0x81800000
#define XPAR_INTC_SINGLE_HIGHADDR 0x8180FFFF
#define XPAR_INTC_SINGLE_DEVICE_ID XPAR_XPS_INTC_0_DEVICE_ID
#define XPAR_XPS_TIMER_0_INTERRUPT_MASK 0X000001
#define XPAR_XPS_INTC_0_XPS_TIMER_0_INTERRUPT_INTR 0

/******************************************************************/

/* Canonical definitions for peripheral XPS_INTC_0 */
#define XPAR_INTC_0_DEVICE_ID XPAR_XPS_INTC_0_DEVICE_ID
#define XPAR_INTC_0_BASEADDR 0x81800000
#define XPAR_INTC_0_HIGHADDR 0x8180FFFF
#define XPAR_INTC_0_KIND_OF_INTR 0xFFFFFFFF

#define XPAR_INTC_0_TMRCTR_0_VEC_ID XPAR_XPS_INTC_0_XPS_TIMER_0_INTERRUPT_INTR

/******************************************************************/

/* Definitions for driver TMRCTR */
#define XPAR_XTMRCTR_NUM_INSTANCES 1

/* Definitions for peripheral XPS_TIMER_0 */
#define XPAR_XPS_TIMER_0_DEVICE_ID 0
#define XPAR_XPS_TIMER_0_BASEADDR 0x83C00000
#define XPAR_XPS_TIMER_0_HIGHADDR 0x83C0FFFF
#define XPAR_XPS_TIMER_0_CLOCK_FREQ_HZ 66666666


/******************************************************************/

/* Canonical definitions for peripheral XPS_TIMER_0 */
#define XPAR_TMRCTR_0_DEVICE_ID XPAR_XPS_TIMER_0_DEVICE_ID
#define XPAR_TMRCTR_0_BASEADDR 0x83C00000
#define XPAR_TMRCTR_0_HIGHADDR 0x83C0FFFF
#define XPAR_TMRCTR_0_CLOCK_FREQ_HZ XPAR_XPS_TIMER_0_CLOCK_FREQ_HZ

/******************************************************************/

/* Definitions for bus frequencies */
#define XPAR_CPU_DPLB_FREQ_HZ 66666666
#define XPAR_CPU_IPLB_FREQ_HZ 66666666
/******************************************************************/

/* Canonical definitions for bus frequencies */
#define XPAR_PROC_BUS_0_FREQ_HZ 66666666
/******************************************************************/

#define XPAR_CPU_CORE_CLOCK_FREQ_HZ 66666666
#define XPAR_MICROBLAZE_CORE_CLOCK_FREQ_HZ 66666666

/******************************************************************/


/* Definitions for peripheral MICROBLAZE_0 */
#define XPAR_MICROBLAZE_0_SCO 0
#define XPAR_MICROBLAZE_0_FREQ 66666666
#define XPAR_MICROBLAZE_0_DATA_SIZE 32
#define XPAR_MICROBLAZE_0_DYNAMIC_BUS_SIZING 1
#define XPAR_MICROBLAZE_0_AVOID_PRIMITIVES 0
#define XPAR_MICROBLAZE_0_FAULT_TOLERANT 0
#define XPAR_MICROBLAZE_0_ECC_USE_CE_EXCEPTION 0
#define XPAR_MICROBLAZE_0_LOCKSTEP_SLAVE 0
#define XPAR_MICROBLAZE_0_ENDIANNESS 0
#define XPAR_MICROBLAZE_0_AREA_OPTIMIZED 0
#define XPAR_MICROBLAZE_0_OPTIMIZATION 0
#define XPAR_MICROBLAZE_0_INTERCONNECT 1
#define XPAR_MICROBLAZE_0_STREAM_INTERCONNECT 0
#define XPAR_MICROBLAZE_0_DPLB_DWIDTH 32
#define XPAR_MICROBLAZE_0_DPLB_NATIVE_DWIDTH 32
#define XPAR_MICROBLAZE_0_DPLB_BURST_EN 0
#define XPAR_MICROBLAZE_0_DPLB_P2P 0
#define XPAR_MICROBLAZE_0_IPLB_DWIDTH 32
#define XPAR_MICROBLAZE_0_IPLB_NATIVE_DWIDTH 32
#define XPAR_MICROBLAZE_0_IPLB_BURST_EN 0
#define XPAR_MICROBLAZE_0_IPLB_P2P 0
#define XPAR_MICROBLAZE_0_M_AXI_DP_SUPPORTS_THREADS 0
#define XPAR_MICROBLAZE_0_M_AXI_DP_THREAD_ID_WIDTH 1
#define XPAR_MICROBLAZE_0_M_AXI_DP_SUPPORTS_READ 1
#define XPAR_MICROBLAZE_0_M_AXI_DP_SUPPORTS_WRITE 1
#define XPAR_MICROBLAZE_0_M_AXI_DP_SUPPORTS_NARROW_BURST 0
#define XPAR_MICROBLAZE_0_M_AXI_DP_DATA_WIDTH 32
#define XPAR_MICROBLAZE_0_M_AXI_DP_ADDR_WIDTH 32
#define XPAR_MICROBLAZE_0_M_AXI_DP_PROTOCOL AXI4LITE
#define XPAR_MICROBLAZE_0_M_AXI_DP_EXCLUSIVE_ACCESS 0
#define XPAR_MICROBLAZE_0_INTERCONNECT_M_AXI_DP_READ_ISSUING 1
#define XPAR_MICROBLAZE_0_INTERCONNECT_M_AXI_DP_WRITE_ISSUING 1
#define XPAR_MICROBLAZE_0_M_AXI_IP_SUPPORTS_THREADS 0
#define XPAR_MICROBLAZE_0_M_AXI_IP_THREAD_ID_WIDTH 1
#define XPAR_MICROBLAZE_0_M_AXI_IP_SUPPORTS_READ 1
#define XPAR_MICROBLAZE_0_M_AXI_IP_SUPPORTS_WRITE 0
#define XPAR_MICROBLAZE_0_M_AXI_IP_SUPPORTS_NARROW_BURST 0
#define XPAR_MICROBLAZE_0_M_AXI_IP_DATA_WIDTH 32
#define XPAR_MICROBLAZE_0_M_AXI_IP_ADDR_WIDTH 32
#define XPAR_MICROBLAZE_0_M_AXI_IP_PROTOCOL AXI4LITE
#define XPAR_MICROBLAZE_0_INTERCONNECT_M_AXI_IP_READ_ISSUING 1
#define XPAR_MICROBLAZE_0_D_AXI 0
#define XPAR_MICROBLAZE_0_D_PLB 1
#define XPAR_MICROBLAZE_0_D_LMB 1
#define XPAR_MICROBLAZE_0_I_AXI 0
#define XPAR_MICROBLAZE_0_I_PLB 1
#define XPAR_MICROBLAZE_0_I_LMB 1
#define XPAR_MICROBLAZE_0_USE_MSR_INSTR 1
#define XPAR_MICROBLAZE_0_USE_PCMP_INSTR 1
#define XPAR_MICROBLAZE_0_USE_BARREL 1
#define XPAR_MICROBLAZE_0_USE_DIV 1
#define XPAR_MICROBLAZE_0_USE_HW_MUL 2
#define XPAR_MICROBLAZE_0_USE_FPU 2
#define XPAR_MICROBLAZE_0_UNALIGNED_EXCEPTIONS 0
#define XPAR_MICROBLAZE_0_ILL_OPCODE_EXCEPTION 0
#define XPAR_MICROBLAZE_0_M_AXI_I_BUS_EXCEPTION 0
#define XPAR_MICROBLAZE_0_M_AXI_D_BUS_EXCEPTION 0
#define XPAR_MICROBLAZE_0_IPLB_BUS_EXCEPTION 0
#define XPAR_MICROBLAZE_0_DPLB_BUS_EXCEPTION 0
#define XPAR_MICROBLAZE_0_DIV_ZERO_EXCEPTION 0
#define XPAR_MICROBLAZE_0_FPU_EXCEPTION 0
#define XPAR_MICROBLAZE_0_FSL_EXCEPTION 0
#define XPAR_MICROBLAZE_0_USE_STACK_PROTECTION 0
#define XPAR_MICROBLAZE_0_PVR 0
#define XPAR_MICROBLAZE_0_PVR_USER1 0x00
#define XPAR_MICROBLAZE_0_PVR_USER2 0x00000000
#define XPAR_MICROBLAZE_0_DEBUG_ENABLED 1
#define XPAR_MICROBLAZE_0_NUMBER_OF_PC_BRK 1
#define XPAR_MICROBLAZE_0_NUMBER_OF_RD_ADDR_BRK 0
#define XPAR_MICROBLAZE_0_NUMBER_OF_WR_ADDR_BRK 0
#define XPAR_MICROBLAZE_0_INTERRUPT_IS_EDGE 0
#define XPAR_MICROBLAZE_0_EDGE_IS_POSITIVE 1
#define XPAR_MICROBLAZE_0_RESET_MSR 0x00000000
#define XPAR_MICROBLAZE_0_OPCODE_0X0_ILLEGAL 0
#define XPAR_MICROBLAZE_0_FSL_LINKS 0
#define XPAR_MICROBLAZE_0_FSL_DATA_SIZE 32
#define XPAR_MICROBLAZE_0_USE_EXTENDED_FSL_INSTR 0
#define XPAR_MICROBLAZE_0_M0_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_0_S0_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_0_M1_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_0_S1_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_0_M2_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_0_S2_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_0_M3_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_0_S3_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_0_M4_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_0_S4_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_0_M5_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_0_S5_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_0_M6_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_0_S6_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_0_M7_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_0_S7_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_0_M8_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_0_S8_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_0_M9_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_0_S9_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_0_M10_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_0_S10_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_0_M11_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_0_S11_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_0_M12_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_0_S12_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_0_M13_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_0_S13_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_0_M14_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_0_S14_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_0_M15_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_0_S15_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_0_M0_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_0_S0_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_0_M1_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_0_S1_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_0_M2_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_0_S2_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_0_M3_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_0_S3_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_0_M4_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_0_S4_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_0_M5_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_0_S5_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_0_M6_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_0_S6_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_0_M7_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_0_S7_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_0_M8_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_0_S8_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_0_M9_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_0_S9_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_0_M10_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_0_S10_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_0_M11_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_0_S11_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_0_M12_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_0_S12_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_0_M13_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_0_S13_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_0_M14_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_0_S14_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_0_M15_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_0_S15_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_0_ICACHE_BASEADDR 0x48000000
#define XPAR_MICROBLAZE_0_ICACHE_HIGHADDR 0x4FFFFFFF
#define XPAR_MICROBLAZE_0_USE_ICACHE 1
#define XPAR_MICROBLAZE_0_ALLOW_ICACHE_WR 1
#define XPAR_MICROBLAZE_0_ADDR_TAG_BITS 13
#define XPAR_MICROBLAZE_0_CACHE_BYTE_SIZE 16384
#define XPAR_MICROBLAZE_0_ICACHE_USE_FSL 1
#define XPAR_MICROBLAZE_0_ICACHE_LINE_LEN 4
#define XPAR_MICROBLAZE_0_ICACHE_ALWAYS_USED 1
#define XPAR_MICROBLAZE_0_ICACHE_INTERFACE 0
#define XPAR_MICROBLAZE_0_ICACHE_VICTIMS 0
#define XPAR_MICROBLAZE_0_ICACHE_STREAMS 0
#define XPAR_MICROBLAZE_0_ICACHE_FORCE_TAG_LUTRAM 0
#define XPAR_MICROBLAZE_0_ICACHE_DATA_WIDTH 0
#define XPAR_MICROBLAZE_0_M_AXI_IC_SUPPORTS_THREADS 0
#define XPAR_MICROBLAZE_0_M_AXI_IC_THREAD_ID_WIDTH 1
#define XPAR_MICROBLAZE_0_M_AXI_IC_SUPPORTS_READ 1
#define XPAR_MICROBLAZE_0_M_AXI_IC_SUPPORTS_WRITE 0
#define XPAR_MICROBLAZE_0_M_AXI_IC_SUPPORTS_NARROW_BURST 0
#define XPAR_MICROBLAZE_0_M_AXI_IC_DATA_WIDTH 32
#define XPAR_MICROBLAZE_0_M_AXI_IC_ADDR_WIDTH 32
#define XPAR_MICROBLAZE_0_M_AXI_IC_PROTOCOL AXI4
#define XPAR_MICROBLAZE_0_M_AXI_IC_USER_VALUE 0b11111
#define XPAR_MICROBLAZE_0_M_AXI_IC_SUPPORTS_USER_SIGNALS 1
#define XPAR_MICROBLAZE_0_M_AXI_IC_AWUSER_WIDTH 5
#define XPAR_MICROBLAZE_0_M_AXI_IC_ARUSER_WIDTH 5
#define XPAR_MICROBLAZE_0_M_AXI_IC_WUSER_WIDTH 1
#define XPAR_MICROBLAZE_0_M_AXI_IC_RUSER_WIDTH 1
#define XPAR_MICROBLAZE_0_M_AXI_IC_BUSER_WIDTH 1
#define XPAR_MICROBLAZE_0_INTERCONNECT_M_AXI_IC_READ_ISSUING 2
#define XPAR_MICROBLAZE_0_DCACHE_BASEADDR 0x48000000
#define XPAR_MICROBLAZE_0_DCACHE_HIGHADDR 0x4FFFFFFF
#define XPAR_MICROBLAZE_0_USE_DCACHE 1
#define XPAR_MICROBLAZE_0_ALLOW_DCACHE_WR 1
#define XPAR_MICROBLAZE_0_DCACHE_ADDR_TAG 13
#define XPAR_MICROBLAZE_0_DCACHE_BYTE_SIZE 16384
#define XPAR_MICROBLAZE_0_DCACHE_USE_FSL 1
#define XPAR_MICROBLAZE_0_DCACHE_LINE_LEN 4
#define XPAR_MICROBLAZE_0_DCACHE_ALWAYS_USED 1
#define XPAR_MICROBLAZE_0_DCACHE_INTERFACE 0
#define XPAR_MICROBLAZE_0_DCACHE_USE_WRITEBACK 0
#define XPAR_MICROBLAZE_0_DCACHE_VICTIMS 0
#define XPAR_MICROBLAZE_0_DCACHE_FORCE_TAG_LUTRAM 0
#define XPAR_MICROBLAZE_0_DCACHE_DATA_WIDTH 0
#define XPAR_MICROBLAZE_0_M_AXI_DC_SUPPORTS_THREADS 0
#define XPAR_MICROBLAZE_0_M_AXI_DC_THREAD_ID_WIDTH 1
#define XPAR_MICROBLAZE_0_M_AXI_DC_SUPPORTS_READ 1
#define XPAR_MICROBLAZE_0_M_AXI_DC_SUPPORTS_WRITE 1
#define XPAR_MICROBLAZE_0_M_AXI_DC_SUPPORTS_NARROW_BURST 0
#define XPAR_MICROBLAZE_0_M_AXI_DC_DATA_WIDTH 32
#define XPAR_MICROBLAZE_0_M_AXI_DC_ADDR_WIDTH 32
#define XPAR_MICROBLAZE_0_M_AXI_DC_PROTOCOL AXI4
#define XPAR_MICROBLAZE_0_M_AXI_DC_EXCLUSIVE_ACCESS 0
#define XPAR_MICROBLAZE_0_M_AXI_DC_USER_VALUE 0b11111
#define XPAR_MICROBLAZE_0_M_AXI_DC_SUPPORTS_USER_SIGNALS 1
#define XPAR_MICROBLAZE_0_M_AXI_DC_AWUSER_WIDTH 5
#define XPAR_MICROBLAZE_0_M_AXI_DC_ARUSER_WIDTH 5
#define XPAR_MICROBLAZE_0_M_AXI_DC_WUSER_WIDTH 1
#define XPAR_MICROBLAZE_0_M_AXI_DC_RUSER_WIDTH 1
#define XPAR_MICROBLAZE_0_M_AXI_DC_BUSER_WIDTH 1
#define XPAR_MICROBLAZE_0_INTERCONNECT_M_AXI_DC_READ_ISSUING 2
#define XPAR_MICROBLAZE_0_INTERCONNECT_M_AXI_DC_WRITE_ISSUING 32
#define XPAR_MICROBLAZE_0_USE_MMU 0
#define XPAR_MICROBLAZE_0_MMU_DTLB_SIZE 4
#define XPAR_MICROBLAZE_0_MMU_ITLB_SIZE 2
#define XPAR_MICROBLAZE_0_MMU_TLB_ACCESS 3
#define XPAR_MICROBLAZE_0_MMU_ZONES 16
#define XPAR_MICROBLAZE_0_MMU_PRIVILEGED_INSTR 0
#define XPAR_MICROBLAZE_0_USE_INTERRUPT 1
#define XPAR_MICROBLAZE_0_USE_EXT_BRK 1
#define XPAR_MICROBLAZE_0_USE_EXT_NM_BRK 1
#define XPAR_MICROBLAZE_0_USE_BRANCH_TARGET_CACHE 1
#define XPAR_MICROBLAZE_0_BRANCH_TARGET_CACHE_SIZE 0

/******************************************************************/

#define XPAR_CPU_ID 0
#define XPAR_MICROBLAZE_ID 0
#define XPAR_MICROBLAZE_SCO 0
#define XPAR_MICROBLAZE_FREQ 66666666
#define XPAR_MICROBLAZE_DATA_SIZE 32
#define XPAR_MICROBLAZE_DYNAMIC_BUS_SIZING 1
#define XPAR_MICROBLAZE_AVOID_PRIMITIVES 0
#define XPAR_MICROBLAZE_FAULT_TOLERANT 0
#define XPAR_MICROBLAZE_ECC_USE_CE_EXCEPTION 0
#define XPAR_MICROBLAZE_LOCKSTEP_SLAVE 0
#define XPAR_MICROBLAZE_ENDIANNESS 0
#define XPAR_MICROBLAZE_AREA_OPTIMIZED 0
#define XPAR_MICROBLAZE_OPTIMIZATION 0
#define XPAR_MICROBLAZE_INTERCONNECT 1
#define XPAR_MICROBLAZE_STREAM_INTERCONNECT 0
#define XPAR_MICROBLAZE_DPLB_DWIDTH 32
#define XPAR_MICROBLAZE_DPLB_NATIVE_DWIDTH 32
#define XPAR_MICROBLAZE_DPLB_BURST_EN 0
#define XPAR_MICROBLAZE_DPLB_P2P 0
#define XPAR_MICROBLAZE_IPLB_DWIDTH 32
#define XPAR_MICROBLAZE_IPLB_NATIVE_DWIDTH 32
#define XPAR_MICROBLAZE_IPLB_BURST_EN 0
#define XPAR_MICROBLAZE_IPLB_P2P 0
#define XPAR_MICROBLAZE_M_AXI_DP_SUPPORTS_THREADS 0
#define XPAR_MICROBLAZE_M_AXI_DP_THREAD_ID_WIDTH 1
#define XPAR_MICROBLAZE_M_AXI_DP_SUPPORTS_READ 1
#define XPAR_MICROBLAZE_M_AXI_DP_SUPPORTS_WRITE 1
#define XPAR_MICROBLAZE_M_AXI_DP_SUPPORTS_NARROW_BURST 0
#define XPAR_MICROBLAZE_M_AXI_DP_DATA_WIDTH 32
#define XPAR_MICROBLAZE_M_AXI_DP_ADDR_WIDTH 32
#define XPAR_MICROBLAZE_M_AXI_DP_PROTOCOL AXI4LITE
#define XPAR_MICROBLAZE_M_AXI_DP_EXCLUSIVE_ACCESS 0
#define XPAR_MICROBLAZE_INTERCONNECT_M_AXI_DP_READ_ISSUING 1
#define XPAR_MICROBLAZE_INTERCONNECT_M_AXI_DP_WRITE_ISSUING 1
#define XPAR_MICROBLAZE_M_AXI_IP_SUPPORTS_THREADS 0
#define XPAR_MICROBLAZE_M_AXI_IP_THREAD_ID_WIDTH 1
#define XPAR_MICROBLAZE_M_AXI_IP_SUPPORTS_READ 1
#define XPAR_MICROBLAZE_M_AXI_IP_SUPPORTS_WRITE 0
#define XPAR_MICROBLAZE_M_AXI_IP_SUPPORTS_NARROW_BURST 0
#define XPAR_MICROBLAZE_M_AXI_IP_DATA_WIDTH 32
#define XPAR_MICROBLAZE_M_AXI_IP_ADDR_WIDTH 32
#define XPAR_MICROBLAZE_M_AXI_IP_PROTOCOL AXI4LITE
#define XPAR_MICROBLAZE_INTERCONNECT_M_AXI_IP_READ_ISSUING 1
#define XPAR_MICROBLAZE_D_AXI 0
#define XPAR_MICROBLAZE_D_PLB 1
#define XPAR_MICROBLAZE_D_LMB 1
#define XPAR_MICROBLAZE_I_AXI 0
#define XPAR_MICROBLAZE_I_PLB 1
#define XPAR_MICROBLAZE_I_LMB 1
#define XPAR_MICROBLAZE_USE_MSR_INSTR 1
#define XPAR_MICROBLAZE_USE_PCMP_INSTR 1
#define XPAR_MICROBLAZE_USE_BARREL 1
#define XPAR_MICROBLAZE_USE_DIV 1
#define XPAR_MICROBLAZE_USE_HW_MUL 2
#define XPAR_MICROBLAZE_USE_FPU 2
#define XPAR_MICROBLAZE_UNALIGNED_EXCEPTIONS 0
#define XPAR_MICROBLAZE_ILL_OPCODE_EXCEPTION 0
#define XPAR_MICROBLAZE_M_AXI_I_BUS_EXCEPTION 0
#define XPAR_MICROBLAZE_M_AXI_D_BUS_EXCEPTION 0
#define XPAR_MICROBLAZE_IPLB_BUS_EXCEPTION 0
#define XPAR_MICROBLAZE_DPLB_BUS_EXCEPTION 0
#define XPAR_MICROBLAZE_DIV_ZERO_EXCEPTION 0
#define XPAR_MICROBLAZE_FPU_EXCEPTION 0
#define XPAR_MICROBLAZE_FSL_EXCEPTION 0
#define XPAR_MICROBLAZE_USE_STACK_PROTECTION 0
#define XPAR_MICROBLAZE_PVR 0
#define XPAR_MICROBLAZE_PVR_USER1 0x00
#define XPAR_MICROBLAZE_PVR_USER2 0x00000000
#define XPAR_MICROBLAZE_DEBUG_ENABLED 1
#define XPAR_MICROBLAZE_NUMBER_OF_PC_BRK 1
#define XPAR_MICROBLAZE_NUMBER_OF_RD_ADDR_BRK 0
#define XPAR_MICROBLAZE_NUMBER_OF_WR_ADDR_BRK 0
#define XPAR_MICROBLAZE_INTERRUPT_IS_EDGE 0
#define XPAR_MICROBLAZE_EDGE_IS_POSITIVE 1
#define XPAR_MICROBLAZE_RESET_MSR 0x00000000
#define XPAR_MICROBLAZE_OPCODE_0X0_ILLEGAL 0
#define XPAR_MICROBLAZE_FSL_LINKS 0
#define XPAR_MICROBLAZE_FSL_DATA_SIZE 32
#define XPAR_MICROBLAZE_USE_EXTENDED_FSL_INSTR 0
#define XPAR_MICROBLAZE_M0_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_S0_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_M1_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_S1_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_M2_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_S2_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_M3_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_S3_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_M4_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_S4_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_M5_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_S5_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_M6_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_S6_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_M7_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_S7_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_M8_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_S8_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_M9_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_S9_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_M10_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_S10_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_M11_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_S11_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_M12_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_S12_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_M13_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_S13_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_M14_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_S14_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_M15_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_S15_AXIS_PROTOCOL GENERIC
#define XPAR_MICROBLAZE_M0_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_S0_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_M1_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_S1_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_M2_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_S2_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_M3_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_S3_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_M4_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_S4_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_M5_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_S5_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_M6_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_S6_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_M7_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_S7_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_M8_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_S8_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_M9_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_S9_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_M10_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_S10_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_M11_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_S11_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_M12_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_S12_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_M13_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_S13_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_M14_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_S14_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_M15_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_S15_AXIS_DATA_WIDTH 32
#define XPAR_MICROBLAZE_ICACHE_BASEADDR 0x48000000
#define XPAR_MICROBLAZE_ICACHE_HIGHADDR 0x4FFFFFFF
#define XPAR_MICROBLAZE_USE_ICACHE 1
#define XPAR_MICROBLAZE_ALLOW_ICACHE_WR 1
#define XPAR_MICROBLAZE_ADDR_TAG_BITS 13
#define XPAR_MICROBLAZE_CACHE_BYTE_SIZE 16384
#define XPAR_MICROBLAZE_ICACHE_USE_FSL 1
#define XPAR_MICROBLAZE_ICACHE_LINE_LEN 4
#define XPAR_MICROBLAZE_ICACHE_ALWAYS_USED 1
#define XPAR_MICROBLAZE_ICACHE_INTERFACE 0
#define XPAR_MICROBLAZE_ICACHE_VICTIMS 0
#define XPAR_MICROBLAZE_ICACHE_STREAMS 0
#define XPAR_MICROBLAZE_ICACHE_FORCE_TAG_LUTRAM 0
#define XPAR_MICROBLAZE_ICACHE_DATA_WIDTH 0
#define XPAR_MICROBLAZE_M_AXI_IC_SUPPORTS_THREADS 0
#define XPAR_MICROBLAZE_M_AXI_IC_THREAD_ID_WIDTH 1
#define XPAR_MICROBLAZE_M_AXI_IC_SUPPORTS_READ 1
#define XPAR_MICROBLAZE_M_AXI_IC_SUPPORTS_WRITE 0
#define XPAR_MICROBLAZE_M_AXI_IC_SUPPORTS_NARROW_BURST 0
#define XPAR_MICROBLAZE_M_AXI_IC_DATA_WIDTH 32
#define XPAR_MICROBLAZE_M_AXI_IC_ADDR_WIDTH 32
#define XPAR_MICROBLAZE_M_AXI_IC_PROTOCOL AXI4
#define XPAR_MICROBLAZE_M_AXI_IC_USER_VALUE 0b11111
#define XPAR_MICROBLAZE_M_AXI_IC_SUPPORTS_USER_SIGNALS 1
#define XPAR_MICROBLAZE_M_AXI_IC_AWUSER_WIDTH 5
#define XPAR_MICROBLAZE_M_AXI_IC_ARUSER_WIDTH 5
#define XPAR_MICROBLAZE_M_AXI_IC_WUSER_WIDTH 1
#define XPAR_MICROBLAZE_M_AXI_IC_RUSER_WIDTH 1
#define XPAR_MICROBLAZE_M_AXI_IC_BUSER_WIDTH 1
#define XPAR_MICROBLAZE_INTERCONNECT_M_AXI_IC_READ_ISSUING 2
#define XPAR_MICROBLAZE_DCACHE_BASEADDR 0x48000000
#define XPAR_MICROBLAZE_DCACHE_HIGHADDR 0x4FFFFFFF
#define XPAR_MICROBLAZE_USE_DCACHE 1
#define XPAR_MICROBLAZE_ALLOW_DCACHE_WR 1
#define XPAR_MICROBLAZE_DCACHE_ADDR_TAG 13
#define XPAR_MICROBLAZE_DCACHE_BYTE_SIZE 16384
#define XPAR_MICROBLAZE_DCACHE_USE_FSL 1
#define XPAR_MICROBLAZE_DCACHE_LINE_LEN 4
#define XPAR_MICROBLAZE_DCACHE_ALWAYS_USED 1
#define XPAR_MICROBLAZE_DCACHE_INTERFACE 0
#define XPAR_MICROBLAZE_DCACHE_USE_WRITEBACK 0
#define XPAR_MICROBLAZE_DCACHE_VICTIMS 0
#define XPAR_MICROBLAZE_DCACHE_FORCE_TAG_LUTRAM 0
#define XPAR_MICROBLAZE_DCACHE_DATA_WIDTH 0
#define XPAR_MICROBLAZE_M_AXI_DC_SUPPORTS_THREADS 0
#define XPAR_MICROBLAZE_M_AXI_DC_THREAD_ID_WIDTH 1
#define XPAR_MICROBLAZE_M_AXI_DC_SUPPORTS_READ 1
#define XPAR_MICROBLAZE_M_AXI_DC_SUPPORTS_WRITE 1
#define XPAR_MICROBLAZE_M_AXI_DC_SUPPORTS_NARROW_BURST 0
#define XPAR_MICROBLAZE_M_AXI_DC_DATA_WIDTH 32
#define XPAR_MICROBLAZE_M_AXI_DC_ADDR_WIDTH 32
#define XPAR_MICROBLAZE_M_AXI_DC_PROTOCOL AXI4
#define XPAR_MICROBLAZE_M_AXI_DC_EXCLUSIVE_ACCESS 0
#define XPAR_MICROBLAZE_M_AXI_DC_USER_VALUE 0b11111
#define XPAR_MICROBLAZE_M_AXI_DC_SUPPORTS_USER_SIGNALS 1
#define XPAR_MICROBLAZE_M_AXI_DC_AWUSER_WIDTH 5
#define XPAR_MICROBLAZE_M_AXI_DC_ARUSER_WIDTH 5
#define XPAR_MICROBLAZE_M_AXI_DC_WUSER_WIDTH 1
#define XPAR_MICROBLAZE_M_AXI_DC_RUSER_WIDTH 1
#define XPAR_MICROBLAZE_M_AXI_DC_BUSER_WIDTH 1
#define XPAR_MICROBLAZE_INTERCONNECT_M_AXI_DC_READ_ISSUING 2
#define XPAR_MICROBLAZE_INTERCONNECT_M_AXI_DC_WRITE_ISSUING 32
#define XPAR_MICROBLAZE_USE_MMU 0
#define XPAR_MICROBLAZE_MMU_DTLB_SIZE 4
#define XPAR_MICROBLAZE_MMU_ITLB_SIZE 2
#define XPAR_MICROBLAZE_MMU_TLB_ACCESS 3
#define XPAR_MICROBLAZE_MMU_ZONES 16
#define XPAR_MICROBLAZE_MMU_PRIVILEGED_INSTR 0
#define XPAR_MICROBLAZE_USE_INTERRUPT 1
#define XPAR_MICROBLAZE_USE_EXT_BRK 1
#define XPAR_MICROBLAZE_USE_EXT_NM_BRK 1
#define XPAR_MICROBLAZE_USE_BRANCH_TARGET_CACHE 1
#define XPAR_MICROBLAZE_BRANCH_TARGET_CACHE_SIZE 0
#define XPAR_MICROBLAZE_HW_VER "8.20.a"

/******************************************************************/
