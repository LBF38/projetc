/**
 * @file list.h
 * @author Mathis URIEN (LBF38)
 * @version 1.0.0
 * @date 2022-10-19
 * 
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
 * @brief 
 * 
 */
struct list {
    struct cell* head;
};

/**
 * @brief 
 * 
 */
struct cell {
    char* fname;
    char* lname;
    char* zip;
    struct cell* next;
};

/* Allocate memory for a list structure and return the pointer */
/**
 * @brief 
 * 
 * @return struct list* 
 */
struct list* new_list();

/* Free the input list and its cells */
/**
 * @brief 
 * 
 * @param lst 
 */
void free_list(struct list* lst);

/* Print a cell as [fname,lname,zip] */
/**
 * @brief 
 * 
 * @param c 
 */
void print_cell(struct cell* c);

/* Print a list and its cells */
/**
 * @brief 
 * 
 * @param lst 
 */
void print_list(struct list *lst);

/* Make a cell from given values */
/**
 * @brief 
 * 
 * @param fname 
 * @param lname 
 * @param zip 
 * @return struct cell* 
 */
struct cell* make_cell(char* fname, char* lname, char* zip);

/* Make a cell from an input text line */
/**
 * @brief 
 * 
 * @param line 
 * @return struct cell* 
 */
struct cell* make_cell_from_line(char* line);

/* Push a cell on top */
/**
 * @brief 
 * 
 * @param lst 
 * @param c 
 */
void push(struct list *lst, struct cell* c);

/* Pop the head of the list in the given out pointer */
/**
 * @brief 
 * 
 * @param lst 
 * @param out 
 */
void pop(struct list* lst, struct cell* out);

/* Compare two cells, outputs 0 if equal, a negative number if a<b and positive otherwise */
/**
 * @brief 
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int compare_cells(struct cell* a, struct cell* b);

/* Add the cell to the list respecting alphabetical order of names/lnames */
/**
 * @brief 
 * 
 * @param lst 
 * @param c 
 */
void insert(struct list* lst, struct cell* c);

/* Load the contents of a file in a sorted list */
/**
 * @brief 
 * 
 * @param file_name 
 * @return struct list* 
 */
struct list* load_file(char* file_name);