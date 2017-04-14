#ifndef INOUT_H_INCLUDED
#define INOUT_H_INCLUDED
#include <stdio.h>

typedef struct {
    char *name,
         *surname;
    int place;
    double average;
} participant;

FILE* initFILE(FILE *file);

void scanFILE(FILE *file, participant** part);

void printFILE(FILE *file, participant** part);

void closeFILE(FILE *file);

#endif // INOUT_H_INCLUDED
