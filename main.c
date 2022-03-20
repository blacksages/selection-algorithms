#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Array.h"
#include "Select.h"

static const size_t ARRAY_LENGTH = 10000;
static const size_t ELEMENT_IDX =   ARRAY_LENGTH / 10;

/* Prototypes */

/* ------------------------------------------------------------------------- *
 * Compute the CPU time (in seconds) used by the Sort function.
 *
 * PARAMETERS
 * array        Array to sort
 * length       Number of elements in the array
 *
 * RETURN
 * seconds      The number of seconds used by Sort
 * ------------------------------------------------------------------------- */
static double cpuTimeUsedToSelect(int* array, size_t length, size_t k)
{
    clock_t start = clock();
    select(array, length, k);
    return ((double) (clock() - start)) / CLOCKS_PER_SEC;
}

/**
 * Basic tests
 */
static void basicTest() {
    int* array = (int*) malloc(ARRAY_LENGTH * sizeof(int));
    for (size_t i = 0; i < ARRAY_LENGTH; i++)
        array[i] = i;

    if(select(array, ARRAY_LENGTH, 10) != 10)
        printf("INVALID\n");
    if(select(array, ARRAY_LENGTH, 100) != 100)
        printf("INVALID\n");
    if(select(array, ARRAY_LENGTH, 1000) != 1000)
        printf("INVALID\n");

    for (size_t i = 0; i < ARRAY_LENGTH; i++)
        array[i] = ARRAY_LENGTH-i-1;

    if(select(array, ARRAY_LENGTH, 10) != 10)
        printf("INVALID\n");
    if(select(array, ARRAY_LENGTH, 100) != 100)
        printf("INVALID\n");
    if(select(array, ARRAY_LENGTH, 1000) != 1000)
        printf("INVALID\n");

    free(array);
}

/* ------------------------------------------------------------------------- *
 * Main
 * ------------------------------------------------------------------------- */
int main(void)
{
    int *result = fopen("result.txt", "a");
    basicTest();
    srand(time(NULL));//Use an integer seed to get a fix sequence

    /*
    printf("Times to find element %zu for arrays of size %zu\n", ELEMENT_IDX, ARRAY_LENGTH);
    printf("-----------------------------\n");
    printf("Array type | Sorting time [s]\n");
    printf("-----------------------------\n");
    */
    // ---------------------------- Sorted array ---------------------------- //
    int* sorted = createSortedArray(ARRAY_LENGTH);
    if (!sorted)
    {
        fprintf(stderr, "Could not created sorted array. Aborting...\n");
        return EXIT_FAILURE;
    }

    double sec = cpuTimeUsedToSelect(sorted, ARRAY_LENGTH, ELEMENT_IDX);
    fprintf(result, "%f ",sec );
    //printf("Sorted     | %f\n", sec);
    free(sorted);

    // -------------------------- Decreasing array -------------------------- //
    int* decreasing = createDecreasingArray(ARRAY_LENGTH);
    if (!decreasing)
    {
        fprintf(stderr, "Could not created decreasing array. Aborting...\n");
        return EXIT_FAILURE;
    }

    sec = cpuTimeUsedToSelect(decreasing, ARRAY_LENGTH, ELEMENT_IDX);
    fprintf(result, "%f ",sec );
    //printf("Decreasing | %f\n", sec);
    free(decreasing);

    // ---------------------------- Random array ---------------------------- //
    int* random = createRandomArray(ARRAY_LENGTH);
    if (!random)
    {
        fprintf(stderr, "Could not created random array. Aborting...\n");
        return EXIT_FAILURE;
    }

    sec = cpuTimeUsedToSelect(random, ARRAY_LENGTH, ELEMENT_IDX);
    fprintf(result, "%f ",sec );
    //printf("Random     | %f\n", sec);
    free(random);

    //fprintf(result, "\n" );
    fclose(result);
    //printf("-----------------------------\n");

    return EXIT_SUCCESS;
}
