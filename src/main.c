#include <time.h>

#include "list.h"

int main(int argc, char *argv[])
{
    struct list *l;
    l = new_list();
    print_list(l);

    struct cell *c;
    c = make_cell("Annie", "ERNAUX", "76170");

    push(l, c);

    printf("List status\n");
    print_list(l);

    struct cell *out;
    out=malloc(sizeof(struct cell));
    pop(l,out);

    printf("out cell content : \n");
    print_cell(out);

    printf("List status\n");
    print_list(l);

    free_list(l);
    free(out);

    // Tests sur partie 2 :
    char str[50] = "this,is,a,test\nand,a,another\none";
    print_cell(make_cell_from_line(str));
    return 0;
}