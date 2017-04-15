#ifndef INOUT_H_INCLUDED
#define INOUT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define N 256

typedef struct {
    char *name,
         *surname;
    int place;
    double average;
} participant;

FILE *initFILE(void);

int scanFILE(FILE *file, int record, participant *particip);

void printFILE(FILE *file, participant** particip);

void printUser(participant user);

void closeFILE(FILE *file);

#endif // INOUT_H_INCLUDED
