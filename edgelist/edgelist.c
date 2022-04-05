#include "../graphutils.h" // header for functions to load and free adjacencyList

// A program to print the edge list of a graph given the adjacency matrix
int main ( int argc, char* argv[] ) {

    // FIRST, READ THE ADJACENCY MATRIX FILE
    AdjacencyListNode* adjacencyList = NULL;
    /* ... */
    int x = adjMatrixToList(argv[1], &adjacencyList);

    // AdjacencyListNode* buff = adjacencyList;

    for(int i = 0; i < x; i++){

      AdjacencyListNode* buff = adjacencyList[i].next;

      while(buff){

        if(buff->graphNode > i){
          printf("%d %zu\n", i, buff -> graphNode);
        }
        buff = buff -> next;

      }

    }
    freeAdjList(x, adjacencyList);



    // NEXT, TRAVERSE THE ADJACENCY LIST AND PRINT EACH EDGE, REPRESENTED AS A PAIR OF NODES
    // Example of traversing the adjacency list is in the freeAdjList() function in graphutils.h
    /* ... */

    // NOW, BE SURE TO FREE THE ADJACENCY LIST
    /* ... */

    return EXIT_SUCCESS;
}
