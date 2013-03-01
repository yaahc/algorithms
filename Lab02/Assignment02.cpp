#include <iostream>
#include <sys/time.h>
#include "Search.cpp"

using namespace std;

int main() {
    int num, target;
    int* list;
    struct timezone whatever;
    cin >> num;
    while(num != 0) {
        cin >> target;

        list = new int[num];

        for(int i = 0; i < num; i++)
            cin >> list[i];
  
        struct timeval time1, time2;

        gettimeofday(&time1, NULL);
        int answer = binarySearch(list, 0, num-1, target);
        //int answer = linearSearch(list, num, target); 
        gettimeofday(&time2, NULL);
    
        cerr << time2.tv_usec << " - " << time1.tv_usec << " = " << time2.tv_usec - time1.tv_usec <<  endl;

        cout << answer << endl;

        delete[] list;
        cin >> num;
    }

    return 0;
}
