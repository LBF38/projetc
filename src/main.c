#include <time.h>

#include "list.h"

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
    // char str[50] = "this,is,a,test\nand,a,another\none";
    // print_cell(make_cell_from_line(str));

    char file[50]="/home/mathis/projetc/projetc/data/small.txt";
    struct list *lst;
    lst = load_file(file);
    print_list(lst);
    // print_cell(lst->head);
    free_list(lst);
    return 0;
}