/*

    scanFixationPointsApplication.cpp - application file for the program needed to assign unique identification numbers to visual attention scanpath fixation points.
   ================================================================================================================================================================

   This program is for course 04-630 Data Structures and Algorithms for Engineers, Assignment No. 1

   The assignment is defined as follows.

   When people view a scene, they fixate on specific points, transitioning from point to point
  with fast eye movements called saccades. The sequence of fixation points as people scan a
  scene is known as a scanpath pattern. Automatic eye trackers provide information
  on the scanpath, such as the coordinates of the fixation point and the time spent fixating at
  that point (known as dwell time). The same fixation point may be visited several times,
  depending on the attention strategy.
  The goal of this assignment is to design and implement an algorithm to process a list of
  fixations points, each one specified by its x and y coordinates, assign a unique identification
  number to each distinct point, and produce a list of fixations points with no duplicates (i.e.
  with the same coordinates). The identification numbers should be contiguous, beginning with
  1, and they should reflect the order in which the fixation point was encountered in the original
  list. The final list should appear in ascending order by identification number.





   Input data with test cases and the number of test cases is provided in an input file named input.txt.
   This input file is located in the data directory. Since this directory is a sibling directory of the bin directory
   where the dtogun .exe file resides, the filename used when opening the file is "../data/input.txt".

   Output for the test case is written to an output file "../data/output.txt"

   There are a maximum of ten scanpaths to be read.  If more than ten scanpaths are given, only the first ten are read.

   Input
   -----

   - The first line: A single digit representing the number of test cases (Scan paths)
   - Subsequent lines: N ses of fixation points, each comprised of the fixation number, and the x & y coordinates of the point.


   Output
   ------

   -  The first line simply displays my andrew ID.
   -  Subsequent lines show the deduplicated fixation points, each with its unique identification number.


   Sample Input
   ------------

   1
   1  4 5
   2  3 4
   3  -1  -1
   1  2 3
   2  -1  -1


   Sample Output
   -------------

   dtogun
   1  4 5
   2  3 4
   -------
   1  2 3


   Solution Strategy
   -----------------
  I implemented a simple algorithm, that first read the number of test cases; and used the number of test cases to loop through the  provided test cases in the input file.
  then it read the various scanpaths and their fixation points. These scanpaths were stored in my chosen data structure (an array of struct), which held the x and y coordinates for each scanpath.
  while ensuring no duplicates. My chosen data structure would have a much higher order of complexity than a more efficient one like a binary tree.


   Pseudocode
   -----------

  - Declare a struct with three variables (num, x, y)
  - Declare and initialize an array of struct, with size 1000
  - Declare and initialize variables for the number of test cases, counter and for i and j to be used in the loops.
  - Open the file for reading, if unable to open print an error message.
  - Read the number of test cases, and store it in the variable.
  - Print AndrewID to file,
  - If the number of test cases read is Outside the given range, give a warning message.
  - Using the number of test cases read in, loop through the file and read in each fixation point.
  - Assign the fixation point values (fixation point number and the x & y coordinates) to the struct declared
  - If the value of the struct is not present in the array, add it to the array. To eliminate duplicates.
  - Also checking if the x and y coordinates are in the given range.
  - Increment the counter after each fixation point is added to the array
  - If the x and y coordinates of any fixation point are -1, print a row of dashes and exit the loop.
  - Print the newly deduplicated values to the file, and use the incremented array index (k+1) to provide unique identification numbers.
  - Close the input file.
  - Close the output file.


   Test Strategy
   -------------

   The program has been tested with a variety of test data sets that reflect all valid conditions, including boundary conditions:

   - Scanpaths with more than two coordinates
   - Scanpaths with duplicate fixation point numbers
   - Scanpaths with non integer coordinate values
   - message with number of characters in the range 1-80
   - The number of test cases should be in the range (1<+N<=10)
   - Scanpaths have coordinates in the range (0<=x, y<=2000)



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

#include <jmorecfg.h>
#include "scanFixationPoints.h"
#include <stdbool.h>

int main() {

    //Declare a struct to hold fixation point values
    struct FixPoint{

        int num;
        int x;
        int y;

    };
    //Declare an array of struct
    struct FixPoint store [1000];
    int numberOfTestCases = 0;
    int i = 0;
    int j = 0;

    int count;
    int fixationNumber = 0, x = 0, y = 0;
    struct FixPoint currentPoint;

    int debug = TRUE;
    char message[MAX_MESSAGE_LENGTH];

    FILE *fp_in, *fp_out;
    //Check if input file and output files can be opened for reading and writing operations
    if ((fp_in = fopen("../data/input.txt","r")) == 0) {
        printf("Error can't open input input.txt\n");
        //prompt_and_exit(1);
    }

    if ((fp_out = fopen("../data/output.txt","w")) == 0) {
        printf("Error can't open output output.txt\n");
       // prompt_and_exit(1);
    }


    numberOfTestCases=0;
    //Read in the number of test cases from the first line
    fscanf(fp_in,"%d", &numberOfTestCases);
    printf("The number of test cases is: %d\n",numberOfTestCases);
    //Print my Andrew ID
    fprintf(fp_out,"dTogun\n",i);
    i = 0;
    int k=0;

    bool yes = false;
    //Check if the number of test cases is in the given range.
    if(numberOfTestCases < 0 || numberOfTestCases > 10){
        printf("The given Number of test cases is out of range\n");

    }
    for (i; i<numberOfTestCases; i++)
    {

        k = 0;
        count = 0;

        //Read in the values of each fixation point.
        fscanf(fp_in, "%d	%d	%d", &fixationNumber, &x, &y);
        //loop to handle storing each fixation point, and terminate when terminating value is met
        while((x!=-1 && y!=-1))
        {
            //add fixation point values to the struct
            currentPoint.num = (k+1);
            currentPoint.x = x;
            currentPoint.y = y;

            for (j=0;j<count;j++)
            {

                //Condition to check for duplicates
                if (store[j].x==x && store[j].y==y)
                {
                   yes = true;
                }
                    //Condition to check if the coordinates are in the stated range
                else if(x<=0 || y<=2000)
                {
                    yes = true;
                }
            }


            if(!yes)
            {
                //Store the fixation point values at that point in the array
                store[k] = currentPoint;
                k++;

            }

            yes = false;
            count++;

            {

            }

            fscanf(fp_in, "%d	%d	%d", &fixationNumber, &x, &y);

        }
        for (int l=0;l<(k);l++)
        {
            fprintf(fp_out,"%d	%d	%d\n",(store[l]));
        }
        //Print out a row of dashes when the terminating coordinates are met, indicating the end of a scanpath
        fprintf(fp_out,"-----------------\n");
    }

    if (debug) printf ("%s\n",message);
    //print_message_to_file(fp_out, message);

    //Close the files (input and output)
    fclose(fp_in);
    fclose(fp_out);

//    prompt_and_exit(0);
}