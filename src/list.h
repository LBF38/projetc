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
struct list
{
    struct cell *head;
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
struct cell
{
    char *fname;
    char *lname;
    char *zip;
    struct cell *next;
};

/**
 * @brief Creates and allocates memory for a new list structure and return the pointer
 *
 * Initialize head to NULL.
 *
 * @return struct list*
 */
struct list *new_list();

/**
 * @brief Free the input list and its cells
 *
 * @param lst
 */
void free_list(struct list *lst);

/**
 * @brief Print a cell as [fname,lname,zip]
 *
 * @param c
 */
void print_cell(struct cell *c);

/**
 * @brief Print a list and its cells
 *
 * @param lst
 */
void print_list(struct list *lst);

/**
 * @brief Makes a cell from given values and allocates memory accordingly
 *
 * @param fname
 * @param lname
 * @param zip
 * @return struct cell*
 */
struct cell *make_cell(char *fname, char *lname, char *zip);

/**
 * @brief Makes a cell from given line
 *
 * Lines are formatted like that : first_name,last_name,zipcode;\\n \n
 * So, we need to separate the string according to the separator ","
 * and remove the last two characters, which is done by separating the string with ";".
 *
 * @warning The string is a single memory space and each value of the cell (fname, lname and zip)
 * points to a part of the string pointer.
 *
 * strtok cuts the given string and replaces the first occurence encountered of the separator by a '\0' character
 * to mark the end of the char.
 *
 * Therefore, when we will want to free the cells value, we only need to free fname
 * because it points to the first character of the whole string.
 *
 * We can imagine the values like a big box separated in four and where the first three are pointed by fname, lname and zip.
 * The fourth one contains the two last characters we don't want (";\n" in our case).
 *
 * @param line
 * @return struct cell*
 */
struct cell *make_cell_from_line(char *line);

/**
 * @brief Pushes a cell on top of the given list
 *
 * @param lst
 * @param c
 */
void push(struct list *lst, struct cell *c);

/**
 * @brief Pops a cell from the list
 *
 * Pops the first cell of the list
 * and stores it in the given `out` cell pointer.
 *
 * @param lst
 * @param out
 */
void pop(struct list *lst, struct cell *out);

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
int compare_cells(struct cell *a, struct cell *b);

/**
 * @brief Inserts a cell to the given list respecting alphabetical order of names.
 *
 * There are 4 cases :
 * 1. the list is empty. We add the cell to the list.
 * 2. the cell needs to go first. We add the cell to the top of the list.
 * 3. the cell goes between two elements.
 * 4. the cell goes at the bottom of the list.
 *
 * @param lst
 * @param c
 */
void insert(struct list *lst, struct cell *c);

/**
 * @brief Load the contents of a file in a sorted list
 *
 * Uses the first method. Returns a simple list.
 * 
 * @param file_name
 * @return struct list*
 */
struct list *load_file(char *file_name);