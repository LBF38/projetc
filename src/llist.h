/**
 * @file llist.h
 * @author Mathis URIEN (LBF38)
 * @version 1.0.0
 * @date 2022-10-19
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "list.h"

/**
 * @brief
 *
 */
struct llist
{
    struct lcell *head;
};

/**
 * @brief
 *
 */
struct lcell
{
    char *index;
    struct list *index_list;
    struct lcell *next;
};

/**
 * @brief Allocate memory for a llist structure and return the pointer
 *
 * @return struct llist*
 */
struct llist *new_llist();

/* Free the input llist and its lcells */
/**
 * @brief 
 * 
 * @param llst 
 */
void free_llist(struct llist *llst);

/* Print a lcell as [fname,lname,zip] */
/**
 * @brief 
 * 
 * @param lcell 
 */
void print_lcell(struct lcell *lcell);

/* Print a llist and its lcells */
/**
 * @brief 
 * 
 * @param llst 
 */
void print_llist(struct llist *llst);

/* Make a lcell from given values */
/**
 * @brief 
 * 
 * @param index_list 
 * @param c 
 * @return struct lcell* 
 */
struct lcell *make_lcell(struct list *index_list, struct cell *c);

/**
 * @brief Compare cells to the index to insert it to the right place
 * 
 * @param lcellule 
 * @param c 
 * @return int 
 */
int compare_lcells(struct lcell *lcellule, struct cell *c);

/**
 * @brief Add the cell to the llist respecting alphabetical order of names/lnames 
 *        and inserting into the right index to optimize the llist
 * 
 * @param llst 
 * @param c 
 */
void insert_optimized(struct llist *llst, struct cell *c);

/**
 * @brief Load the contents of a file in a sorted list
 * 
 * @param file_name 
 * @return struct llist* 
 */
struct llist *load_file_optimized(char *file_name);