#include <stdio.h>
#include <stdlib.h>
#include "headers/baseFunc.h"
#include "headers/file_inout.h"

int main()
{
    int record, i;
    participant *participants = NULL;
    FILE *f = initFILE();

    {
        TEST_count_Record();
    }

    record = recordsCount(f);
    participants = (participant*) malloc(record * sizeof(participant));

    scanFILE(f, record, participants);


    printFILE(f, record, participants);
    closeFILE(f);

    return 0;
}
