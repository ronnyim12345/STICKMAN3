/****************************************************************************************
 * VGA_functions.h
 * Stores all functions necessary for drawing objects on the VGA display 
****************************************************************************************/


/****************************************************************************************
 * Draw a filled rectangle on the VGA monitor 
****************************************************************************************/
void VGA_box(int x1, int y1, int x2, int y2, short pixel_color, void *virtual_base)
{ 
	unsigned int pixel_ptr, row, col;

	/* assume that the box coordinates are valid */
	for (row = y1; row <= y2; row++)
		for (col = x1; col <= x2; ++col)
		{
			pixel_ptr = HW_OCRAM_BASE + (row << 10) + (col << 1);
			PHYSMEM_16(pixel_ptr) = pixel_color;		// set pixel color
		}
}

/****************************************************************************************
 * Draw an un-filled rectangle on the VGA monitor 
****************************************************************************************/
void VGA_unfilled_box(int x1, int y1, int x2, int y2, int thickness, short pixel_color, short background_color, void *virtual_base)
{ 
	unsigned int pixel_ptr, row, col;

	/* assume that the box coordinates are valid */
	// draw rectangle with color that will be seen on screen
	for (row = y1; row <= y2; row++)
		for (col = x1; col <= x2; ++col)
		{
			pixel_ptr = HW_OCRAM_BASE + (row << 10) + (col << 1);
			PHYSMEM_16(pixel_ptr) = pixel_color;		// set pixel color
		}
		
	// draw rectangle in the middle of the previous one
	for (row = y1 + thickness; row <= y2 - thickness; row++)
		for (col = x1 + thickness; col <= x2 - thickness; ++col)
		{
			pixel_ptr = HW_OCRAM_BASE + (row << 10) + (col << 1);
			PHYSMEM_16(pixel_ptr) = background_color;		// set pixel color
		}
}

/****************************************************************************************
 * Draw a line between any two points in a specified color on the VGA monitor 
****************************************************************************************/
void VGA_line(int x1, int y1, int x2, int y2, short line_color, void *virtual_base)
{
	unsigned int pixel_ptr, row, col;
	double slope;
	
	if (x2 == x1) // vertical line - infinite slope
	{
		col = x2; // column will remain constant
		if (y2 > y1)
		{
			for (row = y1; row <= y2; ++row)
			{	
				// adjust pointer to the next pixel
				pixel_ptr = HW_OCRAM_BASE + (row << 10) + (col << 1);
				// color the pixel
				PHYSMEM_16(pixel_ptr) = line_color;
			}
		}
		else
		{
			for (row = y1; row >= y2; --row)
			{	
				// adjust pointer to the next pixel
				pixel_ptr = HW_OCRAM_BASE + (row << 10) + (col << 1);
				// color the pixel
				PHYSMEM_16(pixel_ptr) = line_color;
			}
		}
	}
	else
	{
		// calculate slope as it should not be undefined
		slope = ((y2-y1)*1.0/(x2-x1));
		
		if (x2 > x1) 
		{
			for (col = x1; col <= x2; ++col)
			{
				row = y1 + (col - x1) * slope + 0.5;
				// adjust pointer to the next pixel
				pixel_ptr = HW_OCRAM_BASE + (row << 10) + (col << 1);
				// color the pixel
				PHYSMEM_16(pixel_ptr) = line_color;
			}
		}
		else
		{
			for (col = x1; col >= x2; --col) // reverse direction
			{
				row = y1 + ((double)col - (double)x1) * slope + 0.5;
				// adjust pointer to the next pixel
				pixel_ptr = HW_OCRAM_BASE + (row << 10) + (col << 1);
				// color the pixel
				PHYSMEM_16(pixel_ptr) = line_color;
			}
		}
	}
}


/****************************************************************************************
 * Displays text on the VGA monitor 
****************************************************************************************/
void VGA_text(int x, int y, char * text_ptr, void *virtual_base)
{
	int offset;
  	unsigned int  char_ptr;

	/* assume that the text string fits on one line */
	offset = (y << 7) + x;
	while ( *(text_ptr) )
	{
		char_ptr =  FPGA_CHAR_BASE + offset;
		
		PHYSMEM_32(char_ptr) = *(text_ptr);
		
		++text_ptr;
		++offset;
	}
}

