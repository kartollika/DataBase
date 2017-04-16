#include "../headers/file_inout.h"

FILE *initFILE(void)
{
    char *s = calloc(N, sizeof(char));
    FILE *file;
    scanf("%s", s);
    if (fopen(s, "r") == NULL)
    {
        file = fopen(s, "w+");
        return file;
    }
    else
    {
        int task = 1;
        printf("File in this directory exist. Orders?\n"
               "1) Rewrite this file\n"
               "2) Open this file\n"
               "3) Rename your database");
        scanf("%i", &task);
        switch(task)
        {
        case 1:
            {
                fclose(file);
                file = fopen(s, "w+");
                return file;
            }
        case 2:
            {
                return file;
            }
        case 3:
            {

            }
        }
    }
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

        fscanf(file, "%i", &part[i].place);

        fscanf(file, "%lf", &part[i].average);
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
