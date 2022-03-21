/* ========================================================================= *
 * QuickSelect
 * Implementation of the QuickSelect algorithm
 * ========================================================================= */

#include <stddef.h>
#include "Select.h"

static void swap(int *array, int index_1, int index_2)
{
  int tmp = array[index_1];
  array[index_1] = array[index_2];
  array[index_2] = tmp;
}

/*

*/
static int partition(int *array, int p, int r)
{
  int x = array[r];
  int i = p - 1; //-
  int j = p;
  for (; j < r; j++)
  {
    if (array[j] <= x)
    {
      i++;
      swap(array, i, j);
    }
  }
  swap(array, i + 1, r);
  return i + 1;
}

/*

*/
static int quickselect(int *array, int p, int r, int k)
{
  if (p < r)
  {
    int q = partition(array, p, r);
    if (k == q)
    {
      return array[q];
    }
    if (k < q)
    {
      // Left
      return quickselect(array, p, q - 1, k);
    }
    if (k > q)
    {
      // Right
      return quickselect(array, q + 1, r, k);
    }
  }
  return -1;
}

int select(int *array, size_t length, size_t k)
{
  return quickselect(array, 0, length - 1, k);
}
