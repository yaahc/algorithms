#include <iostream>
#include <stdlib.h>
#include "BST.h"

using namespace std;

int main(int argc,char **argv)
{
    // Create an empty Binary Search Tree
    BST Tree;
    string input;
    cin >> input;
    while(input != "ENDINSERT") {
        //cout << "got here" << endl;
        Tree.Insert(input);
        cin >> input;
    }
    //cout << "done inserting" << endl;
    Tree.Print("POST");
}
