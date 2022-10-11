#include "list.h"
#include <errno.h>

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
		// free(tmp->fname);
		// free(tmp->lname);
		// free(tmp->zip);
		free(tmp);
	}
	lst->head = NULL;
}

void free_list(struct list *lst)
{
	free_cells(lst);
	free(lst);
}

/* Printing
======== */

void print_cell(struct cell *c)
{
	/* Your code here */
	printf("[%s,%s,%s]", c->fname, c->lname, c->zip);
}

void print_list(struct list *lst)
{
	/* Your code here */
	struct cell *pCell;
	pCell = lst->head;
	printf("{\n");
	while (pCell != NULL)
	{
		printf("   "); // une tabulation pour afficher joliment la liste et son contenu.
		print_cell(pCell);
		printf(",\n");
		pCell = pCell->next;
	}
	printf("}\n");
}

/* Cell addition
============= */

struct cell *make_cell(char *fname, char *lname, char *zip)
{
	/* Your code here */
	struct cell *one_cell;
	one_cell = malloc(sizeof(struct cell));
	one_cell->fname = fname;
	one_cell->lname = lname;
	one_cell->zip = zip;
	one_cell->next = NULL;
	return one_cell;
}

void push(struct list *lst, struct cell *c)
{
	/* Your code here */
	c->next = lst->head;
	lst->head = c;
}

void pop(struct list *lst, struct cell *out)
{
	memcpy(out, lst->head, sizeof(struct cell));
	free(lst->head);
	lst->head = out->next;
	out->next = NULL;
}

struct cell *make_cell_from_line(char *line)
{
	// ref pour le strtok : https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm
	struct cell *pCell;
	pCell=malloc(sizeof(struct cell));
	char *token;
	char *delim;
	delim = ",";
	token = strtok(line, delim);
	int i = 0;
	while (token != NULL)
	{
		// printf("token %d: ", i);
		// printf("%s\n", token);
		switch (i++)
		{
		case 0:
			pCell->fname = token;
			break;
		case 1:
			pCell->lname = token;
			break;
		case 2:
			pCell->zip = token;
			break;
		default:
			break;
		}
		token = strtok(NULL, delim);
		// TODO: ajouter à pCell les infos au bon endroit
	}
	return pCell;
}

// struct list *load_file(char *file_name)
// {
// 	struct list *data;
// 	struct cell *pCell;

// 	FILE *inputFile = fopen(file_name, "r");
// 	// Gestion erreur ouverture fichier
// 	if (inputFile == NULL)
// 	{
// 		fprintf(stderr, "error opening file : %s\n", strerror(errno));
// 		exit(-1);
// 	}
// 	char *token;
// 	char *delim;
// 	delim = "\n";
// 	token = strtok(inputFile, delim);
// 	while (token != NULL)
// 	{
// 		pCell = make_cell_from_line(token);
// 		printf("lecture fichier : ");
// 		printf("%s\n", token);
// 		token = strtok(NULL, delim);
// 		// TODO: stocker les infos ligne par ligne.
// 	}
// }
