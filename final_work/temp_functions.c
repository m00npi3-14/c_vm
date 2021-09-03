#include "temp_functions.h"

#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

void help(const char *appname)
{
    char text_to_print[1000] = "************    HELP MESSAGE    ************\n"
                                "!!! This program requieres -f<filename.csv> argument. (like this: ./main -f temp.csv)\n"
                                "If you only want to see statistics on one month, also put -m<month's number>. (1 is for Jan, 2-Feb and so on)\n"
                                "If you want to see this help message again, put a -h argument).\n";
    printf("%s", text_to_print);

    printf("You are in %s\n", appname);
}

void minimal(int* pointer, int temperature)
{
    if(temperature < *pointer)
    {
        *pointer = temperature;
    }
}

void maximal(int* pointer, int temperature)
{
    if(temperature > *pointer)
    {
        *pointer = temperature;
    }
}

void mean_month(int* ctr_pointer, int* sum_pointer, int temperature)
{
    *sum_pointer = *sum_pointer + temperature;
    *ctr_pointer += 1;
}

void mean_year(int* sum_pointer, int temperature)
{
    *sum_pointer = *sum_pointer + temperature;
}