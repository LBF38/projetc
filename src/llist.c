#include "llist.h"

/* Construction/Destruction
======================== */

struct llist *new_llist()
{
    struct llist *llst = (struct llist *)malloc(sizeof(struct llist));
    if (llst == NULL)
    {
        return NULL;
    }
    llst->head = NULL;
    return llst;
}

static void free_lcells(struct llist *llst)
{
    struct lcell *current;
    struct lcell *temp;
    // Empty llist
    if (llst == NULL)
    {
        return;
    }
    // Free each lcell one by one
    current = llst->head;
    while (current != NULL)
    {
        temp = current;
        current = current->next;
        free_list(temp->index_list);
        free(temp);
    }
    llst->head = NULL;
}

void free_llist(struct llist *llst)
{
    free_lcells(llst);
    free(llst);
    return;
}

/* Printing
======== */

void print_lcell(struct lcell *lcell)
{
    printf("[%s,\n", lcell->index);
    printf("   ");
    print_list(lcell->index_list);
    if (lcell->next != NULL)
    {
        printf(",%s]", lcell->next->index);
    }
    else
    {
        printf(",(NULL)]");
    }
}

void print_llist(struct llist *llst)
{
    struct lcell *plcell;
    plcell = llst->head;
    printf("{{\n");
    while (plcell != NULL)
    {
        printf("   ");
        print_lcell(plcell);
        printf(",\n");
        plcell = plcell->next;
    }
    printf("}}\n");
}

/* Cell addition
============= */

struct lcell *make_lcell(char *index, struct list *index_list)
{
    struct lcell *lcellule = (struct lcell *)malloc(sizeof(struct lcell));
    lcellule->index = index;
    lcellule->index_list = index_list;
    lcellule->next = NULL;
    return lcellule;
}

int compare_lcells(struct llist *llst, struct cell *c)
{
    return 0;
}

void insert_optimized(struct llist *llst, struct cell *c)
{
    return;
}

struct llist *load_file_optimized(char *file_name)
{
    struct llist *llst = (struct llist *)malloc(sizeof(struct llist));
    return llst;
}
