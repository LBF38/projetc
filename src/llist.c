/**
 * @file llist.c
 * @author Mathis URIEN (LBF38)
 * @brief This is the llist.c file
 * @version 1.0.0
 * @date 2022-10-19
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "llist.h"

/* Construction/Destruction
======================== */

/**
 * @brief new_llist allocates memory for a new llist and returns its pointer.
 * 
 * @return struct llist* 
 */
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

/// @brief
/// @param llst
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
        free(temp->index);
        free_list(temp->index_list);
        free(temp);
    }
    llst->head = NULL;
}

/// @brief
/// @param llst
void free_llist(struct llist *llst)
{
    free_lcells(llst);
    free(llst);
    return;
}

/* Printing
======== */

/// @brief
/// @param lcell
void print_lcell(struct lcell *lcell)
{
    printf("[%s,\n", lcell->index);
    printf("   ");
    print_list(lcell->index_list);
    if (lcell->next != NULL)
    {
        printf("   ,%c]", *(lcell->next->index));
    }
    else
    {
        printf("   ,(NULL)]");
    }
}

/// @brief
/// @param llst
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

/// @brief
struct lcell *make_lcell(struct list *index_list, struct cell *c)
{
    struct lcell *lcellule = (struct lcell *)malloc(sizeof(struct lcell));
    lcellule->index = (char *)malloc(sizeof(char) + 1);
    memcpy(lcellule->index, c->lname, 1);
    lcellule->index[1] = 0;
    insert(index_list, c);
    lcellule->index_list = index_list;
    lcellule->next = NULL;
    return lcellule;
}

/// @brief
/// @param lcellule
/// @param c
/// @return
int compare_lcells(struct lcell *lcellule, struct cell *c)
{
    return strncmp(lcellule->index, c->lname, 1);
}

/**
 * @brief
 *
 * @param llst
 * @param c
 */
void insert_optimized(struct llist *llst, struct cell *c)
{
    struct lcell *current_lcell;
    struct lcell *new_lcell;
    struct list *lst;
    // CAS 1: la lliste est vide
    if (llst->head == NULL)
    {
        lst = new_list();
        current_lcell = make_lcell(lst, c);
        llst->head = current_lcell;
        return;
    }
    // CAS 2: insertion d'une lcell dans une lliste (ajout d'une lettre au début de l'index)
    if (compare_lcells(llst->head, c) > 0)
    {
        lst = new_list();
        current_lcell = make_lcell(lst, c);
        current_lcell->next = llst->head;
        llst->head = current_lcell;
        return;
    }
    // CAS 3: insertion d'une cell dans une list d'une lcell. (on revient aux cas déjà implémentés dans list.c)
    current_lcell = llst->head;
    while (current_lcell->next != NULL)
    {
        if (compare_lcells(current_lcell, c) == 0)
        {
            insert(current_lcell->index_list, c);
            return;
        }
        if (compare_lcells(current_lcell->next, c) > 0)
        {
            lst = new_list();
            new_lcell = make_lcell(lst, c);
            new_lcell->next = current_lcell->next;
            current_lcell->next = new_lcell;
            return;
        }
        current_lcell = current_lcell->next;
    }
    // CAS 4: insertion à la fin de la lliste d'une lcell
    // On vérifie au cas où si c ne va pas dans la dernière lcell de l'index
    if (compare_lcells(current_lcell, c) == 0)
    {
        insert(current_lcell->index_list, c);
        return;
    }
    lst = new_list();
    current_lcell->next = make_lcell(lst, c);
    return;
}

/// @brief This is a brief description of load_file_optimized
struct llist *load_file_optimized(char *file_name)
{
    struct llist *llst;
    llst = new_llist();
    struct cell *cellule;
    char *line = (char *)malloc(100 * sizeof(char));

    FILE *inputFile = fopen(file_name, "r");
    // Gestion erreur ouverture fichier
    if (inputFile == NULL)
    {
        fprintf(stderr, "error opening file : %s\n", strerror(errno));
        exit(-1);
    }
    while (fgets(line, 100, inputFile) != NULL)
    {
        cellule = make_cell_from_line(line);
        insert_optimized(llst, cellule);
    }
    fclose(inputFile);
    free(line);
    return llst;
}
