#include <iostream>
#include "JLSorts.h"
#include <cmath>

using namespace std;

int main() {
    int num;
    float* list;
    cin >> num;
    while(num != 0) {
        list = new float[num];

        for(int i = 0; i < num; i++)
            cin >> list[i];
        
        /* jlusby_InsertionSort(list, num); */
        /* jlusby_MergeSort(list, 0, num-1); */
        //jlusby_HeapSort(list, num);
        /* jlusby_QuickSort(list, 0, num-1); */
        jlusby_BucketSort(list, num);
        for(int i = 0; i < num; i++)
            cout << list[i] << endl;

        delete[] list;
        cin >> num;
    }

    return 0;
}
