#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

/*
 * Implimentation of double hashing algorithm
 *
 * John Lusby Friday 15 March
 *
 */

void printHashTable(int* hashTable) {
    for(int i = 0; i < 13; i++) {
        if(hashTable[i] != -1)
            cout << hashTable[i];
        cout << endl;
    }
}

void insertKey(int* hashTable, int key) {
    int hashKey1 = key%13;
    int hashKey2 = 1 + (key%11);
    int index;
    for(int i = 0; i != 13*hashKey2; i += hashKey2) {
        index = (hashKey1 + i)%13;
        if(hashTable[index] == -1) {
            hashTable[index] = key;
            return;
        }
    }
}

void searchKey(int* hashTable, int key) {
    int hashKey1 = key%13;
    int hashKey2 = 1 + (key%11);
    int index;
    for(int i = 0; i != 13*hashKey2; i += hashKey2) {
        index = (hashKey1 + i)%13;
        if(hashTable[index] == key) {
            cout << index << endl;
            return;
        }
    }
    cout << "NOT_FOUND" << endl;
}

void deleteKey(int* hashTable, int key) {
    int hashKey1 = key%13;
    int hashKey2 = 1 + (key%11);
    int index;
    for(int i = 0; i != 13*hashKey2; i += hashKey2) {
        index = (hashKey1 + i)%13;
        if(hashTable[index] == key) {
            hashTable[index] = -1;
            return;
        }
    }
    //not found
}

int main() {
    int* hashTable = new int[13];
    memset(hashTable, -1, 13*sizeof(int));
    int input;
    cin >> input;
    while(input != -1) {
        insertKey(hashTable, input);
        cin >> input;
    }
    printHashTable(hashTable);
    cin >> input;
    while(input != -2) {
        searchKey(hashTable, input);
        cin >> input;
    }
    cin >> input;
    while(input != -3) {
        deleteKey(hashTable, input);
        cin >> input;
    }
    printHashTable(hashTable);
}

