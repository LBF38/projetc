/**
 * @file list.c
 * @author Mathis URIEN (LBF38)
 * @brief This is the list.c file
 * @version 1.0.0
 * @date 2022-10-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "list.h"

/* Construction/Destruction
======================== */

struct list *new_list()
{
	struct list *lst = (struct list *)malloc(sizeof(struct list));

	if (lst == NULL)
	{
		return NULL;
	}

	lst->head = NULL;
	return lst;
}

/**
 * @brief Frees memory occupied by each cells of the given list.
 * 
 * @param lst 
 */
static void free_cells(struct list *lst)
{
	struct cell *cur;
	struct cell *tmp;
	// Empty list
	if (lst == NULL)
	{
		return;
	}
	// Free each cell one by one
	cur = lst->head;
	while (cur != NULL)
	{
		tmp = cur;
		cur = cur->next;
		// If dynamically allocated!
		free(tmp->fname);
		free(tmp);
	}
	lst->head = NULL;
}

/**
 * @brief Frees the complete list and its pointer.
 * 
 * @param lst 
 */
void free_list(struct list *lst)
{
	free_cells(lst);
	free(lst);
}

/* Printing
======== */

/**
 * @brief Prints a cell as [fname,lname,zip]
 * 
 * @param c 
 */
void print_cell(struct cell *c)
{
	printf("[%s,%s,%s]", c->fname, c->lname, c->zip);
}

/**
 * @brief Prints a list and its cells
 * 
 * @param lst 
 */
void print_list(struct list *lst)
{
	struct cell *pCell;
	pCell = lst->head;
	printf("\t{\n");
	while (pCell != NULL)
	{
		printf("\t\t");
		print_cell(pCell);
		printf(",\n");
		pCell = pCell->next;
	}
	printf("\t}\n");
}

/* Cell addition
============= */

/**
 * @brief Makes a cell and allocates memory accordingly
 * 
 * @param fname 
 * @param lname 
 * @param zip 
 * @return struct cell* 
 */
struct cell *make_cell(char *fname, char *lname, char *zip)
{
	struct cell *one_cell;
	one_cell = malloc(sizeof(struct cell));
	one_cell->fname = fname;
	one_cell->lname = lname;
	one_cell->zip = zip;
	one_cell->next = NULL;
	return one_cell;
}

/**
 * @brief Pushes a cell to the given list
 * 
 * @param lst 
 * @param c 
 */
void push(struct list *lst, struct cell *c)
{
	struct cell *cell_copy;
	cell_copy = malloc(sizeof(struct cell));
	memcpy(cell_copy, c, sizeof(struct cell));
	cell_copy->next = lst->head;
	lst->head = cell_copy;
	free(c);
}

/**
 * @brief Pops a cell from the list
 * 
 * Pops the first cell of the list
 * and stores it in the given `out` cell pointer.
 * 
 * @param lst 
 * @param out 
 */
void pop(struct list *lst, struct cell *out)
{
	memcpy(out, lst->head, sizeof(struct cell));
	free(lst->head);
	lst->head = out->next;
	out->next = NULL;
}

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
struct cell *make_cell_from_line(char *line)
{
	char *fname;
	char *lname;
	char *zip;
	char *separator;
	char *string = (char *)malloc((strlen(line) + 1) * sizeof(char));
	strcpy(string, line);
	separator = ",;"; // permet de séparer par rapport à tous les caractères fournis
	fname = strtok(string, separator);
	lname = strtok(NULL, separator);
	zip = strtok(NULL, separator);
	return make_cell(fname, lname, zip);
}

/**
 * @brief Loads the file using the first method. Returns a simple list.
 * 
 * @param file_name 
 * @return struct list* 
 */
struct list *load_file(char *file_name)
{
	struct list *data;
	data = new_list();
	struct cell *cellule;
	char *entry;
	entry = malloc(100 * sizeof(char));

	FILE *inputFile = fopen(file_name, "r");
	// Gestion erreur ouverture fichier
	if (inputFile == NULL)
	{
		fprintf(stderr, "error opening file : %s\n", strerror(errno));
		exit(-1);
	}

	while (fgets(entry, 100, inputFile) != NULL)
	{
		cellule = make_cell_from_line(entry);
		insert(data, cellule);
	}
	fclose(inputFile);

	free(entry);
	return data;
}

/**
 * @brief Compares simple cells by last names and then by first names.
 * 
 * It firstly compares last names. If equal, it compares the first names.
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int compare_cells(struct cell *a, struct cell *b)
{
	int compare = strcmp(a->lname, b->lname);
	if (compare != 0)
	{
		return compare;
	}
	compare = strcmp(a->fname, b->fname);
	return compare;
}

/**
 * @brief Inserts a cell to the given list.
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
void insert(struct list *lst, struct cell *c)
{
	struct cell *current_cell;
	// CAS 1: la liste est vide
	if (lst->head == NULL)
	{
		c->next = lst->head;
		lst->head = c;
		return;
	}
	// CAS 2 : insertion en début de liste
	if (compare_cells(lst->head, c) > 0)
	{
		c->next = lst->head;
		lst->head = c;
		return;
	}

	// CAS 3: on insère au milieu de la liste (entre 2 élts)
	current_cell = lst->head;
	while (current_cell->next != NULL)
	{
		if (compare_cells(current_cell->next, c) > 0)
		{
			c->next = current_cell->next;
			current_cell->next = c;
			return;
		}
		current_cell = current_cell->next;
	}
	// CAS 4: on insère à la fin de la liste
	current_cell->next = c;
	c->next = NULL;
	return;
}
