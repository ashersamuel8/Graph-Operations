#include "../graphutils.h" // header for functions to load and free adjacencyList

// A program to solve a maze that may contain cycles using BFS

// BFS requires using a queue data structure
typedef struct QueueNode {
    graphNode_t graphNode;
    struct QueueNode* next;
} QueueNode;

struct Queue {
    struct QueueNode* front; // front (head) of the queue
    struct QueueNode* back; // back (tail) of the queue
};
typedef struct Queue Queue;

// Append a new QueueNode to the back of the Queue
struct Queue enqueue ( struct Queue queue, graphNode_t graphNode ) {

    QueueNode* buff = calloc(1, sizeof(QueueNode));
    buff -> graphNode = graphNode;
    buff -> next = NULL;
    if (queue.front == NULL) {
      queue.front = buff;
      queue.back = buff;
    }
    else{
      queue.back -> next = buff;
      queue.back = buff;
    }

    return queue;
}

// Remove a QueueNode from the front of the Queue
graphNode_t dequeue ( Queue* queue ) {

  if (queue -> front == NULL) return -1;

    QueueNode* x = queue -> front;
    graphNode_t y = x -> graphNode;
    queue -> front = (queue -> front) -> next;
    free(x);


  return y;

}

int main ( int argc, char* argv[] ) {

    // First, read the query file to get the source and target nodes in the maze
    /* ... */

    // READ INPUT FILE TO CREATE GRAPH ADJACENCY LIST
    AdjacencyListNode* adjacencyList = NULL;

    int graphNodeCount = adjMatrixToList(argv[1], &adjacencyList);

    FILE* fp = fopen(argv[2], "r");
    if (!fp) {
        perror("fopen failed");
        return 0;
    }

    graphNode_t source;
    fscanf(fp, "%ld", &source);

    graphNode_t target;
    fscanf(fp, "%ld", &target);
    // USE A QUEUE TO PERFORM BFS

    if(source == target){
      printf("%zu %zu", source, target);
      return EXIT_SUCCESS;

    }
    Queue queue = { .front=NULL, .back=NULL };

    // An array that keeps track of who is the parent node of each graph node we visit
    graphNode_t* parents = calloc(graphNodeCount, sizeof(graphNode_t));
    for (size_t i=0; i<graphNodeCount; i++) {
        parents[i] = -1; // -1 indicates that a nodes is not yet visited
    }

    /* ... */
    parents[source] = source;
    queue = enqueue(queue, source);
    // graphNode_t current = source;
    while (queue.front) {
      graphNode_t father = dequeue(&queue);
      AdjacencyListNode* x = adjacencyList[father].next;
      while(x){
        if(parents[x -> graphNode] == -1){
          queue = enqueue(queue, x -> graphNode);
          parents[x -> graphNode] = father;
        }
        if(x -> graphNode == target) break;
        x = x -> next;
      }

      if(x == NULL) continue;
      if(x -> graphNode == target) break;

        // so long as we haven't found the target node yet, iterate through the adjacency list
        // add each neighbor that has not been visited yet (has no parents) to the queue of nodes to visit
        /* ... */

        // Visit the next node at the front of the queue of nodes to visit
        /* ... */
    }


    // printf("%lu %lu\n", target, parents[target]);

    while( target != source){
      printf("%lu %lu\n", target, parents[target]);
      target = parents[target];
    }
    // Now that we've found the target graph node, use the parent array to print maze solution
    // Print the sequence of edges that takes us from the source to the target node
    /* ... */

    // free any queued graph nodes that we never visited because we already solved the maze
    while ( queue.front ) {
        dequeue(&queue);
    }
    free (parents);
    freeAdjList (graphNodeCount, adjacencyList);

    return EXIT_SUCCESS;
}
