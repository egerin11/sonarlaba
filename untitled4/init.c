#include"struct.h"
#include<stdlib.h>
#include<stdio.h>

struct Table *memory(const int number) {
    struct Table *table;
    table = (struct Table *) malloc(number * sizeof(struct Table));
    return table;
}

struct Table init(char name[100], int screen, int matrix[100], float price, int ram, int rom) {
    struct Table param;
    snprintf(param.name, sizeof(param.name), "%s", name);
    param.screen = screen;
    snprintf(param.matrix, sizeof(param.matrix), "%s", matrix);
    param.price = price;
    param.ram = ram;
    param.rom = rom;
    return param;
}