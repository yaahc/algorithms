#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

void jlusby_InsertionSort(int* A, int n);
void jlusby_MergeSort(int* A, int p, int r);
void jlusby_Merge(int* A, int p, int q, int r);
void jlusby_HeapSort(int* A, int count);
void max_heap(int* A, int count);
int sift_down(int* A, int root, int end);
void jlusby_QuickSort(int* A, int count);


void swap(int* A, int index1, int index2) { 
   int temp = A[index1];
   A[index1] = A[index2];
   A[index2] = temp;
}

void fancy_heap_print(int* A, int count) {
    int i = 0, perrow = 1;
    while(i < count) {
        for(int j = 0; j < perrow && i < count; j++, i++) {
            cout << A[i] << " ";
        }
        perrow *= 2;
        cout << endl;
    }
}

void jlusby_HeapSort(int* A, int count) {
    max_heap(A, count);

    /* fancy_heap_print(A, count); */

    int end = count-1;
    while(end > 0) {
        swap(A, end, 0);
        end--;
        sift_down(A, 0, end);
    }
    /* fancy_heap_print(A, count); */
}

void max_heap(int* A, int count) {
    int curr = (count - 2) / 2;

    while(curr >= 0) {
        sift_down(A, curr, count-1);
        curr--;
    }
}

int sift_down(int* A, int root, int end) {
    while(2*root+1 <= end) {
        /* cout << "got here root:" << root << endl; */
        int swap = root;
        int child = 2*root+1;
        swap = (A[child] > A[swap]) ? child : swap;
        if(child+1 <= end)
            swap = (A[child+1] > A[swap]) ? child+1 : swap;
        if(swap != root) {
            /* cout << "swapping " << swap << " and " << root << endl; */
            int temp = A[swap];
            A[swap] = A[root];
            A[root] = temp;
            root = swap;
        } else
            return 0;
    }
    return 0;
}

void jlusby_InsertionSort(int* A, int n) {
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

void jlusby_MergeSort(int* A, int p, int r) {
    if(r > p) {
        int q = (p+r)/2;
        jlusby_MergeSort(A, p, q);
        jlusby_MergeSort(A, q+1, r);
        jlusby_Merge(A,p,q,r);
    }
}

void jlusby_Merge(int* A, int p, int q, int r) {
    /* Merge Function */
    int* temp = new int[r-p+1];
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
