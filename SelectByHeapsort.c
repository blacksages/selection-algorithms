/* ========================================================================= *
 * SelectByHeapsort
 * Implementation of the selection algorithm using heapsort
 * ========================================================================= */

#include <stddef.h>
#include <stdio.h>
#include "Select.h"

static int _heap_sort(int* array, size_t length);
static int _build_max_heap(int* array, size_t length);
static int _max_heapify(int* array, size_t length, size_t i);
static size_t _left(size_t i) { return 2*i + 1; }
static size_t _right(size_t i) { return 2*i + 2; }
static int _swap(int *array, size_t length, size_t index_1, size_t index_2);

int select(int* array, size_t length, size_t k)
{
    if(k > length - 1)
        return -1;
    if(_heap_sort(array, length))
        return -1;
    // printf("\n");
    // for(size_t i = 0; i < 20; i++)
    //     printf("%d\n",array[i]);
    return array[k];
}

static int _heap_sort(int* array, size_t length)
{
    _build_max_heap(array, length);
    for(int i = length - 1; i >= 1; i--)
    {
        if(_swap(array, length, i, 0))
            return -1;
        if(_max_heapify(array, i - 1, 0))
            return -1;
    }
    return 0;
}

static int _build_max_heap(int* array, size_t length)
{
    for(int i = length/2; i >= 0; i--)
        if(_max_heapify(array, length, i))
            return -1;
    return 0;
}

static int _max_heapify(int* array, size_t length, size_t i)
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
            if(_swap(array, length, i, largest))
                return -1;
            i = largest;
            is_looping = 1;
        }
    }    
    return 0;
}

static int _swap(int *array, size_t length, size_t index_1, size_t index_2)
{
    if(index_1 > length - 1 || index_2 > length - 1)
        return -1;
    size_t tmp = array[index_1];
    array[index_1] = array[index_2];
    array[index_2] = tmp;
    return 0;
}