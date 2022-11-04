#ifndef _ALTERA_ARM_A9_HPS_ARM_A9_0_H_
#define _ALTERA_ARM_A9_HPS_ARM_A9_0_H_

/*
 * This file was automatically generated by the swinfo2header utility.
 * 
 * Created from SOPC Builder system 'Computer_System' in
 * file 'Computer_System.sopcinfo'.
 */

/*
 * This file contains macros for module 'ARM_A9_HPS_arm_a9_0' and devices
 * connected to the following master:
 *   altera_axi_master
 * 
 * Do not include this header file and another header file created for a
 * different module or master group at the same time.
 * Doing so may result in duplicate macro names.
 * Instead, use the system header file which has macros with unique names.
 */

/*
 * Macros for device 'ARM_A9_HPS_axi_sdram', class 'axi_sdram'
 * The macros are prefixed with 'ARM_A9_HPS_AXI_SDRAM_'.
 * The prefix is the slave descriptor.
 */
#define ARM_A9_HPS_AXI_SDRAM_COMPONENT_TYPE axi_sdram
#define ARM_A9_HPS_AXI_SDRAM_COMPONENT_NAME ARM_A9_HPS_axi_sdram
#define ARM_A9_HPS_AXI_SDRAM_BASE 0x0
#define ARM_A9_HPS_AXI_SDRAM_SPAN 0x80000000
#define ARM_A9_HPS_AXI_SDRAM_END 0x7fffffff
#define ARM_A9_HPS_AXI_SDRAM_SIZE_MULTIPLE 1
#define ARM_A9_HPS_AXI_SDRAM_SIZE_VALUE 1<<31
#define ARM_A9_HPS_AXI_SDRAM_WRITABLE 1
#define ARM_A9_HPS_AXI_SDRAM_MEMORY_INFO_GENERATE_DAT_SYM 0
#define ARM_A9_HPS_AXI_SDRAM_MEMORY_INFO_GENERATE_HEX 0
#define ARM_A9_HPS_AXI_SDRAM_MEMORY_INFO_MEM_INIT_DATA_WIDTH 31

/*
 * Macros for device 'SDRAM', class 'altera_avalon_new_sdram_controller'
 * The macros are prefixed with 'SDRAM_'.
 * The prefix is the slave descriptor.
 */
#define SDRAM_COMPONENT_TYPE altera_avalon_new_sdram_controller
#define SDRAM_COMPONENT_NAME SDRAM
#define SDRAM_BASE 0xc0000000
#define SDRAM_SPAN 67108864
#define SDRAM_END 0xc3ffffff
#define SDRAM_CAS_LATENCY 3
#define SDRAM_CONTENTS_INFO 
#define SDRAM_INIT_NOP_DELAY 0.0
#define SDRAM_INIT_REFRESH_COMMANDS 2
#define SDRAM_IS_INITIALIZED 1
#define SDRAM_POWERUP_DELAY 100.0
#define SDRAM_REFRESH_PERIOD 15.625
#define SDRAM_REGISTER_DATA_IN 1
#define SDRAM_SDRAM_ADDR_WIDTH 25
#define SDRAM_SDRAM_BANK_WIDTH 2
#define SDRAM_SDRAM_COL_WIDTH 10
#define SDRAM_SDRAM_DATA_WIDTH 16
#define SDRAM_SDRAM_NUM_BANKS 4
#define SDRAM_SDRAM_NUM_CHIPSELECTS 1
#define SDRAM_SDRAM_ROW_WIDTH 13
#define SDRAM_SHARED_DATA 0
#define SDRAM_SIM_MODEL_BASE 1
#define SDRAM_STARVATION_INDICATOR 0
#define SDRAM_TRISTATE_BRIDGE_SLAVE ""
#define SDRAM_T_AC 5.5
#define SDRAM_T_MRD 3
#define SDRAM_T_RCD 20.0
#define SDRAM_T_RFC 70.0
#define SDRAM_T_RP 20.0
#define SDRAM_T_WR 14.0
#define SDRAM_MEMORY_INFO_DAT_SYM_INSTALL_DIR SIM_DIR
#define SDRAM_MEMORY_INFO_GENERATE_DAT_SYM 1
#define SDRAM_MEMORY_INFO_MEM_INIT_DATA_WIDTH 16

/*
 * Macros for device 'Onchip_SRAM', class 'altera_avalon_onchip_memory2'
 * The macros are prefixed with 'ONCHIP_SRAM_'.
 * The prefix is the slave descriptor.
 */
