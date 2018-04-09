/*
  BSTTextAnalysisImplementation.cpp - interface file for the program
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

 BSTTextAnalysisApplication.cpp				application file:
											contains the code that instantiates the abstract data types and calls the associated functions
											order to effect the required functionality for this application


 Author
 ------

 Daniel Togun
 16/03/2018


 Andrew ID
 dTogun


 Audit Trail
 -----------

 */

 /*include the header file where the program prototype is defined.*/
#include "BSTTextAnalysis.h"
int m = 0;



bool isPunctuation(char c)
{
	if (c == '.')
		return true;
	else if (c == ',')
		return true;
	else if (c == '?')
		return true;
	else if (c == '\'') //escape character needed
		return true;
	else if (c == '!')
		return true;
	else if (c == '\"') //escape character needed
		return true;
	else if (c == '-')
		return true;
	else if (c == ';')
		return true;
	else
		return false;
}

int height_of_the_tree(BINARY_TREE_TYPE tree) {

	if (tree == NULL) {
		
		return 0;
	}
	int left, right, treeHeight;

	if ( (tree != NULL)) {
		left = height_of_the_tree(tree->left);
		right = height_of_the_tree(tree->right);
		
	
		treeHeight = (1 + max(left, right));
		
		return treeHeight;
	}
}

int max(int w1, int w2)
{
	int theMax = w2;
	if (w1 > w2)
		theMax = w1;
	
	return theMax;
}

//
int inorder(BINARY_TREE_TYPE tree, int n, FILE *fp_out) {

	//int i;

	if (tree != NULL) {
		inorder(tree->left, n + 1, fp_out);

		fprintf(fp_out, "%-25s%d(%d)\n", tree->element.string, tree->element.frequency, n);
		inorder(tree->right, n + 1, fp_out);

	}

	return(0);


}
//Calculate the number of probes
int number_of_probes(BINARY_TREE_TYPE tree, int n) {

	if (n == 0)
		m = 0;
	if (tree != NULL) {
		number_of_probes(tree->left, n + 1);
		m = m + n + 1;
		number_of_probes(tree->right, n + 1);
	}
	return m;
}

//calculate the number of nodes in the tree
int number_of_nodes(BINARY_TREE_TYPE tree)
{
	int count = 1;
	if (tree == NULL)
		return 0;
	else
	{
		count += number_of_nodes(tree->left);
		count += number_of_nodes(tree->right);
		return count;
	}
}