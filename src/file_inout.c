#include "../headers/file_inout.h"

FILE* initFILE(FILE *file)
{
    file = fopen("base.in", "a");
    return file;
}

void printFILE(FILE *file, participant** part)
{
    int i;
    for (i=0; i<4; ++i)
    {

    }

}

void closeFILE(FILE *file)
{
    fclose(file);
}
