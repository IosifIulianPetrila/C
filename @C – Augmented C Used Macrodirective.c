// Testing whether a C language parameter has been used
// See @C – augmented version of C programming language

#include <stdio.h>

#ifndef __augmented
#error This compiler has no augmented C features
#endif

void MyProcedure();              // Declaration

int main(void)
{
  // Uncomment next lines to use MyProcedure
  MyProcedure();                 // Used
  // void (*P)() = &MyProcedure; // Also Used

  #if used MyProcedure
    printf("MyProcedure is used!\n");
  #endif

  return 0;
}

//Include MyProcedure code only if it was used
#if used MyProcedure
void MyProcedure(){/* .. */}
#endif
