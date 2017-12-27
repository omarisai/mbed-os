 /*
 *  @file: startup_MKL28Z7.s
 *
 *   Created on: Dec 24, 2017
 *      @Author: omarisai_p@hotmail.com
 *     @version: 1.0 
 *        @date: 2017-12-26
 *  Abstract:
 *
 *      For GCC for ARM Embedded Processors
 *
 */
 
    .syntax unified
    .arch armv6-m

    .section .isr_vector, "a"
    .align 2
    .globl __isr_vector
__isr_vector:
    .long   __StackTop                         /* Top of Stack */
    .long   Reset_Handler                      /* Reset Handler */
    .long   NMI_Handler                        /* NMI Handler*/
    .long   HardFault_Handler                  /* Hard Fault Handler*/
    .long   0                                  /* Reserved*/
    .long   0                                  /* Reserved*/
    .long   0                                  /* Reserved*/
    .long   0                                  /* Reserved*/
    .long   0                                  /* Reserved*/
    .long   0                                  /* Reserved*/
    .long   0                                  /* Reserved*/
    .long   SVC_Handler                        /* SVCall Handler*/
    .long   0                                  /* Reserved*/
    .long   0                                  /* Reserved*/
    .long   PendSV_Handler                     /* PendSV Handler*/
    .long   SysTick_Handler                    /* SysTick Handler*/

                                               /* External Interrupts*/
    .long   DMA0_04_IRQHandler                 /* DMA channel 0 or 4 transfer complete*/
    .long   DMA0_15_IRQHandler                 /* DMA channel 1 or 5 transfer complete*/
    .long   DMA0_26_IRQHandler                 /* DMA channel 2 or 6 transfer complete*/
    .long   DMA0_37_IRQHandler                 /* DMA channel 3 ot 7 transfer complete*/
    .long   CTI0_DMA0_Error_IRQHandler         /* Cross Trigger Interface or DMA channel errors*/
    .long   FLEXIO0_IRQHandler                 /* Flexible IO*/
    .long   TPM0_IRQHandler                    /* TPM0 single interrupt vector for all sources*/
    .long   TPM1_IRQHandler                    /* TPM1 single interrupt vector for all sources*/
    .long   TPM2_IRQHandler                    /* TPM2 single interrupt vector for all sources*/
    .long   LPIT0_IRQHandler                   /* LPIT interrupt*/
    .long   LSPI0_IRQHandler                   /* LSPI0 single interrupt vector for all sources*/
    .long   LSPI1_IRQHandler                   /* LSPI1 single interrupt vector for all sources*/
    .long   LPUART0_IRQHandler                 /* LPUART0 status and error*/
    .long   LPUART1_IRQHandler                 /* LPUART1 status and error*/
    .long   LI2C0_IRQHandler                   /* LI2C0 interrupt*/
    .long   LI2C1_IRQHandler                   /* LI2C1 interrupt*/
    .long   0                                  /* Reserved*/
    .long   PORTA_IRQHandler                   /* PORTA Pin detect*/
    .long   PORTB_IRQHandler                   /* PORTB Pin detect*/
    .long   PORTC_IRQHandler                   /* PORTC Pin detect*/
    .long   PORTD_IRQHandler                   /* PORTD Pin detect*/
    .long   PORTE_IRQHandler                   /* PORTE Pin detect*/
    .long   LLWU0_IRQHandler                   /* Low leakage wakeup*/
    .long   I2S0_IRQHandler                    /* Serial Audio Interface*/
    .long   USB0_IRQHandler                    /* USB0 interrupt*/
    .long   ADC0_IRQHandler                    /* ADC0 interrupt*/
    .long   LPTMR0_IRQHandler                  /* LPTMR0 interrupt*/
    .long   RTC_Seconds_IRQHandler             /* RTC seconds*/
    .long   INTMUX0_IRQHandler                 /* INTMUX0 interrupt*/
    .long   INTMUX1_IRQHandler                 /* INTMUX1 interrupt*/
    .long   INTMUX2_IRQHandler                 /* INTMUX2 interrupt*/
    .long   INTMUX3_IRQHandler                 /* INTMUX3 interrupt*/

    .size    __isr_vector, . - __isr_vector

/* Flash Configuration */
    .section .FlashConfig, "a"
    .long 0xFFFFFFFF
    .long 0xFFFFFFFF
    .long 0xFFFFFFFF
    .long 0xFFFF3DFE

    .text
    .thumb

/* Reset Handler */

    .thumb_func
    .align 2
    .globl   Reset_Handler
    .weak    Reset_Handler
    .type    Reset_Handler, %function
