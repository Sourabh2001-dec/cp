#include <bits/stdc++.h>
using namespace std;

struct Node
{
  Node *right = NULL;
  Node *left = NULL;
  int val;
};

void changeTree(Node *root)
{
  if (root == NULL)
    return;
  int child = 0;
  if (root->left)
  {
    child += root->left->val;
  }
  if (root->right)
  {
    child += root->right->val;
  }

  if (child >= root->val)
  {
    root->val = child;
  }
  else
  {
    if (root->left)
      root->left->val = root->val;
    if (root->right)
      root->right->val = root->val;
  }

  changeTree(root->left);
  changeTree(root->right);

  int total = 0;
  if (root->left)
  {
    total += root->left->val;
  }
  if (root->right)
  {
    total += root->right->val;
  }
  if (root->left || root->right)
    root->val = total;
}

void inorder(Node *node)
{
  if (node == NULL)
    return;
  inorder(node->left);
  cout << node->val << " ";
  inorder(node->right);
}

int main(int argc, char const *argv[])
{
  vector<string> nodes = {"40", "10", "20", "2", "5", "30", "40"};
  vector<Node *> genNodes;
  Node *root = new Node();
  for (int i = 0; i < nodes.size(); i++)
  {
    if (nodes[i] == "null")
    {
      genNodes.push_back(NULL);
      continue;
    }
    Node *newNode = new Node();
    newNode->val = stoi(nodes[i]);
    genNodes.push_back(newNode);
  }
  for (int i = 0; i < genNodes.size(); i++)
  {
    if (genNodes[i] == NULL)
      continue;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < genNodes.size() && genNodes[left] != NULL)
    {
      genNodes[i]->left = genNodes[left];
    }
    if (right < genNodes.size() && genNodes[right] != NULL)
    {
      genNodes[i]->right = genNodes[right];
    }
  }
  changeTree(genNodes[0]);
  inorder(genNodes[0]);

  return 0;
}
