#include <iostream>
#include <string>
#include "BST.h"

using namespace std;

/****************************************************************
 * CONSTRUCTOR #1 
 *   Creates an binary tree
 ****************************************************************/
BST::BST() {
}

/****************************************************************
 * DECONSTRUCTOR
 *   Empty constructor
 ****************************************************************/
BST::~BST() {
}

void BST::Insert(string toInsert) {
    Node *curr = root;
    while(curr != NULL) {
        if(toInsert.compare(curr->val) <= 0) { //to insert is <= current node
            if(curr->left == NULL) {
                curr->left = new Node();
                curr->left->val = toInsert;
                /* cout << "inserted in a left branch" << endl; */
                return;
            } else
                curr = curr->left;
        } else {
            if(curr->right == NULL) {
                curr->right = new Node();
                curr->right->val = toInsert;
                /* cout << "inserted in a right branch" << endl; */
                return;
            } else
                curr = curr->right;
        }
    }
    root = new Node();
    root->val = toInsert;
    /* cout << "inserted at root" << endl; */
}

void BST::Delete(string toDelete) {
}

void BST::Transplant(Node *u, Node *v) {
    // Write your codes here
}

Node *BST::Successor(Node *x) {
    // Write your codes here
}

Node *BST::Minimum(Node *x) {
    // Write your codes here
}

Node *BST::Maximum(Node *x) {
    // Write your codes here
}

Node *BST::Search(string toFind) {
    // Write your codes here
}

void BST::Print(string Order) {
    if(Order=="IN")
        InOrder(root);
    else if(Order=="PRE")
        PreOrder(root);
    else if(Order=="POST")
        PostOrder(root);
}

void BST::PreOrder(Node *x) {
    if(x == NULL)
        return;
    cout << x->val << endl;
    PreOrder(x->left);
    PreOrder(x->right);
}

void BST::InOrder(Node *x) {
    if(x == NULL)
        return;
    InOrder(x->left);
    cout << x->val << endl;
    InOrder(x->right);
}

void BST::PostOrder(Node *x) {
    if(x == NULL)
        return;
    PostOrder(x->left);
    PostOrder(x->right);
    cout << x->val << endl;
}
