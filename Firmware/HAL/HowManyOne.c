/* 
 * File:   HowManyOne.c
 * Author: abutel
 *
 * Created on January 03, 2016, 11:27 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "HowManyOne.h"

/**************************************************************/
/*                         PUBLIC DATA                        */
/**************************************************************/

/**************************************************************/
/*                         PRIVATE DATA                       */
/**************************************************************/

static int OldNumberRead;       // Hold the number of each line
static char NewCharacterRead;   // Hold the char read each time
static int NumberOfOne;         // Hold the number of one on the binary number of each line

/**************************************************************/
/*                         PRIVATE FUNCTIONS                  */
/**************************************************************/

/**************************************************************/
/*                         PUBLIC FUNCTIONS                   */
/**************************************************************/

void Reset(void)
{
	OldNumberRead = 0;
	NewCharacterRead = '0';
	NumberOfOne = 0;
}


bool EmptyLine(void)
{
   if(NewCharacterRead == '\n')       // If we are at the end of the line
   {
      return true;
   }
   else
   {
      return false;
   }
}


void CountOne(void)
{
   while(OldNumberRead != 0)     
   {
      if(OldNumberRead%2 == 1)   // Easy way to know how many one there is on the binary number => mod2 = 1 => There is a 1 / mod2 = 0 => There is a 0
      {
         NumberOfOne++;
      }
      OldNumberRead = OldNumberRead/2;
   }
}


void AddNumber(void)
{
   OldNumberRead = OldNumberRead*10 + (NewCharacterRead-'0');  // Convert the char to an int and add it
}


void HowManyOne(FILE *fp)
{ 
   Reset();   
   while(!feof(fp))
   {
      NewCharacterRead= fgetc(fp);   // Get the char
      if(EmptyLine()==true)
      {
      	CountOne();
      	printf("%d\n", NumberOfOne);
      	Reset();
      }
      else
      {
      	AddNumber();
      }
   }
}


