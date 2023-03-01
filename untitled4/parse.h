#ifndef PARSE_H
#define PARSE_H
char *findString(char *, const char *);
int getCount( const char *, const  char *);
int contains( const char *, const  char *);
char* getLeft( const char* );
void  returnTagText(char *, char *);
void prim(char *);
void parseData(char* , const  char* , struct Table ** , int );
void parse(struct Table** , int* );
#endif
