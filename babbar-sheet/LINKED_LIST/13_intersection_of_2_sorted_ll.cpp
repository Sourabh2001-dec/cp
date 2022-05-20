// 13.
// Intersection of two Sorted Linked List.
// [Practice here: https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1 ]

// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *next;
  Node(int val)
  {
    data = val;
    next = NULL;
  }
};

Node *inputList(int size)
{
  Node *head, *tail;
  int val;

  cin >> val;
  head = tail = new Node(val);

  while (--size)
  {
    cin >> val;
    tail->next = new Node(val);
    tail = tail->next;
  }

  return head;
}

void printList(Node *n)
{
  while (n)
  {
    cout << n->data << " ";
    n = n->next;
  }
}

Node *findIntersection(Node *head1, Node *head2);

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, m;
    cin >> n >> m;

    Node *head1 = inputList(n);
    Node *head2 = inputList(m);

    Node *result = findIntersection(head1, head2);

    printList(result);
    cout << endl;
  }
  return 0;
}
// } Driver Code Ends

/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node *findIntersection(Node *head1, Node *head2)
{
  // Your Code Here
  Node *ans = NULL;
  Node* ansHead;
  Node *it1 = head1;
  Node *it2 = head2;

  while (it1 != NULL && it2 != NULL)
  {
    if (it1->data == it2->data)
    {
      if (ans == NULL)
      {
        ans = new Node(it1->data);
        ansHead = ans;
      }
      else
      {
        ans->next = new Node(it1->data);
        ans = ans->next;
      }
      it1 = it1->next;
      it2 = it2->next;
    }
    else if (it1->data < it2->data)
    {
      it1 = it1->next;
    }
    else
    {
      it2 = it2->next;
    }
  }

  return ansHead;
}