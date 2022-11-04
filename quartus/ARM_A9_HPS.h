#ifndef _ALTERA_ARM_A9_HPS_H_
#define _ALTERA_ARM_A9_HPS_H_

/*
 * This file was automatically generated by the swinfo2header utility.
 * 
 * Created from SOPC Builder system 'Computer_System' in
 * file 'Computer_System.sopcinfo'.
 */

/*
 * This file contains macros for module 'ARM_A9_HPS' and devices
 * connected to the following masters:
 *   h2f_axi_master
 *   h2f_lw_axi_master
 * 
 * Do not include this header file and another header file created for a
 * different module or master group at the same time.
 * Doing so may result in duplicate macro names.
 * Instead, use the system header file which has macros with unique names.
 */

/*
 * Macros for device 'SDRAM', class 'altera_avalon_new_sdram_controller'
 * The macros are prefixed with 'SDRAM_'.
 * The prefix is the slave descriptor.
 */
#define SDRAM_COMPONENT_TYPE altera_avalon_new_sdram_controller
#define SDRAM_COMPONENT_NAME SDRAM
#define SDRAM_BASE 0x0
#define SDRAM_SPAN 67108864
#define SDRAM_END 0x3ffffff
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
 * Macros for device 'LEDs', class 'altera_avalon_pio'
 * The macros are prefixed with 'LEDS_'.
 * The prefix is the slave descriptor.
 */
#define LEDS_COMPONENT_TYPE altera_avalon_pio
#define LEDS_COMPONENT_NAME LEDs
#define LEDS_BASE 0x0
#define LEDS_SPAN 16
#define LEDS_END 0xf
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
#define HEX3_HEX0_BASE 0x20
#define HEX3_HEX0_SPAN 16
#define HEX3_HEX0_END 0x2f
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
#define SLIDER_SWITCHES_BASE 0x40
#define SLIDER_SWITCHES_SPAN 16
#define SLIDER_SWITCHES_END 0x4f
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
#define PUSHBUTTONS_BASE 0x50
#define PUSHBUTTONS_SPAN 16
#define PUSHBUTTONS_END 0x5f
#define PUSHBUTTONS_IRQ 1
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
#define SYSID_BASE 0x2040
#define SYSID_SPAN 8
#define SYSID_END 0x2047
#define SYSID_ID 0
#define SYSID_TIMESTAMP 1600543965

/*
 * Macros for device 'AV_Config', class 'altera_up_avalon_audio_and_video_config'
 * The macros are prefixed with 'AV_CONFIG_'.
 * The prefix is the slave descriptor.
 */
#define AV_CONFIG_COMPONENT_TYPE altera_up_avalon_audio_and_video_config
#define AV_CONFIG_COMPONENT_NAME AV_Config
#define AV_CONFIG_BASE 0x3000
#define AV_CONFIG_SPAN 16
#define AV_CONFIG_END 0x300f

/*
 * Macros for device 'Pixel_DMA_Addr_Translation', class 'altera_up_avalon_video_dma_ctrl_addr_trans'
 * The macros are prefixed with 'PIXEL_DMA_ADDR_TRANSLATION_'.
 * The prefix is the slave descriptor.
 */
#define PIXEL_DMA_ADDR_TRANSLATION_COMPONENT_TYPE altera_up_avalon_video_dma_ctrl_addr_trans
#define PIXEL_DMA_ADDR_TRANSLATION_COMPONENT_NAME Pixel_DMA_Addr_Translation
#define PIXEL_DMA_ADDR_TRANSLATION_BASE 0x3020
#define PIXEL_DMA_ADDR_TRANSLATION_SPAN 16
#define PIXEL_DMA_ADDR_TRANSLATION_END 0x302f

/*
 * Macros for device 'VGA_Subsystem_VGA_Char_Buffer_avalon_char_control_slave', class 'altera_up_avalon_video_character_buffer_with_dma'
 * The macros are prefixed with 'VGA_SUBSYSTEM_VGA_CHAR_BUFFER_AVALON_CHAR_CONTROL_SLAVE_'.
 * The prefix is the slave descriptor.
 */
#define VGA_SUBSYSTEM_VGA_CHAR_BUFFER_AVALON_CHAR_CONTROL_SLAVE_COMPONENT_TYPE altera_up_avalon_video_character_buffer_with_dma
#define VGA_SUBSYSTEM_VGA_CHAR_BUFFER_AVALON_CHAR_CONTROL_SLAVE_COMPONENT_NAME VGA_Subsystem_VGA_Char_Buffer
#define VGA_SUBSYSTEM_VGA_CHAR_BUFFER_AVALON_CHAR_CONTROL_SLAVE_BASE 0x3030
#define VGA_SUBSYSTEM_VGA_CHAR_BUFFER_AVALON_CHAR_CONTROL_SLAVE_SPAN 8
#define VGA_SUBSYSTEM_VGA_CHAR_BUFFER_AVALON_CHAR_CONTROL_SLAVE_END 0x3037

/*
 * Macros for device 'Audio_Subsystem_Audio', class 'altera_up_avalon_audio'
 * The macros are prefixed with 'AUDIO_SUBSYSTEM_AUDIO_'.
 * The prefix is the slave descriptor.
 */
#define AUDIO_SUBSYSTEM_AUDIO_COMPONENT_TYPE altera_up_avalon_audio
#define AUDIO_SUBSYSTEM_AUDIO_COMPONENT_NAME Audio_Subsystem_Audio
#define AUDIO_SUBSYSTEM_AUDIO_BASE 0x3040
#define AUDIO_SUBSYSTEM_AUDIO_SPAN 16
#define AUDIO_SUBSYSTEM_AUDIO_END 0x304f
#define AUDIO_SUBSYSTEM_AUDIO_IRQ 6

/*
 * Macros for device 'Onchip_SRAM', class 'altera_avalon_onchip_memory2'
 * The macros are prefixed with 'ONCHIP_SRAM_'.
 * The prefix is the slave descriptor.
 */
#define ONCHIP_SRAM_COMPONENT_TYPE altera_avalon_onchip_memory2
#define ONCHIP_SRAM_COMPONENT_NAME Onchip_SRAM
#define ONCHIP_SRAM_BASE 0x8000000
#define ONCHIP_SRAM_SPAN 262144
#define ONCHIP_SRAM_END 0x803ffff
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
#define VGA_SUBSYSTEM_VGA_CHAR_BUFFER_AVALON_CHAR_BUFFER_SLAVE_BASE 0x9000000
#define VGA_SUBSYSTEM_VGA_CHAR_BUFFER_AVALON_CHAR_BUFFER_SLAVE_SPAN 8192
#define VGA_SUBSYSTEM_VGA_CHAR_BUFFER_AVALON_CHAR_BUFFER_SLAVE_END 0x9001fff


#endif /* _ALTERA_ARM_A9_HPS_H_ */
