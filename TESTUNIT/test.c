#include "../headers/file_inout.h"

void TEST_count_Record(void)
{
    FILE *test = fopen("TESTUNIT/test1.in", "r");
    int record = recordsCount(test);
    fclose(test);
    assert(record == 2);
}
