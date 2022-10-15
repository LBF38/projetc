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
	printf("\t{\n");
	while (pCell != NULL)
	{
		printf("\t\t"); // une tabulation pour afficher joliment la liste et son contenu.
		print_cell(pCell);
		printf(",\n");
		pCell = pCell->next;
	}
	printf("\t}\n");
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
	struct cell *cell_copy;
	cell_copy = malloc(sizeof(struct cell));
	memcpy(cell_copy, c, sizeof(struct cell));
	cell_copy->next = lst->head;
	lst->head = cell_copy;
	free(c);
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

void insert(struct list *lst, struct cell *c)
{
	struct cell *current_cell;
	// CAS 1: la liste est vide
	if (lst->head == NULL)
	{
		push(lst, c);
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