#define ONCHIP_SRAM_COMPONENT_TYPE altera_avalon_onchip_memory2
#define ONCHIP_SRAM_COMPONENT_NAME Onchip_SRAM
#define ONCHIP_SRAM_BASE 0xc8000000
#define ONCHIP_SRAM_SPAN 262144
#define ONCHIP_SRAM_END 0xc803ffff
#define ONCHIP_SRAM_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_SRAM_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_SRAM_CONTENTS_INFO ""
#define ONCHIP_SRAM_DUAL_PORT 1
#define ONCHIP_SRAM_GUI_RAM_BLOCK_TYPE AUTO
#define ONCHIP_SRAM_INIT_CONTENTS_FILE Computer_System_Onchip_SRAM
#define ONCHIP_SRAM_INIT_MEM_CONTENT 1
#define ONCHIP_SRAM_INSTANCE_ID NONE
#define ONCHIP_SRAM_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_SRAM_RAM_BLOCK_TYPE AUTO
#define ONCHIP_SRAM_READ_DURING_WRITE_MODE DONT_CARE
#define ONCHIP_SRAM_SINGLE_CLOCK_OP 1
#define ONCHIP_SRAM_SIZE_MULTIPLE 1
#define ONCHIP_SRAM_SIZE_VALUE 262144
#define ONCHIP_SRAM_WRITABLE 1
#define ONCHIP_SRAM_MEMORY_INFO_DAT_SYM_INSTALL_DIR SIM_DIR
#define ONCHIP_SRAM_MEMORY_INFO_GENERATE_DAT_SYM 1
#define ONCHIP_SRAM_MEMORY_INFO_GENERATE_HEX 1
#define ONCHIP_SRAM_MEMORY_INFO_HAS_BYTE_LANE 0
#define ONCHIP_SRAM_MEMORY_INFO_HEX_INSTALL_DIR QPF_DIR
#define ONCHIP_SRAM_MEMORY_INFO_MEM_INIT_DATA_WIDTH 32
#define ONCHIP_SRAM_MEMORY_INFO_MEM_INIT_FILENAME Computer_System_Onchip_SRAM

/*
 * Macros for device 'VGA_Subsystem_VGA_Char_Buffer_avalon_char_buffer_slave', class 'altera_up_avalon_video_character_buffer_with_dma'
 * The macros are prefixed with 'VGA_SUBSYSTEM_VGA_CHAR_BUFFER_AVALON_CHAR_BUFFER_SLAVE_'.
 * The prefix is the slave descriptor.
 */
#define VGA_SUBSYSTEM_VGA_CHAR_BUFFER_AVALON_CHAR_BUFFER_SLAVE_COMPONENT_TYPE altera_up_avalon_video_character_buffer_with_dma
#define VGA_SUBSYSTEM_VGA_CHAR_BUFFER_AVALON_CHAR_BUFFER_SLAVE_COMPONENT_NAME VGA_Subsystem_VGA_Char_Buffer
#define VGA_SUBSYSTEM_VGA_CHAR_BUFFER_AVALON_CHAR_BUFFER_SLAVE_BASE 0xc9000000
#define VGA_SUBSYSTEM_VGA_CHAR_BUFFER_AVALON_CHAR_BUFFER_SLAVE_SPAN 8192
#define VGA_SUBSYSTEM_VGA_CHAR_BUFFER_AVALON_CHAR_BUFFER_SLAVE_END 0xc9001fff

/*
 * Macros for device 'LEDs', class 'altera_avalon_pio'
 * The macros are prefixed with 'LEDS_'.
 * The prefix is the slave descriptor.
 */
#define LEDS_COMPONENT_TYPE altera_avalon_pio
#define LEDS_COMPONENT_NAME LEDs
#define LEDS_BASE 0xff200000
#define LEDS_SPAN 16
#define LEDS_END 0xff20000f
#define LEDS_BIT_CLEARING_EDGE_REGISTER 0
#define LEDS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LEDS_CAPTURE 0
#define LEDS_DATA_WIDTH 10
#define LEDS_DO_TEST_BENCH_WIRING 0
#define LEDS_DRIVEN_SIM_VALUE 0
#define LEDS_EDGE_TYPE NONE
#define LEDS_FREQ 100000000
#define LEDS_HAS_IN 0
#define LEDS_HAS_OUT 1
#define LEDS_HAS_TRI 0
#define LEDS_IRQ_TYPE NONE
#define LEDS_RESET_VALUE 0

/*
 * Macros for device 'HEX3_HEX0', class 'altera_avalon_pio'
 * The macros are prefixed with 'HEX3_HEX0_'.
 * The prefix is the slave descriptor.
 */
#define HEX3_HEX0_COMPONENT_TYPE altera_avalon_pio
#define HEX3_HEX0_COMPONENT_NAME HEX3_HEX0
#define HEX3_HEX0_BASE 0xff200020
#define HEX3_HEX0_SPAN 16
#define HEX3_HEX0_END 0xff20002f
#define HEX3_HEX0_BIT_CLEARING_EDGE_REGISTER 0
#define HEX3_HEX0_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HEX3_HEX0_CAPTURE 0
#define HEX3_HEX0_DATA_WIDTH 16
#define HEX3_HEX0_DO_TEST_BENCH_WIRING 0
#define HEX3_HEX0_DRIVEN_SIM_VALUE 0
#define HEX3_HEX0_EDGE_TYPE NONE
#define HEX3_HEX0_FREQ 100000000
#define HEX3_HEX0_HAS_IN 0
#define HEX3_HEX0_HAS_OUT 1
#define HEX3_HEX0_HAS_TRI 0
#define HEX3_HEX0_IRQ_TYPE NONE
#define HEX3_HEX0_RESET_VALUE 0

/*
 * Macros for device 'Slider_Switches', class 'altera_avalon_pio'
 * The macros are prefixed with 'SLIDER_SWITCHES_'.
 * The prefix is the slave descriptor.
 */
