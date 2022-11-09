/****************************************************************************************
 * hatchet.h
 * Stores the declarations for the properties and methods of the Hatchet object
****************************************************************************************/
#ifndef HATCHET_H
#define HATCHET_H

typedef struct _Hatchet Hatchet;

// defines the properties of the Stickman object
struct _Hatchet {
	// coordinates of bottom of left foot
	int x;
	int y;
	
};

Hatchet* Hatchet_create(int x, int y);
void Hatchet_init(Hatchet* self, int x, int y);
void Hatchet_destroy(Hatchet* self);
void Hatchet_display_info(Hatchet* self);

#endif //HATCHET_H