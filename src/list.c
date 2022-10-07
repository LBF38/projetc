#include "list.h"

/* Construction/Destruction
======================== */

struct list* new_list() {
	struct list* lst = (struct list*)malloc(sizeof(struct list));

	if (lst == NULL) { 
		return NULL; 
	}

	lst->head=NULL;
	return lst;
}


static void free_cells(struct list *lst) {
	struct cell *cur;
	struct cell *tmp;
    // Empty list 
	if (lst == NULL) { 
        return; 
    }
    // Free each cell one by one
	cur = lst->head;
	while (cur != NULL) {
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

void free_list(struct list* lst) {
    free_cells(lst);
	free(lst);
}


/* Printing
======== */

void print_cell(struct cell* c) {
	/* Your code here */
	printf("[%s,%s,%s]\n",c->fname,c->lname,c->zip);
}

void print_list(struct list *lst) {
	/* Your code here */
	struct cell* pCell;
	pCell=lst->head;
	while (pCell != NULL){
		print_cell(pCell);
		pCell=pCell->next;
	}
}

/* Cell addition
============= */

struct cell* make_cell(char* fname, char* lname, char* zip) {
	/* Your code here */
	struct cell* one_cell;
	one_cell=malloc(sizeof(struct cell));
	one_cell->fname=fname;
	one_cell->lname=lname;
	one_cell->zip=zip;
	return one_cell;
}

void push(struct list *lst, struct cell* c) {
	/* Your code here */
	c->next=lst->head;
	lst->head=c;	
}