#define SLIDER_SWITCHES_COMPONENT_TYPE altera_avalon_pio
#define SLIDER_SWITCHES_COMPONENT_NAME Slider_Switches
#define SLIDER_SWITCHES_BASE 0xff200040
#define SLIDER_SWITCHES_SPAN 16
#define SLIDER_SWITCHES_END 0xff20004f
#define SLIDER_SWITCHES_BIT_CLEARING_EDGE_REGISTER 0
#define SLIDER_SWITCHES_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SLIDER_SWITCHES_CAPTURE 0
#define SLIDER_SWITCHES_DATA_WIDTH 10
#define SLIDER_SWITCHES_DO_TEST_BENCH_WIRING 1
#define SLIDER_SWITCHES_DRIVEN_SIM_VALUE 0
#define SLIDER_SWITCHES_EDGE_TYPE NONE
#define SLIDER_SWITCHES_FREQ 100000000
#define SLIDER_SWITCHES_HAS_IN 1
#define SLIDER_SWITCHES_HAS_OUT 0
#define SLIDER_SWITCHES_HAS_TRI 0
#define SLIDER_SWITCHES_IRQ_TYPE NONE
#define SLIDER_SWITCHES_RESET_VALUE 0

/*
 * Macros for device 'Pushbuttons', class 'altera_avalon_pio'
 * The macros are prefixed with 'PUSHBUTTONS_'.
 * The prefix is the slave descriptor.
 */
#define PUSHBUTTONS_COMPONENT_TYPE altera_avalon_pio
#define PUSHBUTTONS_COMPONENT_NAME Pushbuttons
#define PUSHBUTTONS_BASE 0xff200050
#define PUSHBUTTONS_SPAN 16
#define PUSHBUTTONS_END 0xff20005f
#define PUSHBUTTONS_BIT_CLEARING_EDGE_REGISTER 1
#define PUSHBUTTONS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PUSHBUTTONS_CAPTURE 1
#define PUSHBUTTONS_DATA_WIDTH 4
#define PUSHBUTTONS_DO_TEST_BENCH_WIRING 1
#define PUSHBUTTONS_DRIVEN_SIM_VALUE 0
#define PUSHBUTTONS_EDGE_TYPE FALLING
#define PUSHBUTTONS_FREQ 100000000
#define PUSHBUTTONS_HAS_IN 1
#define PUSHBUTTONS_HAS_OUT 0
#define PUSHBUTTONS_HAS_TRI 0
#define PUSHBUTTONS_IRQ_TYPE EDGE
#define PUSHBUTTONS_RESET_VALUE 0

/*
 * Macros for device 'SysID', class 'altera_avalon_sysid_qsys'
 * The macros are prefixed with 'SYSID_'.
 * The prefix is the slave descriptor.
 */
#define SYSID_COMPONENT_TYPE altera_avalon_sysid_qsys
#define SYSID_COMPONENT_NAME SysID
#define SYSID_BASE 0xff202040
#define SYSID_SPAN 8
#define SYSID_END 0xff202047
#define SYSID_ID 0
#define SYSID_TIMESTAMP 1600543965

/*
 * Macros for device 'AV_Config', class 'altera_up_avalon_audio_and_video_config'
 * The macros are prefixed with 'AV_CONFIG_'.
 * The prefix is the slave descriptor.
 */
#define AV_CONFIG_COMPONENT_TYPE altera_up_avalon_audio_and_video_config
#define AV_CONFIG_COMPONENT_NAME AV_Config
#define AV_CONFIG_BASE 0xff203000
#define AV_CONFIG_SPAN 16
#define AV_CONFIG_END 0xff20300f

/*
 * Macros for device 'Pixel_DMA_Addr_Translation', class 'altera_up_avalon_video_dma_ctrl_addr_trans'
 * The macros are prefixed with 'PIXEL_DMA_ADDR_TRANSLATION_'.
 * The prefix is the slave descriptor.
 */
#define PIXEL_DMA_ADDR_TRANSLATION_COMPONENT_TYPE altera_up_avalon_video_dma_ctrl_addr_trans
#define PIXEL_DMA_ADDR_TRANSLATION_COMPONENT_NAME Pixel_DMA_Addr_Translation
#define PIXEL_DMA_ADDR_TRANSLATION_BASE 0xff203020
#define PIXEL_DMA_ADDR_TRANSLATION_SPAN 16
#define PIXEL_DMA_ADDR_TRANSLATION_END 0xff20302f

/*
 * Macros for device 'VGA_Subsystem_VGA_Char_Buffer_avalon_char_control_slave', class 'altera_up_avalon_video_character_buffer_with_dma'
 * The macros are prefixed with 'VGA_SUBSYSTEM_VGA_CHAR_BUFFER_AVALON_CHAR_CONTROL_SLAVE_'.
 * The prefix is the slave descriptor.
 */
#define VGA_SUBSYSTEM_VGA_CHAR_BUFFER_AVALON_CHAR_CONTROL_SLAVE_COMPONENT_TYPE altera_up_avalon_video_character_buffer_with_dma
#define VGA_SUBSYSTEM_VGA_CHAR_BUFFER_AVALON_CHAR_CONTROL_SLAVE_COMPONENT_NAME VGA_Subsystem_VGA_Char_Buffer
#define VGA_SUBSYSTEM_VGA_CHAR_BUFFER_AVALON_CHAR_CONTROL_SLAVE_BASE 0xff203030
#define VGA_SUBSYSTEM_VGA_CHAR_BUFFER_AVALON_CHAR_CONTROL_SLAVE_SPAN 8
#define VGA_SUBSYSTEM_VGA_CHAR_BUFFER_AVALON_CHAR_CONTROL_SLAVE_END 0xff203037

