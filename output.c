/*
 * Description:
 *
 * First created: 2018 Aug 01
 * Last modified: 2018 Aug 01
 *
 * Author: Yuankun Fu
 * e-mail: qoofyk@gmail.com
 */

#include <stdio.h>

#define N 10

int main (int argc, char* argv[]){
    int a[N];

    for(int i=0; i<N; ++i) {
#pragma omp task out(a[i]) label(init) firstprivate(i) 
        a[i]=0;
    }

    for(int i=0; i<N; ++i) {
#pragma omp task inout(a[i]) label(inc) firstprivate(i) 
        a[i]++;
    }

#pragma omp taskwait
    for(int i=0; i<N; ++i) { 
        printf("%d,",a[i]);
    }
}    
