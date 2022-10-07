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

    print("List status\n");
    print_list(l);

    struct cell *out;
    out=malloc(sizeof(struct cell));
    pop(l,out);

    print("out cell content : \n");
    print_cell(out);

    print("List status\n");
    print_list(l);

    free_list(l);
    return 0;
}