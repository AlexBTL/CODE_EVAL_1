/* 
 * File:   Main.c
 * Author: abutel
 *
 * Created on January 03, 2016, 11:27 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "HowManyOne.h"

/**************************************************************/
/*                         PUBLIC DATA                        */
/**************************************************************/



/**************************************************************/
/*                         PRIVATE DATA                       */
/**************************************************************/

/**************************************************************/
/*                         PRIVATE FUNCTIONS                  */
/**************************************************************/

/**************************************************************/
/*                         PUBLIC FUNCTIONS                   */
/**************************************************************/
int main(int argc, char* argv [])
{
	FILE *fp;
	if(argc==2)
	{
		if((fp = fopen(argv[1],"r"))==NULL)
		{
			printf("Error 00 : This file doesn't exist"); 
		}
		else
		{
			HowManyOne(fp);
			fclose(fp);
		}		                      
	}
	if(argc>2)
	{
		printf("Error 01 : Too much arguments"); 
	}
	if(argc<2)
	{
		printf("Error 02 : Not enough arguments"); 
	}                                              
    
	return(0);
}