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

participant *addRecord(participant *part, int *record, int n);

/** \brief Delete *n* records from *pos* position from database
 *
 * \param part - pointer to beginning of database
 * \param pos - position from where deleting start
 * \param n - number of records to delete from position *pos*
 * \param record - count of records in database
 * \return pointer to new/old beginning of database
 *
 */

participant *delRecord(participant *part, int pos, int n, int *record);

/** \brief Edit field in record by unique identifier
 *
 * \param part - pointer to beginning of database
 *
 */

void editRecord(participant *part);

/** \brief Sorts database by any of field in increasing or decreasing line
 *
 * \param part - pointer to beginning of database
 * \param column - selected column to sort by it
 * \param direction - increasing || decreasing sorting
 * \param record - count of records in database
 * \return 1 - sort is successful 0 - isn't successful (records == 0)
 *
 */

int sortBase(participant *part, int column, int direction, int *record);

/** \brief gives the memory to something new which needs memory to exist
 *
 * \param part - pointer to pointer to beginning of database
 * \param record - count of records in database
 *
 */

void m_mloc(participant **part, int record);

/** \brief reallocate memory
 *
 * \param part - pointer to pointer to beginning of database
 * \param record - count of records in database
 *
 */

void m_rloc(participant **part, int record);

#endif // BASEFUNC_H_INCLUDED

