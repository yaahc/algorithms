#include <iostream>

using namespace std;

int main() {
    int num, target;
    int* list;

    cout << "Input the number of elements" << endl;
    cin >> num;
    cout << "Input the value you're searching for" << endl;
    cin >> target;

    list = new int[num];

    for(int i = 0; i < num; i++)
        cin >> list[i];

    //Start of algorithm
    for(int i = 0; i < num; i++)
        if(list[i] == target) {
            cout << i << endl;
            return i;
        }

    cout << -1 << endl;
    return -1;
}
