#include <stdio.h>
#include <stdlib.h>
#include "array_list.h"
#include "checkit.h"

int main(int argc, char *argv[]) {
    char *str = "example string";
    
    
    struct array_list *the_list = array_list_new();
 
  
    array_list_add_to_end(the_list, str);
    checkit_string(the_list->entries[0], str);

    array_list_add_to_end(the_list, "Will");
    array_list_add_to_end(the_list, "End");
    array_list_add_to_end(the_list, "Now");
    printf("%s %s %s %s\n", the_list->entries[0], the_list->entries[1], the_list->entries[2], the_list->entries[3]);

    
    array_list_add_to_end(the_list, "Psyche");
    checkit_string(the_list->entries[4], "Psyche");
    printf("%s %s %s %s %s\n", the_list->entries[0], the_list->entries[1], the_list->entries[2], the_list->entries[3], the_list->entries[4]);
    
    free_array_list(the_list);
    
    return EXIT_SUCCESS;
}
