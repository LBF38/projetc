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
 * @brief Allocates memory for a llist structure and returns the pointer
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
 * @brief Prints the lcell content using a list format : \n
 *
 * Example of printing : \n
 *        [A, \n
 *          { \n
 *              [Firstname,Aname,1234], \n
 *          } \n
 *        ,B] \n
 * Therefore, it shows the content of the current index letter, the index_list and the next index letter.
 *
 * @param lcell
 */
void print_lcell(struct lcell *lcell);

/**
 * @brief Prints the llist using a format like : \n
 *        {{ \n
 *          "prints the lcells" \n
 *        }}
 *
 * @param llst
 */
void print_llist(struct llist *llst);

/**
 * @brief Make a lcell from given values
 * 
 * It uses the first character of the c->lname
 *        and inserts the cellule `c` into the index_list
 *        It also allocates the memory for the lcellule and its core components. (index, index_list)
 *
 * @param index_list
 * @param c
 * @return struct lcell*
 */
struct lcell *make_lcell(struct list *index_list, struct cell *c);

/**
 * @brief Compares the cellule we want to insert with the index
 *
 * @param lcellule
 * @param c
 * @return int
 */
int compare_lcells(struct lcell *lcellule, struct cell *c);

/**
 * @brief Inserts the cell in the optimized llist.
 * 
 * It compares the cell we want to insert with the index letters
 * and then insert it in the right place.
 * 
 * There are 4 cases : \n
 * - the list is empty.
 * - the list doesn't have the lcell at the beginning. We create and insert a lcell at the top of the llist.
 * - the list doesn't have the lcell at the end. We create and insert a lcell at the end of the llist.
 * - the list has the lcell and we insert the cell in the index_list.
 *
 * @param llst
 * @param c
 */
void insert_optimized(struct llist *llst, struct cell *c);

/**
 * @brief Load the contents of a file in a sorted list
 *
 * Loads the file, creates cells with each line 
 * and insert it into the llist.
 * 
 * @param file_name
 * @return struct llist*
 */
struct llist *load_file_optimized(char *file_name);