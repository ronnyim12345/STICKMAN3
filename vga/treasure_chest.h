/****************************************************************************************
 * treasure_chest.h
 * Stores the declarations and definitions for the properties and methods of the TresureChest object
****************************************************************************************/

typedef struct _TreasureChest TreasureChest;

// defines the properties of the TreasureChest object
struct _TreasureChest {
	int x;
	int y;
};

TreasureChest* TreasureChest_create(int x, int y);
void TreasureChest_init(TreasureChest* treasureChest, int x, int y);
void TreasureChest_destroy(TreasureChest* treasureChest);
void TreasureChest_display_info(TreasureChest* treasureChest);

// constructor for the TreasureChest object
TreasureChest* TreasureChest_create(int x, int y) {
	// allocation and initialization
	TreasureChest* treasureChest = (TreasureChest*)malloc(sizeof(TreasureChest));
	TreasureChest_init(treasureChest, x, y);
	
	return treasureChest;
}

// reinitializes the coordinates of the TreasureChest object
void TreasureChest_init(TreasureChest* treasureChest, int x, int y) {
	treasureChest->x = x;
	treasureChest->y = y;
}

// deconstructor for the TreasureChest object
void TreasureChest_destroy(TreasureChest* treasureChest) {
	if (treasureChest) {
		free(treasureChest);
	}
}

void TreasureChest_display_info(TreasureChest* treasureChest) {
    printf("\nTreasureChest Info:\nx: %d y: %d\n", treasureChest->x, treasureChest->y);
}
