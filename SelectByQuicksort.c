/* ========================================================================= *
 * SelectByQuicksort
 * Implementation of the selection algorithm using quicksort
 * ========================================================================= */

#include <stddef.h>
#include "Select.h"

/*

*/

static void swap(int *array, int index_1, int index_2){
  int tmp = array[index_1];
  array[index_1] = array[index_2];
  array[index_2] = tmp;
}

/*

*/
static int partition(int *array, int p, int r){
  int x = array[r];
  int i = p - 1; //-
  int j = p;
  for( ; j < r; j++){
    if(array[j] <= x){
      i++;
      swap(array, i, j);
    }
  }
  swap(array, i + 1, r);
  return i + 1;
}

/*

*/
static void quicksort(int *array, int p, int r){
  if(p < r){
    int q = partition(array, p, r);
    //Left
    quicksort(array, p, q - 1);
    //Right
    quicksort(array, q + 1, r);
  }
}

int select(int* array, size_t length, size_t k)
{
  quicksort(array, 0, length - 1);
  return array[k];
}
