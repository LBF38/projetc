#include <time.h>

#include "llist.h"

int main(int argc, char *argv[])
{
    // Test Partie 1:

    // struct list *l;
    // l = new_list();
    // print_list(l);

    // struct cell *c;
    // struct cell *d;
    // c = make_cell("Annie", "ERNAUX", "76170");
    // d = make_cell("Bertrand", "DOE", "29200");

    // push(l, c);
    // push(l, d);
    // push(l, c);
    // push(l, c);
    // push(l, d);

    // printf("List status\n");
    // print_list(l);

    // struct cell *out;
    // out=malloc(sizeof(struct cell));
    // pop(l,out);

    // printf("out cell content : \n");
    // print_cell(out);

    // printf("List status\n");
    // print_list(l);

    // free_list(l);
    // free(out);

    // Tests sur partie 2 :

    // Test sur compare_cells :
    // struct cell* c1;
    // struct cell* c2;
    // struct cell* c3;
    // c1=make_cell("a","a","123");
    // c2=make_cell("a","b","123");
    // c3=make_cell("b","b","123");
    // printf("%d\n",compare_cells(c1,c2)); // résultat attendu : -1 correct!
    // printf("%d\n",compare_cells(c2,c1)); // résultat attendu :  1 correct!
    // printf("%d\n",compare_cells(c2,c3)); // résultat attendu : -1 correct!

    // Test sur insert:
    // struct list *lst;
    // lst=new_list();
    // struct cell* c1;
    // struct cell* c2;
    // struct cell* c3;
    // c1=make_cell("a","a","123");
    // c2=make_cell("a","b","123");
    // c3=make_cell("b","b","123");
    // print_list(lst);
    // insert(lst,c2);
    // print_list(lst);
    // insert(lst,c1);
    // print_list(lst);
    // insert(lst,c3);
    // print_list(lst);
    // free_list(lst);

    // char file[50] = "/home/mathis/projetc/projetc/data/small.txt";
    // struct list *lst;
    // lst = load_file(file);
    // print_list(lst);
    // // print_cell(lst->head);
    // free_list(lst);

    // Test sur partie 3 :
    // struct llist *llst;
    // struct lcell*lcellule;
    // char*index;
    // llst = new_llist();
    // print_llist(llst);
    // index="A";
    // struct list*lst;
    // lst=new_list();
    // lcellule = make_lcell(index,lst);
    // print_lcell(lcellule);

    // char file[50] = "/home/mathis/projetc/projetc/data/small.txt";
    // struct llist *llst;
    // llst = load_file_optimized(file);
    // print_llist(llst);
    // free_llist(llst);
    int display_mode=0;
    if (argc < 2)
    {
        printf("Please include a path to the file you want to open.\n");
        exit(-1);
    }
    if (argc > 2 && argv[2] != NULL)
    {
        if (strcmp(argv[2], "--display") == 0)
        {
            display_mode = 1;
        }
    }
    char *file = argv[1];

    if (file != NULL)
    {
        // printf("Méthode 1 :\n");
        // struct list *lst;
        // lst = load_file(file);
        // if (display_mode)
        // {
        //     print_list(lst);
        // }
        // free_list(lst);

        printf("Méthode 2 :\n");
        struct llist *llst;
        llst = load_file_optimized(file);
        if (display_mode)
        {
            print_llist(llst);
        }
        free_llist(llst);
    }

    return 0;
}