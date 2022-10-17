#include "list.h"

struct llist
{
    struct lcell *head;
};

struct lcell
{
    char *index;
    struct list *index_list;
    struct lcell *next;
};

/* Allocate memory for a llist structure and return the pointer */
struct llist *new_llist();

/* Free the input llist and its lcells */
void free_llist(struct llist *llst);

/* Print a lcell as [fname,lname,zip] */
void print_lcell(struct lcell *lcell);

/* Print a llist and its lcells */
void print_llist(struct llist *llst);

/* Make a lcell from given values */
struct lcell *make_lcell(struct list *index_list,struct cell*c);

/* Compare cells to the index to insert it to the right place */
int compare_lcells(struct lcell *lcellule, struct cell *c);

/* Add the cell to the llist respecting alphabetical order of names/lnames and inserting into the right index to optimize the llist */
void insert_optimized(struct llist *llst, struct cell *c);

/* Load the contents of a file in a sorted list */
struct llist *load_file_optimized(char *file_name);