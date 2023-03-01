#include"struct.h"
#include<stdbool.h>
#include<string.h>


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

void sortTable(struct Table **table, const int number, int (*cmp)(const struct Table, const struct Table)) {

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

int countIdentical(const struct Table *table,const int pos, const int number, int (*cmp)(const struct Table, const struct Table)) {
    int count = 0;
    for (int i = pos; i < number - 1; i++) {
        if ((*cmp)(table[i], table[i + 1]) == 0) {
            count++;
        }
        else break;
    }
    return count;
}

int findFirstIdentical(const struct Table *table, int number, int (*cmp)(const struct Table, const struct Table)) {
    for (int i = 0; i < number-1; i++) {
        int count = 1;
        for (int j = i + 1; j < number; j++) {
            if ((*cmp)(table[i], table[j]) == 0) {
                count++;
                return count;
            }
        }

    }

}

void sort(struct Table **table, int number, int *pos, int *count, enum SortParam sortParam) {

    switch (sortParam) {
        case sortByName: {
            sortTable(table, number, (int (*)(const struct Table, const struct Table)) cmpByName);
            *pos = findFirstIdentical(*table, number, (int (*)(const struct Table, const struct Table)) cmpByName);
            *count = countIdentical(*table, *pos, number, (int (*)(const struct Table, const struct Table)) cmpByName);

        }
            break;
        case sortByMatrix: {
            sortTable(table, number, (int (*)(const struct Table, const struct Table)) cmpByMatrix);
            *pos = findFirstIdentical(*table, number, (int (*)(const struct Table, const struct Table)) cmpByMatrix);
            *count = countIdentical(*table, *pos,number, (int (*)(const struct Table, const struct Table)) cmpByMatrix);
        }
            break;
        case sortByScreen: {
            sortTable(table, number, (int (*)(const struct Table, const struct Table)) compareScreen);
            *pos = findFirstIdentical(*table, number, (int (*)(const struct Table, const struct Table)) compareScreen);
            *count = countIdentical(*table,*pos, number, (int (*)(const struct Table, const struct Table)) compareScreen);
        }
            break;
        case sortByPrice : {
            sortTable(table, number, (int (*)(const struct Table, const struct Table)) comparePrice);
            *pos = findFirstIdentical(*table, number, (int (*)(const struct Table, const struct Table)) comparePrice);
            *count = countIdentical(*table, *pos,number, (int (*)(const struct Table, const struct Table)) comparePrice);
        }
            break;
        case sortByRam: {
            sortTable(table, number, (int (*)(const struct Table, const struct Table)) compareRam);
            *pos = findFirstIdentical(*table, number, (int (*)(const struct Table, const struct Table)) compareRam);
            *count = countIdentical(*table, *pos,number, (int (*)(const struct Table, const struct Table)) compareRam);
        }
            break;
        case sortByRom: {
            sortTable(table, number, (int (*)(const struct Table, const struct Table)) compareRom);
            *pos = findFirstIdentical(*table, number, (int (*)(const struct Table, const struct Table)) compareRom);
            *count = countIdentical(*table, *pos,number, (int (*)(const struct Table, const struct Table)) compareRom);
        }
            break;
        default:
            break;
    }
}

void sortTwo(struct Table **table, const int pos, int count, int (*cmp)(const struct Table, const struct Table)) {
    struct Table temp;
    bool swapped;

    for (int i = pos; i < pos + count; i++) {
        swapped = false;

        for (int j = pos; j < pos + count - i; j++) {
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


void sortSecond(struct Table **table, int pos, int count, enum SortParam sortParam) {

    switch (sortParam) {
        case sortByName: {

            sortTwo(table, pos, count, (int (*)(const struct Table, const struct Table)) cmpByName);
        }
            break;
        case sortByMatrix: {

            sortTwo(table, pos, count, (int (*)(const struct Table, const struct Table)) cmpByMatrix);
        }
            break;
        case sortByScreen: {

            sortTwo(table, pos, count, (int (*)(const struct Table, const struct Table)) compareScreen);
        }
            break;
        case sortByPrice : {

            sortTwo(table, pos, count, (int (*)(const struct Table, const struct Table)) comparePrice);
        }
            break;
        case sortByRam: {

            sortTwo(table, pos, count, (int (*)(const struct Table, const struct Table)) compareRam);
        }
            break;
        case sortByRom: {

            sortTwo(table, pos, count, (int (*)(const struct Table, const struct Table)) compareRom);
        }
            break;
        default:
            break;
    }
}


