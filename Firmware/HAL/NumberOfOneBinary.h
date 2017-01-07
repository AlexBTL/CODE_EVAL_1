/* 
 * File:   NumberOfOneBinary.h
 * Author: abutel
 *
 * Created on January 03, 2016, 02:04 PM
 */

#ifndef NUMBEROFONEBINARY_H
#define	NUMBEROFONEBINARY_H

/**************************************************************/
/*                        DEFINE & TYPEDEF                    */
/**************************************************************/

#define NB_ARGUMENTS_WANTED 2
#define ALLOCATION_STEP 1
#define SIZE_BUFF_READ 2

typedef struct BufferInt_t
{
	int *pInt;
	int *pRead;
	int indice;
	bool notOnlyLetter;	
} bufferInt_s;

/**************************************************************/
/*                        PUBLIC FUNCTIONS                    */
/**************************************************************/

void DecToBin(FILE *fp);

/**************************************************************/
/*                        PRIVATE FUNCTIONS                   */
/**************************************************************/

#endif	/* NUMBEROFONEBINARY */
