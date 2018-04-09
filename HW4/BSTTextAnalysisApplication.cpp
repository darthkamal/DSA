/*
Application file for the program
 ===================================================================================================================================================


 This program is for course 04-630 Data Structures and Algorithms for Engineers, Assignment No. 4
 The program analyses a set of text files. For each file analyzed, it will compile a list of all the distinct words in it by reading
 them from the file and inserting them in a binary search tree (BST). When all the words have been read from that file,
 the program traverses the BST and writes the words to an output file, one word per line, in alphabetic order,
 together with the number of occurrences of each word in the file and,
 in brackets, the level at which they are stored in the BST. The root of the tree is at level 0.

 For each file, the program will compute the height of the BST, and the average and the maximum number of probes
 (i.e. nodes examined) to find a word in the BST. There may be multiple input files, but there is just one output file.

 Each list begins with the name of the file from which they were taken. This is followed by the height of the tree, the average number of probes,
 the maximum both on separate lines.
 At the end of each list, the program appends a line comprising 20 dashes (i.e. �--------------------�).

 A word is defined to be a contiguous sequence of alphanumeric characters (�a� .. �z�, �A� .. �Z�, or �0� .. �9�) possibly including a hyphen.
 If a word is followed by an apostrophe and an �s�, e.g. �it�s a special case�, the �s� following the apostrophe should not be treated as a word.




 File organization
 ------------------

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



Sample Input
-----------
../data/textfile1.txt
../ data/textfile2.txt
../data/textfile3.txt
../data/textfile4.txt

Sample Output
-------------
dTogun
../data/textfile1.txt
Maximum number of probes: 4
Average number of probes: 2.5
heart         2 (1)
in            2 (3)
is            2 (2)
my            2 (0)
the           2 (1)
work          2 (2)
--------------------
../data/textfile2.txt
Maximum number of probes: 6
Average number of probes: 3.5
can           1 (0)
do            1 (1)
fear          1 (2)
i             1 (3)
she           1 (4)
what          1 (5)
--------------------
../data/textfile3.txt
Maximum number of probes: 3
Average number of probes: 1.5
is      	  1 (0)
my            1 (1)
name          1 (2)
salah         1 (3)
--------------------

Solution Strategy
------------------

- The program starts by opening the declared input file, it reads the filenames in the input file and then stores each in an array.
- The binary search tree is initialized before each iteration to ensure it will only contain the words read in that iteration (from the file).
- Each file is passed in, opened and read.
- The words in it file are read, and all characters are switched to lowercase
- If a character in the word is not alphanumeric as declared in the question, it is substituted with a space (" ").
- Special cases are also filtered, such as characters with hyphens which are ignored, and words with ("'s")
- After filtering, a new word is created (lowercase and stripped of punctuation).
- The newly created word is then assigned to an element E and inserted into the Binary Search Tree.
- The program loops through until all words in the provided file are inserted.
- The program computes the height of the tree (when it has all its elements)
- The program computes the number of probes in the BST
- The program computes the average number of probes in the BST
- The program performs an inorder traversal of the BST and then it writes each word to the output file. In alphabetic order.
- The program closes every text file after reading it, and opens the next for reading.
- When all textfiles are read, the program closes the input file (containing the names of the textfiles) and the output file.


Algorithm for computing the height of the Tree
----------------------------------------------
If the tree is empty
	return 0 as the height of the tree
Else
	Recursively compute the height of the left subtree
	Recursively compute the height of the right subtree
	Compare and compute the maximum of the heights of the left and right subtree
	Add 1 to the maximum height computed
	Return height

Pseudocode
-----------
if(tree == NULL)
{
	treeHeight =0;
}

else{

	leftTreeHeight = height recursive call for leftsubtree
	righTreetHeight = height recursive call for rightsubtree
	maximum(leftTreeHeight,righTreetHeight)
	treeHeight = (maximum + 1)
}

return treeHeighteight

Complexity: Time complexity is 0(n) for the worst case of traversals

Algorithm for computing the Average number of probes
------------------------------------------------------

The average number of probes is simply computed by dividing the total number of probes by the number of nodes in the BST

The Total number of probes is computed as:
- If the tree is empty then the number of probes is 0
- If tree is not empty
- Traverse to the left subtree
- Recursively compute the number of probes for the left tree
- The level used in this recursive call is always incremented by 1 since we are moving to lower levels
- Store the value obtained at each call in a result that will be incremented at each stage
- Traverse to the right subtree
- Recursively compute the number of probes for the left tree

Number of nodes
-----------------
-If the tree is empty then the number of nodes is 0
-If tree is not empty
- Traverse to the left subtree
- Recursively compute the number of nodes while summing up the values obtained at each call
- Traverse to the right subtree
- Recursively compute the number of nodes while summing up the values obtained at each call and the sum obtained from the left subtree
- return the value computed

After computing the total number of probes and number of nodes, we can compute the average number of probes

The average number of probes is expressed as:
	Average number of probes = total number of probes/ number of nodes

]

 Test Strategy
 --------------

  The program has been tested with a variety of test data sets that reflect all valid conditions, including boundary conditions: Multiple text files were created to try the various scenarios
   - Testing for empty input files
   - Testing with the sample data sets provided by the instructor, serving as a good guide to overall correctness of solution
   - Testing values with punctuation marks to ensure they conform to program functionality
   - Testing when the file only contains punctuation marks
   - Testing for special cases, as stated in the question, such as apostrophes with and without s ('s), as well as words with hyphens.
   - Testing with only numbers
   - Testing with really long words, up to 20 words as stated in the question

*/

