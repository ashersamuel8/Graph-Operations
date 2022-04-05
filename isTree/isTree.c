#include "../graphutils.h" // header for functions to load and free adjacencyList

// A program to determine whether an undirected graph is a tree

// A recursive function that returns true if no cycles found
bool isTreeDFS (
    size_t graphNodeCount,
    AdjacencyListNode* adjacencyList,
    bool* visited,
    graphNode_t parent,
    graphNode_t current
) {
    //
    // // First see if current node has already been visited, indicating a cycle found
    // /* ... */
    // if(visited[current] == 1) return false;
    // // Current node was not already visited, so now mark it as visited
    // /* ... */
    // else{
    //   visited[current] = 1;
    // }
    //
    // // Now iterate through each of the neighboring graph nodes
    // AdjacencyListNode* neighbor = adjacencyList[current].next;
    // while (neighbor) {
    //     if (neighbor->graphNode!=parent) {
    //         // If the neighbor nodes is not the parent node (the node from which we arrived at current), call DFS
    //         /* ... */
    //         isTreeDFS(graphNodeCount, neighbor, visited, parent, current);
    //     }
    //     neighbor = neighbor->next;
    // }
    //
    // // All DFS searches from current node found no cycles, so graph is a tree from this node
    // return true;



    // if(visited[parent] == true) return true;
    if(visited[current] == true && current != parent) return false;
    if(visited[current] == false){
      visited[current] = true;
    }
    AdjacencyListNode* neighbor = adjacencyList[current].next;
    while(neighbor){
      // if(neighbor -> graphNode == parent) return false;
      if(neighbor -> graphNode != parent){
        bool x = isTreeDFS(graphNodeCount, adjacencyList, visited, current, neighbor -> graphNode);
        if(x == false){
          return false;
        }

      }

      neighbor = neighbor -> next;
    }

    return true;
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

int main ( int argc, char* argv[] ) {

    // READ INPUT FILE TO CREATE GRAPH ADJACENCY LIST
    AdjacencyListNode* adjacencyList = NULL;
    int graphNodeCount = adjMatrixToList(argv[1], &adjacencyList);
    /* ... */

    // Array of boolean variables indicating whether graph node has been visited
    bool* visited = calloc ( graphNodeCount, sizeof(bool) );
    /* ... */

    /* ... */


    // Print(graphNodeCount, adjacencyList);
    bool isTree = isTreeDFS(graphNodeCount, adjacencyList, visited, 0, 0);
    // for(int i = 0; i < graphNodeCount; i++){
  
    //   for(int j = 0; j < graphNodeCount; j++){
    //     visited[i] = false;
    //   }
    //   if(isTree ==  false) break;
    // }


    printf(isTree ? "yes" : "no");
    freeAdjList(graphNodeCount, adjacencyList);
    free(visited);

    return EXIT_SUCCESS;
}
