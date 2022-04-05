#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>
#include <stdbool.h>

typedef struct bstNode {
  int data;
  struct bstNode* l_child;
  struct bstNode* r_child;
}node;

void insert(node** root, int value){

  if(*root == NULL){
     node* x = malloc(sizeof(node));
     *root = x;
     (*root) -> data = value;
     (*root) -> l_child = NULL;
     (*root) -> r_child = NULL;
     return;
  }

  if((*root) -> data == value){
    return;
  }

  else if((*root) -> data < value && (*root) -> r_child != NULL){
    insert(&((*root) -> r_child), value);
    return;
  }
  else if((*root) -> data > value && (*root) -> l_child != NULL){
    insert(&((*root) -> l_child), value);
    return;
  }
  else if((*root) -> data < value && (*root) -> r_child == NULL){
    node* buff = malloc(sizeof(node));
    buff -> r_child = NULL;
    buff -> l_child = NULL;
    buff -> data = value;
    (*root) -> r_child = buff;
    // insert(&buff, value);
    return;
  }
  else if((*root) -> data > value && (*root) -> l_child == NULL){
    node* buff = malloc(sizeof(node));
    buff -> r_child = NULL;
    buff -> l_child = NULL;
    (*root) -> l_child = buff;
    buff -> data = value;
    return;
  }
  else if((*root) -> r_child == NULL && (*root) -> l_child == NULL){
    (*root) -> data = value;
    return;
  }
  return;

}

// void delete(node* root){
//
//   if(root == NULL) return;
//   else if((root) -> r_child == NULL && (root) -> l_child == NULL){
//     free(root);
//     return;
//   }
//   delete((root) -> l_child);
//   delete((root) -> r_child);
//
// }

 void printBST(node* root){
   // if(root == NULL) return;
   //
   // printBST(root -> r_child);
   //
   // if(((root) -> r_child) -> r_child == NULL && ((root) -> r_child) -> l_child == NULL){
   //   printf("%d %d ", ((root) -> r_child) -> data, root -> data);
   //   free((root) -> r_child);
   //   (root) -> r_child = NULL;
   //   printBST(root -> l_child);
   //   free(root);
   //
   // }
   //
   // if(root -> r_child == NULL && root -> l_child == NULL){
   //   printf("%d ", root -> data);
   //   free(root);
   //   return;
   // }
   // if((root) -> r_child == NULL && root -> l_child != NULL){
   //   printf("%d ", (root) -> data);
   //   printBST((root) -> l_child);
   // }
   // if((root) -> l_child == NULL && root -> r_child != NULL){
   //   printBST((root) -> r_child);
   // }
   //
   // // else if(((root) -> l_child) -> r_child == NULL && ((root) -> l_child) -> l_child == NULL){
   // //   printf("%d ", ((root) -> l_child) -> data);
   // //   free((root) -> l_child);
   // //   (root) -> l_child = NULL;
   // //   return;
   // // }
   //
   // // printBST(root -> l_child);
   //
   // return;
   if(root == NULL) return;
   // if(root -> l_child == NULL && root -> r_child == NULL){
   //   printf("%d ", root -> data);
   //   free(root);
   //   return;
   // }
   // else if(root -> r_child == NULL){
   //
   //   printf("%d ", root -> data);
   //   printBST(root -> l_child);
   //   // root -> l_child = NULL;
   //   // free(root -> l_child);
   //   // printBST(root);
   //   return;
   // }

   printBST(root -> r_child);
   // root -> r_child = NULL;
   printf("%d ", root -> data);
   // printBST(root);
   // free(root);
   printBST(root -> l_child);
   free(root);
   // free(root -> r_child);
   // free(root -> l_child);
   return;

 }









int main(int argc, char* argv[])
{
    FILE* fp = fopen(argv[1], "r");                                     //each line has an element to be inputted
    if (!fp) {                                                          //repetitions can be
        perror("fopen failed");                                         //print depth first Zreverse order traversal
        return EXIT_FAILURE;
    }

    node* root = NULL;

    int buff[10];
    while ( fscanf(fp, "%d", buff)!=EOF ) {
      // fscanf(fp, "%s", buff);
      // char x = atoi(buff);
      insert(&root, buff[0]);
      // printf("%d\n", buff[0]);
    }

     printBST(root);
    // printf("%d\n", root -> data);
    // printf("%d\n", (root -> r_child) -> data);
    // printf("%d\n", (root -> l_child) -> data);
    // printf("%d\n", ((root -> r_child) -> r_child) -> data);
    // printf("%d\n", ((root -> r_child) -> l_child) -> data);
    // printf("%d\n", (((root -> r_child) -> r_child) -> r_child) -> data);
    // printf("%d\n", (((root -> r_child) -> r_child) -> l_child) -> data);
    // delete(&root);

    // printf("%d\n", root -> data);
    // printf("%p\n", root -> r_child);
    // printf("%p\n", root -> l_child);
    // printf("%d\n", (root -> r_child) -> data);
    // printf("%p\n", (root -> r_child) -> r_child);
    // printf("%p\n", (root -> r_child) -> l_child);
    // // printf("%d\n", (root -> l_child) -> data);
    // printf("%d\n", ((root -> r_child) -> r_child) -> data);
    // printf("%p\n", ((root -> r_child) -> r_child) -> r_child);
    // printf("%p\n", ((root -> r_child) -> r_child) -> l_child);
    // // printf("%d\n", ((root -> r_child) -> l_child) -> data);
    // printf("%d\n", (((root -> r_child) -> r_child) -> r_child) -> data);
    // printf("%p\n", (((root -> r_child) -> r_child) -> r_child) -> r_child);
    // printf("%p\n", (((root -> r_child) -> r_child) -> r_child) -> l_child);
    // // printf("%d\n", (((root -> r_child) -> r_child) -> l_child) -> data);
    // printf("%d\n", ((((root -> r_child) -> r_child) -> r_child) -> r_child) -> data);
    // printf("%p\n", ((((root -> r_child) -> r_child) -> r_child) -> r_child) -> r_child);
    // printf("%p\n", ((((root -> r_child) -> r_child) -> r_child) -> r_child) -> l_child);

    // printf("%d\n", root -> data);
    // printf("%p\n", root -> r_child);
    // printf("%p\n", root -> l_child);
    // // printf("%d\n", (root -> r_child) -> data);
    // printf("%p\n", (root -> r_child) -> r_child);
    // printf("%p\n", (root -> r_child) -> l_child);
    // // printf("%d\n", (root -> l_child) -> data);
    // // printf("%d\n", ((root -> r_child) -> r_child) -> data);
    // printf("%p\n", ((root -> r_child) -> r_child) -> r_child);
    // printf("%p\n", ((root -> r_child) -> r_child) -> l_child);
    // // printf("%d\n", ((root -> r_child) -> l_child) -> data);
    // printf("%d\n", (((root -> r_child) -> r_child) -> r_child) -> data);
    // printf("%p\n", (((root -> r_child) -> r_child) -> r_child) -> r_child);
    // printf("%p\n", (((root -> r_child) -> r_child) -> r_child) -> l_child);
    // // printf("%d\n", (((root -> r_child) -> r_child) -> l_child) -> data);
    // printf("%d\n", ((((root -> r_child) -> r_child) -> r_child) -> r_child) -> data);
    // printf("%p\n", ((((root -> r_child) -> r_child) -> r_child) -> r_child) -> r_child);
    // printf("%p\n", ((((root -> r_child) -> r_child) -> r_child) -> r_child) -> l_child);


    fclose(fp);
    return 0;
}
