/* 
 * File:   Conversion.c
 * Author: abutel
 *
 * Created on January 03, 2016, 02:04 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "NumberOfOneBinary.h"
#include "Conversion.h"
#include "Memory.h"

/**************************************************************/
/*                         PUBLIC DATA                        */
/**************************************************************/
/**************************************************************/
/*                         PRIVATE DATA                       */
/**************************************************************/
/**************************************************************/
/*                         PRIVATE FUNCTIONS                  */
/**************************************************************/

static int *RenewBuffer(int *buffer)
{
   free(buffer);
   buffer = (int*)calloc(ALLOCATION_STEP, sizeof(int));
   MemoryCheck(buffer);

   return (buffer);
}

static int TestEqualZero(int *buffer, int indice)
{
   if(buffer[indice] == 0)
   {                                                                     
      indice++;
   }
   return (indice); 
}

static int FunctionDivByTwo(int indice, int size, int* buffer)
{
   int temp;                                                  // Hold the temporary value allowing to use the conversion method
   int carry;
   
   temp = 0;
   carry = 0;

   while(indice <= size)                                        // indice        = 1  / 2  / 3               2  / 3         2  / 3        2  / 3            3       3      3        3                  
   { 
      temp = (10 * carry + buffer[indice]);                     // temp         <= 1  / 13 / 14              6  / 7         3 / 13        1  / 16           8       4      2        1
      buffer[indice] = temp / 2;                                // bufferInt[]  <= 0  / 6  / 7               3  / 3         1  / 6        0  / 8            4       2      1        0
      carry = temp % 2;                                         // carry        <= 1  / 1  / (0)             0  / (1)       1  / (1)      1  / (0)         (0)     (0)    (0)      (1)
      indice++;                                                 // indice       <= 2  / 3  / 4               3  / 4         3  / 4        3  / 4            4       4      4        4
   }
   return (carry);    
}

static int CountOne(int carry, int nbOfOne)
{
   if(carry == 1)
   {
      nbOfOne++;
   }
   return (nbOfOne);
}   

/**************************************************************/
/*                         PUBLIC FUNCTIONS                   */
/**************************************************************/

int* HowManyOne(int *buffer,int size)               
{   
   int firstIndice;                                                // Put an offset if we loose un digit between the number and the result of his division by two
   int carry;
   int nbOfOne;                                                      
   
   firstIndice = 1;                                               // Use when you loose a digit during the division to read next time one indice after the begining
   carry = 0;
   nbOfOne = 0;

   while(firstIndice <= size)                                                            // Exemple : number 134 (1000 0110)=> size 3  bufferInt = [1,3,4]                            
   {  
      carry = FunctionDivByTwo(firstIndice, size, buffer);
      firstIndice = TestEqualZero(buffer, firstIndice);
      nbOfOne = CountOne(carry, nbOfOne);                                                                                     
   }
   printf("%d\n", nbOfOne);
   return (RenewBuffer(buffer));
}
