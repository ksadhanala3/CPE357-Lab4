struct array_list {
    char **entries;  // an array of strings
    // define additional struct members here
    int cap;
    int used;
};

struct array_list *array_list_new();
void array_list_add_to_end(struct array_list *the_list, char *str_to_add);
void free_array_list(struct array_list *the_list);
