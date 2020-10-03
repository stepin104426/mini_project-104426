#ifndef __TRANSYS_H__
#define __TRANSYS_H__



#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Train{
	int sl_no;
	int train_number;
	char train_name[30];
	char source[30];
	char destination[30];
	char arr_time[10];
	char dept_time[10];
	}train;

train train_data[10];
int train_count ;
train *t_array[10];

void show_menu();
char train_listing();
char train_search();
void getTrainData();
void train_sort(int sort_type);
int compare_train(train *t_array1,train *t_array2, int num);
int compare_time(char* t1, char* t2);

#endif