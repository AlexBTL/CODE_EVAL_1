/* 
 * File:   How_Many_One.h
 * Author: abutel
 *
 * Created on January 03, 2016, 11:27 AM
 */

#ifndef HOWMANYONE_H
#define	HOWMANYONE_H

#include <stdio.h>
#include <stdlib.h>

/**************************************************************/
/*                        DEFINE & TYPEDEF                    */
/**************************************************************/

/**************************************************************/
/*                        PUBLIC FUNCTIONS                    */
/**************************************************************/
void Reset(void);
void HowManyOne(FILE *fp);
bool EmptyLine(void);
void CountOne(void);
void AddNumber(void);

/**************************************************************/
/*                        PRIVATE FUNCTIONS                   */
/**************************************************************/


#endif	/* HOWMANYONE_H */
