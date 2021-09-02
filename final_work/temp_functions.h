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
void min_year(int* pointer, int temperature);
void max_year(int* pointer, int temperature);
void mean_year(int* sum_pointer, int temperature);

void minimum_month(int* pointer, int temperature);
void maximum_month(int* pointer, int temperature);
void mean_month(int* ctr_pointer, int* sum_pointer, int temperature);