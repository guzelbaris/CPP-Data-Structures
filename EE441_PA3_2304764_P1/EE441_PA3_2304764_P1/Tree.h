#ifndef TREE_H
#define TREE_H
#include <iostream>
#include "math.h"
#include "Matrix.h"

using namespace std;

class BST_Node {
 public:
  Matrix key;
  long value;
  BST_Node* left;
  BST_Node* right;
};

class BST {
 public:
  // check if a key exists in the tree
  bool key_exists(const Matrix& key);
  // search for a value of a key
  long search(const Matrix& key);
  // insert a key-value pair
  void insert(const Matrix& key, long value);
  // get root node
  BST_Node* get_root();
  // destructor
  ~BST();
  BST();
 private:
  BST_Node* root_;
  void delete_node(BST_Node* node);
};

#endif
