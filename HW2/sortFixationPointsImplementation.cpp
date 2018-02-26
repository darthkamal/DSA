/*

   sortFixationPointsImplementation.cpp - implementation file for the program needed to stably sort visual attention scanpath fixation points.
   ======================================================================================================================================================================

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

#include "sortFixationPoints.h"

void prompt_and_exit(int status) {
	printf("Press any key to continue and close terminal\n");
	getchar();
	exit(status);
}

void print_message_to_file(FILE *fp, char message[]) {

	fprintf(fp, "The message is: %s\n", message);
}

void insertionSort(FixPoint arr[], int n, int XorY)
{
	int i, j;
	//Temporary structure to hold fixation point data while sorting
	struct FixPoint temp;
	for (i = 1; i < n; i++) {
		j = i;

		if (XorY == 1) {

			while ((j > 0) && (arr[j].x < arr[j - 1].x)) {
				temp = arr[j - 1]; // swap
				arr[j - 1] = arr[j];
				arr[j] = temp;
				j = j - 1;
			}
		}

		if (XorY == 2) {

			while ((j > 0) && (arr[j].y < arr[j - 1].y)) {
				temp = arr[j - 1]; // swap
				arr[j - 1] = arr[j];
				arr[j] = temp;
				j = j - 1;
			}
		}
	}
}