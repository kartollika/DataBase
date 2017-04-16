#include <stdio.h>
#include <stdlib.h>
#include "headers/baseFunc.h"
#include "headers/file_inout.h"

int main()
{
    int record, task = 1;
    participant *participants = NULL;
    FILE *f = NULL;

    {
        TEST_count_Record();
        printf("ALL TESTS SUCCESSFUL\n"
               "READY TO WORK\n");
    }

    while ( 1 )
    {
        printf("\nChoose your operation with database\n"
               "    1) Create new database\n"
               "    2) Load database from file\n"
               "    3) Save database in same file\n"
               "    4) Print database on console\n"
               "    5) Print specific record by identifier\n"
               "    6) Add new records to database\n"
               "    7) Delete records from database\n"
               "    8) Sort database by specific field\n"
               "Other) Exit\n");

        scanf("%i", &task);
        switch(task)
        {
        case 1:
            {
                if (!f)
                {
                    f = initFILE(0);
                    if (!f) continue;
                    record = recordsCount(f);
                    participants = (participant*) malloc(record * sizeof(participant));
                }
                continue;
            }
        case 2:
            {
                if (!f)
                {
                    f = initFILE(1);
                    record = recordsCount(f);
                    participants = (participant*) malloc(record * sizeof(participant));
                    scanFILE(f, record, participants);
                }

                continue;
            }
        case 3:
            {
                if (f)
                    printFILE(f, record, participants);
                else
                    printf("DATABASE HASN'T FOUND\n");

                continue;
            }
        case 4:
            {
                if (f)
                    printConsole(record, participants);
                else
                    printf("DATABASE HASN'T FOUND\n");
                continue;
            }
        case 5:
            {
                int ident;
                scanf("%i", &ident);
                printUser(participants, ident);
                continue;
            }
        case 6:
            {
                if (f)
                {
                    int count;
                    printf("Enter count of new records\nCount = ");
                    scanf("%i", &count);
                    participants = addRecord(participants, &record, count);
                }
                else
                    printf("DATABASE HASN'T FOUND\n");

                continue;
            }
        case 7:
            {


                continue;
            }
        case 8:
            {


                continue;
            }
        default:
            {
                closeFILE(f);
                return 0;
            }
        }
    }
    return 0;
}
