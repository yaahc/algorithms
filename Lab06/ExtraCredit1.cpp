#include <iostream>
#include "CountingSort.h"
#include <cmath>

using namespace std;

int main() {
    int num;
    int* list;
    cin >> num;
    while(num != 0) {
        list = new int[num];

        for(int i = 0; i < num; i++)
            cin >> list[i];
        
        countingSort(list, num);
        for(int i = 0; i < num; i++)
            cout << list[i] << endl;

        delete[] list;
        cin >> num;
    }

    return 0;
}
