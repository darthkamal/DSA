/* 

   scanFixationPoints.h - interface file for the program needed to assign unique identification numbers to visual attention scanpath fixation points.
 ===================================================================================================================================================

  
  This program is for course 04-630 Data Structures and Algorithms for Engineers, Assignment No. 1

  Kindly refer to the application file - scanFixationPointsApplication.cpp - for details of the functionality of this program


  File organization
  -----------------

 scanFixationPoints.h						            interface file:      
											                      contains the declarations required to use the functions that implement the solution to this problem
											                      typically, these will include the definitions of the abstract data types used in the implementation

 scanFixationPointsImplementation.cpp	    	implementation file: 
											                      contains the definitions of the functions that implement the algorithms used in the implementation
 
 scanFixationPointsApplication.cpp   	    	application file:    
										                        contains the code that instantiates the abstract data types and calls the associated functions
											                      in order to effect the required functionality for this application


   Author
   ------

   Daniel Togun
   03/02/2018


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

#define TRUE 1
//#define FALSE 0
#define MAX_MESSAGE_LENGTH 81

/* function prototypes go here */

void prompt_and_exit(int status);
//void print_message_to_file(FILE *fp, char message[]);