/*
 * Macros for device 'Audio_Subsystem_Audio', class 'altera_up_avalon_audio'
 * The macros are prefixed with 'AUDIO_SUBSYSTEM_AUDIO_'.
 * The prefix is the slave descriptor.
 */
#define AUDIO_SUBSYSTEM_AUDIO_COMPONENT_TYPE altera_up_avalon_audio
#define AUDIO_SUBSYSTEM_AUDIO_COMPONENT_NAME Audio_Subsystem_Audio
#define AUDIO_SUBSYSTEM_AUDIO_BASE 0xff203040
#define AUDIO_SUBSYSTEM_AUDIO_SPAN 16
#define AUDIO_SUBSYSTEM_AUDIO_END 0xff20304f

/*
 * Macros for device 'ARM_A9_HPS_gmac0', class 'stmmac'
 * The macros are prefixed with 'ARM_A9_HPS_GMAC0_'.
 * The prefix is the slave descriptor.
 */
#define ARM_A9_HPS_GMAC0_COMPONENT_TYPE stmmac
#define ARM_A9_HPS_GMAC0_COMPONENT_NAME ARM_A9_HPS_gmac0
#define ARM_A9_HPS_GMAC0_BASE 0xff700000
#define ARM_A9_HPS_GMAC0_SPAN 8192
#define ARM_A9_HPS_GMAC0_END 0xff701fff

/*
 * Macros for device 'ARM_A9_HPS_gmac1', class 'stmmac'
 * The macros are prefixed with 'ARM_A9_HPS_GMAC1_'.
 * The prefix is the slave descriptor.
 */
#define ARM_A9_HPS_GMAC1_COMPONENT_TYPE stmmac
#define ARM_A9_HPS_GMAC1_COMPONENT_NAME ARM_A9_HPS_gmac1
#define ARM_A9_HPS_GMAC1_BASE 0xff702000
#define ARM_A9_HPS_GMAC1_SPAN 8192
#define ARM_A9_HPS_GMAC1_END 0xff703fff

/*
 * Macros for device 'ARM_A9_HPS_sdmmc', class 'sdmmc'
 * The macros are prefixed with 'ARM_A9_HPS_SDMMC_'.
 * The prefix is the slave descriptor.
 */
#define ARM_A9_HPS_SDMMC_COMPONENT_TYPE sdmmc
#define ARM_A9_HPS_SDMMC_COMPONENT_NAME ARM_A9_HPS_sdmmc
#define ARM_A9_HPS_SDMMC_BASE 0xff704000
#define ARM_A9_HPS_SDMMC_SPAN 4096
#define ARM_A9_HPS_SDMMC_END 0xff704fff

/*
 * Macros for device 'ARM_A9_HPS_qspi', class 'cadence_qspi'
 * The macros are prefixed with 'ARM_A9_HPS_QSPI_'.
 * The prefix is the slave descriptor.
 */
#define ARM_A9_HPS_QSPI_COMPONENT_TYPE cadence_qspi
#define ARM_A9_HPS_QSPI_COMPONENT_NAME ARM_A9_HPS_qspi
#define ARM_A9_HPS_QSPI_BASE 0xff705000
#define ARM_A9_HPS_QSPI_SPAN 256
#define ARM_A9_HPS_QSPI_END 0xff7050ff

/*
 * Macros for device 'ARM_A9_HPS_fpgamgr', class 'altera_fpgamgr'
 * The macros are prefixed with 'ARM_A9_HPS_FPGAMGR_'.
 * The prefix is the slave descriptor.
 */
#define ARM_A9_HPS_FPGAMGR_COMPONENT_TYPE altera_fpgamgr
#define ARM_A9_HPS_FPGAMGR_COMPONENT_NAME ARM_A9_HPS_fpgamgr
#define ARM_A9_HPS_FPGAMGR_BASE 0xff706000
#define ARM_A9_HPS_FPGAMGR_SPAN 4096
#define ARM_A9_HPS_FPGAMGR_END 0xff706fff

/*
 * Macros for device 'ARM_A9_HPS_gpio0', class 'dw_gpio'
 * The macros are prefixed with 'ARM_A9_HPS_GPIO0_'.
 * The prefix is the slave descriptor.
 */
#define ARM_A9_HPS_GPIO0_COMPONENT_TYPE dw_gpio
#define ARM_A9_HPS_GPIO0_COMPONENT_NAME ARM_A9_HPS_gpio0
#define ARM_A9_HPS_GPIO0_BASE 0xff708000
#define ARM_A9_HPS_GPIO0_SPAN 256
#define ARM_A9_HPS_GPIO0_END 0xff7080ff

/*
 * Macros for device 'ARM_A9_HPS_gpio1', class 'dw_gpio'
 * The macros are prefixed with 'ARM_A9_HPS_GPIO1_'.
 * The prefix is the slave descriptor.
 */
#define ARM_A9_HPS_GPIO1_COMPONENT_TYPE dw_gpio
#define ARM_A9_HPS_GPIO1_COMPONENT_NAME ARM_A9_HPS_gpio1
#define ARM_A9_HPS_GPIO1_BASE 0xff709000
#define ARM_A9_HPS_GPIO1_SPAN 256
#define ARM_A9_HPS_GPIO1_END 0xff7090ff

