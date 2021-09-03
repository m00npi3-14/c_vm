#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

#include "temp_functions.h"

extern char *optarg;
extern int optind, opterr, optopt;


int main(int argc, char **argv)
{
    int ret;
    char *filename;
    int month_num = 0;
    int argum = 0;

    int mins_in_y = 0; //минут в году

    int ctr = 0; //минут в месяце
    int *p_ctr = &ctr;

    int minimum = 0;
    int *p_min = &minimum;

    int maximum = 0;
    int *p_max = NULL;
    p_max = &maximum;

    int sum_temps_in_year = 0;//сумма температур в году
    int *p_sum_y = &sum_temps_in_year;

    int mean_y = 0;

    int sum_temps_in_month = 0; //сумма температур в заданном месяце
    int *p_sum_m = &sum_temps_in_month;

    int min_month = 0;
    int *p_min_month = &min_month;

    int max_month = 0;
    int *p_max_month = &max_month;

    int mean = 0;
    //int *p_mean = &mean;

    if (argc == 1) {
        help(argv[0]);
        return 0;
    }

    while ((ret = getopt(argc, argv, "hf:m:")) != -1)
    {
        switch(ret) {
            case 'h' : {
                printf("rettt h %d\n", ret);
                help(argv[0]);
                return 0;
            }

            case 'f' : {
                filename = optarg;
                break;
            }

            case 'm' : {
                month_num = atoi(optarg);
                argum = 1;
                break;
            }
        
        }
    }

    FILE *f = fopen(filename, "r");
    if (!f) 
    {
        printf("Error opening file\n");
        return 0;
    }


    while (!feof(f)) 
    {
        struct meas m;

        int scanfret = fscanf(f, "%d;%d;%d;%d;%d;%d",
                &m.year,
                &m.month,
                &m.day,
                &m.hour,
                &m.minute,
                &m.temp);
        

        mins_in_y++;

        if(m.month == month_num)
        {
            minimum_month(p_min_month, m.temp);
            maximum_month(p_max_month, m.temp);
            mean_month(p_ctr, p_sum_m, m.temp);
        }
        else
        {
            min_year(p_min, m.temp);
            max_year(p_max, m.temp);
            mean_year(p_sum_y, m.temp);
        }
        
    }

    if(argum == 1)
    {
        mean = *p_sum_m / *p_ctr;
        printf("*******\tStatistics on month %d\t*******\n", month_num);
        printf("Min in month %d: %d\n", month_num,*p_min_month);
        printf("Max in month: %d\n", *p_max_month);
        printf("Mean in month: %d\n", mean);
    } 
    else 
    {
        mean_y = *p_sum_y / mins_in_y;
        printf("*******\tStatistics on the year\t*******\n");
        printf("Min in year: %d\n", *p_min);
        printf("Max in year: %d\n", *p_max);
        printf("Mean in year: %d\n", mean_y);
    }

    fclose(f);


    return 0;
}

