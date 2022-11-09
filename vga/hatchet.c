/****************************************************************************************
 * hatchet.c
 * Stores the definitions for the properties and methods of the Hatchet object
****************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hatchet.h"


// constructor for the Tree object
Hatchet* Hatchet_create(int x, int y) {
	// allocation and initialization
	Hatchet* hatchet = (Hatchet*)malloc(sizeof(Hatchet));
	Hatchet_init(hatchet, x, y);
	
	
	return hatchet;
}

// reinitializes the coordinates of the Tree object
void Hatchet_init(Hatchet* self, int x, int y) {
	self->x = x;
	self->y = y;
}

// deconstructor for the Tree object
void Hatchet_destroy(Hatchet* self) {
	if (self) {
		free(self);
	}
}

void Hatchet_display_info(Hatchet* self) {
    printf("Hatchet Info:\nx: %d y: %d\n", self->x, self->y);
	//printf("Inventory: [ %d %d %d ]", self->inventory[0], self->inventory[1], self->inventory[2]);
	
	// for (i = 0; i < (sizeof(self->inventory)/sizeof(self->inventory[0])); i++) {
		// printf("%d ", self->inventory[i]);
	// }
}
