#ifndef INOUT_H_INCLUDED
#define INOUT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "baseFunc.h"
#define N 256

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

FILE *initFILE(int mode);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int recordsCount(FILE *file);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void scanFILE(FILE *file, int record, participant *particip);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void printFILE(FILE *file, int record, participant* particip);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void printUser(participant *user, int ident);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void closeFILE(FILE *file);

#endif // INOUT_H_INCLUDED
