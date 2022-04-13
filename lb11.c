/*****+-**--------*--*-*-**---*---*--***-*-**-******************************
*
*  Lab #: 11
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Program Description:
*
******+-**--------*--*-*-**---*---*--***-*-**-*****************************/

/*****+--**---*-*----*-****----------*-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: 
*
*  Function Return Type: 
*
*  Parameters (list data type, name, and comment one per line):
*  1.
*  2. 
*  3. 
*
*  Function Description: 
*
******+--**---*-*----*-****----------*-*-*-**-*****************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define ARRAY_SIZE 100

void getSeed();
int getMax();
int isPerfectSquare(int);
int findIdentifiedVal(int);
void fillArray(int, int[]);
void findPerfectSquares(int[]);
void bubbleSort(int x[]);

int main(void)
{
  int data[ARRAY_SIZE];
  int range;
  
  getSeed();
  range = getMax();
  fillArray(range, data);
  bubbleSort(data);
  findPerfectSquares(data);

  
  return 0;
}

/*****+--**---*-*----*-****----------*-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: getSeed()
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line): NONE

*  Function Description: Gets the seed input from the user that will be used 
*  to calculate random values. Also gets the maximum value allowed in the random
*  numbers
*
******+--**---*-*----*-****----------*-*-*-**-*****************************/

void getSeed()
{
  int seed; // stores the seed value from the user
  
  do
  {
    printf("Enter seed value -> ");
    scanf("%d", &seed);  

    if (seed <= 0)
    {
      printf("Error! Positive seed values only!!\n");
    }
  } while (seed <= 0);
  srand(seed);

}

/*****+--**---*-*----*-****----------*-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: getMax()
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line): NONE
*
*  Function Description:  Gets the maximum value allowed in the random
*  numbers and returns it
*
******+--**---*-*----*-****----------*-*-*-**-*****************************/

int getMax()
{
  int max; // user inputed maximum random value
  
  do
  {
    printf("Enter maximum range value -> ");
    scanf("%d", &max);

    if (max <= 0)
    {
      printf("Error! Positive range values only!!\n");
    }
  } while (max <= 0);

  return (max);
}

/*****+--**---*-*----*-****----------*-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: fillArray()
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*  1. int range // 
*  2. 
*  3. 
*
*  Function Description: 
*
******+--**---*-*----*-****----------*-*-*-**-*****************************/

void fillArray(int range, int array[])
{
  int x;
  
  for(x = 0; x < ARRAY_SIZE; x++)
  {
    array[x] = rand() % range + 1;
  }
}

void findPerfectSquares(int array[])
{
  int x;
  int count_prints;

  count_prints = 0;

  printf("\n");

  for(x = 0; x < ARRAY_SIZE; x++)
  {
    if(isPerfectSquare(array[x] != 0))
    {
      printf("Perfect squares: ");
    }
    break;
  }

  for(x = 0; x < ARRAY_SIZE; x++)
  {
    if(findIdentifiedVal(array[x]) != 0)
    {
      if(findIdentifiedVal(array[x]) == isPerfectSquare(array[x]))
      {
        ++count_prints;
        printf("%d ", findIdentifiedVal(array[x]));
      }
    }
  } 
  printf("\n");
  

  for(x = 0; x < ARRAY_SIZE; x++)
  {
     if((findIdentifiedVal(array[x]) != 0) && (findIdentifiedVal(array[x]) != isPerfectSquare(array[x])))
     {
        printf("Semi-squares: ");
     }
    break;
  }
  
  for(x = 0; x < ARRAY_SIZE; x++)
  {
    if(findIdentifiedVal(array[x]) != 0)
    {
      if(findIdentifiedVal(array[x]) != isPerfectSquare(array[x]))
      {
        ++count_prints;
        printf("%d ", findIdentifiedVal(array[x]));
      }
    }
  } 

  if (count_prints == 0)
  {
    printf("Result: No perfect or semi-squares found.");
  }
  
  printf("\n");
}

void bubbleSort(int x[])
{
  int numPasses; //LCV that controls number of passes
  int lcv; // loop control variable for sorting
  int temp; //holds value during swap

  for(numPasses = 1; numPasses < ARRAY_SIZE; numPasses++)
  {
    for(lcv = 0; lcv < ARRAY_SIZE; lcv++)
    {
      if(x[lcv] > x[lcv + 1])
      {
        temp = x[lcv];
        x[lcv] = x[lcv + 1];
        x[lcv + 1] = temp;
      } // end of if statement
    } // end neighbor comparing loop
  } //end passes loop
}


/*****+-**------*---**-*-**---*-*-*--*-*****--******************************
*
*  Function Information
*
*  Name of Function: isPerfectSquare
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*  1. int, number, is the calculated square or semisquare
*
*  Function Description: Calculates if the inputed number is a perfect square
*  or not. If the value is a perfect sqaure returns 1, otherwise returns 0. 
*
******+-**------*---**-*-**---*-*-*--*-*****--*****************************/
int isPerfectSquare(int number)
{
  int currentSquare; // current square value being checked against
  int index; // index for the for loop
  int squareValue; // if the number is a perfect square, is the value of the square root of number.

  squareValue = 0; // sets the initial returned value to 0 in case it's not a perfect square 
  for(index = ((int) sqrt(number) - 1); index < ((int) sqrt(number)) + 1; index++) // go one past the number to see if the number is the highest square root
  { 
    currentSquare = pow(index, 2);
    if(number == currentSquare) // if the number is equal to a calculated perfect square between 1 and the number, return 1 to signal that it is a perfect square
    {
      squareValue = number;
    }
  }

  if(number == 1)
  {
    squareValue = number;
  }
  
  return squareValue;
}

/*****+-**------*---**-*-**---*-*-*--*-*****--******************************
*
*  Function Information
*
*  Name of Function: findIndentifiedVal
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*  1. int, b, is the user inputed starting value
*
*  Function Description: Finds the lowest square or semisquare value that is
*  equal to or greater than the user inputed value. It does this by seeing if
*  a value that is less than the square root of the user inputed value is equal
*  to b. If it is not it checks if that value multiplied by an intiger that is
*  than the squared value would equal b. If both options do not work it raises
*  b by one and checks that number. 
*
******+-**------*---**-*-**---*-*-*--*-*****--*****************************/
int findIdentifiedVal(int b)
{
  int a; // the 'a' value in the equation
  int c; // the 'c' value in the equation
  int returnValue;
  
  returnValue = 0;
  
  for(a = 1; a <= ceil(sqrt(b)); a++)
  {
    for(c = 1; c < a; c++)
    {
      if (b == pow(a, 2) * c)
      {
        returnValue = b;
      }
    }
  }
   
  return returnValue;
}

