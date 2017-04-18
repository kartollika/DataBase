#include "../headers/baseFunc.h"
#include "../headers/file_inout.h"

participant *addRecord(participant *part, int *record, int *n)
{
    char *s = calloc(N, sizeof(char));

    part = (participant*) realloc(part, (*record+*n) * sizeof(participant));

    int k = *record;
    while (k < *record + *n)
    {
        printf("User #%i\n", k);
        printf("Name ");
        scanf("%s", s);
        part[k].name = malloc(strlen(s)+1);
        strcpy(part[k].name, s);

        printf("Surname ");
        scanf("%s", s);
        part[k].surname = malloc(strlen(s)+1);
        strcpy(part[k].surname, s);

        printf("Place ");
        scanf("%i", &part[k].place);
        printf("Average point ");
        scanf("%lf", &part[k].average);

        printf("===================================\n");
        k++;
    }
    *record += *n;
    return part;
}

participant *delRecord(participant *part, int *pos, int *n, int *record)
{
  //  participant *beg =
   //             *end = ;
    int i = *pos - 1,
        e = i + *n;

    for (; e<*record; ++i, ++e)
        part[i] = part[e];

    *record -= *n;
        part = realloc(part, (*record) * sizeof(participant));
    return part;
}

int sortBase(participant *part, int column, int direction)
{

    return 0;
}
