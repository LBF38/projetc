/**
 * @file llist.h
 * @author Mathis URIEN (LBF38)
 * @version 1.0.0
 * @date 2022-10-19
 * @brief Defines the llist.c functions and structures.
 * @copyright Copyright (c) 2022
 *
 */
#include "list.h"

/**
 * @brief Defines the llist structure
 * 
 * The llist points to the first lcell named head.
 *
 */
struct llist
{
    struct lcell *head;
};

/**
 * @brief Defines the lcell structure
 * 
 * The lcell has 3 values :
 * - index : it is the letter for referencing the last names
 * - index_list : it contains the names corresponding to the index letter
 * - next : it points to the next cell or is NULL if it is the last lcell of the llist.
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

/**
 * @brief Free the input llist and its lcells
 * 
 * @param llst 
 */
void free_llist(struct llist *llst);

/**
 * @brief Print a lcell as [fname,lname,zip]
 * 
 * @param lcell 
 */
void print_lcell(struct lcell *lcell);

/**
 * @brief Print a llist and its lcells 
 * 
 * @param llst 
 */
void print_llist(struct llist *llst);

/**
 * @brief Make a lcell from given values
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