#include <stdio.h>
#include <stdlib.h>
#include "headers/file_inout.h"

int main()
{
    int record, i;
    participant *participants = NULL;

    FILE *f = initFILE();
  //  f = initFILE(f);

    {
        TEST_count_Record();
    }

    //char *s = (char*) malloc(N* sizeof(char));

  //  fscanf(f,"%s", s);

    record = recordsCount(f);
    participants = (participant*) malloc(record * sizeof(participant));

    scanFILE(f, record, participants);

    for (i=0; i<record; ++i)
        printf("%s %s\n", participants[i].name, participants[i].surname);

    closeFILE(f);

    return 0;
}
