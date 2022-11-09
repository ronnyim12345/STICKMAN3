/****************************************************************************************
 * river.c
 * Stores the definitions for the properties and methods of the River object
****************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "river.h"


// constructor for the River object
River* River_create(int x) {
	// allocation and initialization
	River* river = (River*)malloc(sizeof(River));
	River_init(river, x);
	
	
	return river;
}

// reinitializes the coordinates of the River object
void River_init(River* self, int x) {
	self->x = x;
}

// deconstructor for the River object
void River_destroy(River* self) {
	if (self) {
		free(self);
	}
}

void River_display_info(River* self) {
    printf("River Info:\nx: %d\n", self->x);
	//printf("Inventory: [ %d %d %d ]", self->inventory[0], self->inventory[1], self->inventory[2]);
	
	// for (i = 0; i < (sizeof(self->inventory)/sizeof(self->inventory[0])); i++) {
		// printf("%d ", self->inventory[i]);
	// }
}
