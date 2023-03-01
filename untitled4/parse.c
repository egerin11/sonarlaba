#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include"struct.h"
#include "init.h"


char *findString(char *str, const char *subStr) {
    int j;

    for(int i = 0; str[i]; i++) {
        if(str[i] == subStr[0]) {
            for(j = 0; subStr[j] && str[i + j] == subStr[j]; j++);
            if(!subStr[j])
                return &str[i];
        }
    }

    return NULL;
}
int getCount(const char *str, const char *subStr) {
    int j; int count = 0;

    for(int i = 0; str[i]; i++) {
        if(str[i] == subStr[0]) {
            for(j = 0; subStr[j] && str[i + j] == subStr[j]; j++);
            if(!subStr[j]) {
                count++;
            }
        }
    }

    return count;
}
int contains(const char *str, const char *substr) {
    int j;

    for(int i = 0; str[i]; i++) {
        if(str[i] == substr[0]) {
            for(j = 0; substr[j] && str[i+j] == substr[j]; j++);
            if(!substr[j]) {
                return 1;
            }
        }
    }

    return 0;
}

void returnTagText(char *tag, char *bufArray) {
    char *ptr1; const char *ptr2;

    ptr1 = findString(tag, ">") + 1;
    ptr2 = findString(ptr1, "<");
    strncpy(bufArray, ptr1, ptr2-ptr1);
    bufArray[ptr2-ptr1] = '\0';
}


char* getLeft(const char* str) {
    int sub = 0;
    char nbsp[6] = "&nbsp;";
    int j; int i;
    for(i = 0; str[i]; i++) {
        if(str[i] == '&' || str[i] == ' ') {
            for(j = 0; j < 6 && str[i+j] != nbsp[j]; j++);
            if(j == 6 || str[i] == ' ')
            {
                sub = i;
                break;
            }
        }
    }
    if(sub == 0)
        sub = i;
    char* buf = (char*)malloc((sub+1)*sizeof(char));
    strncpy(buf, str, sub);
    buf[sub] = '\0';
    return buf;
}
void prim(char *str) {
    int j = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

void parseData(char* ptr, const char* localEnd, struct Table ** table, int currPos) {
    char name[1000];
    float screen;
    char matrix[1000];
    float price;
    int ram;
    int rom;
    char buffer[1000];
    char typeBuffer[1000];
    ptr = findString(ptr, "<span class=\"result__name\">");
    returnTagText(ptr, buffer);
    snprintf(name, sizeof(name), "%s", buffer);
    char *descPtr = findString(ptr, "<td class=\"result__attr_var");
    while(descPtr != NULL && descPtr < localEnd) {
        returnTagText(descPtr, typeBuffer);

        descPtr = findString(descPtr, "<td class=\"result__attr_val");
       returnTagText(descPtr, buffer);

        if(contains(typeBuffer, "Диагональ экрана")) {
            char* gl = getLeft(buffer);
            sscanf(gl, "%f", &screen);
            free(gl);

        }
        else if(contains(typeBuffer, "Тип матрицы")) {
            snprintf(matrix, sizeof(matrix), "%s", buffer);
        }

        else if(contains(typeBuffer, "Оперативная память")) {
            char* gl = getLeft(buffer);
            sscanf(gl, "%d", &ram);
            free(gl);
        }
        else if(contains(typeBuffer, "Встроенная память")) {
            char* gl = getLeft(buffer);
            sscanf(gl, "%d", &rom);
            free(gl);
        }

        descPtr = findString(descPtr, "<td class=\"result__attr_var");
    }
    ptr = findString(ptr, "<span data-code=\"");
    returnTagText(ptr, buffer);
    prim(buffer);
    sscanf(buffer, "%f", &price);
    (*table)[currPos] = initialization(name, screen,matrix,price,ram,rom);
}


void parse(struct Table** table, int* size) {
    char html[1000000]; char *ptr; char *start; const char *end;

    FILE *fp = fopen("/home/egerin/CLionProjects/untitled4/21vek.html", "r");
    if (fp == NULL) {
        printf("Error: Failed to open URL.");
        return;
    }

    fread(html, 1, sizeof(html), fp);
    fclose(fp);

    start = findString(html, "<ul class=\"b-result\" id=\"j-result-page-");
    end = findString(start, "</ul>");

    ptr = start;
    int count = getCount(ptr, "<li class=\"result__item cr-result__full");
    *size = count;
    *table = (struct Table*)malloc(60* sizeof(table));
    int currPos = 0;
    while (ptr < end) {
        ptr = findString(ptr, "<li class=\"result__item cr-result__full");
        if (ptr == NULL)
            break;
        char* localEnd = findString(ptr, "</li>");
        parseData(ptr,localEnd,table,currPos);
        currPos++;
        ptr = localEnd;
    }
}