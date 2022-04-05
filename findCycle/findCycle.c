#include "../graphutils.h"

// A program to find a cycle in a directed graph

// You may use DFS or BFS as needed
/* ... */

void Print (
    size_t graphNodeCount,
    AdjacencyListNode* adjacencyList
) {
    // example of how to traverse the graph adjacency list
    for (size_t source=0; source<graphNodeCount; source++) {
      printf("%zu ", adjacencyList[source].graphNode);
        AdjacencyListNode* dest = adjacencyList[source].next;

        // list iterator
        while (dest) {
            // AdjacencyListNode* temp = dest;
            printf("%zu ",dest -> graphNode);
            dest = dest->next; // iterator moves to next

        }
        printf("\n");
    }
    // free(adjacencyList);
}

void printCycle(graphNode_t graphNodeCount, graphNode_t* cycleRoot, graphNode_t* cycleDest, graphNode_t* parents){

  if(*cycleRoot == *cycleDest){
    printf("%lu ", *cycleDest);
    return;
  }
  for (size_t i = 0; i < graphNodeCount; i++) {
    /* code */
    // if(parents[*cycleRoot] == *cycle)
    if(parents[i] == *cycleRoot){
      printf("%lu ", *cycleRoot);
      *cycleRoot = i;
      printCycle( graphNodeCount, cycleRoot, cycleDest, parents);
      return;
    }



  }


}

bool isTreeDFS (
    size_t graphNodeCount,
    AdjacencyListNode* adjacencyList,
    graphNode_t node
) {

    for (size_t i = 0; i < graphNodeCount; i++){

      AdjacencyListNode* neighbor = adjacencyList[i].next;
      while(neighbor){
        if(neighbor -> graphNode == node) return false;
        neighbor = neighbor -> next;
      }

    }

    return true;
}


bool isCyclicDFS (
    size_t graphNodeCount,
    graphNode_t* cycleRoot,
    graphNode_t* cycleDest,
    AdjacencyListNode* adjacencyList,
    graphNode_t* parents,
    graphNode_t parent,
    graphNode_t current
) {
    // printf(".\n");

    if (parent == current){
      *cycleRoot = parent;
    }
    else if(current == *cycleRoot){


      *cycleDest = parent;

      // printf("cycleRoot: %lu\n", *cycleRoot);
      // printf("cycleDest: %lu\n", *cycleDest);
      // printf("\n");
      parents[current] = parent;
      return true;

    }
    // if(parents[current] != 1 && )
    // if(parents[current] != -1){
    //
    //
    //
    //   return true;
    // }
    // else{
    parents[current] = parent;
    // }
    AdjacencyListNode* neighbor = adjacencyList[current].next;
    while(neighbor){

      // if (neighbor -> graphNode == parent){
      //   printf("-\n");
      //   // *cycleRoot = current;
      //   *cycleDest = parent;
      //   parents[current] = parent;
      //   return true;
      // }
      // else{
      if (neighbor -> graphNode == parent)
      {
        *cycleDest = current;
        *cycleRoot = parent;
        parents[parent] = current;
        return true;
      }

      if (neighbor -> graphNode != parent){

      bool x = isCyclicDFS(graphNodeCount, cycleRoot, cycleDest, adjacencyList, parents, current, neighbor -> graphNode);
      // if(parents[current] == parent && current != *cycleRoot) break;
      if(x == true) return true;
      }




      // if(current == *cycleRoot){
      //   for (size_t i=0; i<graphNodeCount; i++) {
      //       parents[i] = -1; // -1 indicates that a nodes is not yet visited
      //   }
      // }



      // for (size_t i=0; i<graphNodeCount; i++) {
      //     parents[i] = -1; // -1 indicates that a nodes is not yet visited
      // }

      neighbor = neighbor -> next;

    }

    // for (size_t i=0; i<graphNodeCount; i++) {
    //     parents[i] = -1; // -1 indicates that a nodes is not yet visited
    // }

    return false;
}

int main ( int argc, char* argv[] ) {

    // READ INPUT FILE TO CREATE GRAPH ADJACENCY LIST
    AdjacencyListNode* adjacencyList;
    /* ... */
    graphNode_t graphNodeCount = adjMatrixToList(argv[1], &adjacencyList);
    // Print(graphNodeCount, adjacencyList);
    // printf("\n");


    graphNode_t* cycleRoot = malloc(sizeof(graphNode_t));
    *cycleRoot = -1;
    graphNode_t* cycleDest = malloc(sizeof(graphNode_t));
    *cycleDest = -1;


    graphNode_t* parents = calloc( graphNodeCount, (sizeof(graphNode_t)));
    for (size_t i=0; i<graphNodeCount; i++) {
        parents[i] = -1; // -1 indicates that a nodes is not yet visited
    }
    // bool* visited = calloc(graphNodeCount, sizeof(bool));

    bool isCyclic = false;
    // bool isTree = false;


    for (unsigned source=0; source<graphNodeCount; source++) {


      // if(source == 4) continue;
      // printf("%u\n", source);
      if (!isTreeDFS(graphNodeCount, adjacencyList, source)) {
        isCyclic = isCyclicDFS(graphNodeCount, cycleRoot, cycleDest, adjacencyList, parents, source, source);
      }

      if (isCyclic == true) break;


      for (size_t i=0; i<graphNodeCount; i++){
          parents[i] = -1; // -1 indicates that a nodes is not yet visited
      }

    }
    // if (!isTreeDFS(graphNodeCount, adjacencyList, 3)) {
    //   isCyclic = isCyclicDFS(graphNodeCount, cycleRoot, cycleDest, adjacencyList, parents, 3, 3);
    // }



    // printf("%d\n\n", isTree);

    // for (size_t i = 0; i < graphNodeCount; i++) {
    //   /* code */
    //   printf("%lu %lu\n",i,parents[i]);
    // }
    // printf("\n");

    // printf("cycleRoot: %lu\n", *cycleRoot);
    // printf("cycleDest: %lu\n", *cycleDest);
    // printf("\n");
    // printf("%d\n\n", isCyclic);



      if(isCyclic) printCycle(graphNodeCount, cycleRoot, cycleDest, parents);




    // printf("\n");
    // printf("\n");
    //
    // printf("cycleRoot: %lu\n", *cycleRoot);
    // printf("cycleDest: %lu\n", *cycleDest);
    // printf("\n");
    // printf("%d\n\n", isCyclic);

    if (!isCyclic) { printf("DAG\n"); }


    // free(visited);
    free(parents);
    free(cycleDest);
    free(cycleRoot);
    freeAdjList ( graphNodeCount, adjacencyList );
    return EXIT_SUCCESS;
}