/****************************************************************************************
 * Clears text from the VGA monitor 
****************************************************************************************/
void VGA_text_clear(void *virtual_base)
{
	int x,y;
	int offset;
	char blank[1] = " ";
  	unsigned int  char_ptr;

	// Character coordinates are from 0,0 to 79,59 (x,y) position
	for(x = 0; x < 80; x++)
		for(y = 0; y < 60; y++)
		{
		/* assume that the text string fits on one line */
		offset = (y << 7) + x;
		char_ptr =  FPGA_CHAR_BASE + offset;
		PHYSMEM_32(char_ptr) = *blank;
		}
}

/****************************************************************************************
 * Clears text and sets each pixel black on the VGA monitor 
****************************************************************************************/
void VGA_clear(int x1, int y1, int x2, int y2, void *virtual_base)
{
	// clear the text content
	VGA_text_clear(virtual_base);
	// set all pixels to black
	VGA_box(x1, y1, x2, y2, BLACK, virtual_base);
}

/****************************************************************************************
	* Draw Inventory header and three inventory spaces
****************************************************************************************/
void VGA_inventory(void *virtual_base)
{
	//height = 50
	//width = 33
	
	char text_inventory[40] = "Inventory\0";
	// draw inventory header box
	VGA_unfilled_box(1, 1, 43, 20, 1, WHITE, BLACK, virtual_base);
	// draw text "Inventory"
	VGA_text(1, 1, text_inventory, virtual_base);
	// draw first inventory slot
	VGA_unfilled_box(1, 22, 1+WIDTH_INV_BOX, 22+HEIGHT_INV_BOX, 1, WHITE, BLACK, virtual_base);
	// draw second inventory slot
	VGA_unfilled_box(1, 22+HEIGHT_INV_BOX, 1+WIDTH_INV_BOX, 22+2*HEIGHT_INV_BOX, 1, WHITE, BLACK, virtual_base);
	// draw third inventory slot
	VGA_unfilled_box(1, 22+2*HEIGHT_INV_BOX, 1+WIDTH_INV_BOX, 22+3*HEIGHT_INV_BOX, 1, WHITE, BLACK, virtual_base);
}

/****************************************************************************************
 * Draws a Treasure Chest Object on screen given a starting point (top left corner)
****************************************************************************************/
void VGA_treasureChest(int x1, int y1, void *virtual_base)
{
	// x1 has to be at least 2 greater than 0 and at least 32 less than 320
	// y1 has to be at least 46 less than 480
	
	// draw main box
	VGA_unfilled_box(x1, y1, x1+30, y1+39, 3, WHITE, BLACK, virtual_base);
	// draw main wooden body
	VGA_box(x1+3, y1, x1+3+24, y1+39, BROWN, virtual_base);
	VGA_unfilled_box(x1+10, y1+17, x1+10+10, y1+17+14, 1, BROWN, BLACK, virtual_base);
	VGA_box(x1-2, y1+19, x1-2+34, y1+19+3, BLACK, virtual_base);
	// draw rectangle in the middle
	VGA_box(x1-2, y1+15, x1-2+34, y1+15+5, WHITE, virtual_base);
	// draw chest latch
	VGA_unfilled_box(x1+12, y1+19, x1+12+6, y1+19+9, 2, WHITE, BLACK, virtual_base);
	// draw rectangle at bottom
	VGA_box(x1-2, y1+40, x1-2+34, y1+40+5, WHITE, virtual_base);
}

/****************************************************************************************
 * Draws a Locked Door Object on screen given a starting point (top left corner)
****************************************************************************************/
void VGA_lockedDoor(int x1, int y1, void *virtual_base)
{
	//figure out dimensions of the door
	// draw main wooden body
	VGA_box(x1, y1, x1+25, y1+75, BROWN, virtual_base);
	// draw steel bar
	VGA_box(x1, y1+30, x1+25, y1+38, WHITE, virtual_base);
	// draw padlock
	VGA_unfilled_box(x1+14, y1+22, x1+22, y1+29, 2, WHITE, BROWN, virtual_base);
	VGA_box(x1+14, y1+29, x1+22, y1+43, WHITE, virtual_base);
	// draw keyhole
	VGA_box(x1+16, y1+30, x1+20, y1+36, BLACK, virtual_base);
	VGA_box(x1+18, y1+36, x1+19, y1+40, BLACK, virtual_base);
}

