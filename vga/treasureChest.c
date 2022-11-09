/****************************************************************************************
 * treasureChest.c
 * Stores the definitions for the properties and methods of the TreasureChest object
****************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treasureChest.h"

// constructor for the TreasureChest object
TreasureChest* TreasureChest_create(int x, int y) {
	// allocation and initialization
	TreasureChest* treasureChest = (TreasureChest*)malloc(sizeof(TreasureChest));
	TreasureChest_init(treasureChest, x, y);
	
	
	return treasureChest;
}

// reinitializes the coordinates of the TreasureChest object
void TreasureChest_init(TreasureChest* self, int x, int y) {
	self->x = x;
	self->y = y;
}

// deconstructor for the TreasureChest object
void TreasureChest_destroy(TreasureChest* self) {
	if (self) {
		free(self);
	}
}

void TreasureChest_display_info(TreasureChest* self) {
    printf("TreasureChest Info:\nx: %d y: %d\n", self->x, self->y);
	//printf("Inventory: [ %d %d %d ]", self->inventory[0], self->inventory[1], self->inventory[2]);
	
	// for (i = 0; i < (sizeof(self->inventory)/sizeof(self->inventory[0])); i++) {
		// printf("%d ", self->inventory[i]);
	// }
}
