/**
 * @file main.c
 * @author Mathis URIEN (LBF38)
 * @brief This is the main.c file used to launch the methods for loading files.
 * @version 1.0.0
 * @date 2022-10-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <time.h>
#include "llist.h"

/**
 * @brief The main file runs the different methods and measures execution time.
 * 
 * It has some options to only measure one method with a file.
 * @warning The file argument is needed to correctly use the program.
 * Only options are optional.
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char *argv[])
{
    int display_mode = 0;
    int method1 = 0;
    int method2 = 0;
    int default_mode = 1;
    if (argc < 2)
    {
        printf("Please include a path to the file you want to open.\n\n"
               "Usage : ./bin/womc [path/to/file.txt] [-options]\n\n"
               "Available options :\n\n"
               "-d,--display               Display the list resulting of the method used\n"
               "-m1,--method1              Launch only the method 1. Compatible with the display option.\n"
               "-m2,--method2              Launch only the method 2. Compatible with the display option.\n"
               "--default       (optional) Launch both methods in default mode. Compatible with the display option.\n"
               );

        exit(-1);
    }
    if (argc > 2 && argv[2] != NULL)
    {
        for (int i = 2; i < argc; i++)
        {
            printf("%s\n", argv[i]);
            if (strcmp(argv[i], "--display") == 0 || strcmp(argv[i], "-d") == 0)
            {
                display_mode = 1;
            }
            if (strcmp(argv[i], "--method1") == 0 || strcmp(argv[i], "-m1") == 0)
            {
                method1 = 1;
                method2 = 0;
                default_mode=0;
            }
            if (strcmp(argv[i], "--method2") == 0 || strcmp(argv[i], "-m2") == 0)
            {
                method1 = 0;
                method2 = 1;
                default_mode=0;
            }
            if (strcmp(argv[i], "--default") == 0)
            {
                default_mode = 1;
                method1 = 0;
                method2 = 0;
                display_mode = 0;
            }
        }
    }
    char *file = argv[1];

    if (file)
    {
        if (method1 || default_mode)
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
        }

        if (method2 || default_mode)
        {
            printf("\nMéthode 2 :\n\n");
            printf("Start loading file using method 2\n");
            clock_t function_time2;
            function_time2 = clock();
            struct llist *llst;
            llst = load_file_optimized(file);
            if (display_mode)
            {
                print_llist(llst);
            }
            free_llist(llst);
            function_time2 = clock() - function_time2;
            printf("Ended loading file using method 2\n");
            double time_taken2 = ((double)function_time2) / CLOCKS_PER_SEC;
            printf("Time used by method 2 : %f seconds\n", time_taken2);
        }
    }

    return 0;
}

// /**
//  * @mainpage My Personal Index Page
//  * 
//  * @section intro_sec Introduction
//  * 
//  * This is the introduction for my C-lang project.
//  * Here is a table of content of the documentation : @tableofcontents
//  * 
//  * @section install_sec Installation
//  * 
//  * This is a section about how to install the project.
//  * 
//  * @subsection step1 Step 1: Downloading the code.
//  * 
//  * blabla...
//  * 
//  */