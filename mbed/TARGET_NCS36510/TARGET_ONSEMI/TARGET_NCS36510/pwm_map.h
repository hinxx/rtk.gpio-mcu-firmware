/**
 ******************************************************************************
 * @file pwm_map.h
 * @brief PWM HW register map
 * @internal
 * @author ON Semiconductor
 * $Rev: 3378 $
 * $Date: 2015-04-28 13:38:36 +0530 (Tue, 28 Apr 2015) $
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
 * @ingroup pwm
 *
 * @details
 * <p>
 * PWM HW register map description
 * </p>
 *
 * <h1> Reference document(s) </h1>
 * <p>
 * <a href="../../../../build/doc/pdf/IPC7205_PWM_APB_DS_v1P1.pdf" target="_blank">
 * IPC7205 APB PWM Design Specification v1.1 </a>
 * </p>
 */

#ifndef PWM_MAP_H_
#define PWM_MAP_H_

#include "architecture.h"

/** Power management Control HW Structure Overlay */
#ifdef REVB
typedef struct {
    __IO uint32_t DUTYCYCLE;
    union {
        struct {
            __IO uint32_t ENABLED :1;/**< 1 = PWM enable , 0 = PWM disable  */
            __I uint32_t CURRENT :1;/**< current state of PWM enable signal  */
            __O uint32_t PAD1 :6; /**< Reserved. Writes have no effect; Read as 0x00. */
            __O uint32_t RDPWMEN :1;/**< current state of pwmEnable configuration  */
            __O uint32_t RDPWMOP :1;/**< current state of PWM out signal  */
            __O uint32_t PAD2 :6; /**< Reserved. Writes have no effect; Read as 0x00. */
        } BITS;
        __I uint32_t WORD;
    } PWMOUT;
    __O uint32_t DISABLE;
    union {
        struct {
            __IO uint32_t ENABLED :1;
            __O uint32_t PAD1 :7; /**< Reserved. Writes have no effect */
            __O uint32_t STATE :1; /**< current state of prescaler enable configuration. */
            __O uint32_t PAD2 :7; /**< Reserved. Writes have no effect; Read as 0x00. */
        } BITS;
        __I uint32_t WORD;
    } PRESCALE_EN;

    __O uint32_t PRESCALE_DIS;

} PwmReg_t, *PwmReg_pt;
#endif /* REVB */

#ifdef REVD
typedef struct {
    __IO uint32_t DUTYCYCLE;
    union {
        struct {
            __O uint32_t ENABLE :8;	/**< Write any value to enable PWM output */
            __I uint32_t PAD :1;	/** < Pad */
            __I uint32_t ENABLE_STATE :1;	/**< Current state of pwmEnable configuration bit.  �1� PWM output is enabled.  �0� PWN output is disabled. */
            __I uint32_t OUTPUT_STATE :1;	/**< Current state of PWM output */
        } BITS;
        __IO uint32_t WORD;
    } PWM_ENABLE;
    __O uint32_t PWM_DISABLE;
    union {
        struct {
            __O uint32_t ENABLE :8; /**< Write any value to select enable the 4-bit prescaler */
            __I uint32_t STATE:1; /**< Current state of the prescaler.  �1� the prescaler is enabled.  �0� the prescaler is disabled. */
        } BITS;
        __IO uint32_t WORD;
    } PRESCALE_ENABLE;
    __O uint32_t PRESCALE_DISABLE;
} PwmReg_t, *PwmReg_pt;
#endif /* REVD */
#endif /* PWM_MAP_H_ */
