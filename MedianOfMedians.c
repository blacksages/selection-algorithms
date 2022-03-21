/* ========================================================================= *
 * MedianOfMedians
 * Implementation of the median of medians selection algorithm
 * ========================================================================= */

#include <stddef.h>
#include "Select.h"

static int _median_of_medians_select(int *array, int p, int r, int k);
static int _median_of_medians(int *array, int len);
static int _partition(int *array, int p, int r);
static void _swap(int *array, int index_1, int index_2);
static void _insertion_sort(int *a, int length);

int select(int *array, size_t length, size_t k)
{
    return _median_of_medians_select(array, 0, length - 1, k);
}

static int _median_of_medians_select(int *array, int p, int r, int k)
{
    if (p <= r)
    {
        int q = _partition(array, p, r);
        if (k == q)
            return array[q];
        if (k < q) // Left
            return _median_of_medians_select(array, p, q - 1, k);
        if (k > q) // Right
            return _median_of_medians_select(array, q + 1, r, k);
    }
    return -1;
}

static int _partition(int *array, int p, int r)
{
    int x = _median_of_medians(array + p, r - p + 1);
    _swap(array, p, r);
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (array[j] <= x)
        {
            i++;
            _swap(array, i, j);
        }
    }
    _swap(array, i + 1, r);
    return i + 1;
}

static int _median_of_medians(int *array, int len)
{
    int rest, sub_len;
    int n_sublists = len / 5 + (len % 5 ? 1 : 0); // le modulo nous dit si la division est avec reste
    for (int n = 0; n < n_sublists; n++)
    {
        rest = len - (5 + n * 5); // si moins de 5 éléments restants, rest est le nombre qu'il manque (en négatif)
        sub_len = rest < 0 ? 5 + rest : 5;
        _insertion_sort(array + n * 5, sub_len);
        _swap(array, n, n * 5 + sub_len / 2 - (sub_len % 2 ? 0 : 1)); // n blocs, puis l'élément au centre
    }
    if (n_sublists > 1)
        return _median_of_medians(array, n_sublists);
    else
        return array[0];
}

static void _swap(int *array, int index_1, int index_2)
{
    int tmp = array[index_1];
    array[index_1] = array[index_2];
    array[index_2] = tmp;
}

/* Source: Cours de SDA slide 18 */
static void _insertion_sort(int *a, int length)
{
    int key, i, j;
    for (j = 1; j < length; j++)
    {
        key = a[j];
        /* Insère a[j] dans la séquence triée a[0...j-1] */
        i = j - 1;
        while (i >= 0 && a[i] > key)
        {
            a[i + 1] = a[i];
            i = i - 1;
        }
        a[i + 1] = key;
    }
}