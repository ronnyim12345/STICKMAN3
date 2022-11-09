/****************************************************************************************
 * door.c
 * Stores the definitions for the properties and methods of the Door object
****************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "door.h"


// constructor for the Tree object
Door* Door_create(int x, int y) {
	// allocation and initialization
	Door* door = (Door*)malloc(sizeof(Door));
	Door_init(door, x, y);
	
	
	return door;
}

// reinitializes the coordinates of the Tree object
void Door_init(Door* self, int x, int y) {
	self->x = x;
	self->y = y;
}

// deconstructor for the Tree object
void Door_destroy(Door* self) {
	if (self) {
		free(self);
	}
}

void Door_display_info(Door* self) {
    printf("Door Info:\nx: %d y: %d\n", self->x, self->y);
	//printf("Inventory: [ %d %d %d ]", self->inventory[0], self->inventory[1], self->inventory[2]);
	
	// for (i = 0; i < (sizeof(self->inventory)/sizeof(self->inventory[0])); i++) {
		// printf("%d ", self->inventory[i]);
	// }
}
