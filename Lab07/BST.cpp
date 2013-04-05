#include <iostream>
#include <string>
#include "BST.h"

using namespace std;

/****************************************************************
 * CONSTRUCTOR #1 
 *   Creates an binary tree
 ****************************************************************/
BST::BST() {
    root = NULL;
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
        //cout << "got here 2" << endl;
        if(toInsert.compare(curr->val) <= 0) { //to insert is <= current node
            if(curr->left == NULL) {
                curr->left = new Node();
                curr->left->val = toInsert;
                curr->left->parent = curr;
                curr->left->left = curr->left->right = NULL;
                /* cout << "inserted in a left branch" << endl; */
                return;
            } else {
                //cout << "got here 5" << endl;
                curr = curr->left;
            }
        } else {
            if(curr->right == NULL) {
                curr->right = new Node();
                curr->right->parent = curr;
                curr->right->left = curr->right->right = NULL;
                curr->right->val = toInsert;
                /* cout << "inserted in a right branch" << endl; */
                return;
            } else { 
                //cout << "got here 4" << curr->right << endl;
                curr = curr->right;
            }
        }
    }
    //cout << "got here 3" << endl;
    root = new Node();
    root->val = toInsert;
    root->left = root->right = root->parent = NULL;
    /* cout << "inserted at root" << endl; */
}

void BST::Delete(string toDelete) {
    Node *z = Search(toDelete);
    if(z == NULL) {
        //cout << "not in tree" << endl;
    } else {
        //remove z
        if(z->left == NULL) {
            Transplant(z, z->right);
            //delete(z);
        } else if(z->right == NULL) {
            Transplant(z, z->left);
            //delete(z);
        } else {
            Node *y = Minimum(z->right);
            if(y->parent != z) {
                Transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            Transplant(z,y);
            y->left = z->left;
            y->left->parent = y;
        }
    }
}

void BST::Transplant(Node *u, Node *v) {
    // Write your codes here
    if(u->parent == NULL) {
        root = v;
    } else if(u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    } if(v != NULL) {
        v->parent = u->parent;
    }
}

Node *BST::Successor(Node *x) {
    // Write your codes here
}

Node *BST::Minimum(Node *x) {
    while(x->left != NULL)
        x = x->left;
    return x;
}

Node *BST::Maximum(Node *x) {
    // Write your codes here
}

Node *BST::Search(string toFind) {
    Node *curr = root;
    while(curr != NULL) {
        //cout << "loop" << endl;
        if(toFind.compare(curr->val) == 0)
            return curr;
        else if(toFind.compare(curr->val) < 0)
            curr = curr->left;
        else
            curr = curr->right;
    }
    //cout << "nothing" << endl;
    return NULL;
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
