#include <iostream>
#include <cmath>
#include <list>

using namespace std;


void printHashTable(list<int>* hashTable, int size) {
    for(int i = 0; i < size; i++) {
        for(list<int>::iterator it=hashTable[i].begin(); it != hashTable[i].end(); ++it) {
            cout << *it << "->";
        }
        cout << endl;
    }
}

void insertKey(list<int>* hashTable, int key, int size) {
    hashTable[key%size].push_front(key);
}

void searchKey(list<int>* hashTable, int key, int size) {
    int index = key%size;
    int listIndex = 0;
    for(list<int>::iterator it=hashTable[index].begin(); it != hashTable[index].end(); ++it, listIndex++) {
        if(*it == key) {
            cout << index << "," << listIndex << endl;
            return;
        }
    }
    cout << "NOT_FOUND" << endl;
}

void deleteKey(list<int>* hashTable, int key, int size) {
    hashTable[key%size].remove(key);
}


int main() {
    list<int>* hashTable;
    int hashSize;
    cin >> hashSize;
    if(hashSize != 0) {
        hashTable = new list<int>[hashSize];
        int input;
        cin >> input;
        while(input != -1) {
            insertKey(hashTable, input, hashSize);
            cin >> input;
        }
        printHashTable(hashTable, hashSize);
        cin >> input;
        while(input != -2) {
            searchKey(hashTable, input, hashSize);
            cin >> input;
        }
        cin >> input;
        while(input != -3) {
            deleteKey(hashTable, input, hashSize);
            cin >> input;
        }
        printHashTable(hashTable, hashSize);
    }
}

