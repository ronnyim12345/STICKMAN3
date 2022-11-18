#ifndef INCLUDES_AND_DEFS_H
#define INCLUDES_AND_DEFS_H
/****************************************************************************************
 * includes_and_defs.h
 * Stores all preprocessor statements necessary for the program to keep our C file short 
****************************************************************************************/

// necessary include statements
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <linux/i2c-dev.h>
#include "hwlib.h"
#include "ADXL345.h"

// object header files
#include "stickman.h"
#include "tree.h"
#include "hatchet.h"
#include "door.h"
#include "river.h"
#include "treasureChest.h"

// defines for memory addressing
#define HW_REGS_BASE ( 0xFC000000 )
#define HW_OCRAM_BASE ( 0xC8000000 )
#define HW_REGS_SPAN ( 0x04000000 )
#define HW_REGS_MASK ( HW_REGS_SPAN - 1 )
#define FPGA_CHAR_BASE      0xC9000000
#define PHYSMEM_32(addr) (*((unsigned int *)(virtual_base + (addr & HW_REGS_MASK))))
#define PHYSMEM_16(addr) (*((unsigned short *)(virtual_base + (addr & HW_REGS_MASK))))
#define PHYSMEM_32_reg(addr) (*((unsigned int *)(virtual_base_reg + (addr & HW_REGS_MASK))))
#define PHYSMEM_16_reg(addr) (*((unsigned short *)(virtual_base_reg + (addr & HW_REGS_MASK))))

// general screen defines
#define X_MAX 320
#define Y_MAX 480
#define BLACK 0x0000
#define WHITE 0xFFFF
#define BROWN 0xF900
#define YELLOW 0xFA701

// box defines
#define BOX_WIDTH 25
#define BOX_HEIGHT 50
#define DELTA_X 3
#define DELTA_Y 6

// stickman defines
#define STICKMAN_WIDTH 9
#define STICKMAN_HEIGHT 26

// inventory defines
#define HEIGHT_INV_BOX 50
#define WIDTH_INV_BOX 33

#endif //INCLUDES_AND_DEFS_H
