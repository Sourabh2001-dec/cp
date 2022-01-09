// to find the largest distance between two leaf nodes in the tree
#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *left, *right;
};

struct Node *newNode(int data)
{
  struct Node *node = new Node;
  node->data = data;
  node->left = node->right = NULL;
  return node;
}

int diameter(Node *root, int *res)
{
  // base condition
  if (root == NULL)
  {
    return 0;
  }

  // hypothesis
  int leftResult = diameter(root->left, res);
  int rightResult = diameter(root->right, res);

  // induction

  // -- does not pass through self
  int temp = 1 + max(leftResult, rightResult);

  // -- max by passing through self or not through self
  int ans = max(temp, leftResult + rightResult + 1);

  *res = max(*res, ans);

  return temp;
}

int main(int argc, char const *argv[])
{
  struct Node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);

  int res = INT_MIN;
  diameter(root, &res);

  cout << res;

  return 0;
}
