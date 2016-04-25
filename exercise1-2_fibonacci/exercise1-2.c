/*
 * This program computes a Fibonacci sequence in two different
 * fashions: iterative and recursive. It also determines the
 * needed time for each approach.
 *
 * File:   exercise1-2.c
 * Author: Maksym Levchenko
 * Date:   24.04.2016
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define F0 0
#define F1 1
#define MIN 35
#define MAX 45

typedef struct
{
  clock_t startCPU, endCPU, diffCPU;
  time_t  startWall, endWall, diffWall;
}Clock;


long long fibonacci_iterative (int);
long long fibonacci_recursive (int);
void print_time (Clock);

int main (void)
{
  long long sum;
  Clock iter,recur;
  int i;

  /* Iterative Fibonacci sequence */
  printf ("Iterative: ");

  iter.startCPU = clock ();
  iter.startWall = time (NULL);

  sum = 0;
  for (i = MIN; i <= MAX; i++)
  {
    sum = sum + fibonacci_iterative (i);
  }
  printf ("%lld \n", sum);
  print_time (iter);

  /* Recursive Fibonacci sequence */
  printf ("Recursive: ");
  recur.startCPU  = clock ();
  recur.startWall = time (NULL);

  sum = 0;
  i = MIN;
  while (i <= MAX)
  {
    sum = sum + fibonacci_recursive (i);
    i++;
  }
  printf ("%lld \n", sum);
  print_time (recur);

  return EXIT_SUCCESS;
}

long long fibonacci_iterative (int n)
{
  long long first;
  long long second;
  long long next;
  int i;

  if (n <= 1)
  {
    return 0;
  }

  first = F0;
  second = F1;
  next = 0;

  if (n == 2)
  {
    return second;
  }

  for (i = 3; i <= n; i++)
  {
    next = first + second;
    first  = second;
    second = next;
  }

  return next;
}

long long fibonacci_recursive (int n)
{
  if (n <= 1)
  {
    return n;
  }

  return fibonacci_recursive (n - 1) + fibonacci_recursive (n - 2);
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

