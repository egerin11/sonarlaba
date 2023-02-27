#include"struct.h"
#include<stdbool.h>
#include<string.h>
#include "tools.h"

int cmpByName(const struct Table left, const struct Table right) {
    return strcmp(left.name, right.name);
}

int cmpByMatrix(const struct Table left, const struct Table right) {
    return strcmp(left.matrix, right.matrix);
}

int compareScreen(const struct Table left, const struct Table right) {
    return left.screen > right.screen ? 0 : ((left.screen < right.screen) ? -1 : 1);
}

int comparePrice(const struct Table left, const struct Table right) {
    return left.price > right.price ? 0 : ((left.price < right.price) ? -1 : 1);
}

int compareRam(const struct Table left, const struct Table right) {
    return left.ram > right.ram ? 0 : ((left.ram < right.ram) ? -1 : 1);
}

int compareRom(const struct Table left, const struct Table right) {
    return left.rom > right.rom ? 0 : ((left.rom < right.rom) ? -1 : 1);
}

void sortTable(struct Table **table, const int number, int (*cmp)(struct Table, struct Table)) {

    struct Table temp;
    bool swapped;

    for (int i = 0; i < number - 1; i++) {
        swapped = false;
        for (int j = 0; j < number - i - 1; j++) {
            if ((*cmp)((*table)[j], (*table)[j + 1])) {
                swapped = true;
                temp = (*table)[j];
                (*table)[j] = (*table)[j + 1];
                (*table)[j + 1] = temp;

            }

        }
        if (swapped == false)
            break;

    }

}

int countIdentical(struct Table *table, const int number, int (*cmp)(struct Table, struct Table)) {
    int count = 0;
    for (int i = 0; i < number - 1; i++) {
        if ((*cmp)(table[i], table[i + 1]) == 0) {
            count++;
        }
    }
    return count;
}

int findFirstIdentical(struct Table *table, const int number, int (*cmp)(struct Table, struct Table)) {
    int firstIdentical = -1;
    for (int i = 0; i < number - 1; i++) {
        if ((*cmp)(table[i], table[i + 1]) == 0) {
            firstIdentical = i;
            break;
        }
    }
    return firstIdentical;
}

void sortTwo(struct Table **table, const int pos, int count, int (*cmp)(struct Table, struct Table)) {
    struct Table temp;
    bool swapped;

    for (int i = pos - 1; i < count - 1; i++) {
        swapped = false;
        for (int j = 0; j < count - i - 1; j++) {
            if ((*cmp)((*table)[j], (*table)[j + 1])) {
                swapped = true;
                temp = (*table)[j];
                (*table)[j] = (*table)[j + 1];
                (*table)[j + 1] = temp;

            }
        }
        if (swapped == false)
            break;

    }
}

void sort(struct Table **table, int number, int *pos, int *count, enum SortParam sortParam) {
    switch (sortParam) {
        case sortByName: {
            *pos = findFirstIdentical(*table, number, (int (*)(struct Table, struct Table)) cmpByName);
            *count = countIdentical(*table, number, (int (*)(struct Table, struct Table)) cmpByName);
            sortTable(table, number, (int (*)(struct Table, struct Table)) cmpByName);
        }
            break;
        case sortByMatrix: {
            sortTable(table, number, (int (*)(struct Table, struct Table)) cmpByMatrix);
            *pos = findFirstIdentical(*table, number, (int (*)(struct Table, struct Table)) cmpByMatrix);
            *count = countIdentical(*table, number, (int (*)(struct Table, struct Table)) cmpByMatrix);
        }
            break;
        case sortByScreen: {
            sortTable(table, number, (int (*)(struct Table, struct Table)) compareScreen);
            *pos = findFirstIdentical(*table, number, (int (*)(struct Table, struct Table)) compareScreen);
            *count = countIdentical(*table, number, (int (*)(struct Table, struct Table)) compareScreen);
        }
            break;
        case sortByPrice : {
            sortTable(table, number, (int (*)(struct Table, struct Table)) comparePrice);
            *pos = findFirstIdentical(*table, number, (int (*)(struct Table, struct Table)) comparePrice);
            *count = countIdentical(*table, number, (int (*)(struct Table, struct Table)) comparePrice);
        }
            break;
        case sortByRam: {
            sortTable(table, number, (int (*)(struct Table, struct Table)) compareRam);
            *pos = findFirstIdentical(*table, number, (int (*)(struct Table, struct Table)) compareRam);
            *count = countIdentical(*table, number, (int (*)(struct Table, struct Table)) compareRam);
        }
            break;
        case sortByRom: {
            sortTable(table, number, (int (*)(struct Table, struct Table)) compareRom);
            *pos = findFirstIdentical(*table, number, (int (*)(struct Table, struct Table)) compareRom);
            *count = countIdentical(*table, number, (int (*)(struct Table, struct Table)) compareRom);
        }
            break;
        default:
            break;
    }
}

void sortSecond(struct Table **table, int pos, int count, enum SortParam sortParam) {

    switch (sortParam) {
        case sortByName: {

            sortTwo(table, pos, count, (int (*)(struct Table, struct Table)) cmpByName);
        }
            break;
        case sortByMatrix: {

            sortTwo(table, pos, count, (int (*)(struct Table, struct Table)) cmpByMatrix);
        }
            break;
        case sortByScreen: {

            sortTwo(table, pos, count, (int (*)(struct Table, struct Table)) compareScreen);
        }
            break;
        case sortByPrice : {

            sortTwo(table, pos, count, (int (*)(struct Table, struct Table)) comparePrice);
        }
            break;
        case sortByRam: {

            sortTwo(table, pos, count, (int (*)(struct Table, struct Table)) compareRam);
        }
            break;
        case sortByRom: {

            sortTwo(table, pos, count, (int (*)(struct Table, struct Table)) compareRom);
        }
            break;
        default:
            break;
    }
}


