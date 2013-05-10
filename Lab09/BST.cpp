#include <iostream>
#include "BST.h"

using namespace std;

// Constructor, set the current root to NULL
BST::BST()
{
  root = NULL;
}

BST::BST(Node* rooot) {
    root = rooot;
}

// Destructor, empty for now
BST::~BST()
{
}

// Inserts a node into the tree.
// If the tree is empty, the node is inserted as the root.
void BST::Insert(int toInsert, char letter)
{
  // Create the new node (allocate space for it)
  Node *newNode = new Node();
  newNode->Frequency = toInsert;
  newNode->Letter = letter;
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->parent = NULL;

  // Find the correct place in the tree for the new node
  Node *prev = NULL;
  Node *curr = root;
  while(curr != NULL)
  {
    prev = curr;
    if(toInsert < curr->Frequency)
      curr = curr->left;
    else
      curr = curr->right;
  }

  // Connect the node to the tree
  newNode->parent = prev;
  if(prev==NULL)
    root = newNode;
  else if(toInsert < prev->Frequency)
    prev->left = newNode;
  else
    prev->right = newNode;
}

// Insert the new node as the root, let its right children to be the original root, and its left children to be NULL
void BST::InsertRightRoot(int toInsert, char letter)
{
  // Put your codes here
}

// Insert the root of the new tree as the root's left children
void BST::InsertTreeLeft(BST Tree)
{
  // Put your codes here
}

// Returns a pointer to the current root of the tree
Node* BST::getRoot()
{
  return root;
}

// Function that prints the code frequencies
void BST::PrintLetterFreqs()
{
  PrintLetterFreqs(root);
}

// Helper function to print the code frequencies
void BST::PrintLetterFreqs(Node *curr)
{
  if(curr == NULL)
  {
    return;
  }

  if((curr->Letter < 'A') || (curr->Letter > 'F')) 
  {
    PrintLetterFreqs(curr->left);
    PrintLetterFreqs(curr->right);
  }
  else 
  {
    cout << curr->Letter << " " << curr->Frequency << endl;
  }
}

// Function to print codes
string BST::PrintLetterCodes(char Letter)
{
  string currCode = "";
  string finalCode = "";
  PrintLetterCodes(root, currCode, finalCode, Letter);
  return finalCode;
}

// Helper function to print codes 
void BST::PrintLetterCodes(Node *curr, string currCode, string& finalCode, char Letter)
{
  // Put your codes here
}

// Print function that prints all the traversal
void BST::Print(string Order)
{
  if(Order=="IN")
    InOrder(root);
  else if(Order=="PRE")
    PreOrder(root);
  else
    PostOrder(root);
}

// Pre-Order Traversal Printing
void BST::PreOrder(Node *curr)
{
  if (curr==NULL)
    return;
  cout << curr->Letter << " " << curr->Frequency << endl;
  PreOrder(curr->left);
  PreOrder(curr->right);
}

// In-Order Traversal Printing
void BST::InOrder(Node *curr)
{
  if (curr==NULL)
    return;
  InOrder(curr->left);
  cout << curr->Letter << " " << curr->Frequency << endl;
  InOrder(curr->right);
}

// Post-Order Traversal Printing
void BST::PostOrder(Node *curr)
{
  if (curr==NULL )
    return;
  PostOrder(curr->left);
  PostOrder(curr->right);
  cout << curr->Letter << " " << curr->Frequency << endl;
}