/*
 * Macros for device 'ARM_A9_HPS_gpio2', class 'dw_gpio'
 * The macros are prefixed with 'ARM_A9_HPS_GPIO2_'.
 * The prefix is the slave descriptor.
 */
#define ARM_A9_HPS_GPIO2_COMPONENT_TYPE dw_gpio
#define ARM_A9_HPS_GPIO2_COMPONENT_NAME ARM_A9_HPS_gpio2
#define ARM_A9_HPS_GPIO2_BASE 0xff70a000
#define ARM_A9_HPS_GPIO2_SPAN 256
#define ARM_A9_HPS_GPIO2_END 0xff70a0ff

/*
 * Macros for device 'ARM_A9_HPS_l3regs', class 'altera_l3regs'
 * The macros are prefixed with 'ARM_A9_HPS_L3REGS_'.
 * The prefix is the slave descriptor.
 */
#define ARM_A9_HPS_L3REGS_COMPONENT_TYPE altera_l3regs
#define ARM_A9_HPS_L3REGS_COMPONENT_NAME ARM_A9_HPS_l3regs
#define ARM_A9_HPS_L3REGS_BASE 0xff800000
#define ARM_A9_HPS_L3REGS_SPAN 4096
#define ARM_A9_HPS_L3REGS_END 0xff800fff

/*
 * Macros for device 'ARM_A9_HPS_nand0', class 'denali_nand'
 * The macros are prefixed with 'ARM_A9_HPS_NAND0_'.
 * The prefix is the slave descriptor.
 */
#define ARM_A9_HPS_NAND0_COMPONENT_TYPE denali_nand
#define ARM_A9_HPS_NAND0_COMPONENT_NAME ARM_A9_HPS_nand0
#define ARM_A9_HPS_NAND0_BASE 0xff900000
#define ARM_A9_HPS_NAND0_SPAN 65536
#define ARM_A9_HPS_NAND0_END 0xff90ffff

/*
 * Macros for device 'ARM_A9_HPS_usb0', class 'usb'
 * The macros are prefixed with 'ARM_A9_HPS_USB0_'.
 * The prefix is the slave descriptor.
 */
#define ARM_A9_HPS_USB0_COMPONENT_TYPE usb
#define ARM_A9_HPS_USB0_COMPONENT_NAME ARM_A9_HPS_usb0
#define ARM_A9_HPS_USB0_BASE 0xffb00000
#define ARM_A9_HPS_USB0_SPAN 262144
#define ARM_A9_HPS_USB0_END 0xffb3ffff

/*
 * Macros for device 'ARM_A9_HPS_usb1', class 'usb'
 * The macros are prefixed with 'ARM_A9_HPS_USB1_'.
 * The prefix is the slave descriptor.
 */
#define ARM_A9_HPS_USB1_COMPONENT_TYPE usb
#define ARM_A9_HPS_USB1_COMPONENT_NAME ARM_A9_HPS_usb1
#define ARM_A9_HPS_USB1_BASE 0xffb40000
#define ARM_A9_HPS_USB1_SPAN 262144
#define ARM_A9_HPS_USB1_END 0xffb7ffff

/*
 * Macros for device 'ARM_A9_HPS_dcan0', class 'bosch_dcan'
 * The macros are prefixed with 'ARM_A9_HPS_DCAN0_'.
 * The prefix is the slave descriptor.
 */
#define ARM_A9_HPS_DCAN0_COMPONENT_TYPE bosch_dcan
#define ARM_A9_HPS_DCAN0_COMPONENT_NAME ARM_A9_HPS_dcan0
#define ARM_A9_HPS_DCAN0_BASE 0xffc00000
#define ARM_A9_HPS_DCAN0_SPAN 4096
#define ARM_A9_HPS_DCAN0_END 0xffc00fff

/*
 * Macros for device 'ARM_A9_HPS_dcan1', class 'bosch_dcan'
 * The macros are prefixed with 'ARM_A9_HPS_DCAN1_'.
 * The prefix is the slave descriptor.
 */
#define ARM_A9_HPS_DCAN1_COMPONENT_TYPE bosch_dcan
#define ARM_A9_HPS_DCAN1_COMPONENT_NAME ARM_A9_HPS_dcan1
#define ARM_A9_HPS_DCAN1_BASE 0xffc01000
#define ARM_A9_HPS_DCAN1_SPAN 4096
#define ARM_A9_HPS_DCAN1_END 0xffc01fff

/*
 * Macros for device 'ARM_A9_HPS_uart0', class 'snps_uart'
 * The macros are prefixed with 'ARM_A9_HPS_UART0_'.
 * The prefix is the slave descriptor.
 */
#define ARM_A9_HPS_UART0_COMPONENT_TYPE snps_uart
#define ARM_A9_HPS_UART0_COMPONENT_NAME ARM_A9_HPS_uart0
#define ARM_A9_HPS_UART0_BASE 0xffc02000
#define ARM_A9_HPS_UART0_SPAN 256
#define ARM_A9_HPS_UART0_END 0xffc020ff
#define ARM_A9_HPS_UART0_FIFO_DEPTH 128
#define ARM_A9_HPS_UART0_FIFO_HWFC 0
#define ARM_A9_HPS_UART0_FIFO_MODE 1
#define ARM_A9_HPS_UART0_FIFO_SWFC 0
#define ARM_A9_HPS_UART0_FREQ 100000000

