#include <string>

#ifndef BST_H
#define BST_H

using namespace std;

// Representation of an element in the tree
struct Node 
{
  int Frequency;   // Frequency of the node
  char Letter;   // Letter associated the the frequency
  Node *left;   // Pointer to the left node
  Node *right;  // Pointer to the right node
  Node *parent; // Pointer to the parent node
};

class BST
{
  // Public Functions/Variables
  public:
    BST();  // Constructor #1
    BST(Node*);
    ~BST(); // Destructor
    void Insert(int toInsert, char letter);
    void InsertRightRoot(int toInsert, char letter);
    void InsertTreeLeft(BST Tree);
    void Print(string Order);
    void PrintLetterFreqs();
    string PrintLetterCodes(char Letter);
    void PrintLetterCodes(Node *curr, string currCode, string& finalCode, char Letter);
    Node *getRoot();
    
  // Private Functions/Variables
  private:
    Node *root;    
    void PrintLetterFreqs(Node *curr); // Prints the huffman codes
    void InOrder(Node *curr); // Prints the tree in order
    void PreOrder(Node *curr); // Prints the tree pre order
    void PostOrder(Node *curr); // Prints the tree post order
};

#endif
