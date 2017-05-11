#include "../headers/baseFunc.h"
#include "../headers/file_inout.h"

int cmp_int(void *a, void *b)
{
    return *(int*)a == *(int*)b ? 0 : ( *(int*)a < *(int*)b ?  -1 :  1);
}

void m_mloc(participant **part, int record)
{
    *part = malloc(record * sizeof(participant));
}

void m_rloc(participant **part, int record)
{
    *part = realloc(*part, record * sizeof(participant));
}

participant *addRecord(participant *part, int *record, int n)
{
    char *s = calloc(N, sizeof(char));

    m_rloc(&part, *record+n);

    int k = *record;
    while (k < *record + n)
    {
        printf("User #%i\n", k+1);
        printf("Name ");
        scanf("%s", s);
        part[k].name =  malloc(strlen(s)+1);
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
    *record += n;
    return part;
}

participant *delRecord(participant *part, int pos, int n, int *record)
{
    int i = pos - 1,
        e = i + n;

    for (; e<*record; ++i, ++e)
        part[i] = part[e];

    *record -= n;

    m_rloc(&part, *record);

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
                    if (col == 1)
                    {
                        printf("%s --> ", user[id-1].name);
                        scanf("%s", user[id-1].name);
                    }
                    else
                    {
                        printf("%s --> ", user[id-1].surname);
                        scanf("%s", user[id-1].surname);
                    }
                else
                    if (col == 3)
                    {
                        printf("%i --> ", user[id-1].place);
                        scanf("%i", &user[id-1].place);
                    }
                    else
                    {
                        printf("%.3lf --> ", user[id-1].average);
                        scanf("%lf", &user[id-1].average);
                    }
            }
        }
    }
}

int sortBase(participant *part, int column, int mode, int *record)
{
    int i, j;
    participant *buf;
    if (column > 2)
    {
        for (i=0; i<*record-1; ++i)
        {
            size_t k = i;
            if (column == 3)
            {
                for (j = i+1; j<*record; ++j)
                    if (mode == 0)
                    {
                        if (part[k].place > part[j].place)
                        k = j;
                    }
                    else
                        if (part[k].place < part[j].place)
                            k = j;
            }
            else
                for (j = i+1; j<*record; ++j)
                    if (mode == 0)
                    {
                        if (part[k].average > part[j].average)
                        k = j;
                    }
                    else
                        if (part[k].average < part[j].average)
                            k = j;
            if (k != j)
            {
                buf =  malloc(sizeof(part[k]));
                *buf = part[k];
                part[k] = part[i];
                part[i] = *buf;
                free(buf);
            }
        }
        return 0;
    }
    else
    {
        int diff = 0;
        for (i=0; i<*record-1; ++i)
        {
            size_t k = i;
            for (j=i+1; j<*record; ++j)
            {
                if (column == 1)
                    diff = strcmp(part[k].name, part[j].name);
                else
                    diff = strcmp(part[k].surname, part[j].surname);
                if (mode == 0)
                {
                    if (diff > 0)
                    {
                        buf =  malloc(sizeof(part[k]));
                        *buf = part[k];
                        part[k] = part[j];
                        part[j] = *buf;
                        free(buf);
                    }
                }
                else
                    if (diff < 0)
                    {
                        buf =  malloc(sizeof(part[k]));
                        *buf = part[k];
                        part[k] = part[j];
                        part[j] = *buf;
                        free(buf);
                    }
            }
        }
        return 0;
    }
}
