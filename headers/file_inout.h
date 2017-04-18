#ifndef INOUT_H_INCLUDED
#define INOUT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "baseFunc.h"
#define N 256

/** \brief Initialize text file with existing/missing database
 *
 * \param mode 0 - was chosen operation "Create file"
 * \param mode 1 - was chosen operation "Open existing file"
 * \return Pointer to initialized file
 *
 */

FILE *initFILE(int mode);

/** \brief Calculate the count of records in opened text file
 *
 * \param file - pointer to file
 * \return count of records
 *
 */

int recordsCount(FILE *file);

/** \brief Read data from text file to program's editor of databases
 *
 * \param file - pointer to file
 * \param record - pointer to count of records in database
 * \param part - pointer to beginning of database
 *
 */

void scanFILE(FILE *file, participant *part, int *record);

/** \brief Print database to file and quicksave text file
 *
 * \param file - pointer to file
 * \param record - pointer to count of records
 * \param part - pointer to beginning of database
 *
 */

void printFILE(FILE *file, participant* part, int *record);

/** \brief Print database on console
 *
 * \param part - pointer to beginning of database
 * \param record - pointer to count of records
 *
 */

void printConsole(participant *part, int *record);

/** \brief Print record of database by unique identifier
 *
 * \param user - pointer to record to print
 *
 */

void printUser(participant *user);

/** \brief Check existence of text file in directory
 *
 * \param file - pointer to file
 * \param s - name of file (e.x base.in)
 * \return 0 - file doesn't exist
 * \return 1 - file exists
 *
 */

int check_ExistName(FILE *file, char *s);

/** \brief Close file and execute the last saving of database
 *
 * \param file - pointer to file
 *
 */

void closeFILE(FILE *file);

#endif // INOUT_H_INCLUDED
