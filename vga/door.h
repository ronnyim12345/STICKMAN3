/****************************************************************************************
 * door.h
 * Stores the declarations for the properties and methods of the Door object
****************************************************************************************/
#ifndef DOOR_H
#define DOOR_H

typedef struct _Door Door;

// defines the properties of the Door object
struct _Door {
	// coordinates of bottom of left foot
	int x;
	int y;
	
};

Door* Door_create(int x, int y);
void Door_init(Door* self, int x, int y);
void Door_destroy(Door* self);
void Door_display_info(Door* self);

#endif //DOOR_H