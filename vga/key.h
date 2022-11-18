/****************************************************************************************
 * key.h
 * Stores the declarations for the properties and methods of the Key object
****************************************************************************************/
#ifndef KEY_H
#define KEY_H


typedef struct _Key Key;

// defines the properties of the Stickman object
struct _Key {
	// coordinates of bottom of left foot
	int x;
	int y;
	
};

Key* Key_create(int x, int y);
void Key_init(Key* self, int x, int y);
void Key_destroy(Key* self);
void Key_display_info(Key* self);

#endif //KEY_H