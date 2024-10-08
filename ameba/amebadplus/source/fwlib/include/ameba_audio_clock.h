/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _AMEBA_AUDIO_CLOCK_H_
#define _AMEBA_AUDIO_CLOCK_H_

/** @addtogroup Ameba_Periph_Driver
  * @{
  */

/** @defgroup AUDIO
  * @brief AUDIO driver modules
  * @{
  */

/** @defgroup AUDIO_CLOCK
* @brief AUDIO_CLOCK driver modules
* @{
*/

/* Exported constants ------------------------------------------------------------*/
/** @defgroup AUDIO_CLOCK_Exported_Constants AUDIO_CLOCK Exported Constants
  * @{
  */

#define PLL_CLK    0
#define XTAL_CLOCK 1

#define PLL_CLOCK_45P1584M	45158400
#define PLL_CLOCK_98P304M	98304000
#define I2S_CLOCK_XTAL40M	40000000

#define PLL_CLOCK_MAX_NUM	    2
/**
* @}
*/

/* Exported types ------------------------------------------------------------*/
/** @addtogroup AUDIO_CLOCK_Exported_Types AUDIO_CLOCK Exported Types
  * @{
  */

/** @defgroup AUDIO_ClockParams
	  * @{
	  */

typedef struct {
	u32 Clock;
	u32 MCLK_NI;
	u32 MCLK_MI;
} AUDIO_ClockParams;
/**
* @}
*/

/** @defgroup AUDIO_InitParams
  * @{
  */

typedef struct {
	u32 sr;
	u32 chn_len;
	u32 chn_cnt;
	u32 codec_multiplier_with_rate;
	u32 sport_mclk_fixed_max;
} AUDIO_InitParams;
/**
* @}
*/

/**
* @}
*/

/* Exported functions ------------------------------------------------------------*/
/** @defgroup AUDIO_CLOCK_Exported_Functions AUDIO_CLOCK Exported Functions
  * @{
  */

bool is_sport_ni_mi_supported(u32 clock, u32 sr, u32 chn_len, u32 chn_cnt);
void Audio_Clock_Choose(u32 clock_sel, AUDIO_InitParams *initparams, AUDIO_ClockParams *params);
/**
* @}
*/

/** @} */

/** @} */

/** @} */


#endif


