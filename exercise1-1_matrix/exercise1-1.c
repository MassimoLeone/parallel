/*
 * This program multiplies two randomly generated
 * matrices and prints out matrices and the
 * multiplication result. The program multiplies
 * two matrices a[P][Q] and b[Q][R].
 *
 * File:   exercise1-1.c         
 * Author: Maksym Levchenko
 * Date:   25.04.2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define P 1024
#define Q 1024
#define R 1024

typedef struct
{
  clock_t startCPU, endCPU, diffCPU;
  time_t  startWall, endWall, diffWall;
} Clock;

int** init (int rows, int columns);
int** multiplymatrix (int**, int, int, int**, int);
void printOut (int**, int, int, char*);
void freeMemory (int**, int);
void print_time (Clock);

int main (void)
{
  /* master pointers (double pointers) */
  int **first = NULL;
  int **second = NULL;
  int **result = NULL;
  Clock clck;

  clck.startCPU = clock ();
  clck.startWall = time (NULL);

  /* initialize and fill two matrices */
  first = init (P, Q);
  printOut (first, P, Q, "first matrix:\n");
  second = init (Q, R);
  printOut (second, Q, R, "second matrix:\n");

  /* multiplication */
  result = multiplymatrix (first, P, Q, second, R);
  printOut (result, P, R, "the multiplication result:\n");

  /* free up occupied memory */
  freeMemory (first, P);
  freeMemory (second, Q);
  freeMemory (result, P);

  print_time(clck);

  return EXIT_SUCCESS;
}

/* initialize and fill matrix */
int** init (int rows, int columns)
{
  srand ((unsigned) time (NULL));
  int **matrix, i, j;
  matrix = (int **) malloc (sizeof (int*) * rows);

  for (i = 0; i < rows; i++)
  {
    matrix[i] = (int *) malloc (sizeof (int) * columns);
    for (j = 0; j < columns; j++)
    {
      matrix[i][j] = rand() % (rows + columns);
    }
  }

  return matrix;
}

/* multiply two matrices */
int** multiplymatrix (int **matrixFirst, int rowsFirst, int columnsFirst,
                      int **matrixSecond, int columnsSecond)
{
  int **result, sum, i, j, k;
  result = NULL;
  result = init (rowsFirst, columnsSecond);

  sum = 0;
  for (i = 0; i < rowsFirst; i++)
  {
    for (j = 0; j < columnsSecond; j++)
    {
      for (k = 0; k < columnsFirst; k++)
      {
        sum += matrixFirst[i][k] * matrixSecond[k][j];
      }
      result[i][j] = sum;
      sum = 0;
    }
  }

  return result;
}

void printOut (int **matrix, int rows, int columns, char* text)
{
  if(Q > 10)
  {
	  return;
  }

  printf ("%s", text);
  int i, j;
  if (matrix == NULL) return;

  for (i = 0; i < rows; ++i)
  {
    for (j = 0; j < columns; ++j)
    {
      printf (" %i\t", matrix[i][j]);
    }
    printf ("\n");
  }
  printf ("\n");
}

void freeMemory (int **matrix, int rows)
{
  int i;

  for (i = 0; i < rows; i++)
  {
    free (matrix[i]);
  }

  free (matrix);
}

void print_time (Clock clck)
{
  clck.endCPU = clock ();
  clck.endWall = time (NULL);
  clck.diffCPU = clck.endCPU - clck.startCPU;
  clck.diffWall = clck.endWall - clck.startWall;

  printf ("CPU  clock: %ld sec\n", (clck.diffCPU / CLOCKS_PER_SEC));
  printf ("Wall clock: %ld sec\n", clck.diffWall);
  printf ("\n");
}

