/**
******************************************************************************
* @file trim_map.h
* @brief trim register map
* @internal
* @author   ON Semiconductor
* $Rev: 3727 $
* $Date: 2015-09-14 14:38:34 +0530 (Mon, 14 Sep 2015) $
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
* @ingroup trim
*
* @details
* <p>
* Rf and Analog control hw module register map
* </p>
*/

#ifndef TRIM_MAP_H_
#define TRIM_MAP_H_

/*************************************************************************************************
*                                                                                                *
*  Header files                                                                                  *
*                                                                                                *
*************************************************************************************************/

#include "architecture.h"

/**************************************************************************************************
*                                                                                                 *
*  Type definitions                                                                               *
*                                                                                                 *
**************************************************************************************************/

/** trim register map */
typedef struct {						/**< REV B 			REV D	*/
    __I uint32_t PAD0;					/**< 0x1FA0 		0x1FA0	*/
    __I uint32_t APP_RESERVED0;			/**< 0x1FA4 		0x1FA4	*/
    __I uint32_t APP_RESERVED1;			/**< 0x1FA8 		0x1FA8	*/
#ifdef REVB
    __I uint32_t TX_POWER;				/**< 0x1FAC */
#endif
    __I uint32_t TRIM_32K_EXT;			/**< 0x1FB0 		0x1FAC	*/
    __I uint32_t TRIM_32M_EXT;			/**< 0x1FB4 		0x1FB0	*/
#ifdef REVD
    __I uint32_t FVVDH_COMP_TH;			/**< 				0x1FB4 */
#endif
    union {
        struct {						/* Common to REV B & REV D */
            __I uint32_t CHANNEL11:4;
            __I uint32_t CHANNEL12:4;
            __I uint32_t CHANNEL13:4;
            __I uint32_t CHANNEL14:4;
            __I uint32_t CHANNEL15:4;
            __I uint32_t CHANNEL16:4;
            __I uint32_t CHANNEL17:4;
            __I uint32_t CHANNEL18:4;
        } BITS;
        __I uint32_t WORD;
    } TX_VCO_LUT1;						/**< 0x1FB8 */
    union {
        struct {
            __I uint32_t CHANNEL19:4;
            __I uint32_t CHANNEL20:4;
            __I uint32_t CHANNEL21:4;
            __I uint32_t CHANNEL22:4;
            __I uint32_t CHANNEL23:4;
            __I uint32_t CHANNEL24:4;
            __I uint32_t CHANNEL25:4;
            __I uint32_t CHANNEL26:4;
        } BITS;
        __I uint32_t WORD;
    } TX_VCO_LUT2;						/**< 0x1FBC */
    union {
        struct {
            __I uint32_t CHANNEL11:4;
            __I uint32_t CHANNEL12:4;
            __I uint32_t CHANNEL13:4;
            __I uint32_t CHANNEL14:4;
            __I uint32_t CHANNEL15:4;
            __I uint32_t CHANNEL16:4;
            __I uint32_t CHANNEL17:4;
            __I uint32_t CHANNEL18:4;
        } BITS;
        __I uint32_t WORD;
    } RX_VCO_LUT1;						/**< 0x1FC0 */
    union {
        struct {
            __I uint32_t CHANNEL19:4;
            __I uint32_t CHANNEL20:4;
            __I uint32_t CHANNEL21:4;
            __I uint32_t CHANNEL22:4;
            __I uint32_t CHANNEL23:4;
            __I uint32_t CHANNEL24:4;
            __I uint32_t CHANNEL25:4;
            __I uint32_t CHANNEL26:4;
        } BITS;
        __I uint32_t WORD;
    } RX_VCO_LUT2;						/**< 0x1FC4 */
    __I uint32_t ON_RESERVED0;			/**< 0x1FC8 */
    __I uint32_t ON_RESERVED1;			/**< 0x1FCC */
    __I uint32_t ADC_OFFSET_TRIM;		/**< 0x1FD0 */
    __I uint32_t TX_PRE_CHIPS;			/**< 0x1FD4 */
    __I uint32_t TX_CHAIN_TRIM;			/**< 0x1FD8 */
    __I uint32_t PLL_VCO_TAP_LOCATION;	/**< 0x1FDC */
    __I uint32_t PLL_TRIM;				/**< 0x1FE0 */
    __I uint32_t RSSI_OFFSET;			/**< 0x1FE4 */
    __I uint32_t RX_CHAIN_TRIM;			/**< 0x1FE8 */
    __I uint32_t PMU_TRIM;				/**< 0x1FEC */
    __I uint32_t WR_SEED_RD_RAND;		/**< 0x1FF0 */
    __I uint32_t WAFER_LOCATION;		/**< 0x1FF4 */
    __I uint32_t LOT_NUMBER;			/**< 0x1FF8 */
    __I uint32_t REVISION_CODE;			/**< 0x1FFC */
} TrimReg_t, *TrimReg_pt;

#endif /* TRIM_MAP_H_ */
