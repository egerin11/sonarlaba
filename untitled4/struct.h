#ifndef UNTITLED4_STRUCT_H
#define UNTITLED4_STRUCT_H
struct Table {
    char name[100];
    float screen;
    char matrix[100];
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
