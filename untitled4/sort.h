#ifndef UNTITLED4_SORT_H
#define UNTITLED4_SORT_H

#include<stdbool.h>

int cmpByName(struct Table left, struct Table right);

int cmpByMatrix(struct Table left, struct Table right);

int compareScreen(struct Table left, struct Table right);

int comparePrice(struct Table left, struct Table right);

int compareRam(struct Table left, struct Table right);

int compareRom(struct Table left, struct Table right);

void sortTable(struct Table **table, int number, int (*cmp)(struct Table, struct Table));

int countIdentical(const struct Table *table, int number, int (*cmp)(struct Table, struct Table));

void sortTwo(struct Table **table, int pos, int count, int (*cmp)(struct Table, struct Table));

int findFirstIdentical(const struct Table *table, int number, int (*cmp)(struct Table, struct Table));

void sort(struct Table **table, int, int *, int *, enum SortParam sortParam);

void sortSecond(struct Table **table, int, int, enum SortParam sortParam);


#endif
