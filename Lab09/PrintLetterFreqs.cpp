#include <iostream>
#include <vector>
#include "BST.h"

using namespace std;

Node* pop_min(vector<Node*> & rootNodes) {
    int min = 0;
    for(int i = 0; i < rootNodes.size(); i++) {
        if(rootNodes[i]->Frequency < rootNodes[min]->Frequency)
            min = i;
    }
    Node* minNode = rootNodes[min];
    rootNodes.erase(rootNodes.begin()+min);
    return minNode;
}

void huffman_code_print(Node* root, string code, string * codes) {
    if(root->Letter == '\0') {
        huffman_code_print(root->left, code+"0", codes);
        huffman_code_print(root->right, code+"1", codes);
    } else {
        codes[root->Letter-65] = code;
    }
}

int main() {
    int letters[6];
    for(int i = 0; i < 6; i++) {
        letters[i] = 0;
    }
    char curr;
    cin >> curr;
    while(curr != 'Z') {
        letters[curr-65]++;
        cin >> curr;
    }

    vector<Node*> nodesVector(6);
    for(int i = 0; i < 6; i++) {
        nodesVector[i] = new Node();
        nodesVector[i]->Frequency = letters[i];
        nodesVector[i]->Letter = i+65;
        nodesVector[i]->left = NULL;
        nodesVector[i]->right = NULL;
        nodesVector[i]->parent = NULL;
    }

    while(nodesVector.size() > 1) {
        Node* leftSide = pop_min(nodesVector);
        Node* rightSide = pop_min(nodesVector);
        Node* newRoot = new Node();
        newRoot->Frequency = rightSide->Frequency + leftSide->Frequency;
        newRoot->Letter = '\0';
        newRoot->left = leftSide;
        newRoot->right = rightSide;
        newRoot->parent = NULL;
        leftSide->parent = newRoot;
        rightSide->parent = newRoot;
        nodesVector.push_back(newRoot);
    }

    BST *huffmanTree = new BST(nodesVector[0]);
    huffmanTree->PrintLetterFreqs();
    //string *codes = new string[6];
    //huffman_code_print(nodesVector[0], "", codes);
    //for(int i = 0; i < 6; i++) {
        //cout << (char)(i+65) << " " << codes[i] << endl;
    //}
    //for(int i = 0; i < 6; i++) {
        //cout << letters[i] << " ";
    //}
    //cout << endl;
    return 0;
}
