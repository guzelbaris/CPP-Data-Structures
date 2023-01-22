#include "Tree.h"

BST::BST() : root_(nullptr) {}
bool BST::key_exists(const Matrix& key) {
  BST_Node* current = root_;
  while (current != nullptr) {
    if (key == current->key) {
      return true;
    } else if (key < current->key) {
      current = current->left;
    } else {
      current = current->right;
    }
  }
  return false;
}

long BST::search(const Matrix& key) {
  BST_Node* current = root_;
  while (current != nullptr) {
    if (key == current->key) {
      return current->value;
    } else if (key < current->key) {
      current = current->left;
    } else {
      current = current->right;
    }
  }
  return 0;
}

void BST::insert(const Matrix& key, long value) {
  BST_Node* new_node = new BST_Node();
  new_node->key = key;
  new_node->value = value;
  new_node->left = nullptr;
  new_node->right = nullptr;

  if (root_ == nullptr) {
    root_ = new_node;
    return;
  }

  BST_Node* current = root_;
  BST_Node* parent = nullptr;
  while (current != nullptr) {
    parent = current;
    if (key < current->key) {
      current = current->left;
    } else {
      current = current->right;
    }
  }

  if (key < parent->key) {
    parent->left = new_node;
  } else {
    parent->right = new_node;
  }
}

BST_Node* BST::get_root() {
  return root_;
}

void BST::delete_node(BST_Node* node) {
  if (node->left != nullptr) {
    delete_node(node->left);
  }
  if (node->right != nullptr) {
    delete_node(node->right);
  }
  delete node;
}

BST::~BST()
{
   delete_node(root_);
}

