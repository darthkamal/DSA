/* 
  Interface file

  Graph - adjacency list implementation based on code by Steven Skiena:

  Steven S. Skiena, "The Algorithm Design Manual", 2nd Edition, Springer, 2008.

  David Vernon
  19 March 2017

*/
 
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <ctype.h>

#define MAX_N 100;
#define MAX_M 100;
#define TRUE 1
#define FALSE 0

#define QUEUESIZE       1000

typedef int item_type;

typedef struct {
        item_type q[QUEUESIZE+1];       /* body of queue */
        int first;                      /* position of first element */
        int last;                       /* position of last element */
        int count;                      /* number of queue elements */
} queue;


/* Adjacency list representation of a graph of degree MAXV          */
/*                                                                  */
/* Directed edge (x, y) is represented by edgenode y in x’s         */
/* adjacency list. Vertices are numbered 1 .. MAXV                  */

#define MAXV 1000  /* maximum number of vertices */

//Original code
//typedef struct {
//   int y;                        /* adjacent vertex number          */
//   int weight;                   /* edge weight, if any             */
//   struct edgenode *next;        /* next edge in list               */
//} edgenode;

typedef struct edgenode *EDGENODE_PTR;

typedef struct edgenode {
   int y;                        /* adjacent vertex number          */
   int weight;                   /* edge weight, if any             */
   EDGENODE_PTR next;            /* next edge in list               */
} edgenode;

typedef struct {
        edgenode *edges[MAXV+1]; /* adjacency info: list of edges   */
        int degree[MAXV+1];      /* number of edges for each vertex */
        int nvertices;           /* number of vertices in graph     */
        int nedges;              /* number of edges in graph        */
        bool directed;           /* is the graph directed?          */
} graph;


void initialize_graph(graph *g, bool directed);

bool read_graph(graph *g, bool directed);
 
void insert_edge(graph *g, int x, int y, bool directed);

void print_graph(graph *g);

void initialize_search(graph *g);

void bfs(graph *g, int start);

void process_vertex_late(int v);

void process_vertex_early(int v);

void process_edge(int x, int y);

//bool find_path(int start, int end, int parents[]);
//
//bool find_path(graph *g, int start, int end);

void init_queue(queue *q);

void enqueue(queue *q, item_type x);

item_type dequeue(queue *q);

item_type headq(queue *q);

int empty_queue(queue *q);

void print_queue(queue *q);

void convertVertexToCell(int nm, int array[100][100], int vertex);

//bool find_path(int start, int end, int parents[], int m, int array[100][100]);
int mapFunc(int i, int j, int numColumns);


bool find_path(int start, int end, int parents[], int m, int array[100][100], int numberOfRows, int numberOfColumns, FILE *file);

bool find_path(graph *g, int start, int end, int m, int array[100][100], int numRows, int numColumns, FILE *out);

void prompt_and_exit(int status);
int find_j(int col, int v, int i);
int find_i(int col, int v);