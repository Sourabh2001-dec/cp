// to find the largest path sum between any two nodes
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

int maxPathSum(Node *root, int *res)
{
  // base condition
  if (root == NULL)
  {
    return 0;
  }

  // hypothesis
  int leftResult = maxPathSum(root->left, res);
  int rightResult = maxPathSum(root->right, res);

  // induction

  // -- does not pass through self
  int temp = max(root->data + max(leftResult, rightResult), root->data);

  // -- max by passing through self or not through self
  int ans = max(temp, leftResult + rightResult + root->data);

  *res = max(*res, ans);

  return temp;
}

int main(int argc, char const *argv[])
{
  struct Node *root = newNode(-10);
  root->left = newNode(9);
  root->right = newNode(20);
  root->right->left = newNode(15);
  root->right->right = newNode(7);

  int res = INT_MIN;
  maxPathSum(root, &res);

  cout << res;

  return 0;
}
