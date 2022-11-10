/****************************************************************************************
 * tree.c
 * Stores the definitions for the properties and methods of the Tree object
****************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"


// constructor for the Tree object
Tree* Tree_create(int x, int y) {
	// allocation and initialization
	Tree* tree = (Tree*)malloc(sizeof(Tree));
	Tree_init(tree, x, y);
	
	
	return tree;
}

// reinitializes the coordinates of the Tree object
void Tree_init(Tree* self, int x, int y) {
	self->x = x;
	self->y = y;
}

// deconstructor for the Tree object
void Tree_destroy(Tree* self) {
	if (self) {
		free(self);
	}
}

void Tree_display_info(Tree* self) {
    printf("Tree Info:\nx: %d y: %d\n", self->x, self->y);
	
}
