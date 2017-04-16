#include <stdio.h>
#include <stdlib.h>
#include "headers/baseFunc.h"
#include "headers/file_inout.h"

int main()
{
    int record, task = 1;
    int i;
    participant *participants = NULL;
    FILE *f = NULL;

    {
        TEST_count_Record();
        printf("ALL TEST SUCCESSFUL\n"
               "READY TO WORK\n\n");
    }
    while ((task > 0) && (task <6))
    {
        printf("Choose your operation with database\n"
               "    1) Create new database\n"
               "    2) Load database from file\n"
               "    3) Save database in same file\n"
               "    4) Print database on console\n"
               "    5) Add new records to database\n"
               "    6) Delete records from database\n"
               "    7) Sort database by specific field\n"
               "Other) Exit\n");
        scanf("%i", &task);
        switch(task)
        {
        case 1:
            {
                f = initFILE();
                record = recordsCount(f);
                participants = (participant*) malloc(record * sizeof(participant));

                continue;
            }
        case 2:
            {
                f = initFILE();
                record = recordsCount(f);
                participants = (participant*) malloc(record * sizeof(participant));
                scanFILE(f, record, participants);

                continue;
            }
        case 3:
            {
                printFILE(f, record, participants);
                continue;
            }
        case 4:
            {


                continue;
            }
        case 5:
            {

                participants = addRecord(participants, &record, 0);

                continue;
            }
        case 6:
            {


                continue;
            }
        case 7:
            {


                continue;
            }
        case 8:
            {
                closeFILE(f);
                return 0;
            }
        }
    }
    return 0;
}
