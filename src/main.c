#include <time.h>

#include "llist.h"

int main(int argc, char *argv[])
{
    int display_mode = 0;
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

    if (file)
    {
        printf("Méthode 1 :\n\n");
        printf("Start loading file using method 1\n");
        clock_t function_time;
        function_time = clock();
        struct list *lst;
        lst = load_file(file);
        if (display_mode)
        {
            print_list(lst);
        }
        free_list(lst);
        function_time = clock() - function_time;
        printf("Ended loading file using method 1\n");
        double time_taken = ((double)function_time) / CLOCKS_PER_SEC;
        printf("Time used by method 1 : %f seconds\n", time_taken);

        printf("\nMéthode 2 :\n\n");
        printf("Start loading file using method 2\n");
        function_time = clock();
        struct llist *llst;
        llst = load_file_optimized(file);
        if (display_mode)
        {
            print_llist(llst);
        }
        free_llist(llst);
        function_time = clock() - function_time;
        printf("Ended loading file using method 2\n");
        time_taken = ((double)function_time) / CLOCKS_PER_SEC;
        printf("Time used by method 2 : %f seconds\n", time_taken);
    }

    return 0;
}