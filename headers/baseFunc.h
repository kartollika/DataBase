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

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

participant *addRecord(participant *part, int *record, int n);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int delRecord(participant *part, int pos, int n);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int sortBase(participant *part, int column, int direction);


#endif // BASEFUNC_H_INCLUDED

