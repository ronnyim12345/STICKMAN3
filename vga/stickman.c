/****************************************************************************************
 * stickman.c
 * Stores the definitions for the properties and methods of the Stickman object
****************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stickman.h"

#define HATCHET 1
#define KEY 2
int i;
int* p;

// constructor for the Stickman object
Stickman* Stickman_create(int x, int y) {
	// allocation and initialization
	Stickman* stickman = (Stickman*)malloc(sizeof(Stickman));
	Stickman_init(stickman, x, y);
	
	// initialize bools to false
	stickman->hasHatchet = 0;
	stickman->hasKey = 0;
	
	// dynamically allocate space for inventory property
	stickman->inventory = (int*)malloc(5 * sizeof(int));
	// initialize each inventory index to zero
	for (p = stickman->inventory; *p; p++) {
		*p = 0;
	}
	
	return stickman;
}

// reinitializes the coordinates of the Stickman object
void Stickman_init(Stickman* self, int x, int y) {
	self->x = x;
	self->y = y;
}

// deconstructor for the Stickman object
void Stickman_destroy(Stickman* self) {
	if (self) {
		free(self->inventory);
		free(self);
	}
}

// sets hasHatchet to true
void Stickman_collect_hatchet(Stickman* self) {
	// set bool
	self->hasHatchet = 1;
	// insert hatchet into next available inventory space
	for (i = 0; i < (sizeof(self->inventory)/sizeof(self->inventory[0])); i++) {
		if (self->inventory[i] == 0) {
			self->inventory[i] = HATCHET;
		}
	}
}

// sets hasKey to true
void Stickman_collect_key(Stickman* self) {
	// set bool
	self->hasKey = 1;
	// insert key into next available inventory space
	for (i = 0; i < (sizeof(self->inventory)/sizeof(self->inventory[0])); i++) {
		if (self->inventory[i] == 0) {
			self->inventory[i] = KEY;
		}
	}
}

void Stickman_display_info(Stickman* self) {
    printf("\nStickman Info:\nx: %d y: %d hasHatchet: %d hasKey: %d\n", self->x, self->y, self->hasHatchet, self->hasKey);
	printf("Inventory: [ ");
	// for (p = self->inventory; *p; p++) {
		// printf("%d ", *p);
	// }
	for (i = 0; i < 5; i++) {
		printf("%d ", self->inventory[i]);
	}
	printf("]\n");
}




