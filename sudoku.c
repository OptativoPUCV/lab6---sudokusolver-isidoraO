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

  for(int i = 0; i < 9; i++)
  {
    for(int i = 0; i < 10 ; i++)
      {
        aux_array_fila[i] = 0;
        aux_array_col[i] = 0;
        aux_array_submatriz[i] = 0;
      }

    for(int j = 0; j < 9; j++)
      {
        if((n->sudo[i][j] != 0) && (aux_array_fila[n->sudo[i][j]] == 0))
          aux_array_fila[n->sudo[i][j]] = 1;
        else if(aux_array_fila[n->sudo[i][j]] == 1)
          return 0;
        if((n->sudo[j][i] != 0) && (aux_array_col[n->sudo[j][i]] == 0))
          aux_array_col[n->sudo[j][i]] = 1;
        else if(aux_array_col[n->sudo[j][i]] == 1)
          return 0;
      }
    for(int k = 0; k < 9; k++)
      {
        int p = 3*(i/3) + (k/3);
        int t = 3*(i%3) + (k%3);

        if((n->sudo[p][t] != 0) && (aux_array_submatriz[n->sudo[p][t]] == 0))
          aux_array_submatriz[n->sudo[p][t]] = 1;
        else if(aux_array_submatriz[n->sudo[p][t]] == 1)
          return 0;
      }
  }
  return 1;
}

List* get_adj_nodes(Node* n)
{
  List* list = createList();
  int is_blank = 0;

  for(int cont = 1; cont < 10; cont++)
        for(int i = 0; i < 9; i++)
        {
          for(int j = 0; j < 9 ; j++)
              if(n->sudo[i][j] == 0)
              {
                Node* new_node = copy(n);
                new_node->sudo[i][j] = cont;
                is_blank = 1;
                if(is_valid(new_node))
                  pushBack(list, new_node);
                break;
              }
          if(is_blank)
          {
            is_blank = 0;
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
  Stack *stack = createStack();
  
  push(stack, initial);
  while(is_empty(stack) == 0)
    {
      Node *n = top(stack);
      pop(stack);
      if(is_final(n))
        return n;
      List *adj_nodes = get_adj_nodes(n);
      Node *aux = first(adj_nodes);
      while(aux != NULL)
        {
          push(stack, aux);
          aux = next(adj_nodes);
        }
      (*cont)++;
      free(n);
    }
  return NULL;
}

/*int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/