Reset_Handler:
    cpsid   i               /* Mask interrupts */
    .equ    VTOR, 0xE000ED08
    ldr     r0, =VTOR
    ldr     r1, =__isr_vector
    str     r1, [r0]
#ifndef __NO_SYSTEM_INIT
    ldr   r0,=SystemInit
    blx   r0
#endif
/*     Loop to copy data from read only memory to RAM. The ranges
 *      of copy from/to are specified by following symbols evaluated in
 *      linker script.
 *      __etext: End of code section, i.e., begin of data sections to copy from.
 *      __data_start__/__data_end__: RAM address range that data should be
 *      copied to. Both must be aligned to 4 bytes boundary.  */

    ldr    r1, =__etext
    ldr    r2, =__data_start__
    ldr    r3, =__data_end__

    subs    r3, r2
    ble     .LC0

.LC1:
    subs    r3, 4
    ldr    r0, [r1,r3]
    str    r0, [r2,r3]
    bgt    .LC1
.LC0:

#ifdef __STARTUP_CLEAR_BSS
/*     This part of work usually is done in C library startup code. Otherwise,
 *     define this macro to enable it in this startup.
 *
 *     Loop to zero out BSS section, which uses following symbols
 *     in linker script:
 *      __bss_start__: start of BSS section. Must align to 4
 *      __bss_end__: end of BSS section. Must align to 4
 */
    ldr r1, =__bss_start__
    ldr r2, =__bss_end__

    subs    r2, r1
    ble .LC3

    movs    r0, 0
.LC2:
    str r0, [r1, r2]
    subs    r2, 4
    bge .LC2
.LC3:
#endif
    cpsie   i               /* Unmask interrupts */
#ifndef __START
#define __START _start
#endif
#ifndef __ATOLLIC__
    ldr   r0,=__START
    blx   r0
#else
    ldr   r0,=__libc_init_array
    blx   r0
    ldr   r0,=main
    bx    r0
#endif
    .pool
    .size Reset_Handler, . - Reset_Handler

    .align  1
    .thumb_func
    .weak DefaultISR
    .type DefaultISR, %function
DefaultISR:
    ldr r0, =DefaultISR
    bx r0
    .size DefaultISR, . - DefaultISR

    .align 1
    .thumb_func
    .weak NMI_Handler
    .type NMI_Handler, %function
NMI_Handler:
    ldr   r0,=NMI_Handler
    bx    r0
    .size NMI_Handler, . - NMI_Handler

    .align 1
    .thumb_func
    .weak HardFault_Handler
    .type HardFault_Handler, %function
HardFault_Handler:
    ldr   r0,=HardFault_Handler
    bx    r0
    .size HardFault_Handler, . - HardFault_Handler

    .align 1
    .thumb_func
    .weak SVC_Handler
    .type SVC_Handler, %function
SVC_Handler:
    ldr   r0,=SVC_Handler
    bx    r0
    .size SVC_Handler, . - SVC_Handler

    .align 1
    .thumb_func
    .weak PendSV_Handler
    .type PendSV_Handler, %function
PendSV_Handler:
    ldr   r0,=PendSV_Handler
    bx    r0
    .size PendSV_Handler, . - PendSV_Handler

    .align 1
    .thumb_func
    .weak SysTick_Handler
    .type SysTick_Handler, %function
SysTick_Handler:
    ldr   r0,=SysTick_Handler
    bx    r0
    .size SysTick_Handler, . - SysTick_Handler

    .align 1
    .thumb_func
    .weak DMA0_IRQHandler
    .type DMA0_IRQHandler, %function
DMA0_04_IRQHandler:
    ldr   r0,=DMA0_04_DriverIRQHandler
    bx    r0
    .size DMA0_IRQHandler, . - DMA0_IRQHandler

    .align 1
    .thumb_func
    .weak DMA0_15_IRQHandler
    .type DMA0_15_IRQHandler, %function
DMA0_15_IRQHandler:
    ldr   r0,=DMA0_15_DriverIRQHandler
    bx    r0
    .size DMA0_15_IRQHandler, . - DMA0_15_IRQHandler

    .align 1
    .thumb_func
    .weak DMA0_26_IRQHandler
    .type DMA0_26_IRQHandler, %function
DMA0_26_IRQHandler:
    ldr   r0,=DMA0_26_DriverIRQHandler
    bx    r0
    .size DMA0_26_IRQHandler, . - DMA0_26_IRQHandler

    .align 1
    .thumb_func
    .weak DMA0_37_IRQHandler
    .type DMA0_37_IRQHandler, %function