/****************************************************************************************
 * Draws a Hatchet Object on screen given a starting point (top left corner)
****************************************************************************************/
void VGA_hatchet(int x1, int y1, void *virtual_base)
{
	// draw wooden handle
	VGA_box(x1, y1, x1+4, y1+45, BROWN, virtual_base);
	// draw axe head
	VGA_box(x1-1, y1+3, x1+10, y1+13, WHITE, virtual_base);
	// drawing the bottom diagonal part that is filled
	unsigned int i;
	for (i = 19; i >= 13; i--) {
		VGA_line(x1+4, y1+13, x1+10, y1+i, WHITE, virtual_base);
	}
}

/****************************************************************************************
 * Draws a Wave Object on screen given a starting point (draws from bottom left corner)
****************************************************************************************/
//PRO-TIP: 0x0FFF IS BLUE !!!
void VGA_wave(int x1, int y1, short color, void *virtual_base)
{
	VGA_line(x1, y1, x1+4, y1-4, color, virtual_base);
	VGA_line(x1+4, y1-4, x1+8, y1, color, virtual_base);
}


/****************************************************************************************
 * Draws ALL THE WAVES on screen given a starting point (draws from top left corner)
****************************************************************************************/
void VGA_allWaves(int x1, short color, void *virtual_base)
{
	VGA_wave(x1+15, 20, color, virtual_base);
	VGA_wave(x1+25, 60, color, virtual_base);
	VGA_wave(x1+40, 90, color, virtual_base);
	VGA_wave(x1+40, 150, color, virtual_base);
	VGA_wave(x1+60, 200, color, virtual_base);
	VGA_wave(x1+70, 250, color, virtual_base);
	VGA_wave(x1+80, 310, color, virtual_base);
	VGA_wave(x1+90, 360, color, virtual_base);
	VGA_wave(x1+100, 400, color, virtual_base);
	VGA_wave(x1+110, 450, color, virtual_base);
}


/****************************************************************************************
 * Draws a River Object on screen given a starting x-coordinate (draws from top left corner)
****************************************************************************************/
void VGA_river(int x1, void *virtual_base)
{

	//left side
	VGA_line(x1, 0, x1+20, 70, 0x0FFF, virtual_base);
	VGA_line(x1+20, 70, x1+30, 140, 0x0FFF, virtual_base);
	VGA_line(x1+30, 140, x1+50, 210, 0x0FFF, virtual_base);
	VGA_line(x1+50, 210, x1+60, 280, 0x0FFF, virtual_base);
	VGA_line(x1+60, 280, x1+80, 350, 0x0FFF, virtual_base);
	VGA_line(x1+80, 350, x1+90, 420, 0x0FFF, virtual_base);
	VGA_line(x1+90, 420, x1+110, 480, 0x0FFF, virtual_base);

	//right side
	VGA_line(x1+30, 0, x1+50, 70, 0x0FFF, virtual_base);
	VGA_line(x1+50, 70, x1+60, 140, 0x0FFF, virtual_base);
	VGA_line(x1+60, 140, x1+80, 210, 0x0FFF, virtual_base);
	VGA_line(x1+80, 210, x1+90, 280, 0x0FFF, virtual_base);
	VGA_line(x1+90, 280, x1+110, 350, 0x0FFF, virtual_base);
	VGA_line(x1+110, 350, x1+120, 420, 0x0FFF, virtual_base);
	VGA_line(x1+120, 420, x1+140, 480, 0x0FFF, virtual_base);
	
}

