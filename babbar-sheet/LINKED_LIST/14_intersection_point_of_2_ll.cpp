// 14.
// Intersection Point of two Linked Lists.
// [Practice here: https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1 ]

// { Driver Code Starts
#include <iostream>

#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
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

int intersectPoint(struct Node *head1, struct Node *head2);

Node *inputList(int size)
{
  if (size == 0)
    return NULL;

  int val;
  cin >> val;

  Node *head = new Node(val);
  Node *tail = head;

  for (int i = 0; i < size - 1; i++)
  {
    cin >> val;
    tail->next = new Node(val);
    tail = tail->next;
  }

  return head;
}

/* Driver program to test above function*/
int main()
{
  int T, n1, n2, n3;

  cin >> T;
  while (T--)
  {
    cin >> n1 >> n2 >> n3;

    Node *head1 = inputList(n1);
    Node *head2 = inputList(n2);
    Node *common = inputList(n3);

    Node *temp = head1;
    while (temp != NULL && temp->next != NULL)
      temp = temp->next;
    if (temp != NULL)
      temp->next = common;

    temp = head2;
    while (temp != NULL && temp->next != NULL)
      temp = temp->next;
    if (temp != NULL)
      temp->next = common;

    cout << intersectPoint(head1, head2) << endl;
  }
  return 0;
}

// } Driver Code Ends

/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

// Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node *head1, Node *head2)
{
  // Your Code Here
  Node *l1 = head1;
  while (l1 != NULL)
  {
    if (l1->data < 0)
    {
      l1->data -= 1001;
    }
    else
    {
      l1->data += 1001;
    }
    l1 = l1->next;
  }

  Node *l2 = head2;
  while (l2 != NULL)
  {
    if (l2->data < 0 && l2->data < (-1001))
    {
      return l2->data + 1001;
    }
    else
    {
      if (l2->data >= 1001)
      {
        return l2->data - 1001;
      }
    }
    l2 = l2->next;
  }

  return -1;
}
