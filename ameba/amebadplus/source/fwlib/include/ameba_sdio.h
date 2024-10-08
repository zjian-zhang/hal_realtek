/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _AMEBA_SDIO_H_
#define _AMEBA_SDIO_H_

/** @addtogroup Ameba_Periph_Driver
  * @{
  */

/** @defgroup SDIO
  * @brief SDIO driver modules
  * @{
  */

/* Exported Types --------------------------------------------------------*/
/** @defgroup SDIO_Exported_Types SDIO Exported Types
  * @{
  */
/**
  * @brief	 SDIO Init structure definition
  */
typedef struct {
	/* TXBD */
	u32 TXBD_BAR;			/*!< Specifies TXBD base address */
	u32 TXBD_RING_SIZE; 	/*!< Specifies TXBD ring size, This parameter must be set to a value in the 0-0xFFFF range. */
	u32 TX_BUFFER_SIZE; 	/*!< Specifies TX buffer size, This parameter must be set to a value in the 0-0xFF range. */

	/* RXBD */
	u32 RXBD_BAR;			/*!< Specifies RXBD base address */
	u32 RXBD_RING_SIZE; 	/*!< Specifies RXBD ring size, This parameter must be set to a value in the 0-0xFFFF range. */
	u32 RXBD_FREE_TH;		/*!< the threshold of free RX BD count to trigger interrupt */
} SDIO_InitTypeDef;
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/

/** @defgroup SDIO_Exported_Constants SDIO Exported Constants
  * @{
  */

/** @defgroup SDIO_MP_CMD_definitions
  * @brief The SDIO MP CMD definations
  * @{
  */
#define SDIO_MP_START			1
#define SDIO_MP_STOP			2
#define SDIO_MP_LOOPBACK		3
#define SDIO_MP_STATUS			4
#define SDIO_MP_READ_REG8		5
#define SDIO_MP_READ_REG16		6
#define SDIO_MP_READ_REG32		7
#define SDIO_MP_WRITE_REG8		8
#define SDIO_MP_WRITE_REG16		9
#define SDIO_MP_WRITE_REG32		10
#define SDIO_MP_WAKEUP			11	// wakeup the SDIO task manually, for debugging
#define SDIO_MP_DUMP			12	// start/stop to dump the SDIO status periodically
#define SDIO_MP_CTX				13	// setup continue TX test
#define SDIO_MP_CRX				14	// setup continue RX test
#define SDIO_MP_CRX_DA			15	// setup continue RX with dynamic allocate RX Buf test
#define SDIO_MP_CRX_STOP		16	// setup continue RX test
#define SDIO_MP_DBG_MSG			17	// Debug message On/Off
/**
  * @}
  */

/** @defgroup SDIO_RPWM_definitions
  * @brief The SDIO RPWM definations
  * @{
  */
#define RPWM2_ACT_BIT			(0x00000001 << 0)	// Active
#define RPWM2_CG_BIT			(0x00000001 << 1)	// Clock Gated
#define RPWM2_TOGGLE_BIT		(0x00000001 << 15)	// Toggle bit
/**
  * @}
  */

/** @defgroup SDIO_CPWM2_definitions
  * @brief The SDIO CPWM2 definations
  * @{
  */
#define CPWM2_ACT_BIT			(0x00000001 << 0)	// Active
#define CPWM2_DSTANDBY_BIT		(0x00000001 << 1)	// Deep Standby
#define CPWM2_FBOOT_BIT			(0x00000001 << 2)	// fast reboot
#define CPWM2_INIC_FW_RDY_BIT	(0x00000001 << 3)	// is the iNIC FW(1) or Boot FW(0)
#define CPWM2_TOGGLE_BIT		(0x00000001 << 15)	// Toggle bit
/**
  * @}
  */

/** @defgroup SDIO_CPWM1_definitions
  * @brief The SDIO CPWM1 definations
  * @{
  */
