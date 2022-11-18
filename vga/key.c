/****************************************************************************************
 * key.c
 * Stores the definitions for the properties and methods of the Key object
****************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "key.h"


// constructor for the Key object
Key* Key_create(int x, int y) {
	// allocation and initialization
	Key* key = (Key*)malloc(sizeof(Key));
	Key_init(key, x, y);
	
	
	return key;
}

// reinitializes the coordinates of the Key object
void Key_init(Key* self, int x, int y) {
	self->x = x;
	self->y = y;
}

// deconstructor for the Key object
void Key_destroy(Key* self) {
	if (self) {
		free(self);
	}
}

void Key_display_info(Key* self) {
    printf("Key Info:\nx: %d y: %d\n", self->x, self->y);
	
}