/*
 * Macros for device 'ARM_A9_HPS_uart1', class 'snps_uart'
 * The macros are prefixed with 'ARM_A9_HPS_UART1_'.
 * The prefix is the slave descriptor.
 */
#define ARM_A9_HPS_UART1_COMPONENT_TYPE snps_uart
#define ARM_A9_HPS_UART1_COMPONENT_NAME ARM_A9_HPS_uart1
#define ARM_A9_HPS_UART1_BASE 0xffc03000
#define ARM_A9_HPS_UART1_SPAN 256
#define ARM_A9_HPS_UART1_END 0xffc030ff
#define ARM_A9_HPS_UART1_FIFO_DEPTH 128
#define ARM_A9_HPS_UART1_FIFO_HWFC 0
#define ARM_A9_HPS_UART1_FIFO_MODE 1
#define ARM_A9_HPS_UART1_FIFO_SWFC 0
#define ARM_A9_HPS_UART1_FREQ 100000000

/*
 * Macros for device 'ARM_A9_HPS_i2c0', class 'designware_i2c'
 * The macros are prefixed with 'ARM_A9_HPS_I2C0_'.
 * The prefix is the slave descriptor.
 */
#define ARM_A9_HPS_I2C0_COMPONENT_TYPE designware_i2c
#define ARM_A9_HPS_I2C0_COMPONENT_NAME ARM_A9_HPS_i2c0
#define ARM_A9_HPS_I2C0_BASE 0xffc04000
#define ARM_A9_HPS_I2C0_SPAN 256
#define ARM_A9_HPS_I2C0_END 0xffc040ff

/*
 * Macros for device 'ARM_A9_HPS_i2c1', class 'designware_i2c'
 * The macros are prefixed with 'ARM_A9_HPS_I2C1_'.
 * The prefix is the slave descriptor.
 */
#define ARM_A9_HPS_I2C1_COMPONENT_TYPE designware_i2c
#define ARM_A9_HPS_I2C1_COMPONENT_NAME ARM_A9_HPS_i2c1
#define ARM_A9_HPS_I2C1_BASE 0xffc05000
#define ARM_A9_HPS_I2C1_SPAN 256
#define ARM_A9_HPS_I2C1_END 0xffc050ff

/*
 * Macros for device 'ARM_A9_HPS_i2c2', class 'designware_i2c'
 * The macros are prefixed with 'ARM_A9_HPS_I2C2_'.
 * The prefix is the slave descriptor.
 */
#define ARM_A9_HPS_I2C2_COMPONENT_TYPE designware_i2c
#define ARM_A9_HPS_I2C2_COMPONENT_NAME ARM_A9_HPS_i2c2
#define ARM_A9_HPS_I2C2_BASE 0xffc06000
#define ARM_A9_HPS_I2C2_SPAN 256
#define ARM_A9_HPS_I2C2_END 0xffc060ff

/*
 * Macros for device 'ARM_A9_HPS_i2c3', class 'designware_i2c'
 * The macros are prefixed with 'ARM_A9_HPS_I2C3_'.
 * The prefix is the slave descriptor.
 */
#define ARM_A9_HPS_I2C3_COMPONENT_TYPE designware_i2c
#define ARM_A9_HPS_I2C3_COMPONENT_NAME ARM_A9_HPS_i2c3
#define ARM_A9_HPS_I2C3_BASE 0xffc07000
#define ARM_A9_HPS_I2C3_SPAN 256
#define ARM_A9_HPS_I2C3_END 0xffc070ff

/*
 * Macros for device 'ARM_A9_HPS_timer0', class 'dw_apb_timer_sp'
 * The macros are prefixed with 'ARM_A9_HPS_TIMER0_'.
 * The prefix is the slave descriptor.
 */
#define ARM_A9_HPS_TIMER0_COMPONENT_TYPE dw_apb_timer_sp
#define ARM_A9_HPS_TIMER0_COMPONENT_NAME ARM_A9_HPS_timer0
#define ARM_A9_HPS_TIMER0_BASE 0xffc08000
#define ARM_A9_HPS_TIMER0_SPAN 256
#define ARM_A9_HPS_TIMER0_END 0xffc080ff

/*
 * Macros for device 'ARM_A9_HPS_timer1', class 'dw_apb_timer_sp'
 * The macros are prefixed with 'ARM_A9_HPS_TIMER1_'.
 * The prefix is the slave descriptor.
 */
#define ARM_A9_HPS_TIMER1_COMPONENT_TYPE dw_apb_timer_sp
#define ARM_A9_HPS_TIMER1_COMPONENT_NAME ARM_A9_HPS_timer1
#define ARM_A9_HPS_TIMER1_BASE 0xffc09000
#define ARM_A9_HPS_TIMER1_SPAN 256
#define ARM_A9_HPS_TIMER1_END 0xffc090ff

/*
 * Macros for device 'ARM_A9_HPS_sdrctl', class 'altera_sdrctl'
 * The macros are prefixed with 'ARM_A9_HPS_SDRCTL_'.
 * The prefix is the slave descriptor.
 */
#define ARM_A9_HPS_SDRCTL_COMPONENT_TYPE altera_sdrctl
#define ARM_A9_HPS_SDRCTL_COMPONENT_NAME ARM_A9_HPS_sdrctl
#define ARM_A9_HPS_SDRCTL_BASE 0xffc25000
#define ARM_A9_HPS_SDRCTL_SPAN 4096
#define ARM_A9_HPS_SDRCTL_END 0xffc25fff

