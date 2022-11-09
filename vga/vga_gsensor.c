#include "includes_and_defs.h"
#include "ADXL_functions.h"
#include "VGA_functions.h"

// Test program for use with the DE1-SoC University Computer
int main(int argc,char ** argv) {
	
	// vga variables
    void *virtual_base;
    int fd;
	// gsensor variables
	int file;
	const char *filename = "/dev/i2c-0";
	uint8_t id;
	bool bSuccess;
	const int mg_per_digi = 4;
	uint16_t szXYZ[3];
	int cnt=0, max_cnt=0;

	// this is a test for git
  	
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
	printf("\n\n");
	TreasureChest_display_info(treasureChest);
	
	
	// gsensor loop to display 3-axis acceleration data
	while(bSuccess && (max_cnt == 0 || cnt < max_cnt)){
		if (ADXL345_IsDataReady(file)){
			bSuccess = ADXL345_XYZ_Read(file, szXYZ);
			if (bSuccess){
				cnt++;
				//printf("[%d]X=%d mg, Y=%d mg, Z=%d mg\r\n", cnt,(int16_t)szXYZ[0]*mg_per_digi, (int16_t)szXYZ[1]*mg_per_digi, (int16_t)szXYZ[2]*mg_per_digi);
				
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
				
				// if stickman tries to go outside window boundaries
				if ((x1_new + STICKMAN_WIDTH >= X_MAX || x1_new <= 0) || (y1_new >= Y_MAX || y1_new - STICKMAN_HEIGHT <= 0) ) {
					//reset coordinates before out of bounds
					x1_new = x1_old;
					y1_new = y1_old;
				}
				
				// if stickman overlaps with the chest
				if ((x1_new + STICKMAN_WIDTH >= treasureChest->x - 2 && x1_new <= treasureChest->x + 33) && (y1_new >= treasureChest->y && y1_new - STICKMAN_HEIGHT <= treasureChest->y + 46) ) {
					//reset coordinates before overlap
					x1_new = x1_old;
					y1_new = y1_old;
				}
				
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
