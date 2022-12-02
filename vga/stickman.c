/****************************************************************************************
 * stickman.c
 * Stores the definitions for the properties and methods of the Stickman object
****************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stickman.h"

#define HATCHET 1
#define LOGS 2
#define KEY 3
int i;
int* p;

// constructor for the Stickman object
Stickman* Stickman_create(int x, int y) {
	// allocation and initialization
	Stickman* stickman = (Stickman*)malloc(sizeof(Stickman));
	Stickman_init(stickman, x, y);
	
	// initialize bools to false
	stickman->hasHatchet = 0;
	stickman->hasLogs = 0;
	stickman->hasKey = 0;
	
	// dynamically allocate space for inventory property
	stickman->inventory = (int*)malloc(3 * sizeof(int));
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

// sets hasHatchet to true and fills inventory
void Stickman_collect_hatchet(Stickman* self) {
	// set bool
	self->hasHatchet = 1;
	// insert hatchet into next available inventory space
	self->inventory[0] = HATCHET;
}

// sets hasLogs to true and fills inventory
void Stickman_collect_logs(Stickman* self) {
	// set bool
	self->hasLogs = 1;
	// insert logs into next available inventory space
	self->inventory[1] = LOGS;
}

// sets hasKey to true and fills inventory
void Stickman_collect_key(Stickman* self) {
	// set bool
	self->hasKey = 1;
	// insert key into next available inventory space
	self->inventory[2] = KEY;
}

// displays all info
void Stickman_display_info(Stickman* self) {
    printf("\nStickman Info:\nx: %d y: %d hasHatchet: %d hasLogs: %d hasKey: %d\n", self->x, self->y, self->hasHatchet, self->hasKey, self->hasLogs);
	printf("Inventory: [ ");
	for (i = 0; i < 3; i++) {
		printf("%d ", self->inventory[i]);
	}
	printf("]\n");
}
