
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100
#define RANGE 100
//PROGRAMMATION DEFENSIVE !!!

/*

*/
void print_int_array(int *array, int size){
  int i;
  printf("\n[ ");
  for(i = 0; i < size; i++)
    {printf("%d, ", array[i]);}
  printf("]\n" );
}

int *rand_int_array(int size, int range){
  int *array = malloc(size * sizeof(int));
  if(array == NULL){
    fprintf(stderr, "\n rand_int_array : couldn't allocate array of size %d\n",size );
    return NULL;
  }
  int i;
  for(i = 0; i < size; i++){
    array[i] = rand() % range;
  }
  return array;
}


/*

*/
void swap(int *tab, int index_1, int index_2){
  int tmp = tab[index_1];
  tab[index_1] = tab[index_2];
  tab[index_2] = tmp;
}

/*

*/
int partition(int *tab, int p, int r){
  int x = tab[r];
  int i = p - 1; //-
  int j = p;
  for( ; j < r; j++){
    if(tab[j] <= x){
      i++;
      swap(tab, i, j);
    }
  }
  swap(tab, i + 1, r);
  return i + 1;
}

/*

*/
void quicksort(int *tab, int p, int r){
  if(p < r){
    int q = partition(tab, p, r);
    quicksort(tab, p, q - 1);
    quicksort(tab, q + 1, r);
  }
}


int main() {
  srand(time(NULL));
  //const int size = 10;
  int *array = rand_int_array(SIZE, RANGE);
  print_int_array(array, SIZE);

  fprintf(stderr, "\n Proceed with quicksort\n" );
  quicksort(array, 0, SIZE - 1);
  print_int_array(array, SIZE);
  free(array);
  return 0;
}
