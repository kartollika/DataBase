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

void scanFILE(FILE *file, int record, participant *part)
{
    int i;
    int place;
    double aver;

    char *s = calloc(N, sizeof(char));
    fseek(file, 0, SEEK_SET);

    for (i=0; i<record; ++i)
    {
        fscanf(file, "%s", s);
        part[i].name =  malloc(strlen(s) + 1);
        strcpy(part[i].name, s);

        fscanf(file, "%s", s);
        part[i].surname =  malloc(strlen(s) + 1);
        strcpy(part[i].surname, s);

        fscanf(file, "%i", &place);
        part[i].place = place;

        fscanf(file, "%lf", &aver);
        part[i].average = aver;
    }
    free(s);
}

void printFILE(FILE *file, int record, participant *part)
{
    int i;
    freopen("base.in", "w", stdout);
    for (i=0; i<record; ++i)
        printf("%s %s %i %.3lf\n", part[i].name, part[i].surname, part[i].place, part[i].average);

    fclose(stdout);
}

void printUser(participant *user)
{
    printf("%s", user->name);
}

void closeFILE(FILE *file)
{
    fclose(file);
}
