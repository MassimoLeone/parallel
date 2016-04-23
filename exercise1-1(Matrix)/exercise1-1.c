/* 
 * This programm multiplies two randomly generated
 * matrices and prints out matrices and the
 * multiplication result.
 * 
 * File: exercise1-1.c         Author: Maksym Levchenko
 * Date: 25.04.2016            Version: 1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define P 4
#define Q 6
#define R 8

int **initMatrix (const int rows, const int columns);
void freeMatrix (int **Matrix, const int rows);
int **multiplyMatrix (int **matrixFirst, const int rowsFirst,
                      const int columnsFirst, int **matrixSecond,
                      const int columnsSecond);
void printMatrix(int **Matrix, const int rows, const int columns);

int main (void)
{
  int **a = NULL;
  int **b = NULL;
  int **c = NULL;

  /* initialize and fill two matrices */
  a = initMatrix (P, Q);
  b = initMatrix (Q, R);

  /* multiply the two matrices */
  c = multiplyMatrix (a, P, Q, b, R);

  printMatrix (a, P, Q);
  printMatrix (b, Q, R);
  printMatrix (c, P, R);

  freeMatrix (a, P);
  freeMatrix (b, Q);
  freeMatrix (c, P);

  return EXIT_SUCCESS;
}

/* initialize and fill matrix */
int **initMatrix (const int rows, const int columns)
{
  srand ((unsigned) time (NULL));
  int **Matrix, i, j;
  Matrix = (int **) malloc (sizeof (int *) * rows);
  
  for (i = 0; i < rows; i++)
  {
    Matrix[i] = (int *) malloc (sizeof (int) * columns);
    for (j = 0; j < columns; j++)
      Matrix[i][j] = rand() % (rows + columns);       
  }

  return Matrix;
}

void freeMatrix (int **Matrix, const int rows){
  int i;

  for (i = 0; i < rows; i++) {
    free (Matrix[i]);
  }
  
  free (Matrix);
}

/* multiply two matrices */
int **multiplyMatrix (int **matrixFirst, const int rowsFirst,
                      const int columnsFirst, int **matrixSecond,
                      const int columnsSecond){
    
  int **result, sum, i, j, k;
  result = NULL;
  result = initMatrix (rowsFirst, columnsSecond);
  
  sum = 0;
  for (i = 0; i < rowsFirst; i++) {
    for (j = 0; j < columnsSecond; j++) {
      for (k = 0; k < columnsFirst; k++) {
        sum += matrixFirst[i][k] * matrixSecond[k][j];
      }
      result[i][j] = sum;
      sum = 0;
    }
  }

  return result;
}

/* print matrix for debugging reasons */
void printMatrix (int **Matrix, const int rows, const int columns) {
  int i, j;
  if (Matrix == NULL) return;

  printf ("Matrix: \n");
  for (i = 0; i < rows; ++i) {
    for (j = 0; j < columns; ++j) {
      printf (" %i\t", Matrix[i][j]);
    }
    printf ("\n");
  }
}
