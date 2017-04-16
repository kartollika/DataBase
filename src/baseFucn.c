#include "../headers/baseFunc.h"
#include "../headers/file_inout.h"

participant *addRecord(participant *part, int *record, int n)
{
    char *s = calloc(N, sizeof(char));

    part = (participant*) realloc(part, (*record+n) * sizeof(participant));

    int k = *record;
    while (k < *record + n)
    {
        printf("User #%i", k);
        printf("Name ");
        scanf("%s", s);
        part[*record].name = malloc(strlen(s)+1);
        strcpy(part[*record].name, s);

        printf("Surname ");
        scanf("%s", s);
        part[*record].surname = malloc(strlen(s)+1);
        strcpy(part[*record].surname, s);

        printf("Place ");
        scanf("%i", &part[*record].place);
        printf("Average point ");
        scanf("%lf", &part[(*record)++].average);

        k++;
    }

    return part;
}

int delRecord(participant *part, int pos, int n)
{


    return 0;
}

int sortBase(participant *part, int column, int direction)
{

    return 0;
}
