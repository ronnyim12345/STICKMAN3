/****************************************************************************************
 * treasureChest.h
 * Stores the declarations for the properties and methods of the TreasureChest object
****************************************************************************************/
#ifndef TREASURECHEST_H
#define TREASURECHEST_H

typedef struct _TreasureChest TreasureChest;

// defines the properties of the Stickman object
struct _TreasureChest {
	// coordinates of bottom of left foot
	int x;
	int y;
	
};

TreasureChest* TreasureChest_create(int x, int y);
void TreasureChest_init(TreasureChest* self, int x, int y);
void TreasureChest_destroy(TreasureChest* self);
void TreasureChest_display_info(TreasureChest* self);

#endif //TREE_H