/*
 * Macros for device 'ARM_A9_HPS_timer2', class 'dw_apb_timer_osc'
 * The macros are prefixed with 'ARM_A9_HPS_TIMER2_'.
 * The prefix is the slave descriptor.
 */
#define ARM_A9_HPS_TIMER2_COMPONENT_TYPE dw_apb_timer_osc
#define ARM_A9_HPS_TIMER2_COMPONENT_NAME ARM_A9_HPS_timer2
#define ARM_A9_HPS_TIMER2_BASE 0xffd00000
#define ARM_A9_HPS_TIMER2_SPAN 256
#define ARM_A9_HPS_TIMER2_END 0xffd000ff

/*
 * Macros for device 'ARM_A9_HPS_timer3', class 'dw_apb_timer_osc'
 * The macros are prefixed with 'ARM_A9_HPS_TIMER3_'.
 * The prefix is the slave descriptor.
 */
#define ARM_A9_HPS_TIMER3_COMPONENT_TYPE dw_apb_timer_osc
#define ARM_A9_HPS_TIMER3_COMPONENT_NAME ARM_A9_HPS_timer3
#define ARM_A9_HPS_TIMER3_BASE 0xffd01000
#define ARM_A9_HPS_TIMER3_SPAN 256
#define ARM_A9_HPS_TIMER3_END 0xffd010ff

/*
 * Macros for device 'ARM_A9_HPS_wd_timer0', class 'dw_wd_timer'
 * The macros are prefixed with 'ARM_A9_HPS_WD_TIMER0_'.
 * The prefix is the slave descriptor.
 */
#define ARM_A9_HPS_WD_TIMER0_COMPONENT_TYPE dw_wd_timer
#define ARM_A9_HPS_WD_TIMER0_COMPONENT_NAME ARM_A9_HPS_wd_timer0
#define ARM_A9_HPS_WD_TIMER0_BASE 0xffd02000
#define ARM_A9_HPS_WD_TIMER0_SPAN 256
#define ARM_A9_HPS_WD_TIMER0_END 0xffd020ff

/*
 * Macros for device 'ARM_A9_HPS_wd_timer1', class 'dw_wd_timer'
 * The macros are prefixed with 'ARM_A9_HPS_WD_TIMER1_'.
 * The prefix is the slave descriptor.
 */
#define ARM_A9_HPS_WD_TIMER1_COMPONENT_TYPE dw_wd_timer
#define ARM_A9_HPS_WD_TIMER1_COMPONENT_NAME ARM_A9_HPS_wd_timer1
#define ARM_A9_HPS_WD_TIMER1_BASE 0xffd03000
#define ARM_A9_HPS_WD_TIMER1_SPAN 256
#define ARM_A9_HPS_WD_TIMER1_END 0xffd030ff

/*
 * Macros for device 'ARM_A9_HPS_clkmgr', class 'asimov_clkmgr'
 * The macros are prefixed with 'ARM_A9_HPS_CLKMGR_'.
 * The prefix is the slave descriptor.
 */
#define ARM_A9_HPS_CLKMGR_COMPONENT_TYPE asimov_clkmgr
#define ARM_A9_HPS_CLKMGR_COMPONENT_NAME ARM_A9_HPS_clkmgr
#define ARM_A9_HPS_CLKMGR_BASE 0xffd04000
#define ARM_A9_HPS_CLKMGR_SPAN 4096
#define ARM_A9_HPS_CLKMGR_END 0xffd04fff

/*
 * Macros for device 'ARM_A9_HPS_rstmgr', class 'altera_rstmgr'
 * The macros are prefixed with 'ARM_A9_HPS_RSTMGR_'.
 * The prefix is the slave descriptor.
 */
#define ARM_A9_HPS_RSTMGR_COMPONENT_TYPE altera_rstmgr
#define ARM_A9_HPS_RSTMGR_COMPONENT_NAME ARM_A9_HPS_rstmgr
#define ARM_A9_HPS_RSTMGR_BASE 0xffd05000
#define ARM_A9_HPS_RSTMGR_SPAN 256
#define ARM_A9_HPS_RSTMGR_END 0xffd050ff

/*
 * Macros for device 'ARM_A9_HPS_sysmgr', class 'altera_sysmgr'
 * The macros are prefixed with 'ARM_A9_HPS_SYSMGR_'.
 * The prefix is the slave descriptor.
 */
#define ARM_A9_HPS_SYSMGR_COMPONENT_TYPE altera_sysmgr
#define ARM_A9_HPS_SYSMGR_COMPONENT_NAME ARM_A9_HPS_sysmgr
#define ARM_A9_HPS_SYSMGR_BASE 0xffd08000
#define ARM_A9_HPS_SYSMGR_SPAN 1024
#define ARM_A9_HPS_SYSMGR_END 0xffd083ff

/*
 * Macros for device 'ARM_A9_HPS_dma', class 'arm_pl330_dma'
 * The macros are prefixed with 'ARM_A9_HPS_DMA_'.
 * The prefix is the slave descriptor.
 */
#define ARM_A9_HPS_DMA_COMPONENT_TYPE arm_pl330_dma
#define ARM_A9_HPS_DMA_COMPONENT_NAME ARM_A9_HPS_dma
#define ARM_A9_HPS_DMA_BASE 0xffe01000
#define ARM_A9_HPS_DMA_SPAN 4096
#define ARM_A9_HPS_DMA_END 0xffe01fff

