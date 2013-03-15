/*
 * Implementation of Counting Sort
 *
 * John Lusby
 *
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void countingSort(int* A, int n) {
    if(n <= 0)
        return; //Invalid Array paramaters

    int *B, *C;
    int max = A[0];
    int i;
    for(i = 0; i < n; i++)
        if(A[i] > max)
            max = A[i];
    B = (int*) malloc(sizeof(int)*n);
    C = (int*) malloc(sizeof(int)*(1+max));
    memset(C,0,sizeof(int)*(1+max));

    for(i = 0; i < n; i++)
        C[A[i]]++;
    for(i = 1; i < max+1; i++)
        C[i] += C[i-1];
    for(i = n-1; i >= 0; i--) {
        B[C[A[i]]-1] = A[i];
        C[A[i]]--;
    }
    memcpy(A, B, sizeof(int)*n);
}
