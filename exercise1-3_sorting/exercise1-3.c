/*
 * This program sorts elements of an array with different algorithms.
 * The array is initialized with a random number generator and uses
 * the algorithms "bubblesort" and "selection sort" to sort the array.
 * The program also measures the time needed for the sorting.
 *
 * File:   exercise1-3.c
 * Author: Maksym Levchenko
 * Date:   24.04.2016
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define LIMIT_50K  50000
#define LIMIT_100K 100000

typedef struct
{
  clock_t start_CPU,
          end_CPU,
          total_CPU;

  time_t  start_Wall,
          end_Wall,
          total_Wall;
}Clock;

void copyArray (int*,int*,int);
void initArrayRandom (int*, int);
void bubbleSort(int*, int);
void selectionSort(int*, int);

int main (void)
{
  Clock bubble_50K,
        bubble_100K,
        selection_50K,
        selection_100K;
  int rand_50K_1 [LIMIT_50K];
  int rand_50K_2 [LIMIT_50K];
  int rand_100K_1 [LIMIT_100K];
  int rand_100K_2 [LIMIT_100K];

  srand (time (NULL));

  initArrayRandom(rand_50K_1, LIMIT_50K);
  copyArray(rand_50K_2, rand_50K_1, LIMIT_50K);
  initArrayRandom(rand_100K_1, LIMIT_100K);
  copyArray(rand_100K_2, rand_100K_1, LIMIT_100K);

  printf ("Algorithm \t array size \t CPU time \t elapsed time\n");
  printf ("\t \t \t \t (in seconds) \t (in seconds)\n");

  /* 50K LIMIT */
  bubble_50K.start_CPU = clock ();
  bubble_50K.start_Wall = time (NULL);
  bubbleSort (rand_50K_1, LIMIT_50K);
  bubble_50K.end_CPU = clock ();
  bubble_50K.end_Wall = time (NULL);

  bubble_50K.total_CPU = bubble_50K.end_CPU - bubble_50K.start_CPU;
  bubble_50K.total_Wall = bubble_50K.end_Wall - bubble_50K.start_Wall;
  printf ("Bubblesort \t %i \t\t %.3f \t\t %.3f\n", LIMIT_50K, (float) bubble_50K.total_CPU / CLOCKS_PER_SEC, (float) bubble_50K.total_Wall);

  selection_50K.start_CPU = clock ();
  selection_50K.start_Wall = time (NULL);
  selectionSort (rand_50K_2, LIMIT_50K);
  selection_50K.end_CPU = clock ();
  selection_50K.end_Wall = time (NULL);

  selection_50K.total_CPU = selection_50K.end_CPU - selection_50K.start_CPU;
  selection_50K.total_Wall = selection_50K.end_Wall - selection_50K.start_Wall;
  printf ("Selection sort \t %i \t\t %.3f \t\t %.3f\n", LIMIT_50K, (float) selection_50K.total_CPU / CLOCKS_PER_SEC, (float) selection_50K.total_Wall);

  /* 100K LIMIT */
  bubble_100K.start_CPU = clock ();
  bubble_100K.start_Wall = time (NULL);
  bubbleSort (rand_100K_1, LIMIT_100K);
  bubble_100K.end_CPU = clock ();
  bubble_100K.end_Wall = time (NULL);

  bubble_100K.total_CPU = bubble_100K.end_CPU - bubble_100K.start_CPU;
  bubble_100K.total_Wall = bubble_100K.end_Wall - bubble_100K.start_Wall;
  printf ("Bubblesort \t %i \t %.3f \t %.3f\n", LIMIT_100K, (float) bubble_100K.total_CPU / CLOCKS_PER_SEC, (float) bubble_100K.total_Wall);

  selection_100K.start_CPU = clock ();
  selection_100K.start_Wall = time (NULL);
  selectionSort (rand_100K_2, LIMIT_100K);
  selection_100K.end_CPU = clock ();
  selection_100K.end_Wall = time (NULL);

  selection_100K.total_CPU = (selection_100K.end_CPU - selection_100K.start_CPU);
  selection_100K.total_Wall = selection_100K.end_Wall - selection_100K.start_Wall;
  printf ("Selection sort \t %i \t %.3f \t %.3f\n", LIMIT_100K, (float) selection_100K.total_CPU / CLOCKS_PER_SEC, (float) selection_100K.total_Wall);

  return EXIT_SUCCESS;
}

void initArrayRandom (int* array, int length)
{
  int i = 0;
  for (i = 0; i < length; i++)
  {
    array [i] = rand ();
  }
}

void copyArray(int* a, int* b, int limit)
{
  int i;
  for (i = 0; i < limit; i++)
  {
    a[i] = b[i];
  }
}

void bubbleSort (int* array, int length)
{
  int i, j;
  for (i = 0; i < length -1; ++i)
  {
    for (j = 0; j < length - i - 1; ++j)
    {
      if (array[j] > array[j + 1])
      {
        int tmp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = tmp;
      }
    }
  }
}

void selectionSort( int *array, int length)
{
  int outside,
      inside,
      tmp,
      min;

  for(outside = 0; outside < length-1; outside++)
  {
    min = outside;
    for( inside = outside+1; inside < length; inside++)
    {
      if(array[inside] < array[min])
      {
        min = inside;
      }
    }
    tmp = array[min];  // exchange
    array[min] = array[outside];
    array[outside] = tmp;
  }
}

