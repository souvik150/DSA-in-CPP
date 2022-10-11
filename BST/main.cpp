#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
  T data;
  BinaryTreeNode *left;
  BinaryTreeNode *right;

  BinaryTreeNode(T data)
  {
    this->data = data;
    left = NULL;
    right = NULL;
  }

  ~BinaryTreeNode()
  {
    delete left;
    delete right;
  }
};

class BST
{
  BinaryTreeNode<int> *root;

public:
  BST()
  {
    root = NULL;
  }

  ~BST()
  {
    delete root;
  }

private:
  BinaryTreeNode<int> *deleteData(int data, BinaryTreeNode<int> *node)
  {
    if (node == NULL)
    {
      return NULL;
    }
    if (data > node->data)
    {
      node->right = deleteData(data, node->right);
    }
    else if (data < node->data)
    {
      node->left = deleteData(data, node->left);
    }
    else
    {
      if (node->left == NULL && node->right == NULL)
      {
        delete node;
        return NULL;
      }
      else if (node->left == NULL)
      {
        BinaryTreeNode<int> *temp = node->right;
        node->right = NULL;
        delete node;
        return temp;
      }
      else if (node->right == NULL)
      {
        BinaryTreeNode<int> *temp = node->left;
        node->left = NULL;
        delete node;
        return temp;
      }
      else
      {
        BinaryTreeNode<int> *minNode = node->right;
        while (minNode->left != NULL)
        {
          minNode = minNode->left;
        }
        int rightMin = minNode->data;
        node->data = rightMin;
        node->right = deleteData(rightMin, node->right);
        return node;
      }
    }
  }

public:
  void deleteData(int data)
  {
    deleteData(data, root);
  }

private:
  BinaryTreeNode<int> *insert(int data, BinaryTreeNode<int> *node)
  {
    if (node == NULL)
    {
      BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
      return newNode;
    }

    if (data < root->data)
    {
      node->left = insert(data, node->left);
    }
    else
    {
      node->right = insert(data, node->right);
    }
    return node;
  }

public:
  void insert(int data)
  {
    this->root = insert(data, this->root);
    return NULL;
  }

private:
  bool hasData(int data, BinaryTreeNode<int> *node)
  {
    if (node == NULL)
    {
      return false;
    }

    if (root->data == data)
    {
      return true;
    }

    else if (data < root->data)
    {
      return hasData(data, root->left);
    }
    else
    {
      return hasData(data, root->right);
    }
  }

public:
  bool hasData(int data)
  {
    return hasData(data, root);
  }

private:
  void printTree(BinaryTreeNdoe<int> *root)
  {
    cout << root->data << ":";
    if (root->left != NULL)
    {
      cout << "L" << root->left->data;
    }
    if (root->right != NULL)
    {
      cout << "R" << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
  }

public:
  void printTree()
  {
    printTree(root);
  }
}
