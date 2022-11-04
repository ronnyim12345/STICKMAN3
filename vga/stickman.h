/****************************************************************************************
 * stickman.h
 * Stores the declarations for the properties and methods of the Stickman object
****************************************************************************************/
#ifndef STICKMAN_H
#define STICKMAN_H

typedef struct _Stickman Stickman;

// defines the properties of the Stickman object
struct _Stickman {
	// coordinates of bottom of left foot
	int x;
	int y;
	// bools for whether Stickman has inventory objects
	short hasHatchet;
	short hasKey;
	// array for inventory where HATCHET = 1, KEY = 2
	int* inventory;
};

Stickman* Stickman_create(int x, int y);
void Stickman_init(Stickman* self, int x, int y);
void Stickman_destroy(Stickman* self);

void Stickman_collect_hatchet(Stickman* self);
void Stickman_collect_key(Stickman* self);
void Stickman_display_info(Stickman* self);

#endif //STICKMAN_H