#define CPWM1_TOGGLE_BIT		(0x00000001 << 7)	// Toggle bit
/**
  * @}
  */

/** @defgroup SDIO_EVENT_definitions
  * @brief The SDIO EVENT definations
  * @{
  */
#define SDIO_EVENT_RX_PKT_RDY		(0x00000001 << 1)	// A new SDIO packet ready
#define SDIO_EVENT_DUMP				(0x00000001 << 3)	// SDIO status dump periodically Enable
#define SDIO_EVENT_EXIT				(0x00000001 << 27)	// Request to exit the SDIO task
#define SDIO_EVENT_MP_STOPPED		(0x00000001 << 28)	// The SDIO task is stopped
#define SDIO_EVENT_IRQ_STOPPED		(0x00000001 << 29)	// The SDIO task is stopped
#define SDIO_EVENT_TX_STOPPED		(0x00000001 << 30)	// The SDIO task is stopped
#define SDIO_EVENT_RX_STOPPED		(0x00000001 << 31)	// The SDIO task is stopped
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
/**
  * @}
  */

_LONG_CALL_ void SDIO_StructInit(SDIO_InitTypeDef *SDIO_InitStruct);
_LONG_CALL_ void SDIO_Init(SDIO_InitTypeDef *SDIOInit_Struct);
_LONG_CALL_ void SDIO_INTClear(u16 IntStatus);
_LONG_CALL_ void SDIO_INTClearAll(void);
_LONG_CALL_ void SDIO_INTConfig(u16 IntMask, u32 NewState);
_LONG_CALL_ u16 SDIO_INTStatus(void);
_LONG_CALL_ u8 SDIO_RPWM1_Get(void);
_LONG_CALL_ u16 SDIO_RPWM2_Get(void);
_LONG_CALL_ void SDIO_CPWM1_Set(u8 Val);
_LONG_CALL_ void SDIO_CPWM2_Set(u16 Val, u32 Newstate);
_LONG_CALL_ u32 SDIO_H2C_MSG_Get(void);
_LONG_CALL_ u16 SDIO_RXBD_RPTR_Get(void);
_LONG_CALL_ void SDIO_RXBD_WPTR_Set(u16 Val);
_LONG_CALL_ u32 SDIO_TXBD_WPTR_Get(void);
_LONG_CALL_ void SDIO_TXBD_RPTR_Set(u32 Val);
_LONG_CALL_ u32 SDIO_TXBD_RPTR_Get(void);
_LONG_CALL_ void SDIO_DMA_Reset(void);
_LONG_CALL_ u32 SDIO_DMA_CTRL_Get(void);
_LONG_CALL_ void SDIO_SetReady(int ready);
_LONG_CALL_ void SDIO_RxReq(void);


#define SDIO_CCCR_REG_BASE					(SDIO_REG_BASE + 0x1000)
#define SDIO_LOCAL_REG_BASE					(SDIO_REG_BASE + 0x2000)

