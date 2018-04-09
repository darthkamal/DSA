/*

	sortFixationPointsApplication.cpp - application file for the program needed to assign unique identification numbers to visual attention scanpath fixation points.
   ================================================================================================================================================================

This program is for course 04-630 Data Structures and Algorithms for Engineers, Assignment No. 2

The assignment is defined as follows.

 When people view a scene, they fixate on specific points, transitioning from point to point
 with fast eye movements called saccades. The sequence of fixation points as people scan a
 scene is known as a scanpath pattern. Automatic eye trackers provide information
 on the scanpath, such as the coordinates of the fixation point and the time spent fixating at
 that point (known as dwell time). The same fixation point may be visited several times,
 depending on the attention strategy.

 The goal of this assignment is to write a program to produce a sort a list of fixations points, each one specified by its fixation
point number and x and y coordinates. The list should be sorted by two keys: the x coordinate
and the y coordinate.

The sorted list should have all x coordinates in ascending order. If points have with the same x coordinate, the points should be listed so that y coordinates are in ascending order. Points
with the same x and y coordinates should be listed in the same order in which they appear in the input, i.e. in ascending order by fixation point number.


Input data with test cases and the number of test cases is provided in an input file named input.txt.
This input file is located in the data directory. Since this directory is a sibling directory of the bin directory
where the dtogun .exe file resides, the filename used when opening the file is "../data/input.txt".

Output for the test case is written to an output file "../data/output.txt"

There are a maximum of ten scanpaths to be read. If more than ten scanpaths are given, only the first ten are processed.

Input
------

 - The first line: A single digit representing the number of test cases (Scan paths)
 - Subsequent lines: N ses of fixation points, each comprised of the fixation number, and the x & y coordinates of the point.


Output
------

   -  The first line simply displays my andrew ID.
   -  Subsequent lines show the stably sorted fixation points, each with its fixation number.


 Sample Input
 ------------

 2
 1	382	353
 2	484	328
 3	695	241
 4	715	242
 5	695	241
 6	695	241
 7	710	245
 8	715	242
 9	695	241
 10	695	241
 11  696 545
 12  696 700
 13  696 432
 14  696 323
 15	696 323
 16	-1	-1


 Sample Output
 -------------

 dTogun
1 382	353
2 484	328
3 695	241
5 695	241
6 695	241
9 695	241
10 695	241
14 696	323
15 696	323
13 696	432
11 696	545
12 696	700
7 710	245
4 715	242
8 715	242
-----------------
1 0	0
5 0	0
2 1	1
4 1	1
3 2	2
6 4	4
-----------------


   Solution Strategy
   -----------------
  I implemented a simple solution, that first read the number of test cases, and used the number of test cases to loop through the provided test cases in the input file.
  then it read the various scanpaths and their fixation points. These scanpaths were stored in my chosen data structure (an array of struct), which held the x and y coordinates for each scanpath
  as well as its fixation point number. I chose and implemented an insertion sort, a simple sorting algortihm that builds the final sorted array one item at a time and I passed my array of fixation points to it. 
  And it stably sorted the array. Then I printed the sorted scanpaths to the output file.

  I picked the insertion sort because.
  -----------------------------------
  -It had a simple implementation.
  -It is efficient for smaller data sets.
  -It is a stable sort, as it does not change the relative order of elements with equal keys, compared to a selection sort which I implemented initially in my application.
  -It is adaptive, that means it reduces its total number of steps if given a partially sorted list, hence it increases its efficiency.
  -It is online, as it can sort a list in real time as it receives elements.
  -Its space complexity is less. Like Bubble Sorting, insertion sort also requires a single additional memory space.


  Algorithm (for sorting)
  -------------------------------------------------------------------
  Step 1 − If it is the first element, it is already sorted. return 1;
  Step 2 − Pick next element
  Step 3 − Compare with all elements in the sorted sub-list
  Step 4 − Shift all the elements in the sorted sub-list that is greater than the
  value to be sorted
  Step 5 − Insert the value
  Step 6 − Repeat until list is sorted
  Step 7 - End

  Pseudocode (for sorting)
  ------------------------

  //for an Array arr
  InsertionSort(arr)
  for i = 2 to n
	j = i
	while j > 1
		if A[j] < A[j - 1]
			swap A[j] and A[j - 1]
		  j = j - 1

   Pseudocode
   -----------

	READ numberOfTestCases;
	FOR counter = 0 to numberOfTestCases
		READ FixationPoint values on each line of input file
			While (x is not equal to -1 and y is not equal to -1)
				ADD the fixation point values to the struct
				STORE the current fixation point read in array of Fixpoint.
			Print out a row of dashes when the terminating coordinates are met, indicating the end of a scanpath
		CALL the sort function to sort Y
		CALL the sort functon to sort X
		FOR each index of the array
			WRITE the contents to the output file
	CLOSE the output file
	
  Complexity Analysis of my sort algorithm (insertion Sort)
  ---------------------------------------------------------

  Worst Case Time Complexity : O(n2) [The maximum number of comparisons for an insertion sort is the sum of the first n−1 integers,
  each element is compared with all the other elements in the sorted array. For N  elements, there will be N2 comparisons.
  Therefore, the time complexity is O(N2)]

  Its space complexity is significantly less. Like Bubble Sorting, insertion sort also requires a single additional memory space.

  It is a good example of the time-space tradeoff(No free lunch)


   Test Strategy
   -------------

   The program has been tested with a variety of test data sets that reflect all valid conditions, including boundary conditions:
   - Scanpaths with no test cases
   - Scanpaths with identical coordinates to test stability of sort
   - Scanpaths with duplicate fixation point numbers
   - Scanpaths with 
   - Scanpaths with x & y coordinates of -1
   - The number of test cases should be in the range (1<+N<=10)
   - Scanpaths have coordinates in the range (0<=x, y<=2000)


   File organization
   -----------------

   sortFixationPoints.h						interface file:
											contains the declarations required to use the functions that implement the solution to this problem
											typically, these will include the definitions of the abstract data types used in the implementation

   sortFixationPointsImplementation.cpp		implementation file:
											contains the definitions of the functions that implement the algorithms used in the implementation

   sortFixationPointsApplication.cpp		application file:
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

int main() {

	//Declare a struct to hold fixation point values
	/*struct FixPoint{

		int num;
		int x;
		int y;

	}*/

	//Declare an array of struct
	FixPoint store[1000];
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
	if ((fp_in = fopen("../data/input.txt", "r")) == 0) {
		printf("Error can't open input input.txt\n");
		prompt_and_exit(1);
	}

	if ((fp_out = fopen("../data/output.txt", "w")) == 0) {
		printf("Error can't open output output.txt\n");
		prompt_and_exit(1);
	}


	numberOfTestCases = 0;
	//Read in the number of test cases from the first line
	fscanf(fp_in, "%d", &numberOfTestCases);
	printf("The number of test cases is: %d\n", numberOfTestCases);
	//Print my Andrew ID
	fprintf(fp_out, "dTogun\n", i);
	i = 0;
	int k = 0;
	bool yes = false;
	//Check if the number of test cases is in the given range.
	if (numberOfTestCases < 0 || numberOfTestCases > 10) {
		printf("The given Number of test cases is out of range\n");
	}
	for (i; i < numberOfTestCases; i++)
	{

		k = 0;
		count = 0;

		//Read in the values of each fixation point.
		fscanf(fp_in, "%d	%d	%d", &fixationNumber, &x, &y);
		//loop to handle storing each fixation point, and terminate when terminating value is met
		while ((x != -1 && y != -1))
		{
			//add fixation point values to the struct
			currentPoint.num = fixationNumber;
			currentPoint.x = x;
			currentPoint.y = y;

			//Store the fixation point values at that point in the array
			store[k] = currentPoint;
			//printf("k ==> %d \n", store[k].num);
			k++;
			//Calling the sort function to sort the array, Y is sorted in the first call.
			insertionSort(store, k, 2);
			//X is sorted in the second call
			insertionSort(store, k, 1);

			count++;

			fscanf(fp_in, "%d	%d	%d", &fixationNumber, &x, &y);

		}
		for (int l = 0; l < (k); l++)
		{
			//Printing output to file
			fprintf(fp_out, "%d %d	%d\n", store[l].num, store[l].x, store[l].y);
		}
		//Print out a row of dashes when the terminating coordinates are met, indicating the end of a scanpath
		fprintf(fp_out, "-----------------\n");
	}

	if (debug) printf("%s\n", message);
	//print_message_to_file(fp_out, message);

   //Close the files (input and output)
	fclose(fp_in);
	fclose(fp_out);

	prompt_and_exit(0);
}
