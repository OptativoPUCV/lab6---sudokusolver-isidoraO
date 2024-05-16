#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){

    return 1;
}


List* get_adj_nodes(Node* n){
  List* list=createList();
  int cont = 1;
  int algo = 0;
  for(int i=0;i<9;i++)
    for(int j=0;j<9;j++)
      {
        if(n->sudo[i][j])
        {
          Node *nodo = createNode();

          for(int k=0;k<9;k++)
            for(int m = 0; m < 9; m++)
              {
                nodo->sudo[k][m] = n->sudo[k][m];
                if(nodo->sudo[k][m] == 0)
                {
                  nodo->sudo[k][m] = cont;
                  algo++;
                }
                if(cont == 9)  cont = 0;
              }
          if(algo != 0)
            pushBack(list, nodo);
          cont++;
        }
      }
  return list;
}


int is_final(Node* n){
  int i, j, k = 0; 
  for(;i < 9; i++)
    {
      if(n->sudo[j][k] == n->sudo[i][k]) return 0;
    }
  return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/