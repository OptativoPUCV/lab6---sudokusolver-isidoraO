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
void inicializar_array(int *array)
{
  for(int i = 0; i < 10; i++)
    array[i] = 0;
}

int is_valid(Node* n){
  int aux_array_fila[10], aux_array_col[10], aux_array_submatriz[10];

  for(int j = 0; j < 9; j++)
  {
    for(int i = 0; i < 10 ; i++)
      {
        aux_array_fila[i] = 0;
        aux_array_col[i] = 0;
        aux_array_submatriz[i] = 0;
      }

    for(int i = 0; i < 9; i++)
      {
        if((n->sudo[i][j] != 0) && (aux_array_fila[n->sudo[i][j]] == 0))
              aux_array_fila[n->sudo[i][j]] = 1;
        else if(aux_array_fila[n->sudo[i][j]] == 1)
            return 0;
        if((n->sudo[j][i] != 0) && (aux_array_fila[n->sudo[j][i]] == 0))
          aux_array_col[n->sudo[j][i]] = 1;
        else if(aux_array_col[n->sudo[j][i]] == 1)
            return 0;
      }
    for(int k = 0; k < 9; k++)
      {
        int p = 3*(j/3) + (k/3);
        int t = 3*(j%3) + (k%3);


        if((n->sudo[p][t] != 0) && (aux_array_submatriz[n->sudo[p][t]] == 0))
            aux_array_submatriz[n->sudo[p][t]] = 1;
        else if(aux_array_submatriz[n->sudo[p][t]] == 1)
        {
          printf("hello");
          printf("ggf%i ", aux_array_submatriz[n->sudo[p][t]]);
          return 0;
        }
        printf("ggg%i ", aux_array_submatriz[n->sudo[p][t]]);

      }
  }
  printf("Hello");
  for(int i = 0; i < 10; i++)
    printf("%i ", aux_array_submatriz[i]);
  return 1;
}

List* get_adj_nodes(Node* n)
{
  List* list = createList();
  int cont = 1;
  for(int i=0;i<9;i++)
    for(int j=0;j<9;j++)
      {
        if(n->sudo[i][j] == 0)
        {
          Node *nodo = copy(n);

          for(int k=0;k<9;k++)
            {for(int m = 0; m < 9; m++)
              {
                if(nodo->sudo[k][m] == 0)
                {
                    nodo->sudo[k][m] = cont;    
                    break;
                }
                if(cont == 9)  
                  return list;
              }
              break;
            }
          if(nodo != NULL && is_valid(nodo) == 1)
            pushBack(list, nodo);
          cont++;
          break;
        }
      }
  return list;
}

int is_final(Node* n){
  for(int i = 0; i < 9; i++)
      for(int j = 0; j < 9; j++)
          if(n->sudo[i][j] == 0)
            return 0;
  return 1;
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