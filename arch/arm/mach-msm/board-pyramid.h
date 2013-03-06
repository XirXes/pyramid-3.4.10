/* linux/arch/arm/mach-msm/board-pyramid.h
 *
 * Copyright (C) 2010-2011 HTC Corporation.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __ARCH_ARM_MACH_MSM_BOARD_PYRAMID_H
#define __ARCH_ARM_MACH_MSM_BOARD_PYRAMID_H

#include <mach/board.h>

#define PYRAMID_PROJECT_NAME	"pyramid"

#define MSM_RAM_CONSOLE_BASE	MSM_HTC_RAM_CONSOLE_PHYS
#define MSM_RAM_CONSOLE_SIZE	MSM_HTC_RAM_CONSOLE_SIZE


#if defined(CONFIG_CRYPTO_DEV_QCRYPTO) || \
		defined(CONFIG_CRYPTO_DEV_QCRYPTO_MODULE) || \
		defined(CONFIG_CRYPTO_DEV_QCEDEV) || \
		defined(CONFIG_CRYPTO_DEV_QCEDEV_MODULE)
#define QCE_SIZE		0x10000
#define QCE_0_BASE		0x18500000
#endif

#ifdef CONFIG_FB_MSM_LCDC_DSUB
#define MSM_FB_DSUB_PMEM_ADDER (0x9E3400-0x4B0000)
#else
#define MSM_FB_DSUB_PMEM_ADDER (0)
#endif

#ifdef CONFIG_FB_MSM_TRIPLE_BUFFER
#define MSM_FB_PRIM_BUF_SIZE (960 * ALIGN(540, 32) * 4 * 3)
#else
#define MSM_FB_PRIM_BUF_SIZE (960 * ALIGN(540, 32) * 4 * 2)
#endif


#ifdef CONFIG_FB_MSM_OVERLAY0_WRITEBACK
#define MSM_FB_WRITEBACK_SIZE roundup(960 * ALIGN(540, 32) * 3 * 2, 4096)
#else
#define MSM_FB_WRITEBACK_SIZE 0
#endif

#ifdef CONFIG_FB_MSM_HDMI_MSM_PANEL
#define MSM_FB_SIZE roundup(MSM_FB_PRIM_BUF_SIZE + 0x3F4800 + MSM_FB_DSUB_PMEM_ADDER, 4096)
#elif defined(CONFIG_FB_MSM_TVOUT)
#define MSM_FB_SIZE roundup(MSM_FB_PRIM_BUF_SIZE + 0x195000 + MSM_FB_DSUB_PMEM_ADDER, 4096)
#else 
#define MSM_FB_SIZE roundup(MSM_FB_PRIM_BUF_SIZE + MSM_FB_DSUB_PMEM_ADDER, 4096)
#endif 
#ifdef CONFIG_MSM_IOMMU
#define MSM_PMEM_SF_SIZE 0x00000000 
#else
#define MSM_PMEM_SF_SIZE 0x4000000 
#endif
#define MSM_OVERLAY_BLT_SIZE   roundup(960 * ALIGN(540, 32) * 3 * 2, 4096)

#define MSM_PMEM_KERNEL_EBI1_SIZE  0x600000 
#define MSM_PMEM_ADSP_SIZE	0x2E00000
#define MSM_PMEM_ADSP2_SIZE 0x1700000
#define MSM_PMEM_AUDIO_SIZE	0x4CF000

#define MSM_PMEM_SF_BASE		(0x70000000 - MSM_PMEM_SF_SIZE)
#define MSM_PMEM_ADSP_BASE		(MSM_PMEM_SF_BASE - MSM_PMEM_ADSP_SIZE)
#define MSM_FB_BASE				(0x40400000)
#define MSM_PMEM_AUDIO_BASE		(0x46400000)


#define MSM_SMI_BASE          0x38000000
#define MSM_SMI_SIZE          0x4000000

#define KERNEL_SMI_BASE       (MSM_SMI_BASE)
#define KERNEL_SMI_SIZE       0x400000

#define USER_SMI_BASE         (KERNEL_SMI_BASE + KERNEL_SMI_SIZE)
#define USER_SMI_SIZE         (MSM_SMI_SIZE - KERNEL_SMI_SIZE)
#define MSM_PMEM_SMIPOOL_BASE USER_SMI_BASE
#define MSM_PMEM_SMIPOOL_SIZE USER_SMI_SIZE

#ifdef CONFIG_MSM_MULTIMEDIA_USE_ION
#define MSM_ION_SF_SIZE       MSM_PMEM_SF_SIZE
#define MSM_ION_CAMERA_SIZE   0x2000000
#define MSM_ION_ROTATOR_SIZE  MSM_PMEM_ADSP2_SIZE
#define MSM_ION_MM_FW_SIZE    0x200000  
#define MSM_ION_MM_SIZE       0x3D00000 
#define MSM_ION_MFC_SIZE      0x100000  
#define MSM_ION_WB_SIZE       0x2FD000  

#ifdef CONFIG_TZCOM
#define MSM_ION_QSECOM_SIZE   MSM_PMEM_KERNEL_EBI1_SIZE
#ifdef CONFIG_MSM_IOMMU
#define MSM_ION_HEAP_NUM      9
#else
#define MSM_ION_HEAP_NUM      10
#endif
#else
#ifdef CONFIG_MSM_IOMMU
#define MSM_ION_HEAP_NUM      8
#else
#define MSM_ION_HEAP_NUM      9
#endif
#endif

#define MSM_ION_CAMERA_BASE   (0x40E00000)	
#define MSM_ION_WB_BASE       (0x46400000)
#define MSM_ION_AUDIO_BASE    (0x7FB00000)

#else 
#define MSM_ION_HEAP_NUM      1
#endif

#define PHY_BASE_ADDR1  0x48000000
#define SIZE_ADDR1      0x38000000


#define PYRAMID_GPIO_KEY_CAM_STEP1   (123)
#define PYRAMID_GPIO_KEY_VOL_DOWN    (103)
#define PYRAMID_GPIO_KEY_VOL_UP      (104)
#define PYRAMID_GPIO_KEY_CAM_STEP2   (115)
#define PYRAMID_GPIO_KEY_POWER       (125)

#define PYRAMID_GPIO_CAPTURE_MODE_KEY       (131) 
#define PYRAMID_GPIO_VIDEO_MODE_KEY       (68)

#define PYRAMID_GPIO_MBAT_IN		   (61)
#define PYRAMID_GPIO_CHG_INT		   (126)

#define PYRAMID_GPIO_WIFI_IRQ              (46)
#define PYRAMID_GPIO_WIFI_SHUTDOWN_N       (96)

#define PYRAMID_GPIO_WIMAX_UART_SIN        (41)
#define PYRAMID_GPIO_WIMAX_UART_SOUT       (42)
#define PYRAMID_GPIO_V_WIMAX_1V2_RF_EN     (43)
#define PYRAMID_GPIO_FL_I2C_SDA            (43)
#define PYRAMID_GPIO_FL_I2C_SCL            (44)
#define PYRAMID_GPIO_WIMAX_EXT_RST         (49)
#define PYRAMID_GPIO_V_WIMAX_DVDD_EN       (94)
#define PYRAMID_GPIO_V_WIMAX_PVDD_EN       (105)
#define PYRAMID_GPIO_WIMAX_SDIO_D0         (143)
#define PYRAMID_GPIO_WIMAX_SDIO_D1         (144)
#define PYRAMID_GPIO_WIMAX_SDIO_D2         (145)
#define PYRAMID_GPIO_WIMAX_SDIO_D3         (146)
#define PYRAMID_GPIO_WIMAX_SDIO_CMD        (151)
#define PYRAMID_GPIO_WIMAX_SDIO_CLK_CPU    (152)
#define PYRAMID_GPIO_CPU_WIMAX_SW          (156)
#define PYRAMID_GPIO_CPU_WIMAX_UART_EN     (157)

#define PYRAMID_SENSOR_I2C_SDA		(72)
#define PYRAMID_SENSOR_I2C_SCL		(73)
#define PYRAMID_GYRO_INT               (127)

#define PYRAMID_GENERAL_I2C_SDA		(59)
#define PYRAMID_GENERAL_I2C_SCL		(60)


#define PYRAMID_GPIO_TP_I2C_SDA         (51)
#define PYRAMID_GPIO_TP_I2C_SCL         (52)
#define PYRAMID_GPIO_TP_ATTz		(57)

#define PYRAMID_GPIO_CAP_I2C_SCL	(115)
#define PYRAMID_GPIO_CAP_I2C_SDA	(116)
#define PYRAMID_GPIO_CAP_RST		(6)
#define PYRAMID_GPIO_CAP_ATTz		(67)

#define GPIO_LCD_TE	28
#define GPIO_LCM_ID	50
#define GPIO_LCM_RST_N	66

#define PYRAMID_GPIO_QTR_SDA    (64)
#define PYRAMID_GPIO_QTR_SCL    (65)
#define PYRAMID_GPIO_BT_HOST_WAKE      (45)
#define PYRAMID_GPIO_BT_UART1_TX       (53)
#define PYRAMID_GPIO_BT_UART1_RX       (54)
#define PYRAMID_GPIO_BT_UART1_CTS      (55)
#define PYRAMID_GPIO_BT_UART1_RTS      (56)
#define PYRAMID_GPIO_BT_SHUTDOWN_N     (100)
#define PYRAMID_GPIO_BT_CHIP_WAKE      (130)
#define PYRAMID_GPIO_BT_RESET_N        (142)

#define PYRAMID_GPIO_MHL_WAKE_UP        (62)
#define PYRAMID_GPIO_USB_ID        (63)
#define PYRAMID_GPIO_MHL_RESET        (70)
#define PYRAMID_GPIO_MHL_INT		(71)
#define PYRAMID_GPIO_MHL_USB_EN         (139)
#define PYRAMID_GPIO_MHL_USB_SW        (99)

#define PYRAMID_CAM_I2C_SDA           (47)
#define PYRAMID_CAM_I2C_SCL           (48)
#define PYRAMID_CAM_ID           (135)
#define PYRAMID_GPIO_V_CAM_D1V2_EN     (7)
#define PYRAMID_GPIO_CAM_MCLK     	(32)
#define PYRAMID_GPIO_RAW_RSTN         (49)
#define PYRAMID_GPIO_RAW_INTR0       (106)
#define PYRAMID_GPIO_RAW_INTR1       (105)
#define PYRAMID_GPIO_MCLK_SWITCH     (141)

#define PYRAMID_GPIO_CAM2_RSTz       (138)
#define PYRAMID_GPIO_CAM_PWDN        (107)
#define PYRAMID_GPIO_CAM2_PWDN       (140)
#define PYRAMID_GPIO_CAM_VCM_PD       (58)

#define PYRAMID_GPIO_MCAM_SPI_DO	(33)
#define PYRAMID_GPIO_MCAM_SPI_DI	(34)
#define PYRAMID_GPIO_MCAM_SPI_CLK	(36)
#define PYRAMID_GPIO_MCAM_SPI_CS	(35)

#define PYRAMID_FLASH_EN				(29)
#define PYRAMID_FLASH_TORCH             (30)
#define PYRAMID_FLASH_RST				(139)

#define PYRAMID_GPIO_AUD_HP_DET        (31)
#define PYRAMID_AUD_UART_TX		(41)
#define PYRAMID_AUD_UART_RX		(42)

#define PYRAMID_SPI_DO                 (33)
#define PYRAMID_SPI_DI                 (34)
#define PYRAMID_SPI_CS                 (35)
#define PYRAMID_SPI_CLK                (36)


#define PMGPIO(x) (x-1)
#define PYRAMID_VOL_UP             (104)
#define PYRAMID_VOL_DN             (103)
#define PYRAMID_AUD_QTR_RESET      PMGPIO(21)
#define PYRAMID_AUD_HANDSET_ENO    PMGPIO(18)
#define PYRAMID_AUD_SPK_ENO        PMGPIO(19)
#define PYRAMID_AUD_2V85_EN        PMGPIO(34) 
#define PYRAMID_AUD_UART_OE        PMGPIO(20) 
#define PYRAMID_PS_VOUT            PMGPIO(22)
#define PYRAMID_GREEN_LED          PMGPIO(24)
#define PYRAMID_AMBER_LED          PMGPIO(25)
#define PYRAMID_AUD_2V85_EN	   PMGPIO(34)
#define PYRAMID_SDC3_DET           PMGPIO(35) 
#define PYRAMID_AUD_REMO_PRESz	   PMGPIO(37)
#define PYRAMID_WIFI_BT_SLEEP_CLK  PMGPIO(38)
#define PYRAMID_WIMAX_HOST_WAKEUP  PMGPIO(17)
#define PYRAMID_TP_RST             PMGPIO(23)
#define PYRAMID_TORCH_SET1         PMGPIO(40)
#define PYRAMID_TORCH_SET2         PMGPIO(31)
#define PYRAMID_CHG_STAT		 PMGPIO(33)
#define PYRAMID_AUD_REMO_EN        PMGPIO(15)
#define PYRAMID_AUD_REMO_PRES      PMGPIO(37)

#ifdef CONFIG_RESET_BY_CABLE_IN
#define PYRAMID_CHG_WDT_EN	       PMGPIO(15)
#define PYRAMID_WDT_RST            PMGPIO(16)
#endif

extern int panel_type;

int __init pyramid_init_mmc(void);
void __init pyramid_audio_init(void);
int __init pyramid_init_keypad(void);
int __init pyramid_wifi_init(void);
int __init pyramid_init_panel(struct resource *res, size_t size);
void pyramid_init_gpiomux(void);

#endif 
