#pragma once

#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

struct meas 
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int temp;
} m;

void help(const char *appname);

void minimal(int* pointer, int temperature);
void maximal(int* pointer, int temperature);

void mean_year(int* sum_pointer, int temperature);
void mean_month(int* ctr_pointer, int* sum_pointer, int temperature);