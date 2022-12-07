#ifndef BRIDGE_H
#define BRIDGE_H
/****************************************************************************************
 * bridge.h
 * Stores the declarations for the properties and methods of the Bridge object
****************************************************************************************/
typedef struct _Bridge Bridge;

// defines the properties of the Stickman object
struct _Bridge {
	// coordinates of bottom of left foot
	int x;
	int y;
	// bool for whether it has been built
	short hasBeenBuilt;
};

Bridge* Bridge_create(int x, int y);
void Bridge_init(Bridge* self, int x, int y);
void Bridge_destroy(Bridge* self);
void Bridge_build(Bridge* self);

#endif //BRIDGE_H