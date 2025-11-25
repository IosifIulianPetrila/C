// Using parallel directive for parallel tensor calculus in C
// See @C – augmented version of C programming language

#include <stdio.h>

#ifndef __augmented
#warning This compiler has no augmented C features
#define parallel // Sequential fallback execution: same semantics & results 
#endif

#define PROCESS_COUNT 2
#define VECTOR_LENGTH 3

parallel float A[PROCESS_COUNT][VECTOR_LENGTH] = {{0, 1, 2}, {3, 4, 5}};
parallel float B[PROCESS_COUNT][VECTOR_LENGTH] = {{1, 2, 3}, {4, 5, 6}};
parallel float C[PROCESS_COUNT] = {0, 0};

int main(void)
{
  // Example of parallel calculation for vectors dot product
  parallel for(int p = 0; p < PROCESS_COUNT; p++)
  {
    // Here each process computes its own dot product
    for(int i = 0; i < VECTOR_LENGTH; i++)C[p] += A[p][i] * B[p][i];    
  }

  for(int p = 0; p < PROCESS_COUNT; p++)printf("C[%d] = %f\n", p, C[p]);
  
  return 0;
}
