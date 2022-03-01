// 8. Remove Duplicates in a sorted Linked List.
// [Practice here : https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1 ]

// { Driver Code Starts
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
  Node(int x)
  {
    data = x;
    next = NULL;
  }
};

void print(Node *root)
{
  Node *temp = root;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
}
Node *removeDuplicates(Node *root);
int main()
{
  // your code goes here
  int T;
  cin >> T;

  while (T--)
  {
    int K;
    cin >> K;
    Node *head = NULL;
    Node *temp = head;

    for (int i = 0; i < K; i++)
    {
      int data;
      cin >> data;
      if (head == NULL)
        head = temp = new Node(data);
      else
      {
        temp->next = new Node(data);
        temp = temp->next;
      }
    }

    Node *result = removeDuplicates(head);
    print(result);
    cout << endl;
  }
  return 0;
} // } Driver Code Ends

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

// Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
  if(head == nullptr) return head;
  Node *prev = head;
  Node *curr = head->next;
  Node *next;

  while (curr != nullptr)
  {
    if (curr->data == prev->data)
    {
      next = curr->next;
      delete curr;
      prev->next = next;
      curr = next;
    }
    else
    {
      prev = curr;
      curr = curr->next;
    }
  }
  return head;
}