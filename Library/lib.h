#ifndef LIB_H
#define LIB_H
#include <iostream>
#include <cstring>

typedef struct Book
{
    std::string *name,*author;
    int price, LPIN;
}Book;

extern int num = 0;
extern Book *Lib = nullptr;

int Search (Book[], std::string);
void Issue_Book (Book[], std::string, int);
void Return_Book (Book[], std::string, int);

#endif