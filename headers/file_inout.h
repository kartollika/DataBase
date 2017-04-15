#ifndef INOUT_H_INCLUDED
#define INOUT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "baseFunc.h"
#define N 256

FILE *initFILE(void);

int recordsCount(FILE *file);

void scanFILE(FILE *file, int record, participant *particip);

void printFILE(FILE *file, int record, participant* particip);

void printUser(participant *user);

void closeFILE(FILE *file);

#endif // INOUT_H_INCLUDED
