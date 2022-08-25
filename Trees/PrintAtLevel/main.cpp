#include <iostream>
#include <bits/stdc++.h>

using namespace std;

template <typename T>
class TreeNode
{
public:
  T data;
  vector<TreeNode<T> *> children;

  TreeNode(T data)
  {
    this->data = data;
  }
};

TreeNode<int> *takeInputLevelWise()
{
  int rootData;
  cout << "Enter data" << endl;
  cin >> rootData;

  TreeNode<int> *root = new TreeNode<int>(rootData);

  queue<TreeNode<int> *> pendingNodes;

  pendingNodes.push(root);
  while (pendingNodes.size() != 0)
  {
    TreeNode<int> *front = pendingNodes.front();
    pendingNodes.pop();
    cout << "Enter number of children of " << front->data << endl;
    int numChild;
    cin >> numChild;

    for (int i = 0; i < numChild; i++)
    {
      int childData;

      cout << "Enter " << i + 1 << "th child of" << front->data << endl;
      cin >> childData;

      TreeNode<int> *child = new TreeNode<int>(childData);
      front->children.push_back(child);
      pendingNodes.push(child);
    }
  }
  return root;
}

void printTreeLevelWise(TreeNode<int> *root)
{
  queue<TreeNode<int> *> pendingNodes;
  pendingNodes.push(root);

  while (!pendingNodes.empty())
  {
    auto f = pendingNodes.front();
    pendingNodes.pop();

    cout << f->data << ":";

    for (int i = 0; i < f->children.size(); i++)
    {

      if (i == f->children.size() - 1)
        cout << f->children[i]->data << "";

      else
        cout << f->children[i]->data << ",";
      pendingNodes.push(f->children[i]);
    }
    cout << endl;
  }
}

void printAtLevelK(TreeNode<int> *root, int k)
{
  if (k == 0)
  {
    cout << root->data << endl;
  }

  for (int i = 0; i < root->children.size(); i++)
  {
    printAtLevelK(root->children[i], k - 1);
  }
}

int main()
{
  TreeNode<int> *root = takeInputLevelWise();
  printTreeLevelWise(root);
  printAtLevelK(root, 3);
  return 0;
}