DMA0_37_IRQHandler:
    ldr   r0,=DMA0_37_DriverIRQHandler
    bx    r0
    .size DMA0_37_IRQHandler, . - DMA0_37_IRQHandler

    .align 1
    .thumb_func
    .weak FLEXIO0_IRQHandler
    .type FLEXIO0_IRQHandler, %function
FLEXIO0_IRQHandler:
    ldr   r0,=FLEXIO0_DriverIRQHandler
    bx    r0
    .size FLEXIO0_IRQHandler, . - FLEXIO0_IRQHandler

    .align 1
    .thumb_func
    .weak LSPI0_IRQHandler
    .type LSPI0_IRQHandler, %function
LSPI0_IRQHandler:
    ldr   r0,=LSPI0_DriverIRQHandler
    bx    r0
    .size LSPI0_IRQHandler, . - LSPI0_IRQHandler

    .align 1
    .thumb_func
    .weak LSPI1_IRQHandler
    .type LSPI1_IRQHandler, %function
LSPI1_IRQHandler:
    ldr   r0,=LSPI1_DriverIRQHandler
    bx    r0
    .size LSPI1_IRQHandler, . - LSPI1_IRQHandler

    .align 1
    .thumb_func
    .weak LPUART0_IRQHandler
    .type LPUART0_IRQHandler, %function
LPUART0_IRQHandler:
    ldr   r0,=LPUART0_DriverIRQHandler
    bx    r0
    .size LPUART0_IRQHandler, . - LPUART0_IRQHandler

    .align 1
    .thumb_func
    .weak LPUART1_IRQHandler
    .type LPUART1_IRQHandler, %function
LPUART1_IRQHandler:
    ldr   r0,=LPUART1_DriverIRQHandler
    bx    r0
    .size LPUART1_IRQHandler, . - LPUART1_IRQHandler

    .align 1
    .thumb_func
    .weak LI2C0_IRQHandler
    .type LI2C0_IRQHandler, %function
LI2C0_IRQHandler:
    ldr   r0,=LI2C0_DriverIRQHandler
    bx    r0
    .size LI2C0_IRQHandler, . - LI2C0_IRQHandler

    .align 1
    .thumb_func
    .weak LI2C1_IRQHandler
    .type LI2C1_IRQHandler, %function
LI2C1_IRQHandler:
    ldr   r0,=LI2C1_DriverIRQHandler
    bx    r0
    .size LI2C1_IRQHandler, . - LI2C1_IRQHandler


/*    Macro to define default handlers. Default handler
 *    will be weak symbol and just dead loops. They can be
 *    overwritten by other handlers */
    .macro def_irq_handler  handler_name
    .weak \handler_name
    .set  \handler_name, DefaultISR
    .endm

/* Exception Handlers */
    def_irq_handler    DMA0_04_DriverIRQHandler
    def_irq_handler    DMA0_15_DriverIRQHandler
    def_irq_handler    DMA0_26_DriverIRQHandler
    def_irq_handler    DMA0_37_DriverIRQHandler
    def_irq_handler    CTI0_DMA0_Error_IRQHandler
    def_irq_handler    FLEXIO0_DriverIRQHandler
    def_irq_handler    TPM0_IRQHandler
    def_irq_handler    TPM1_IRQHandler
    def_irq_handler    TPM2_IRQHandler
    def_irq_handler    LPIT0_IRQHandler
    def_irq_handler    LSPI0_DriverIRQHandler
    def_irq_handler    LSPI1_DriverIRQHandler
    def_irq_handler    LPUART0_DriverIRQHandler
    def_irq_handler    LPUART1_DriverIRQHandler
    def_irq_handler    LI2C0_DriverIRQHandler
    def_irq_handler    LI2C1_DriverIRQHandler
    def_irq_handler    Reserved32_IRQHandler
    def_irq_handler    PORTA_IRQHandler
    def_irq_handler    PORTB_IRQHandler
    def_irq_handler    PORTC_IRQHandler
    def_irq_handler    PORTD_IRQHandler
    def_irq_handler    PORTE_IRQHandler
    def_irq_handler    LLWU0_IRQHandler
    def_irq_handler    I2S0_IRQHandler
    def_irq_handler    USB0_IRQHandler
    def_irq_handler    ADC0_IRQHandler
    def_irq_handler    LPTMR0_IRQHandler
    def_irq_handler    RTC_Seconds_IRQHandler
    def_irq_handler    INTMUX0_IRQHandler
    def_irq_handler    INTMUX1_IRQHandler
    def_irq_handler    INTMUX2_IRQHandler
    def_irq_handler    INTMUX3_IRQHandler

    .end
