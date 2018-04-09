/* 

RobotPathPlanning.h	 - interface file for the program
 ===================================================================================================================================================


  This program is for course 04-630 Data Structures and Algorithms for Engineers, Assignment No. 5

  Kindly refer to the application file- RobotPathApplication.cpp - for details of the functionality of this program


 File organization
 -----------------

 RobotPathPlanning.h						interface file:
											contains the declarations required to use the functions that implement the solution to this problem
											typically, these will include the definitions of the abstract data types used in the implementation

RobotPathPlanningImplementation.cpp			implementation file:
											contains the definitions of the functions that implement the algorithms used in the implementation

 RobotPathPlanningApplication.cpp			application file:
											contains the code that instantiates the abstract data types and calls the associated functions
											order to effect the required functionality for this application


 Author
 ------

 Daniel Togun
 1/04/2018


 Andrew ID
 dTogun


 Audit Trail
 -----------

 */
                                                 
 /*Includes necessary libraries for the program*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <ctype.h>
#include "graph.h"

#define KEY_LENGTH 100
#define STRING_LENGTH 100

//Global variables definations
#define TRUE 1
#define FALSE 0
#define MAX_R 100
#define MAX_C 100


//Functions prototype
void TwoDArrayInitialization(int x, int y, int value, int arr[MAX_R][MAX_C], FILE *file);
int mappingFunction(int i, int j, int numColumns);
void printChar(int numRows, int numColumns, int mapArr[MAX_R][MAX_C], FILE *file);

int getOriginPoint(int k, int l, int mapArr[MAX_R][MAX_C]);
int getEndPoint(int k, int l, int mapArr[MAX_R][MAX_C]);
void convertVertexToCell(int nm, int array[MAX_R][MAX_C], int vertex);