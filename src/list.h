/**
 * @file list.h
 * @author Mathis URIEN (LBF38)
 * @version 1.0.0
 * @date 2022-10-19
 * @brief Defines the list.c functions and structures.
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define NAME_LENGTH 40
#define ZIP_LENGTH 10

/**
 * @brief Defines the list structure
 * 
 * It points to the first cell named head.
 * 
 */
struct list {
    struct cell* head;
};

/**
 * @brief Defines the cell structure
 * 
 * The cell structure contains :
 * - fname : first name
 * - lname : last name
 * - zip : zip code for the city
 * - next : points to the next cell of the list
 * 
 */
struct cell {
    char* fname;
    char* lname;
    char* zip;
    struct cell* next;
};

/**
 * @brief Creates and allocates memory for a new list structure and return the pointer
 * 
 * Initialize head to NULL.
 * 
 * @return struct list* 
 */
struct list* new_list();

/**
 * @brief Free the input list and its cells
 * 
 * @param lst 
 */
void free_list(struct list* lst);

/**
 * @brief Print a cell as [fname,lname,zip]
 * 
 * @param c 
 */
void print_cell(struct cell* c);

/**
 * @brief Print a list and its cells
 * 
 * @param lst 
 */
void print_list(struct list *lst);

/**
 * @brief Make a cell from given values
 * 
 * @param fname 
 * @param lname 
 * @param zip 
 * @return struct cell* 
 */
struct cell* make_cell(char* fname, char* lname, char* zip);

/**
 * @brief Make a cell from an input text line
 * 
 * @param line 
 * @return struct cell* 
 */
struct cell* make_cell_from_line(char* line);

/**
 * @brief Push a cell on top
 * 
 * @param lst 
 * @param c 
 */
void push(struct list *lst, struct cell* c);

/**
 * @brief Pop the head of the list in the given out pointer
 * 
 * @param lst 
 * @param out 
 */
void pop(struct list* lst, struct cell* out);

/**
 * @brief Compare two cells
 * 
 * Outputs :
 * - -1  if a < b,
 * -  0  if equal, 
 * -  1  if a > b.
 * 
 * It firstly compares the last names of each cell
 * and then, if they are equal, it compares the first names.
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int compare_cells(struct cell* a, struct cell* b);

/**
 * @brief Add the cell to the list respecting alphabetical order of names/lnames
 * 
 * @param lst 
 * @param c 
 */
void insert(struct list* lst, struct cell* c);

/**
 * @brief Load the contents of a file in a sorted list
 * 
 * @param file_name 
 * @return struct list* 
 */
struct list* load_file(char* file_name);