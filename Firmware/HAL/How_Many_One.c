/* 
 * File:   How_Many_One.c
 * Author: abutel
 *
 * Created on January 03, 2016, 11:27 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "./How_Many_One.h"

/**************************************************************/
/*                         PUBLIC DATA                        */
/**************************************************************/


/**************************************************************/
/*                         PRIVATE DATA                       */
/**************************************************************/
static int Old_Number_Read;       // Hold the number of each line
static char New_Character_Read;   // Hold the char read each time
static int Number_Of_One;         // Hold the number of one on the binary number of each line

/**************************************************************/
/*                         PRIVATE FUNCTIONS                  */
/**************************************************************/
/**************************************************************/
/*                         PUBLIC FUNCTIONS                   */
/**************************************************************/

void Reset(void)
{
	Old_Number_Read=0;
	New_Character_Read='0';
	Number_Of_One=0;
}


void How_Many_One(const char* file)
{ 
   FILE *fp;                
   Reset();                                 
   fp = fopen(file,"r");               // "r" => open a file for reading. The file must exist //FILE *fopen(const char *filename, const char *mode)
   while(1)
   {
      New_Character_Read= fgetc(fp);   // Get the char
      if( feof(fp) )
      { 
         break ;
      }
      if(New_Character_Read =='\n')       // If we are at the end of the line
      {
      	while(Old_Number_Read != 0)     
      	{
      		if(Old_Number_Read%2 == 1)   // Easy way to know how many one there is on the binary number => mod2 = 1 => There is a 1 / mod2 = 0 => There is a 0
      		{
      			Number_Of_One++;
      		}
      		Old_Number_Read = Old_Number_Read/2;
      	}
      	printf("%d\n", Number_Of_One);
      	Reset();
      }
      else
      {
      	Old_Number_Read = Old_Number_Read * 10 + (New_Character_Read-'0');  // Convert the char to an int and add it
      }
   }
   fclose(fp);
}