/****************************************************************************************
 * Draws a Tree Object on screen given a starting point (draws from bottom left corner of trunk)
****************************************************************************************/
void VGA_tree(int x1, int y1, void *virtual_base)
{
	//left trunk
	VGA_line(x1, y1, x1, y1-20, 0xF800, virtual_base);
	//right trunk
	VGA_line(x1+8, y1, x1+8, y1-20, 0xF800, virtual_base);
	//bottom trunk
	VGA_line(x1, y1, x1+8, y1, 0xF800, virtual_base);


	VGA_box(x1, y1-20, x1+8, y1, 0xF800, virtual_base);

	//left leaves
	VGA_line(x1, y1-20, x1-20, y1-20, 0x7000, virtual_base);
	VGA_line(x1-20, y1-20, x1-6, y1-34, 0x7000, virtual_base);

	unsigned int i;
	for (i = 20; i <= 44; i++) {
	VGA_line(x1-20, y1-20, x1+4, y1-i, 0X7000, virtual_base);
	}

	VGA_line(x1-6, y1-34, x1-14, y1-34, 0x7000, virtual_base);
	VGA_line(x1-14, y1-34, x1, y1-50, 0x7000, virtual_base);

	for (i = 34; i <= 54; i++) {
	VGA_line(x1-14, y1-34, x1+4, y1-i, 0X7000, virtual_base);
	}

	VGA_line(x1, y1-50, x1-10, y1-50, 0x7000, virtual_base);
	VGA_line(x1-10, y1-50, x1+4, y1-70, 0x7000, virtual_base);

	for (i = 50; i <= 70; i++) {
	VGA_line(x1-10, y1-50, x1+4, y1-i, 0X7000, virtual_base);
	}

	//right leaves
	VGA_line(x1+8, y1-20, x1+28, y1-20, 0x7000, virtual_base);
	VGA_line(x1+28, y1-20, x1+16, y1-34, 0x7000, virtual_base);

	for (i = 20; i <= 48; i++) {
	VGA_line(x1+28, y1-20, x1+4, y1-i, 0X7000, virtual_base);
	}

	VGA_line(x1+16, y1-34, x1+24, y1-34, 0x7000, virtual_base);
	//VGA_line(x1+24, y1-34, x1+10, y1-50, 0x7000, virtual_base);

	for (i = 34; i <= 54; i++) {
	VGA_line(x1+24, y1-34, x1+4, y1-i, 0X7000, virtual_base);
	}

	VGA_line(x1+10, y1-50, x1+18, y1-50, 0x7000, virtual_base);
	VGA_line(x1+18, y1-50, x1+4, y1-70, 0x7000, virtual_base);

	for (i = 50; i <= 70; i++) {
	VGA_line(x1+18, y1-50, x1+4, y1-i, 0X7000, virtual_base);
	}

}
	
/****************************************************************************************
 * Draws Stick Man on screen given a starting point (draws from bottom left corner of foot)
****************************************************************************************/
// REMEMBER TO ERASE HIM TOO
void VGA_stickman(int x1, int y1, short color, void *virtual_base)
{
//left leg
VGA_line(x1, y1, x1+4, y1-8, color, virtual_base);
//right leg
VGA_line(x1+8, y1, x1+4, y1-8, color, virtual_base);
//torso
VGA_line(x1+4, y1-8, x1+4, y1-16, color, virtual_base);
//arms
VGA_line(x1, y1-12, x1+8, y1-12, color, virtual_base);
//head
VGA_box(x1, y1-26, x1+8, y1-16, color, virtual_base);

}

/****************************************************************************************
 * Draws all the objects on the screen at the beginning of game
****************************************************************************************/
void VGA_drawAllObjects(void *virtual_base)
{
// Clear the screen
VGA_clear(0, 0, X_MAX, Y_MAX, virtual_base);

// draw inventory and its spaces
VGA_inventory(virtual_base);
// draw treasure chest, comprised of a main box and two superimposed boxes
VGA_treasureChest(200, 1, virtual_base);
// draw locked door
VGA_lockedDoor(260, 150, virtual_base);
// draw hatchet
VGA_hatchet(50, 300, virtual_base);
// draw river
VGA_river(130, virtual_base);
// draw tree
VGA_tree(100, 120, virtual_base);
}
	