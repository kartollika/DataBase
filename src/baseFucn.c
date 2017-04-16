#include "../headers/baseFunc.h"
#include "../headers/file_inout.h"

participant *addRecord(participant *part, int *record, int n)
{
    char *s = calloc(N, sizeof(char));

    part = (participant*) realloc(part, (*record+n) * sizeof(participant));

    int k = *record;
    while (k < *record + n)
    {
        printf("\nUser #%i\n", k);
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

        k++;
        printf("=============================\n");
    }
    *record += n;

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
