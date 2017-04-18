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
    int i = *pos - 1,
        e = i + *n;

    for (; e<*record; ++i, ++e)
        part[i] = part[e];

    *record -= *n;
        part = realloc(part, (*record) * sizeof(participant));
    return part;
}

void editRecord(participant *user)
{
    int id=1, col=1;
    printf("You entered the editing mode\n"
           "Please choose record to edit\n"
           "To quit the editing mode enter 0 at (id) or (field)\n");
    while (col && id)
    {
        printf("id = ");
        scanf("%i", &id);
        if (id)
        {
            printf("What field to edit? 1 - Name 2 - Surname 3 - Place 4 - Average\n");
            scanf("%i", &col);
            if (col)
            {
                if (col < 3)
                    if (col == 1) scanf("%s", user[id-1].name);
                    else scanf("%s", user[id-1].surname);
                else
                    if (col == 3)
                        scanf("%i", &user[id-1].place);
                    else scanf("%lf", &user[id-1].average);
            }
        }
    }
}

int sortBase(participant *part, int column, int direction)
{

    return 0;
}
