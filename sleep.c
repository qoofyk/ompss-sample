#include <stdio.h>

#define ITERS 10

#pragma omp task
void f( int n ) {
  usleep(100);
  fprintf(stderr,"[%3d]",n);
  usleep(200);
}
int main (int argc, char *argv[] ) {
    for (int i=0; i<ITERS; i++ ) 
        f(i);
#pragma omp taskwait
    fprintf(stderr,"\n");
}
