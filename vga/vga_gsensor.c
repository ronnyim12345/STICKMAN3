#include "includes_and_defs.h"
#include "ADXL_functions.h"
#include "VGA_functions.h"

// Test program for use with the DE1-SoC University Computer
int main(int argc,char ** argv) {
	
	// vga variables
    void *virtual_base;
	void *virtual_base_reg;
    int fd;
	// gsensor variables
	int file;
	const char *filename = "/dev/i2c-0";
	uint8_t id;
	bool bSuccess;
	const int mg_per_digi = 4;
	uint16_t szXYZ[3];
	int cnt=0, max_cnt=0;

	int buttons = 0;
  	
	/****************************************************************************************
	* VGA Initializations
	****************************************************************************************/
   if( ( fd = open( "/dev/mem", ( O_RDWR | O_SYNC ) ) ) == -1 ) {
	    printf( "ERROR: could not open \"/dev/mem\"...\n" );
		return( 1 );
	}
    
	virtual_base = mmap( NULL, HW_REGS_SPAN, ( PROT_READ | PROT_WRITE ), MAP_SHARED, fd, HW_REGS_BASE );
	if( virtual_base == MAP_FAILED ) {
		printf( "ERROR: mmap() failed...\n" );
		close( fd );
		return( 1 );
	}
    // Set framebuffer addr to beginning of the SRAM
    PHYSMEM_32(0xff203024) = 0xc8000000;
    PHYSMEM_32(0xff203020) = 0xc8000000;
    // Unmap registers region, map onchip ram region
    if( munmap( virtual_base, HW_REGS_SPAN ) != 0 ) {
		printf( "ERROR: munmap() failed...\n" );
		close( fd );
		return( 1 );
	}
    virtual_base = mmap( NULL, HW_REGS_SPAN, ( PROT_READ | PROT_WRITE ), MAP_SHARED, fd, HW_OCRAM_BASE );
	if( virtual_base == MAP_FAILED ) {
		printf( "ERROR: mmap() failed...\n" );
		close( fd );
		return( 1 );
	}
	
	virtual_base_reg = mmap( NULL, HW_REGS_SPAN, ( PROT_READ | PROT_WRITE ), MAP_SHARED, fd, HW_REGS_BASE );
	if( virtual_base_reg == MAP_FAILED ) {
		printf( "ERROR: mmap() failed...\n" );
		close( fd );
		return( 1 );
	}
    // Set framebuffer addr to beginning of the SRAM
    PHYSMEM_32_reg(0xff203024) = 0xc8000000;
    PHYSMEM_32_reg(0xff203020) = 0xc8000000;
	
	/****************************************************************************************
	* Gsensor Initializations 
	****************************************************************************************/
	printf("===== gsensor test =====\r\n");
	
	if (argc == 2){
		max_cnt = atoi(argv[1]);
	}
	// open bus
	if ((file = open(filename, O_RDWR)) < 0) {
  	  /* ERROR HANDLING: you can check errno to see what went wrong */
	    perror("Failed to open the i2c bus of gsensor");
  	  exit(1);
	}	
	// init	 
	// gsensor i2c address: 101_0011
	int addr = 0b01010011; 
	if (ioctl(file, I2C_SLAVE, addr) < 0) {
  	  printf("Failed to acquire bus access and/or talk to slave.\n");
	    /* ERROR HANDLING; you can check errno to see what went wrong */
  	  exit(1);
	}	
    // configure accelerometer as +-2g and start measure
    bSuccess = ADXL345_Init(file);
    if (bSuccess){
        // dump chip id
        bSuccess = ADXL345_IdRead(file, &id);
        if (bSuccess)
            printf("id=%02Xh\r\n", id);
    } 
	
	// draw environment
    VGA_drawAllObjects(virtual_base);
	
	// declare variables for old and new coordinates
	int x1_old = X_MAX/2; 
	int y1_old = Y_MAX/2; 
	int x1_new = x1_old; 
	int y1_new = y1_old;
	
	// declare objects here
	Stickman* stickman = Stickman_create(x1_new, y1_new);
	printf("\n\n");
	Stickman_display_info(stickman);
	
	TreasureChest* treasureChest = TreasureChest_create(200, 1);
	Tree* tree = Tree_create(85, 120);
	Hatchet* hatchet = Hatchet_create(50, 300);
	Door* door = Door_create(260, 150);
	Key* key = Key_create(260, 150);
	
	printf("\n\n");
	TreasureChest_display_info(treasureChest);
	
	
	
	int loop = 0;
	
	// gsensor loop to display 3-axis acceleration data
	while(bSuccess && (max_cnt == 0 || cnt < max_cnt)){
		if (ADXL345_IsDataReady(file)){
			bSuccess = ADXL345_XYZ_Read(file, szXYZ);
			if (bSuccess){
				cnt++;
				//printf("[%d]X=%d mg, Y=%d mg, Z=%d mg\r\n", cnt,(int16_t)szXYZ[0]*mg_per_digi, (int16_t)szXYZ[1]*mg_per_digi, (int16_t)szXYZ[2]*mg_per_digi);
				
				buttons = PHYSMEM_32_reg(0xFF200050);
				
				// if X is greater than 100
				if ((int16_t)szXYZ[0]*mg_per_digi > 100){
					x1_new = x1_new+1;
				}
				else if ((int16_t)szXYZ[0]*mg_per_digi < -100){
					x1_new = x1_new-1;
				}
				// if Y is greater than 100
				if ((int16_t)szXYZ[1]*mg_per_digi > 100){
					y1_new = y1_new-1;
				}
				else if ((int16_t)szXYZ[1]*mg_per_digi < -100){
					y1_new = y1_new+1;
				}
				
				// if stickman tries to go outside WINDOW BOUNDARIES
				if ((x1_new + STICKMAN_WIDTH >= X_MAX || x1_new <= 0) || (y1_new >= Y_MAX || y1_new - STICKMAN_HEIGHT <= 0) ) {
					//reset coordinates before out of bounds
					x1_new = x1_old;
					y1_new = y1_old;
				}
				
				// if stickman overlaps with the CHEST
				if ((x1_new + STICKMAN_WIDTH >= treasureChest->x - 2 && x1_new <= treasureChest->x + 33) && (y1_new >= treasureChest->y && y1_new - STICKMAN_HEIGHT <= treasureChest->y + 46) ) {
					//reset coordinates before overlap
					x1_new = x1_old;
					y1_new = y1_old;
				}
				
				// if stickman overlaps with the TREE
				if ((x1_new + STICKMAN_WIDTH >= tree->x - 19 && x1_new <= tree->x + 28) && (y1_new >= tree->y - 70 && y1_new - STICKMAN_HEIGHT <= tree->y) ) {
					//reset coordinates before overlap
					x1_new = x1_old;
					y1_new = y1_old;
				}
				
				// if stickman overlaps with the HATCHET
				if ((x1_new + STICKMAN_WIDTH >= hatchet->x - 1 && x1_new <= hatchet->x + 10) && (y1_new >= hatchet->y && y1_new - STICKMAN_HEIGHT <= hatchet->y + 45) ) {
					//reset coordinates before overlap
					x1_new = x1_old;
					y1_new = y1_old;
					// check for stickman close to collecting the hatchet
					if ( buttons != 0) {
						// erase hatchet from original postion
						VGA_box(hatchet->x-2, hatchet->y, hatchet->x+15, hatchet->y+50, BLACK, virtual_base);
						// draw hatchet in inventory space and update coordinates
						VGA_hatchet(12, 26, virtual_base);
						Hatchet_init(hatchet, 12, 26);
					}
				}
				
				// if stickman overlaps with the DOOR
				if ((x1_new + STICKMAN_WIDTH >= door->x && x1_new <= door->x + 25) && (y1_new >= door->y && y1_new - STICKMAN_HEIGHT <= door->y + 75) ) {
					//reset coordinates before overlap
					x1_new = x1_old;
					y1_new = y1_old;
				}
				
				// if stickman overlaps with the INVENTORY HEADER
				if ((x1_new + STICKMAN_WIDTH >= 0 && x1_new <= 43) && (y1_new >= 0 && y1_new - STICKMAN_HEIGHT <= 20) ) {
					//reset coordinates before overlap
					x1_new = x1_old;
					y1_new = y1_old;
				}
				
				// if stickman overlaps with the INVENTORY BOXES
				if ((x1_new + STICKMAN_WIDTH >= 0 && x1_new <= 35) && (y1_new >= 0 && y1_new - STICKMAN_HEIGHT <= 174) ) {
					//reset coordinates before overlap
					x1_new = x1_old;
					y1_new = y1_old;
				}
				
				
				// if stickman overlaps with the RIVER
				unsigned int i;
				for (i=0; i <= 70; i++){
					
					//TOP-MOST RIVER SEGMENT:
					if ((x1_new + STICKMAN_WIDTH >= (130 + (i*20/70)) && x1_new <= (160 + (i*20/70)) ) && (y1_new >= i && y1_new - STICKMAN_HEIGHT <= (i+1)) ) {
						//reset coordinates before overlap
						x1_new = x1_old;
						y1_new = y1_old;
					}
					
					//2ND RIVER SEGMENT:
					if ((x1_new + STICKMAN_WIDTH >= (150 + (i*10/70)) && x1_new <= (180 + (i*10/70)) ) && (y1_new >= (70+i) && y1_new - STICKMAN_HEIGHT <= (71+i)) ) {
						//reset coordinates before overlap
						x1_new = x1_old;
						y1_new = y1_old;
					}
					
					//3RD RIVER SEGMENT:
					if ((x1_new + STICKMAN_WIDTH >= (160 + (i*20/70)) && x1_new <= (190 + (i*20/70)) ) && (y1_new >= (140+i) && y1_new - STICKMAN_HEIGHT <= (141+i)) ) {
						//reset coordinates before overlap
						x1_new = x1_old;
						y1_new = y1_old;
					}
					
					//4TH RIVER SEGMENT:
					if ((x1_new + STICKMAN_WIDTH >= (180 + (i*10/70)) && x1_new <= (210 + (i*10/70)) ) && (y1_new >= (210+i) && y1_new - STICKMAN_HEIGHT <= (211+i)) ) {
						//reset coordinates before overlap
						x1_new = x1_old;
						y1_new = y1_old;
					}
					
					//5TH RIVER SEGMENT:
					if ((x1_new + STICKMAN_WIDTH >= (190 + (i*20/70)) && x1_new <= (220 + (i*20/70)) ) && (y1_new >= (280+i) && y1_new - STICKMAN_HEIGHT <= (281+i)) ) {
						//reset coordinates before overlap
						x1_new = x1_old;
						y1_new = y1_old;
					}
					
					//6TH ONE IS THE BRIDGE !!!
					//(DRAWN IN VGA_functions.h)
					
					
					//7TH RIVER SEGMENT:
					if ((x1_new + STICKMAN_WIDTH >= (220 + (i*20/70)) && x1_new <= (253 + (i*20/70)) ) && (y1_new >= (420+i) && y1_new - STICKMAN_HEIGHT <= (421+i)) ) {
						//reset coordinates before overlap
						x1_new = x1_old;
						y1_new = y1_old;
					}
					
					
				}
				
				//draws pegs:
				VGA_box(210, 340, 212, 350, 0xF800, virtual_base);
				VGA_box(220, 410, 222, 420, 0xF800, virtual_base);
				VGA_box(240, 340, 242, 350, 0xF800, virtual_base);
				VGA_box(250, 410, 252, 420, 0xF800, virtual_base);
				
				//draw bridge:
				VGA_bridge(virtual_base);
				
				//Moving Waves:
				if(loop == 0){
					VGA_allWaves(129, BLACK, virtual_base);
					VGA_allWaves(126, 0X0FFF, virtual_base);
				}
				
				if(loop == 33 || loop == 100){
					VGA_allWaves(126, BLACK, virtual_base);
					VGA_allWaves(132, BLACK, virtual_base);
					VGA_allWaves(129, 0X0FFF, virtual_base);
				}
				
				if(loop == 66){
					VGA_allWaves(129, BLACK, virtual_base);
					VGA_allWaves(132, 0X0FFF, virtual_base);
				}
				
				if(loop == 133)
					loop = -1;
				
				loop = loop + 1;
				
				
				VGA_stickman(x1_old, y1_old, BLACK, virtual_base);

				VGA_stickman(x1_new, y1_new, WHITE, virtual_base);
				
				Stickman_init(stickman, x1_new, y1_new);
				Stickman_display_info(stickman);
				
				x1_old = x1_new;
				y1_old = y1_new;
			}
		}
	}
	
	// if unsuccessful / close file
    if (!bSuccess)
        printf("Failed to access accelerometer\r\n");
	
		if (file)
			close(file);
			
		printf("gsensor, bye!\r\n");
	
	
	if( munmap( virtual_base, HW_REGS_SPAN ) != 0 ) {
		printf( "ERROR: munmap() failed...\n" );
		close( fd );
		return( 1 );
	}
	
	if( munmap( virtual_base_reg, HW_REGS_SPAN ) != 0 ) {
		printf( "ERROR: munmap() failed...\n" );
		close( fd );
		return( 1 );
	}

	close( fd );

	return( 0 );

}