/* Registers Definitions --------------------------------------------------------*/
#define REG_SPDIO_TXBD_ADDR 					0xA0	// 4 Bytes
#define REG_SPDIO_TXBD_SIZE						0xA4	// 4 Bytes
#define REG_SPDIO_TXBD_WPTR						0xA8	// 4 Bytes
#define REG_SPDIO_TXBD_RPTR						0xAC	// 4 Bytes
#define REG_SPDIO_RXBD_ADDR						0xB0	// 4 Bytes
#define REG_SPDIO_RXBD_SIZE						0xB4	// 2 Bytes
#define REG_SPDIO_RXBD_C2H_WPTR					0xB6	// 2 Bytes
#define REG_SPDIO_RXBD_C2H_RPTR					0xB8	// 2 Bytes
#define REG_SPDIO_HCI_RX_REQ					0xBA	// 1 Byte
#define REG_SPDIO_CPU_RST_DMA					0xBB	// 1 Byte
#define REG_SPDIO_RX_REQ_ADDR					0xBC	// 2 Bytes
#define REG_SPDIO_CPU_INT_MASK					0xC0	// 2 Bytes
#define REG_SPDIO_CPU_INT_STAS					0xC2	// 2 Bytes
#define REG_SPDIO_CCPWM							0xC4	// 1 Byts
#define REG_SPDIO_CPU_IND						0xC5	// 1 Byte
#define REG_SPDIO_CCPWM2						0xC6	// 2 Bytes
#define REG_SPDIO_CPU_H2C_MSG					0xC8	// 4 Bytes
#define REG_SPDIO_CPU_C2H_MSG					0xCC	// 4 Bytes
#define REG_SPDIO_CRPWM							0xD0	// 1 Bytes
#define REG_SPDIO_CRPWM2						0xD2	// 2 Bytes
#define REG_SPDIO_AHB_DMA_CTRL					0xD4	// 4 Bytes
#define REG_SPDIO_RXBD_CNT						0xD8	// 4 Bytes
#define REG_SPDIO_TX_BUF_UNIT_SZ				0xD9	// 1 Bytes
#define REG_SPDIO_RX_BD_FREE_CNT				0xDA	// 2 Bytes
#define REG_SPDIO_CPU_H2C_MSG_EXT				0xDC	// 4 Bytes
#define REG_SPDIO_CPU_C2H_MSG_EXT				0xE0	// 4 Bytes

/********************  Bits definition for REG_SPDIO_TXBD_WPTR register  *******************/
#define BIT_SPDIO_TXBD_H2C_WPTR_WRAP				BIT(31)

/********************  Bits definition for REG_SPDIO_TXBD_RPTR register  *******************/
#define BIT_SPDIO_TXBD_H2C_RPTR_WRAP				BIT(31)

/********************  Bits definition for REG_SPDIO_CPU_RST_DMA register  *******************/
#define BIT_CPU_RST_SDIO_DMA						BIT(7)

/********************  Bits definition for REG_SPDIO_CPU_INT_MASK/REG_SPDIO_CPU_INT_STAS register  *******************/
#define BIT_TXFIFO_H2C_OVF							BIT(0)
#define BIT_H2C_BUS_RES_FAIL						BIT(1)
#define BIT_H2C_DMA_OK								BIT(2)
#define BIT_C2H_DMA_OK								BIT(3)
#define BIT_H2C_MSG_INT								BIT(4)
#define BIT_RPWM1_INT								BIT(5)
#define BIT_RPWM2_INT								BIT(6)
#define BIT_SDIO_RST_CMD_INT						BIT(7)
#define BIT_RXBD_FLAG_ERR_INT						BIT(8)
#define BIT_RX_BD_AVAI_INT							BIT(9)
#define BIT_HOST_WAKE_CPU_INT						BIT(10)

#define SDIO_INIT_INT_MASK							(BIT_H2C_DMA_OK | BIT_C2H_DMA_OK | \
													BIT_H2C_MSG_INT | BIT_RPWM1_INT | \
													BIT_RPWM2_INT |BIT_H2C_BUS_RES_FAIL | \
													BIT_RXBD_FLAG_ERR_INT)
/********************  Bits definition for REG_SPDIO_CPU_IND register  *******************/
#define BIT_SYSTEM_TRX_RDY_IND						BIT(0)
#define BIT_SYSTEM_READEE_DONE						BIT(1)

/********************  Bits definition for REG_SPDIO_HCI_RX_REQ register  *******************/
#define BIT_HCI_RX_REQ								BIT(0)

/********************  Bits definition for REG_SPDIO_AHB_DMA_CTRL register  *******************/
#define DISPATCH_TXAGG_PKT							BIT(31)

/* CCCR Registers Definitions --------------------------------------------------------*/
#define MANF_PID									0x10	// 2 Bytes

#endif	/* #ifndef _AMEBA_SDIO_H_ */
