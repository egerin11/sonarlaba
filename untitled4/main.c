#include "struct.h"
#include "tools.h"
#include <stdlib.h>
#include <stdio.h>
#include"init.h"
#include "sort.h"
#include "parse.h"

#define EXIT 0
#define ADD_TABLE 1
#define DELETE_TABLE 2
#define PRINT_TABLES 3
#define SORT_TABLES_SUB_MENU 4
#define FILL_STRUCT 5
#define PARSE 6

void showMenu() {
    clearScreen();
    printf("\t\t\t\t\t\tMENU\n\n");
    printf("\t0 - EXIT\n");
    printf("\t1 - ADD TABLE\n");
    printf("\t2 - DELETE TABLE\n");
    printf("\t3 - PRINT TABLES\n");
    printf("\t4 - SORT TABLES\n");
    printf("\t5 - FILL STRUCT\n");
    printf("\t6 - PARSE\n");
    printf("\n");
}

int main() {
    int size = 0;
    int capacity = 64;
    struct Table *tables = memory(capacity);

    int key;
    do {
        showMenu();
        inputNumberWithBounds(&key, EXIT, PARSE);


        switch (key) {
            case ADD_TABLE: {
                struct Table table;
                inputTable(&table);
                addTable(&tables, &size, &capacity, table);
                getchar();
            }
                break;
            case DELETE_TABLE: {
                printf("Enter number of Table you want delete :\n");
                int pos;
                inputNumberWithBounds(&pos, 0, size);
                deletedTheSelectedStruct(&tables, &size, pos);
                getchar();
            }
                break;
            case PRINT_TABLES: {
                printStruct(tables, size);
                getchar();
            }
                break;
            case SORT_TABLES_SUB_MENU: {
                    int sizeTwo = 0;
                    int pos = 0;
                    int count = 0;
                    inputNumberWithBounds(&sizeTwo, 0, 6);
                    sort(&tables, size, &pos, &count, sizeTwo);
                    inputNumberWithBounds(&sizeTwo, 0, 6);
                  sortSecond(&tables, pos, count, sizeTwo);
               getchar();

            }
                break;
            case FILL_STRUCT: {
                printf("Enter number of structs: ");
                int number;
                struct Table table;
                inputNumber(&number);
                while (number > 0) {

                    inputTable(&table);
                    addTable(&tables, &size, &capacity, table);
                    number--;
                }
                getchar();
            }
                break;
            case PARSE: {

                parse(&tables, &size);
                getchar();
            }
                break;

            default: {
                printf("");
            }
        }
    } while (key != EXIT);
    free(tables);

    return 0;
}
