#ifndef BASEFUNC_H_INCLUDED
#define BASEFUNC_H_INCLUDED
#include <string.h>
#include <assert.h>

typedef struct {
    char *name,
         *surname;
    int place;
    double average;
} participant;

/** \brief Create *n* new records  to database in position *pos*
 *
 * \param part - pointer to beginning of database
 * \param record - to count of records
 * \param n - number of new records to add
 * \param pos - position where insert will execute
 * \return pointer to new/old beginning of database
 *
 */

participant *addRecord(participant *part, int *record, int *n);

/** \brief Delete *n* records from *pos* position from database
 *
 * \param part - pointer to beginning of database
 * \param pos - position from where deleting start
 * \param n - number of records to delete from position *pos*
 * \param record - count of records in database
 * \return pointer to new/old beginning of database
 *
 */

participant *delRecord(participant *part, int *pos, int *n, int *record);

/** \brief Edit field in record by unique identifier
 *
 * \param part - pointer to beginning of database
 *
 */

void editRecord(participant *part);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int sortBase(participant *part, int *column, int *direction, int *record);


#endif // BASEFUNC_H_INCLUDED

