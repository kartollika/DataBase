#include "../headers/baseFunc.h"
#include "../headers/file_inout.h"

participant *addRecord(participant *part, int *record, int n)
{
    char *s = calloc(N, sizeof(char));

    part = (participant*) realloc(part, (*record+1) * sizeof(participant));

    scanf("%s", s);
    part[*record].name = malloc(strlen(s)+1);
    strcpy(part[*record].name, s);

    scanf("%s", s);
    part[*record].surname = malloc(strlen(s)+1);
    strcpy(part[*record].surname, s);

    scanf("%i", &part[*record].place);

    scanf("%lf", &part[(*record)++].average);

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
