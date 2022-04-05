#include "../graphutils.h"

// A program to find a cycle in a directed graph

// You may use DFS or BFS as needed
/* ... */
typedef struct node{
    graphNode_t graphNode;
    struct node* next;
}node;



void push(node** top, graphNode_t val){

    node* x = malloc(sizeof(node));
    x -> graphNode = val;
    x -> next = *top;
    *top = x;
    // free(x);
    return;

}
graphNode_t pop(node** top){

  if (*top == NULL){
      return -1;

  }

  node* x = *top;
  *top = (*top) -> next;
  graphNode_t y = x -> graphNode;
  free(x);
  // x -> data = 0;
  // x -> next = NULL;
  return y;

}

void freeStack(node* first_node) {
    node* ptr = first_node;

    while (first_node != NULL) {
        ptr = first_node;
        first_node = first_node->next;
        free(ptr);
    }
}

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

void printCycle(graphNode_t graphNodeCount, graphNode_t* cycleRoot, graphNode_t* cycleDest, graphNode_t* parents, node** top){
  //
  // if(*cycleRoot == *cycleDest){
  //   printf("%lu ", *cycleDest);
  //   return;
  // }
  // for (size_t i = 0; i < graphNodeCount; i++) {
  //   /* code */
  //   // if(parents[*cycleRoot] == *cycle)
  //   if(parents[i] == *cycleRoot){
  //     printf("%lu ", *cycleRoot);
  //     *cycleRoot = i;
  //     printCycle( graphNodeCount, cycleRoot, cycleDest, parents);
  //     return;
  //   }
  //
  //
  //
  // }

  if(*cycleRoot == *cycleDest){
    push(top, *cycleRoot);
    return;
  }

    for (size_t i = 0; i < graphNodeCount; i++){

      if(i == *cycleDest){
        push(top, *cycleDest);
        *cycleDest = parents[i];
        printCycle(graphNodeCount, cycleRoot, cycleDest, parents, top);
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
    int* visited,
    node** top,
    graphNode_t parent,
    graphNode_t current
) {


  if(visited[current] == -1){
  push(top, current);
  visited[current] = 0;
  parents[current] = parent;
  }

  if(adjacencyList[current].next == NULL){
    pop(top);
    visited[current] = 1;
    parents[current] = parent;
    return false;
  }



  AdjacencyListNode* neighbor = adjacencyList[current].next;

  while(neighbor){

    if(visited[neighbor -> graphNode] == 0){
      *cycleRoot = neighbor -> graphNode;
      *cycleDest = current;
      parents[neighbor -> graphNode] = parent;
      return true;
    }

    // if(visited[neighbor -> graphNode] == -1){
    //   push(top, neighbor -> graphNode);
    //   visited[neighbor -> graphNode] = 0;
    //   visited[neighbor -> graphNode] = parent;
    // }
    if(visited[neighbor -> graphNode] != 1){
    bool x = isCyclicDFS(graphNodeCount, cycleRoot, cycleDest, adjacencyList, parents, visited, top, current, neighbor -> graphNode);

    if ( x == true ) return true;
    }

    neighbor = neighbor -> next;


  }


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
    int* visited = malloc(graphNodeCount*sizeof(int));
    for (size_t i=0; i<graphNodeCount; i++) {
        parents[i] = -1;
        visited[i] = -1; // -1 indicates that a nodes is not yet visited
    }



    bool isCyclic = false;
    // bool isTree = false;

    node* top = NULL;




    for (unsigned source=0; source<graphNodeCount; source++) {




      isCyclic = isCyclicDFS(graphNodeCount, cycleRoot, cycleDest, adjacencyList, parents, visited, &top, source, source);



      if (isCyclic == true) break;


      // if(source == 4) continue;
      // printf("%u\n", source);
      // if (!isTreeDFS(graphNodeCount, adjacencyList, source)) {
      //   isCyclic = isCyclicDFS(graphNodeCount, cycleRoot, cycleDest, adjacencyList, parents, source, source);
      // }
      //
      // if (isCyclic == true) break;
      //
      // *cycleRoot = -1;
      // *cycleDest = -1;
      //
      for (size_t i=0; i<graphNodeCount; i++){
          parents[i] = -1;
          visited[i] = -1;
      }

    }
    // if (!isTreeDFS(graphNodeCount, adjacencyList, 3)) {
    //   isCyclic = isCyclicDFS(graphNodeCount, cycleRoot, cycleDest, adjacencyList, parents, 3, 3);
    // }

    // isCyclic = isCyclicDFS(graphNodeCount, cycleRoot, cycleDest, adjacencyList, parents, visited, &top, 1, 1);

    // printf("%lu\n", *cycleRoot);
    //
    // for (size_t i = 0; i < graphNodeCount; i++) {
    //   /* code */
    //   printf("\n%lu %lu\n",i,parents[i]);
    // }
    // printf("\n");
    //
    // printf("cycleRoot: %lu\n", *cycleRoot);
    // printf("cycleDest: %lu\n", *cycleDest);
    // // printf("\n");
    // printf("%d\n\n", isCyclic);


      while(top){
        pop(&top);
      }
      if(isCyclic) printCycle(graphNodeCount, cycleRoot, cycleDest, parents, &top);

      while(top){
        printf("%lu ", pop(&top));
      }


    // printf("\n");
    // printf("\n");
    //
    // printf("cycleRoot: %lu\n", *cycleRoot);
    // printf("cycleDest: %lu\n", *cycleDest);
    // printf("\n");
    // printf("%d\n\n", isCyclic);

    if (!isCyclic) { printf("DAG\n"); }

    freeStack(top);
    free(visited);
    free(parents);
    free(cycleDest);
    free(cycleRoot);
    freeAdjList ( graphNodeCount, adjacencyList );
    return EXIT_SUCCESS;
}
