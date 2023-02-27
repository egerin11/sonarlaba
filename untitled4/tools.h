#ifndef UNTITLED4_TOOLS_H
#define UNTITLED4_TOOLS_H

#include<stdbool.h>

bool check(int *number);

void inputNumber(int *number);

void inputNumberWithBounds(int *number, int, int);

void printStruct(struct Table *table, int number);

void getString(char **string);

void deletedTheSelectedStruct(struct Table **table, int *number, int pos);

void clearScreen();

void inputTable(struct Table *);

void addTable(struct Table **, int *size, int *capacity, struct Table);

#endif
