#include <iostream>
#include "JLSorts.h"

using namespace std;

int main() {
    int num;
    int* list;
    cin >> num;
    while(num != 0) {
        list = new int[num];

        for(int i = 0; i < num; i++)
            cin >> list[i];
        
        /* jlusby_InsertionSort(list, num); */
        /* jlusby_MergeSort(list, 0, num-1); */
        jlusby_HeapSort(list, num);

        for(int i = 0; i < num; i++)
            cout << list[i] << endl;

        delete[] list;
        cin >> num;
    }

    return 0;
}
