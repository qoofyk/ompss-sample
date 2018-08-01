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

int main(int argc, char *argv[]) {
    int x = argc;
#pragma omp task inout(x)                                                                                                    
    {   
        x++;
    }
#pragma omp task in(x)
    {   
        printf("argc + 1 == %d\n", x);
    }
#pragma omp taskwait
    return 0;
}

