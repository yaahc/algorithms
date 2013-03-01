#include <stdlib.h>
#include <string.h>

using namespace std;

void jlusby_InsertionSort(int * A, int n);
void jlusby_MergeSort(int * A, int p, int r);
void jlusby_Merge(int * A, int p, int q, int r);


void jlusby_InsertionSort(int * A, int n) {
    for(int i = 1; i < n; i++) {
        int insertVal = A[i];
        int j=i;
        while(j > 0 && insertVal < A[j-1]) {
            A[j] = A[j-1];
            j--;
        }
        A[j] = insertVal;
    }
}

void jlusby_MergeSort(int * A, int p, int r) {
    if(r > p) {
        int q = (p+r)/2;
        jlusby_MergeSort(A, p, q);
        jlusby_MergeSort(A, q+1, r);
        jlusby_Merge(A,p,q,r);
    }
}

void jlusby_Merge(int * A, int p, int q, int r) {
    /* Merge Function */
    int * temp = new int[r-p+1];
    int i = p, j=q+1, k=0;

    while(i < q+1 && j < r+1)
        temp[k++] = (A[i] <= A[j]) ? A[i++] : A[j++];

    while(i < q+1)
        temp[k++] = A[i++];

    while(j < r+1)
        temp[k++] = A[j++];

    memcpy(&A[p], temp, (r-p+1)*sizeof(int));
    delete[] temp;
}
