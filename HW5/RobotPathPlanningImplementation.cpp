/*
  RobotPathPlanningImplementation.cpp - interface file for the program
 ===================================================================================================================================================

 This program is for course 04-630 Data Structures and Algorithms for Engineers, Assignment No. 5

 Kindly refer to the application file - QueueingbehaviorApplication.cpp - for details of the functionality of this program


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

 /*include the header file where the program prototype is defined.*/
#include "RobotPathPlanning.h"


void print_message_to_file(FILE *fp, char message[]) {

	fprintf(fp, "The number is: %s\n", message);
}

void TwoDArrayInitialization(int x, int y, int value, int arr[MAX_R][MAX_C], FILE *file)
{
	int i;
	int j;

	for (i = 0; i < x; i++) {
		for (j = 0; j < y; j++) {
			fscanf(file, "%d", &value);
			arr[i][j] = value;
		}
	}
}

void printChar(int numRows, int numColumns, int mapArr[MAX_R][MAX_C], FILE *file)
{
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numColumns; j++) {

			if (mapArr[i][j] == 0) {
				fprintf(file, "  ");
			}
			else if (mapArr[i][j] == 1) {
				fprintf(file, "# ");
			}
			else if (mapArr[i][j] == 2) {
				fprintf(file, "@ ");
			}
			else if (mapArr[i][j] == 3) {
				fprintf(file, "$ ");
			}
			else if (mapArr[i][j] == 4) {
				fprintf(file, "*");
			}
			
		}
		fprintf(file, "\n");
	}

}


		int mappingFunction(int i, int j, int numColumns){
		
			int a;
			int vertexNum;

			a = numColumns;

			vertexNum = ((a*i) + j + 1); //where b and c are 1
			return vertexNum;
		}

	int	getOriginPoint(int k, int l, int mapArr[MAX_R][MAX_C]){
		
			int originPoint = 0;

			for (int i = 0; i < k; i++) {
				for (int j = 0; j < l; j++)
				{
					if (mapArr[i][j] == 2)
					{
						originPoint = mappingFunction(i, j, l);
					}
				}
			}
			return originPoint;
		}
	
	int	getEndPoint(int k, int l, int mapArr[MAX_R][MAX_C]){
		
			int endpoint = 0;

			for (int i = 0; i < k; i++) {
				for (int j = 0; j < l; j++)
				{
					//printf("DataPoint %d\n", mapArr[i][j]);

					if (mapArr[i][j] == 3)
					{
						endpoint = mappingFunction(i, j, l);
						//printf("OP is %d\n", originPoint);
					}
				}
			}
			return endpoint;
		}

		void convertVertexToCell(int nm, int array[MAX_R][MAX_C], int vertex)
		{
			int i = 0;
			int j = 0;
			int mod;

			mod = (vertex % nm);
			if (mod == 0)
			{
				j = nm - 1;
				i = i - 1;
			}

			if (mod != 0)
			{
				j = mod - 1;
			}
			i = (vertex / nm);

			if (array[i][j] != 3)
			{
				array[i][j] = 4;
			}
		}