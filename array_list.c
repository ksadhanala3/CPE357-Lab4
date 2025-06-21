#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array_list.h"
#include "checkit.h"

struct array_list *array_list_new() {
    // allocate and return a new array list
    struct array_list *new_array = malloc(sizeof(struct array_list));
    new_array->entries = malloc(4 * sizeof(char*));
    new_array->cap = 4;
    new_array->used = 0;
    return new_array;
}

void array_list_add_to_end(struct array_list *the_list, char *str_to_add) {
    // add str_to_add to the end of the array list (resizing if necessary)
    if (the_list->used < the_list->cap) {
	    the_list->entries[the_list->used] = strdup(str_to_add);
	    the_list->used++;
	    return;
    }

    the_list->entries = realloc(the_list->entries, (the_list->cap + 4) * sizeof(char*));
    the_list->entries[the_list->used] = strdup(str_to_add);
    the_list->cap += 4;   
    the_list->used++;
    return;
}

void free_array_list(struct array_list *the_list) {
	for (int i = 0; i < the_list->used; i++) {
		free(the_list->entries[i]);
	}
	free(the_list->entries);
	free(the_list);
}
