/*
Application file for the program
 ===================================================================================================================================================
 
 This program is for course 04-630 Data Structures and Algorithms for Engineers, Assignment No. 5
  
This program determines the shortest path between a robot’s initial position and a goal position using a grid-based map of the robot’s environment.

The map is comprised of a two-dimensional array of numbers, with each number representing the occupancy of a cell in the grid.

 0  indicates that the cell is empty and the robot can occupy that cell when navigating to its goal. 
 1  indicates that there is an obstacle in that cell and the robot cannot move into that cell when navigating to its goal.
 2  indicates the initial position of the robot. 
 3  indicates the goal position of the robot.

 The size of the map can vary.
 Its dimensions are n and m, 1 <= n <= 100  and 1 <= m <= 100, where n is the number of rows in the map and m is the number of columns.

 The origin of the map is given by cell coordinates (0, 0). This is the cell at the top left of the map.

 The robot’s initial position and its goal position are given in cell coordinates.
 The path the robot should take is to be indicated by printing a ‘*’ character in each map cell on the path.

 If no path can be found, a message should be printed saying that no path exists from the robot’s initial position to its goal position, stating the coordinates of both positions in the message.

 The robot can only move forwards, backwards, and sideways, i.e. it can only move from cell (i, j) to cells (i, j-1), (i, j+1), (i-1, j), or (i+1, j).

 The path the robot should take is to be shown on an output map where:    - An empty cell is depicted by a space ' ' character    - An obstacle is depicted by '#' character    - The start position of the robot is depicted by a '@' character      - The destination position of the robot is depicted by a '$' character      - The path cells are depicted by a '*' character     In order to render the graph with the correct aspect ratio (width divided by height), each cell character (' ', '#', '@', '$', '*') should be followed by a space ' '.


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
 

Sample Input
-----------

2 
4 4
2 0 0 0 
0 1 1 0  
0 0 0 0 
0 0 0 3 
10 10
0 0 0 0 0 0 0 0 0 0 
0 2 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 
0 0 0 1 1 1 1 1 1 0 
0 0 0 1 1 1 1 0 0 0 
0 0 0 1 1 1 1 0 0 0 
0 0 0 0 0 1 1 0 0 0
0 1 1 1 0 0 0 0 0 0 
0 1 1 1 0 0 0 0 3 0 
0 0 0 0 0 0 0 0 0 0

Sample Output
-------------

dtogun 
Scenario 1
@       
* # #   
*       
* * * $

Scenario 2 
 @                    
 *                   
 *   # # # # # #      
 *   # # # #         
 *   # # # #         
 * * * * # #          
 # # # *             
 # # # * * * * $
 

 Algorithmic Analysis
 ---------------------

 The time complexity of BFS is O(V + E), where V is the number of nodes and E is the number of edges.


Solution Strategy
------------------

The program reads the input file, extracting the needed parameters. From the number of scenarios to be manipulated, to the map itself.

The map read is stored in an initialized 2D array of Integers.

The program uses the number of scenarios read in to loop through all scenarios, treating each in order and printing the final results to an output file.

A graph is created to represent the map, each cell in the map will have a single vertex. While each vertex could have up to four edges joining the current vertex to the cells connected to it. The program checks that unocupied cells can only be connected to unocupied cells
The program has a mapping function which maps cell coordinates to vertex numbers.

The program uses the row-major-order mapping.

The program does a breadth-first search on the graph, and it uses a find path function to mark the path vertices on the map.

 Test Strategy
 --------------

  The program has been tested with a variety of test data sets that reflect all valid conditions, including boundary conditions: Multiple scenarios were added to the input file
   - Testing for empty test cases
   - Testing for test cases with no start point
   - Testing for test cases with no end point
   - Testing for test cases with no obstacles
   - Testing for test cases with only obstacles
   - Testing with the sample data sets provided by the instructor, serving as a good guide to overall correctness of solution
   - Testing with test cases where numberOfRows != numberOfColumns
   - Testing with test cases where the start and end points are succesive
   - Testing with large data sets to ensure program scales
   
*/

#include "RobotPathPlanning.h"

