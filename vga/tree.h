/****************************************************************************************
 * tree.h
 * Stores the declarations for the properties and methods of the Tree object
****************************************************************************************/
#ifndef TREE_H
#define TREE_H

typedef struct _Tree Tree;

// defines the properties of the Stickman object
struct _Tree {
	// coordinates of bottom of left foot
	int x;
	int y;
	
};

Tree* Tree_create(int x, int y);
void Tree_init(Tree* self, int x, int y);
void Tree_destroy(Tree* self);
void Tree_display_info(Tree* self);

#endif //TREE_H