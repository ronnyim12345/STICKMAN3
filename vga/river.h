/****************************************************************************************
 * river.h
 * Stores the declarations for the properties and methods of the River object
****************************************************************************************/
#ifndef RIVER_H
#define RIVER_H

typedef struct _River River;

// defines the properties of the River object
struct _River {
	// coordinates of bottom of left foot
	int x;
	
};

River* River_create(int x);
void River_init(River* self, int x);
void River_destroy(River* self);
void River_display_info(River* self);

#endif //RIVER_H