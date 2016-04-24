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

#define LIMIT_50K  50
#define LIMIT_100K 100

typedef struct
{
  clock_t start_CPU,
          end_CPU,
          total_CPU;

  time_t  start_Wall,
          end_Wall,
          total_Wall;
}Clock;

void bubbleSort(int*, int);
void selectionSort(int*, int);

int main (void)
{
  Clock bubble_FL, bubble_SL, selection_FL, selection_SL;
  int i;
  int rand_FL_1 [LIMIT_50K];
  int rand_FL_2 [LIMIT_50K];
  int rand_SL_1 [LIMIT_100K];
  int rand_SL_2 [LIMIT_100K];

  srand (time (NULL));

  for (i = 0; i < LIMIT_50K; i++)      /* initialize array with */
  {                                      /*   random numbers      */
    rand_FL_1 [i] = rand ();
  }

  for (i = 0; i < LIMIT_50K; i++)      /* copy initialized array */
  {
    rand_FL_2 [i] = rand_FL_1 [i];
  }

  for (i = 0; i < LIMIT_100K; i++)      /* initialize array with */
  {                                      /*   random numbers      */
    rand_SL_1 [i] = rand ();
  }

  for (i = 0; i < LIMIT_100K; i++)      /* copy initialized array */
  {
    rand_SL_2 [i] = rand_SL_1 [i];
  }
  /* FIRST LIMIT */
  bubble_FL.start_CPU = clock ();
  bubble_FL.start_Wall = time (NULL);
  bubbleSort (rand_FL_1, LIMIT_50K);
  bubble_FL.end_CPU = clock ();
  bubble_FL.end_Wall = time (NULL);

  bubble_FL.total_CPU = bubble_FL.end_CPU - bubble_FL.start_CPU;
  bubble_FL.total_Wall = bubble_FL.end_Wall - bubble_FL.start_Wall;

  selection_FL.start_CPU = clock ();
  selection_FL.start_Wall = time (NULL);
  selectionSort (rand_FL_2, LIMIT_50K);
  selection_FL.end_CPU = clock ();
  selection_FL.end_Wall = time (NULL);

  selection_FL.total_CPU = selection_FL.end_CPU - selection_FL.start_CPU;
  selection_FL.total_Wall = selection_FL.end_Wall - selection_FL.start_Wall;

  /* SECOND LIMIT */
  bubble_SL.start_CPU = clock ();
  bubble_SL.start_Wall = time (NULL);
  bubbleSort (rand_SL_1, LIMIT_100K);
  bubble_SL.end_CPU = clock ();
  bubble_SL.end_Wall = time (NULL);

  bubble_SL.total_CPU = bubble_SL.end_CPU - bubble_SL.start_CPU;
  bubble_SL.total_Wall = bubble_SL.end_Wall - bubble_SL.start_Wall;

  selection_SL.start_CPU = clock ();
  selection_SL.start_Wall = time (NULL);
  selectionSort (rand_SL_2, LIMIT_100K);
  selection_SL.end_CPU = clock ();
  selection_SL.end_Wall = time (NULL);

  selection_SL.total_CPU = (selection_SL.end_CPU - selection_SL.start_CPU);
  selection_SL.total_Wall = selection_SL.end_Wall - selection_SL.start_Wall;

  printf ("Algorithm \t array size \t CPU time \t elapsed time\n");
  printf ("\t \t \t \t (in seconds) \t (in seconds)\n");
  printf ("Bubblesort \t %i \t\t %.3f \t\t %.3f\n", LIMIT_50K, (float) bubble_FL.total_CPU / CLOCKS_PER_SEC, (float) bubble_FL.total_Wall);
  printf ("Bubblesort \t %i \t %.3f \t %.3f\n", LIMIT_100K, (float) bubble_SL.total_CPU / CLOCKS_PER_SEC, (float) bubble_SL.total_Wall);
  printf ("Selection sort \t %i \t\t %.3f \t\t %.3f\n", LIMIT_50K, (float) selection_FL.total_CPU / CLOCKS_PER_SEC, (float) selection_FL.total_Wall);
  printf ("Selection sort \t %i \t %.3f \t %.3f\n", LIMIT_100K, (float) selection_SL.total_CPU / CLOCKS_PER_SEC, (float) selection_SL.total_Wall);

  return EXIT_SUCCESS;
}

void bubbleSort (int *array, int length)
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

void selectionSort( int *array, int length) // Anzahl und Array mit Daten
{
  int i, k, t, min; // i ist Kontrollvariable für die innere, k für die äußere Schleife.
                    // t ist Zwischenspeicher beim Tauschen. min merkt sich den kleinsten Wert
                    // im Teilarray.

  for( i = 0; i < length-1; i++)
  {
    min = i;
    for( k = i+1; k < length; k++)
    {
      if( array[k] < array[min])
        min = k;
    }
    t = array[min];  // Tauschen
    array[min] = array[i];
    array[i] = t;
  }
}

