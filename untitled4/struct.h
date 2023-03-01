#ifndef UNTITLED4_STRUCT_H
#define UNTITLED4_STRUCT_H
struct Table {
    char name[1000];
    float screen;
    char matrix[1000];
    float price;
    int ram;
    int rom;
};
enum SortParam {
    sortByName,
    sortByScreen,
    sortByMatrix,
    sortByPrice,
    sortByRam,
    sortByRom

};
#endif