/*
 * Macros for device 'ARM_A9_HPS_spim0', class 'spi'
 * The macros are prefixed with 'ARM_A9_HPS_SPIM0_'.
 * The prefix is the slave descriptor.
 */
#define ARM_A9_HPS_SPIM0_COMPONENT_TYPE spi
#define ARM_A9_HPS_SPIM0_COMPONENT_NAME ARM_A9_HPS_spim0
#define ARM_A9_HPS_SPIM0_BASE 0xfff00000
#define ARM_A9_HPS_SPIM0_SPAN 256
#define ARM_A9_HPS_SPIM0_END 0xfff000ff

/*
 * Macros for device 'ARM_A9_HPS_spim1', class 'spi'
 * The macros are prefixed with 'ARM_A9_HPS_SPIM1_'.
 * The prefix is the slave descriptor.
 */
#define ARM_A9_HPS_SPIM1_COMPONENT_TYPE spi
#define ARM_A9_HPS_SPIM1_COMPONENT_NAME ARM_A9_HPS_spim1
#define ARM_A9_HPS_SPIM1_BASE 0xfff01000
#define ARM_A9_HPS_SPIM1_SPAN 256
#define ARM_A9_HPS_SPIM1_END 0xfff010ff

/*
 * Macros for device 'ARM_A9_HPS_scu', class 'scu'
 * The macros are prefixed with 'ARM_A9_HPS_SCU_'.
 * The prefix is the slave descriptor.
 */
#define ARM_A9_HPS_SCU_COMPONENT_TYPE scu
#define ARM_A9_HPS_SCU_COMPONENT_NAME ARM_A9_HPS_scu
#define ARM_A9_HPS_SCU_BASE 0xfffec000
#define ARM_A9_HPS_SCU_SPAN 256
#define ARM_A9_HPS_SCU_END 0xfffec0ff

/*
 * Macros for device 'ARM_A9_HPS_timer', class 'arm_internal_timer'
 * The macros are prefixed with 'ARM_A9_HPS_TIMER_'.
 * The prefix is the slave descriptor.
 */
#define ARM_A9_HPS_TIMER_COMPONENT_TYPE arm_internal_timer
#define ARM_A9_HPS_TIMER_COMPONENT_NAME ARM_A9_HPS_timer
#define ARM_A9_HPS_TIMER_BASE 0xfffec600
#define ARM_A9_HPS_TIMER_SPAN 256
#define ARM_A9_HPS_TIMER_END 0xfffec6ff

/*
 * Macros for device 'ARM_A9_HPS_arm_gic_0', class 'arm_gic'
 * The macros are prefixed with 'ARM_A9_HPS_ARM_GIC_0_'.
 * The prefix is the slave descriptor.
 */
#define ARM_A9_HPS_ARM_GIC_0_COMPONENT_TYPE arm_gic
#define ARM_A9_HPS_ARM_GIC_0_COMPONENT_NAME ARM_A9_HPS_arm_gic_0
#define ARM_A9_HPS_ARM_GIC_0_BASE 0xfffed000
#define ARM_A9_HPS_ARM_GIC_0_SPAN 4096
#define ARM_A9_HPS_ARM_GIC_0_END 0xfffedfff

/*
 * Macros for device 'ARM_A9_HPS_L2', class 'arm_pl310_L2'
 * The macros are prefixed with 'ARM_A9_HPS_L2_'.
 * The prefix is the slave descriptor.
 */
#define ARM_A9_HPS_L2_COMPONENT_TYPE arm_pl310_L2
#define ARM_A9_HPS_L2_COMPONENT_NAME ARM_A9_HPS_L2
#define ARM_A9_HPS_L2_BASE 0xfffef000
#define ARM_A9_HPS_L2_SPAN 4096
#define ARM_A9_HPS_L2_END 0xfffeffff

/*
 * Macros for device 'ARM_A9_HPS_axi_ocram', class 'axi_ocram'
 * The macros are prefixed with 'ARM_A9_HPS_AXI_OCRAM_'.
 * The prefix is the slave descriptor.
 */
#define ARM_A9_HPS_AXI_OCRAM_COMPONENT_TYPE axi_ocram
#define ARM_A9_HPS_AXI_OCRAM_COMPONENT_NAME ARM_A9_HPS_axi_ocram
#define ARM_A9_HPS_AXI_OCRAM_BASE 0xffff0000
#define ARM_A9_HPS_AXI_OCRAM_SPAN 65536
#define ARM_A9_HPS_AXI_OCRAM_END 0xffffffff
#define ARM_A9_HPS_AXI_OCRAM_SIZE_MULTIPLE 1
#define ARM_A9_HPS_AXI_OCRAM_SIZE_VALUE 1<<16
#define ARM_A9_HPS_AXI_OCRAM_WRITABLE 1
#define ARM_A9_HPS_AXI_OCRAM_MEMORY_INFO_GENERATE_DAT_SYM 0
#define ARM_A9_HPS_AXI_OCRAM_MEMORY_INFO_GENERATE_HEX 0
#define ARM_A9_HPS_AXI_OCRAM_MEMORY_INFO_MEM_INIT_DATA_WIDTH 16


#endif /* _ALTERA_ARM_A9_HPS_ARM_A9_0_H_ */
