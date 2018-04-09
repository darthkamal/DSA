/*

 sortFixationPoints.h - interface file for the program needed to stably sort visual attention scanpath fixation points.
 ===================================================================================================================================================


  This program is for course 04-630 Data Structures and Algorithms for Engineers, Assignment No. 2

  Kindly refer to the application file - sortFixationPointsApplication.cpp - for details of the functionality of this program


 File organization
   -----------------

  sortFixationPoints.h						interface file:
											contains the declarations required to use the functions that implement the solution to this problem
											typically, these will include the definitions of the abstract data types used in the implementation

  sortFixationPointsImplementation.cpp		implementation file:
											contains the definitions of the functions that implement the algorithms used in the implementation

  sortFixationPointsApplication.cpp		    application file:
											contains the code that instantiates the abstract data types and calls the associated functions
											in order to effect the required functionality for this application


   Author
   ------

   Daniel Togun
   15/02/2018


   Andrew ID
   dTogun


   Audit Trail
   -----------

   - Added prompt_and_exit() to allow users to read the terminal messages before it is closed.  David Vernon, 29/12/2016.

*/


#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <ctype.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define MAX_MESSAGE_LENGTH 81

/* function prototypes go here */

struct FixPoint {

	int num;
	int x;
	int y;

};

void prompt_and_exit(int status);
void print_message_to_file(FILE *fp, char message[]);
void insertionSort(FixPoint arr[], int n, int Desc);
