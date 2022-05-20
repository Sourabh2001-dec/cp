#include <bits/stdc++.h>
using namespace std;

struct Node
{
  Node *right = NULL;
  Node *left = NULL;
  int val;
};

void inorderSucessor(Node *root, Node *p)
{
  Node* successor = NULL;
  while(root){
    if(root->val <= p->val){
      root = root->right;
    }
    else{
      successor = root;
      root = root->left;
    }
  }
  cout << successor->val << "\n";
}

int main(int argc, char const *argv[])
{
  vector<string> nodes = {"5", "2", "7", "1", "4", "6", "9", "null", "null", "3", "null", "null", "null", "8", "10"};
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
  inorderSucessor(genNodes[0],genNodes[5]);

  return 0;
}