#include "BSTTextAnalysis.h"

int main() {
	char studentID[7] = "dTogun";
	ELEMENT_TYPE e;
	BINARY_TREE_TYPE tree;
	int debug = TRUE;
	char word[100];
	char * temp;
	char * puncToken;
	char * puncToken2;
	int endOfFile;
	int innerInputFile;
	double averageNum;
	char filename[100];
	FILE *fp_in, *fp_out, *fname;
	fp_in = fopen("/data/input.txt", "r");
	fp_out = fopen("/data/output.txt", "w");


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

	while ((endOfFile = fscanf(fp_in, "%s", filename)) != EOF) {

		//initializing the BST
		initialize(&tree);
		//if (endOfFile != EOF) {

		fname = fopen(filename, "r");
		if (fname == 0) {
			printf("Error can't open input input %s\n", filename);
			//prompt_and_exit(1);
		}

		fprintf(fp_out, "%s\n", filename);
		//printf("%s\n", filename);
		while ((innerInputFile = fscanf(fname, "%s", word)) != EOF) {
			

			//Converting read in words to lowercase
			for (int i = 0; i < strlen(word); i++) {
				word[i] = tolower(word[i]);
			}


			//Filtering the read in words to remove puntuations and seperate them. Including dealing with special cases
			puncToken = strtok_s(word, " ,.;:?!\\", &temp);
			{
				while (puncToken != NULL)
				{
					//printf("the value is %s\n", puncToken);
					char* sub = strchr(puncToken, '\'');
					if (sub != NULL && strcmp(sub, "'s") == 0) {
						assign_element_values(&e, 1, puncToken);
						insert(e, &tree);
						//printf("%s\n", pch);
					}
					else {
						char * word2 = puncToken;
						puncToken2 = strtok_s(word2, "'", &temp);
						while (puncToken2 != NULL)
						{
							assign_element_values(&e, 1, puncToken2);
							insert(e, &tree);
							//printf("%s\n", pch2);
							puncToken2 = strtok_s(NULL, "'", &temp);
						}
					}

					puncToken = strtok_s(NULL, " ,.;:?!\\", &temp);

				}
			}

		}

		
		//Function call to get the height of the BST
		int maxNum = height_of_the_tree(tree);
		//Function call to get the number of probes in the BST
		int numProbes = number_of_probes(tree, 0);
		//Function call to get the number of nodes in the BST
		int numNodes = number_of_nodes(tree);

		//Computing the average number of nodes
		averageNum = ((double)numProbes / numNodes);

		//Writing the values to the file
		fprintf(fp_out,"Maximum number of probes: %d \n",maxNum);
		fprintf(fp_out,"Average number of probes is: %0.1f \n",averageNum);
		//Function call to print the words to file inorder
		filePrint(fp_out, tree, 0);

		fprintf(fp_out,"--------------------\n");
		
		//}
	}

	//Close the files
	fclose(fname);
	fclose(fp_in);
	fclose(fp_out);
	//prompt_and_exit(0);
}