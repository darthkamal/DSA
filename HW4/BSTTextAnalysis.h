/* 

BSTTextAnalysis.h - interface file for the program 
 ===================================================================================================================================================


  This program is for course 04-630 Data Structures and Algorithms for Engineers, Assignment No. 4

  Kindly refer to the application file - QueueingbehaviorApplication.cpp - for details of the functionality of this program


 File organization
   -----------------

 BSTTextAnalysis.h							interface file:
											contains the declarations required to use the functions that implement the solution to this problem
											typically, these will include the definitions of the abstract data types used in the implementation

 BSTTextAnalysisImplementation.cpp			implementation file:
											contains the definitions of the functions that implement the algorithms used in the implementation

 BSTTextAnalysisApplication.cpp				 application file:
											contains the code that instantiates the abstract data types and calls the associated functions
											in order to effect the required functionality for this application


   Author
   ------

   Daniel Togun
   16/03/2018


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
//#include <iostream>
#include <time.h>
#include <math.h>
#include "binaryTree.h"
//using namespace std;

//Global variables definations
#define TRUE 1
#define FALSE 0

//Functions prototype
void prompt_and_exit(int status);
bool isPunctuation(char c);
int height_of_the_tree(BINARY_TREE_TYPE tree);
int max(int x, int y);//
int inorder(BINARY_TREE_TYPE tree, int n, FILE *fp_out);
//Calculate the number of probes
int number_of_probes(BINARY_TREE_TYPE tree, int n);
//calculate the number of nodes in the tree
int number_of_nodes(BINARY_TREE_TYPE tree);
