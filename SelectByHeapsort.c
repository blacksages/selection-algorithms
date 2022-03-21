/* ========================================================================= *
 * SelectByHeapsort
 * Implementation of the selection algorithm using heapsort
 * ========================================================================= */

#include <stddef.h>
#include "Select.h"

static void _heap_sort(int* array, size_t length);
static void _build_max_heap(int* array, size_t length);
static void _max_heapify(int* array, size_t length, size_t i);
static size_t _left(size_t i) { return 2*i + 1; }
static size_t _right(size_t i) { return 2*i + 2; }
static void _swap(int *array, size_t index_1, size_t index_2);

int select(int* array, size_t length, size_t k)
{
    _heap_sort(array, length);
    return array[k];
}

static void _heap_sort(int* array, size_t length)
{
    _build_max_heap(array, length);
    for(int i = length - 1; i >= 1; i--)
    {
        _swap(array, i, 0);
        _max_heapify(array, i - 1, 0);
    }
}

static void _build_max_heap(int* array, size_t length)
{
    for(int i = length/2; i >= 0; i--)
        _max_heapify(array, length, i);
}

static void _max_heapify(int* array, size_t length, size_t i)
{
    size_t l, r, largest;
    size_t is_looping = 1;
    while(is_looping)
    {
        is_looping = 0;
        l = _left(i);
        r = _right(i);
        if(l < length && array[l] > array[i])
            largest = l;
        else
            largest = i;
        if(r < length && array[r] > array[largest])
            largest = r;
        if(largest != i)
        {
            _swap(array, i, largest);
            i = largest;
            is_looping = 1;
        }
    }
}

static void _swap(int *array, size_t index_1, size_t index_2)
{
    size_t tmp = array[index_1];
    array[index_1] = array[index_2];
    array[index_2] = tmp;
}