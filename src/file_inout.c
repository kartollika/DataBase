#include "../headers/file_inout.h"

FILE *initFILE(int mode)
{
    char *s = calloc(N, sizeof(char));
    FILE *file;
    printf("Enter name of file (ex. ""base.in"")\n");
    scanf("%s", s);

    if (!mode)
    {
        if (!check_ExistName(&file, s))
        {
            file = fopen(s, "w+");
            return file;
        }
        else
        {
            int task;
            while (check_ExistName(&file, s))
            {
                printf("File in directory exist. Orders?\n"
                       "    1) Rewrite file\n"
                       "    2) Write new name\n"
                       "Other) Other operation\n");
                scanf("%i", &task);
                switch(task)
                {
                case 1:
                    {
                        file = fopen(s, "w+");
                        return file;
                    }
                case 2:
                    {
                        printf("Enter new name ");
                        scanf("%s", s);
                        continue;
                    }
                default:
                    {
                        return NULL;
                    }
                }
            }
            file = fopen(s, "w+");
            return file;
        }
    }
    else
    {
        if (check_ExistName(&file, s))
        {
            file = fopen(s, "r");
            return file;
        }
        else
        {
            int task;
            while (!check_ExistName(&file, s))
            {
                printf("File in directory doesn't exist. Orders?\n"
                       "    1) Create file\n"
                       "    2) Write new name\n"
                       "Other) Other operation\n");
                scanf("%i", &task);
                switch(task)
                {
                case 1:
                    {
                        file = fopen(s, "w+");
                        return file;
                    }
                case 2:
                    {
                        printf("Enter new name ");
                        scanf("%s", s);
                        continue;
                    }
                default:
                    {
                        return NULL;
                    }
                }
            }
            file = fopen(s, "r");
            return file;
        }
    }

    return file;
}

int check_ExistName(FILE **file, char *s)
{
    return (fopen(s, "r") != NULL ? 1 : 0);
}

int recordsCount(FILE *file)
{
    int record = 0;
    char c, buf;
    while ((c = getc(file)) != EOF)
    {
        if (c == '\n') record ++;
        buf = c;
    }
    if (!record)
        return 0;
    if (buf != '\n' && c == EOF)
        record++;

    return record;
}

void scanFILE(FILE *file, participant *part, int *record)
{
    int i;
    char *s = calloc(N, sizeof(char));

    fseek(file, 0, SEEK_SET);
    for (i=0; i<*record; ++i)
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

void printFILE(FILE *file, participant *part, int *record)
{
    int i;
    freopen("base.in", "w", stdout);
    for (i=0; i<*record; ++i)
        printf("%s %s %i %.3lf\n", part[i].name, part[i].surname, part[i].place, part[i].average);

    fclose(stdout);
}

void printConsole(participant *part, int *record)
{
    int i;
    for (i=0; i<*record; ++i)
        printf("%8s %10s %4i %5.1lf\n", part[i].name, part[i].surname, part[i].place, part[i].average);
}

void printUser(participant *part)
{
    printf("%10s %10s %6i %7.1lf\n", part->name, part->surname, part->place, part->average);
}

void closeFILE(FILE *file)
{
    fclose(file);
}
