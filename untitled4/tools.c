#include"struct.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"init.h"
#include<string.h>

bool check(int *number) {
    return scanf("%d", number) != 1 || getchar() != '\n';
}

void inputNumber(int *number) {
    while (check(number)) {
        printf("Enter a valid number: ");
        rewind(stdin);
    }

}

void inputNumberWithBounds(int *number, const int leftBound, const int rightBound) {
    do {
        inputNumber(number);
    } while (*number < leftBound || *number > rightBound);
}


void printStruct(struct Table *table, const int number) {
    printf("#\tname\tscreen\tmatrix\tprice\tram\trom\n");
    for (int i = 0; i < number; i++) {

        printf("[%d] %4s\t%f\t%4s\t%4f\t%4d\t%4d\t\n", i + 1, table[i].name, table[i].screen, table[i].matrix,
               table[i].price, table[i].ram, table[i].rom);
    }

}

void getString(char **string) {
    int size = 0;
    int realSize = 8;

    *string = (char *) malloc(realSize * sizeof(char));
    rewind(stdin);
    char check;
    while (true) {
        check = getchar();
        if (check == '\n') {
            if (size + 1 < realSize) {
                *string = (char *) realloc(*string, (size + 1) * sizeof(char));
            }
            (*string)[size] = '\0';
            return;
        }

        (*string)[size] = check;
        size++;
        if (size + 1 == realSize) {
            realSize *= 2;
            *string = (char *) realloc(*string, realSize * sizeof(char));
        }
    }
}


void deletedTheSelectedStruct(struct Table **table, int *number, const int pos) {

    for (int i = pos - 1; i < *number; i++) {
        (*table)[i] = (*table)[i + 1];
    }
    *table = (struct Table *) realloc(*table, ((*number)--) * sizeof(struct Table));

}

void clearScreen() {

#if defined(__linux__)
    system("clear");
#elif defined(_WIN32)
    system("cls");
#else
    for (int i = 0; i < 32; i++)
        printf("\n");
#endif
}

void inputTable(struct Table *in) {
    struct Table table;
    char *temporaryArray;
    printf("NAME :\n");
    getString(&temporaryArray);
    if (strlen(temporaryArray) > 99) {
        printf("out of memory");
        return;
    } else
        strcpy(table.name, temporaryArray);
    printf("input screen");
    while (scanf("%f", &(table.screen)) != 1 || getchar() != '\n') {
        printf("Enter a valid screen: ");
        rewind(stdin);
    }
    printf("MATRIX :\n");
    getString(&temporaryArray);
    if (strlen(temporaryArray) > 99) {
        printf("out of memory");
        return;
    } else
        strcpy(table.matrix, temporaryArray);
    printf("Enter a valid PRICE: ");
    rewind(stdin);
    while (scanf("%f", &(table.price)) != 1 || getchar() != '\n') {
        printf("Enter a valid PRICE: ");
        rewind(stdin);
    }
    printf("input RAM");
    while (check(&(table.ram))) {
        printf("Enter a valid RAM: ");
        rewind(stdin);
    }
    printf("input ROM");
    while (check(&(table.rom))) {
        printf("Enter a valid ROM: ");
        rewind(stdin);
    }

    *in = table;
}

void addTable(struct Table **tables, int *size, int *capacity, const struct Table table) {
    if (*size == *capacity + 1) {
        *capacity *= 2;
        *tables = (struct Table *) realloc(*tables, *capacity * sizeof(struct Table));
    }

    (*tables)[*size] = table;
    (*size)++;
}