int main() {
	char studentID[7] = "dTogun";
	int debug = TRUE;
	typedef char keyword[KEY_LENGTH];
	char input_string[STRING_LENGTH];
	int numColumns = 0; //Number of columns
	int numRows = 0; //Number of Rows
	int value = 0;
	int numScenarios;
	int scenarioCounter = 1;
	/*int right, left;
	int up, down;*/
	graph g;
	int mapArr[MAX_R][MAX_C];
	FILE *fp_in, *fp_out, *fname;

	fp_in = fopen("../data/input.txt", "r");
	fp_out = fopen("../data/output.txt", "w");

	//Function to check if the files can be opened
	if (fp_in == 0) {
		printf("Error can't open input input.txt\n");
		//prompt_and_exit(1);
	}
	if (fp_out == 0) {
		printf("Error can't open output output.txt\n");
		//prompt_and_exit(1);
	}

	fprintf(fp_out, "%s\n", studentID);

	/*fgets(input_string, STRING_LENGTH, fp_in);
	sscanf(input_string, "%d", &value);
	numScenarios = value;*/

	fscanf(fp_in, "%d", &numScenarios);
	//printf("Number of test cases %d\n", numScenarios);

	int num = 0;
	for (int i = 0; i < numScenarios; i++)
	{
		int xi, xj, yi, yj;

		fprintf(fp_out, "Scenario %d\n", scenarioCounter);
		initialize_graph(&g, false);

		fscanf(fp_in, "%d %d", &numRows, &numColumns);

		for (int i = 0; i < numRows; i++) {

			for (int j = 0; j < numColumns; j++) {

				fscanf(fp_in, "%d", &num);
				mapArr[i][j] = num;
				if (num == 2)
				{
					xi = i;
					xj = j;


				}

				if ((num) == 3) {

					yi = i;
					yj = j;

				}


				printf("%d", mapArr[i][j]);

			}
			//printf("\n");
		}
		//printf("\n");

		for (int i = 0; i < numRows; i++) {

			for (int j = 0; j < numColumns; j++) {
				int x = mappingFunction(i, j, numColumns);

				printf("%d", x);
			}
			//printf("\n");
		}


		int sizeOfMap = numRows * numColumns;
		g.nvertices = sizeOfMap;

		for (int m = 0; m < numRows; m++)
		{
			for (int n = 0; n < numColumns; n++)
			{
				
				if (m < numRows - 1) {
					if ((mapArr[m][n] != 1 && mapArr[m + 1][n] != 1))
					{

						int vertexNum1 = mappingFunction(m, n, numColumns);
						int vertexNum2 = mappingFunction(m + 1, n, numColumns);
						insert_edge(&g, vertexNum1, vertexNum2, false);
					}
				}

				if (m > 0) {
					if ((mapArr[m][n] != 1 && mapArr[m - 1][n] != 1))
					{

						int vertexNum1 = mappingFunction(m, n, numColumns);
						int vertexNum2 = mappingFunction(m - 1, n, numColumns);
						insert_edge(&g, vertexNum1, vertexNum2, false);
					}
				}

				if (n > 0) {
					if ((mapArr[m][n - 1] != 1 && mapArr[m][n] != 1))
					{

						int vertexNum1 = mappingFunction(m, n, numColumns);
						int vertexNum2 = mappingFunction(m, n - 1, numColumns);
						insert_edge(&g, vertexNum1, vertexNum2, false);
					}
				}

				if (n < numColumns - 1) {
					if ((mapArr[m][n + 1] != 1 && mapArr[m][n] != 1))
					{

						int vertexNum1 = mappingFunction(m, n, numColumns);
						int vertexNum2 = mappingFunction(m, n + 1, numColumns);
						insert_edge(&g, vertexNum1, vertexNum2, false);
					}

				}
			}
		}

			//print_graph(&g);

			int originPoint = getOriginPoint(numRows, numColumns, mapArr);
			int endPoint = getEndPoint(numRows, numColumns, mapArr);

			//printf("The starting point is====>%d", originPoint);
			//printf("The end point is ====>%d", endPoint);

			if (find_path(&g, originPoint, endPoint, numColumns, mapArr,numRows,numColumns,fp_out))
			{
				printChar(numRows, numColumns, mapArr, fp_out);
				
			}

			else
			{

				int k = 0;
				int l = 0;

				

				fprintf(fp_out, "There is no path from (%d, %d) to (%d, %d)\n", xi, xj, yi, yj);

				
			}
			scenarioCounter++;
		}

		fclose(fp_in);
		fclose(fp_out);
		//prompt_and_exit(0);
	}
