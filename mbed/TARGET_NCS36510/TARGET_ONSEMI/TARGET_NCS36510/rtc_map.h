/**
 ******************************************************************************
 * @file rtc_map.h
 * @brief Real Time Clock HW register map
 * @internal
 * @author  ON Semiconductor.
 * $Rev: 3008 $
 * $Date: 2014-10-16 18:42:48 +0530 (Thu, 16 Oct 2014) $
 ******************************************************************************
 * @copyright (c) 2012 ON Semiconductor. All rights reserved.
 * ON Semiconductor is supplying this software for use with ON Semiconductor
 * processor based microcontrollers only.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * ON SEMICONDUCTOR SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL,
 * INCIDENTAL, OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 * @endinternal
 *
 * @ingroup rtc
 *
 * @details
 * <p>
 * Teal Time Clock HW register map description
 * </p>
 *
 * <h1> Reference document(s) </h1>
 * <p>
 * <a HOURef="../pdf/IPC7206_RTC_APB_DS_v1P0.pdf" target="_blank">
 * IPC7206 APB RTC Design Specification v1.0 </a>
 * </p>
 */

#ifndef RTC_MAP_H_
#define RTC_MAP_H_

#include "architecture.h"

/** Real Time Clock Control HW Structure Overlay */
typedef struct {
#ifdef REVB
    /*REVD REPLACE COMPLETE MAP WITH DATA FROM DIG DESIGN SPEC */
    __IO uint32_t SECOND;/**<SECOND Counter */
    __IO uint32_t MINUTE;/**<DAY Counter */
    __IO uint32_t HOUR;/**< HOUR Counter */
    __IO uint32_t DAY;/**< DAY Counter */
    __IO uint32_t MONTH;/**< MONTH Counter */
    __IO uint32_t YEAR;/**< YEAR Counter */
    union {
        struct {
            __IO uint32_t PAD1 :1;/**<Reserved; Writes have no effect. Read as 0 */
            __IO uint32_t TEST_MINUTE :1;/**<0 = normal operation , 1 = Test Mode */
            __IO uint32_t TEST_HOUR :1;/**<0 = normal operation , 1 = Test Mode */
            __IO uint32_t TEST_DAY :1;/**<0 = normal operation , 1 = Test Mode */
            __IO uint32_t TEST_MONTH :1;/**<0 = normal operation , 1 = Test Mode */
            __IO uint32_t TEST_YEAR :1;/**<0 = normal operation , 1 = Test Mode */
            __IO uint32_t PAD2 :1;/**<Reserved; Writes have no effect. Read as 0 */
            __IO uint32_t RESET :1;/**< 0 = counters are incrementing , 1 = counters are in reset */
        } BITS;
        __IO uint32_t WORD;
    } CONTROL;
    __IO uint32_t DIVISOR;/**<Clock Divisor value */
    __IO uint32_t ALARM_SECOND;/**<SECOND Alarm's BCD value */
    __IO uint32_t ALARM_MINUTE;/**<MINUTE Alarm's BCD value */
    __IO uint32_t ALARM_HOUR;/**<HOUR Alarm's BCD value*/
    __IO uint32_t ALARM_DAY;/**<DAY Alarm's BCD value */
    __IO uint32_t ALARM_MONTH;/**<MONTH Alarm's BCD value */
    __IO uint32_t ALARM_YEAR;/**<YEAR Alarm's BCD value */
    union {
        struct {
            __IO uint32_t SECOND :1;/**<SECOND Alarm interrupt : 0 = disabled, 1 = enabled */
            __IO uint32_t MINUTE :1;/**<MINUTE Alarm interrupt : 0 = disabled, 1 = enabled */
            __IO uint32_t HOUR :1;/**<HOUR Alarm interrupt  : 0 = disabled, 1 = enabled */
            __IO uint32_t DAY :1;/**<DAY Alarm interrupt    : 0 = disabled, 1 = enabled */
            __IO uint32_t MONTH :1;/**<MONTH Alarm interrupt : 0 = disabled, 1 = enabled */
            __IO uint32_t YEAR :1;/**<YEAR Alarm interrupt  : 0 = disabled, 1 = enabled */
            __IO uint32_t PAD :2 ;/**<Writes have no effect; Read as 2�b00 */
        } BITS;
        __IO uint32_t WORD;
    } INT_EN_CONTROL;
    union {
        struct {
            __I uint32_t SECOND :1;/**<SECOND Alarm interrupt : 0= inactive , 1 = active */
            __I uint32_t MINUTE :1;/**<MINUTE Alarm interrupt : 0= inactive , 1 = active */
            __I uint32_t HOUR :1;/**<HOUR Alarm interrupt  : 0= inactive , 1 = active  */
            __I uint32_t DAY :1;/**<DAY Alarm interrupt   : 0= inactive , 1 = active  */
            __I uint32_t MONTH :1;/**<MONTH Alarm interrupt : 0= inactive , 1 = active   */
            __I uint32_t YEAR :1;/**<YEAR Alarm interrupt : 0= inactive , 1 = active */
            __I uint32_t PAD :2; /**<Read as 00 */
        } BITS;
        __I uint32_t WORD;
    } INT_STATUS;
    union {
        struct {
            __O uint32_t SECOND :1;/**<Write 1 to clear the SECOND Alarm interrupt.*/
            __O uint32_t MINUTE :1;/**<Write 1 to clear the MINUTE Alarm interrupt*/
            __O uint32_t HOUR :1;/**<Write 1 to clear the HOUR Alarm interrupt*/
            __O uint32_t DAY :1;/**< Write 1 to clear the DAY Alarm interrupt*/
            __O uint32_t MONTH :1;/**<Write 1 to clear the MONTH Alarm interrupt */
            __O uint32_t YEAR :1;/**< Write 1 to clear the YEAR Alarm interrupt*/
            __O uint32_t PAD :2 ;/**< Writes have no effect. */
        } BITS;
        __O uint32_t WORD;
    } INT_CLEAR;
#endif /* REVB */
#ifdef REVD
    __IO uint32_t SUB_SECOND_COUNTER;	/**<SUB SECOND Counter */	/* 0x4000F000 */
    __IO uint32_t SECOND_COUNTER;		/**<SECOND Counter */		/* 0x4000F004 */
    __IO uint32_t SUB_SECOND_ALARM;		/**< SUB SECOND alarm */	/* 0x4000F008 */
    __IO uint32_t SECOND_ALARM;			/**< SECOND alarm */		/* 0x4000F00c */
    union {
        struct {
            __IO uint32_t SUB_SEC_COUNTER_EN :1;	/**<Sub-second counter enable.  (1=count is enabled, 0=retain count value) */
            __IO uint32_t SEC_COUNTER_EN :1;		/**<Second counter enable. (1=count is enabled, 0=retain count value) */
            __IO uint32_t SUB_SECOND_INT_EN :1;		/**<Sub-second interrupt enable (1=interrupt enabled, 0=interrupt disabled) */
            __IO uint32_t SECOND_INT_EN :1;			/**<Second interrupt enable (1=interrupt enabled, 0=interrupt disabled) */
        } BITS;
        __IO uint32_t WORD;
    } CONTROL;			/* 0x4000F010 */
    union {
        struct {
            /**<Any write to the status register will clear the error bit. */
            __IO uint32_t SUB_SECOND_INT:1;				/**<Sub-second interrupt status.  (1=interrupt active, 0=no interrupt)*/
            __IO uint32_t SECOND_INT :1;				/**<Second interrupt status.  (1=interrupt active, 0=no interrupt)*/
            __IO uint32_t WRITE_ERROR :1;				/**<Reads error bit which is set when a write occurs before a previous write to the same register has completed. */
            __IO uint32_t BSY_ANY_WRT :1;				/**<Busy with any write.*/
            __IO uint32_t BSY_SUB_SEC_CNTR_REG_WRT :1;	/**<Busy with a sub-second counter register write.*/
            __IO uint32_t BSY_SEC_CNTR_REG_WRT :1;		/**<Busy with a second counter register write.*/
            __IO uint32_t BSY_SUB_SEC_ALRM_REG_WRT :1;	/**<Busy with a sub-second alarm register write.*/
            __IO uint32_t BSY_SEC_ALRM_REG_WRT:1;		/**<Busy with a second alarm register write.*/
            __IO uint32_t BSY_CTRL_REG_WRT :1;			/**<Busy with a control register write.*/
            __IO uint32_t BSY_SUB_SEC_INT_CLR_WRT :1;	/**<Busy with a sub-second interrupt clear write.*/
            __IO uint32_t BSY_SEC_INT_CLR_WRT :1;		/**<Busy with a second interrupt clear write.*/
        } BITS;
        __IO uint32_t WORD;
    } STATUS;			/* 0x4000F014 */
    union {
        struct {
            __O uint32_t SUB_SECOND :1;		/**<Write 1 to this register to clear the sub-second interrupt.*/
            __O uint32_t SECOND :1;			/**<Write 1 to this register to clear the second interrupt.*/
        } BITS;
        __O uint32_t WORD;
    } INT_CLEAR;			/* 0x4000F018 */
#endif /* REVD */
} RtcReg_t, *RtcReg_pt;

#endif /* RTC_MAP_H_ */
