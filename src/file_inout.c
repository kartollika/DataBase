#include "../headers/file_inout.h"

FILE *initFILE(void)
{
    FILE *file;
    file = fopen("base.in", "r");
    return file;
}

int recordsCount(FILE *file)
{
    int record = 0;
    char c;
    while ((c = getc(file)) != EOF)
        if (c == '\n') record ++;

    return record;
}

int scanFILE(FILE *file, int record, participant *particip)
{
    int i;

    char *s = calloc(N, sizeof(char));
    fseek(file, 0, SEEK_SET);


    for (i=0; i<record; ++i)
    {
        fscanf(file, "%s", s);
        particip[i].name =  malloc(strlen(s) + 1);
        strcpy(particip[i].name, s);

        fscanf(file, " %s", s);
        particip[i].surname =  malloc(strlen(s) + 1);
        strcpy(particip[i].surname, s);
    }

    free(s);
}

void printFILE(FILE *file, participant** part)
{
    int i;
    for (i=0; i<4; ++i)
    {

    }

}

void printUser(participant user)
{
    printf("%s", user.name);
}

void closeFILE(FILE *file)
{
    fclose(file);
}
