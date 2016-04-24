/* This program computes a fibonacci sequence in two different
 * approaches: iterative and recursive. It also determines the
 * computing time for each approach.
 * The program computes the sums for fibonacci numbers 'n' in the range
 * 35 <= n <= 45. It prints the fibonacci solutions along with the
 * determined computing times in standard output. 
 * 
 * File Name: exercise1-2.c        Author: Juergen Goebel
 * Date: 05.05.2015
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define F0 0
#define F1 1
#define MIN 35
#define MAX 45

struct Clock
{
  clock_t startCPU, endCPU, diffCPU;
  time_t  startWall, endWall, diffWall;
};


long long fibonacci_iterative (int);
long long fibonacci_recursive (int);
void print_time (struct Clock);

int main (void)
{
  long long sum;
  struct Clock iter,recur;
  int i;

  /* Start block for Iterative Fibonacci */
  printf ("\x1b[1;4mIterative\x1b[0m \n");
  
  iter.startCPU = clock ();
  iter.startWall = time (NULL);
  
  /* computes and prints all sums in
   * range with MIN and MAX boundaries
   */
  sum = 0;
  for (i = MIN; i <= MAX; i++)
  {
    sum = sum + fibonacci_iterative (i);
  }
  printf ("%lld \n", sum);   
  
  iter.endCPU   = clock ();
  iter.endWall  = time (NULL);
  iter.diffCPU  = iter.endCPU - iter.startCPU;
  iter.diffWall = iter.endWall - iter.startWall;

  print_time (iter);
  /* End block for Iterative Fibonacci */
  
  /* Start block for Recursive Fibonacci */
  printf ("\x1b[1;4mRecursive\x1b[0m \n");
  recur.startCPU  = clock ();
  recur.startWall = time (NULL);

  sum = 0;
  for (i = MIN; i <= MAX; i++)
  {
    sum = sum + fibonacci_recursive (i);
  }
  printf ("%lld \n", sum);   

  recur.endCPU = clock ();
  recur.endWall = time (NULL);
  recur.diffCPU = recur.endCPU - recur.startCPU;
  recur.diffWall = recur.endWall - recur.startWall;

  print_time (recur);
  /* End block of Recursive Fibonacci */

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
  if (n == 1)
  {
    return 0;
  }
  if (n == 2)
  {
    return 1;
  }

  return fibonacci_recursive (n - 1) + fibonacci_recursive (n - 2);
}

void print_time (struct Clock clck) {
  printf ("\n");
  printf ("\x1b[1mCPU  clock:\x1b[0m \t %ld sec\n", (clck.diffCPU / CLOCKS_PER_SEC));
  printf ("\x1b[1mWall clock:\x1b[0m \t %ld sec\n", clck.diffWall);
  printf ("\n\n");
}