// necessary for drawing a circle
typedef unsigned char  byte;
typedef unsigned short word;
typedef long           fixed16_16;
fixed16_16 SIN_ACOS[1024];
byte *VGA=(byte *)0xA0000000L;        /* this points to video memory. */

/**************************************************************************
 *  circle_fast                                                           *
 *    Draws a circle by using fixed point numbers and a trigonometry      *    FIXME
 *    table.                                                              *
 * found from http://www.brackeen.com/vga/source/bc31/circle.c.html		  *
 **************************************************************************/
void VGA_circle(int x,int y, int radius, byte color)
{
  fixed16_16 n=0,invradius=(1/(float)radius)*0x10000L;
  int dx=0,dy=radius-1;
  word dxoffset,dyoffset,offset = (y<<8)+(y<<6)+x;

  while (dx<=dy)
  {
    dxoffset = (dx<<8) + (dx<<6);
    dyoffset = (dy<<8) + (dy<<6);
    VGA[offset+dy-dxoffset] = color;  /* octant 0 */
    VGA[offset+dx-dyoffset] = color;  /* octant 1 */
    VGA[offset-dx-dyoffset] = color;  /* octant 2 */
    VGA[offset-dy-dxoffset] = color;  /* octant 3 */
    VGA[offset-dy+dxoffset] = color;  /* octant 4 */
    VGA[offset-dx+dyoffset] = color;  /* octant 5 */
    VGA[offset+dx+dyoffset] = color;  /* octant 6 */
    VGA[offset+dy+dxoffset] = color;  /* octant 7 */
    dx++;
    n+=invradius;
    dy = (int)((radius * SIN_ACOS[(int)(n>>6)]) >> 16);
  }
}
