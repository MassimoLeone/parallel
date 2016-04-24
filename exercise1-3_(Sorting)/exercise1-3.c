/* 
 * This program computes a fibonacci sequence in two different
 * approaches: iterative and recursive. It also determines the
 * computing time for each approach.
 * The program computes the sums for fibonacci numbers 'n' in the range
 * 35 <= n <= 45. It prints the fibonacci solutions along with the
 * determined computing times in standard output. 
 * 
 * File Name: exercise1-3.c
 * Author: Maksym Levchenko
 * Date: 09.05.2014
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define FIRST_LIMIT 50000
#define SEC_LIMIT 100000

struct Clocks
{
  clock_t start_CPU, 
          end_CPU,
          total_CPU;
  
  time_t  start_Wall,
          end_Wall,
          total_Wall;
};

void bubbleSort(int*, int);
void selectionSort(int*, int);

int main (void)
{
  struct Clocks bubble_FL, bubble_SL, selection_FL, selection_SL;
  int i;
  int rand_FL_1 [FIRST_LIMIT];
  int rand_FL_2 [FIRST_LIMIT];
  int rand_SL_1 [SEC_LIMIT];
  int rand_SL_2 [SEC_LIMIT];

  srand (time (NULL));
  
  for (i = 0; i < FIRST_LIMIT; i++)      /* initialize array with */
  {                                      /*   random numbers      */ 
    rand_FL_1 [i] = rand ();         
  }

  for (i = 0; i < FIRST_LIMIT; i++)      /* copy initialized array */
  {
    rand_FL_2 [i] = rand_FL_1 [i];
  } 

  for (i = 0; i < SEC_LIMIT; i++)      /* initialize array with */
  {                                      /*   random numbers      */ 
    rand_SL_1 [i] = rand ();         
  }

  for (i = 0; i < SEC_LIMIT; i++)      /* copy initialized array */
  {
    rand_SL_2 [i] = rand_SL_1 [i];
  }
  /* FIRST LIMIT */
  bubble_FL.start_CPU = clock ();
  bubble_FL.start_Wall = time (NULL);
  bubbleSort (rand_FL_1, FIRST_LIMIT);
  bubble_FL.end_CPU = clock ();
  bubble_FL.end_Wall = time (NULL);

  bubble_FL.total_CPU = bubble_FL.end_CPU - bubble_FL.start_CPU;
  bubble_FL.total_Wall = bubble_FL.end_Wall - bubble_FL.start_Wall;

  selection_FL.start_CPU = clock ();
  selection_FL.start_Wall = time (NULL);
  selectionSort (rand_FL_2, FIRST_LIMIT);
  selection_FL.end_CPU = clock ();
  selection_FL.end_Wall = time (NULL);

  selection_FL.total_CPU = selection_FL.end_CPU - selection_FL.start_CPU;
  selection_FL.total_Wall = selection_FL.end_Wall - selection_FL.start_Wall;

  /* SECOND LIMIT */
  bubble_SL.start_CPU = clock ();
  bubble_SL.start_Wall = time (NULL);
  bubbleSort (rand_SL_1, SEC_LIMIT);
  bubble_SL.end_CPU = clock ();
  bubble_SL.end_Wall = time (NULL);

  bubble_SL.total_CPU = bubble_SL.end_CPU - bubble_SL.start_CPU;
  bubble_SL.total_Wall = bubble_SL.end_Wall - bubble_SL.start_Wall;

  selection_SL.start_CPU = clock ();
  selection_SL.start_Wall = time (NULL);
  selectionSort (rand_SL_2, SEC_LIMIT);
  selection_SL.end_CPU = clock ();
  selection_SL.end_Wall = time (NULL);

  selection_SL.total_CPU = (selection_SL.end_CPU - selection_SL.start_CPU);
  selection_SL.total_Wall = selection_SL.end_Wall - selection_SL.start_Wall;

  printf ("Algorithm \t array size \t CPU time \t elapsed time\n");
  printf ("\t \t \t \t (in seconds) \t (in seconds)\n");
  printf ("Bubblesort \t %i \t\t %.3f \t\t %.3f\n", FIRST_LIMIT, (float) bubble_FL.total_CPU / CLOCKS_PER_SEC, (float) bubble_FL.total_Wall);
  printf ("Bubblesort \t %i \t %.3f \t %.3f\n", SEC_LIMIT, (float) bubble_SL.total_CPU / CLOCKS_PER_SEC, (float) bubble_SL.total_Wall);
  printf ("Selection sort \t %i \t\t %.3f \t\t %.3f\n", FIRST_LIMIT, (float) selection_FL.total_CPU / CLOCKS_PER_SEC, (float) selection_FL.total_Wall);
  printf ("Selection sort \t %i \t %.3f \t %.3f\n", SEC_LIMIT, (float) selection_SL.total_CPU / CLOCKS_PER_SEC, (float) selection_SL.total_Wall);

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