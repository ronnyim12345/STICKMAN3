/****************************************************************************************
 * bridge.c
 * Stores the definitions for the properties and methods of the Bridge object
****************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bridge.h"

// constructor for the Bridge object
Bridge* Bridge_create(int x, int y) {
	// allocation and initialization
	Bridge* bridge = (Bridge*)malloc(sizeof(Bridge));
	Bridge_init(bridge, x, y);
	// init bool to false
	bridge->hasBeenBuilt = 0;	
	return bridge;
}

// reinitializes the coordinates of the Bridge object
void Bridge_init(Bridge* self, int x, int y) {
	self->x = x;
	self->y = y;
}

// deconstructor for the Bridge object
void Bridge_destroy(Bridge* self) {
	if (self) {
		free(self);
	}
}

// sets hasBeenBuilt to true
void Bridge_build(Bridge* self) {
    self->hasBeenBuilt = 1;
}
