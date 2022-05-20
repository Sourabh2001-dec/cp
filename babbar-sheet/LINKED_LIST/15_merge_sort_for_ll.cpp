// 15.
// Merge Sort For Linked lists.[Very Important]
// [Follow : https://www.geeksforgeeks.org/merge-sort-for-linked-list/ ]

// { Driver Code Starts
// Initial Template for C++// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
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

// } Driver Code Ends
/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution
{
public:
  void FrontBackSplit(Node *source, Node **frontRef, Node **backRef)
  {
    Node *fast;
    Node *slow;
    slow = source;
    fast = source->next;

    while (fast != NULL)
    {
      fast = fast->next;
      if (fast != NULL)
      {
        slow = slow->next;
        fast = fast->next;
      }
    }

    *frontRef = source;
    *backRef = slow->next;

    // split at mid
    slow->next = NULL;
  }

  Node *SortedMerge(Node *a, Node *b)
  {
    Node *result = NULL;

    if (a == NULL)
    {
      return b;
    }
    else if (b == NULL)
    {
      return a;
    }

    if (a->data <= b->data)
    {
      result = a;
      result->next = SortedMerge(a->next, b);
    }
    else
    {
      result = b;
      result->next = SortedMerge(a, b->next);
    }

    return result;
  }

  void mergeSort(struct Node **headRef)
  {
    Node *head = *headRef;
    Node *a;
    Node *b;
    if (head == NULL || head->next == NULL)
    {
      return;
    }

    FrontBackSplit(head, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *headRef = SortedMerge(a, b);
  }
};

// { Driver Code Starts.

void printList(struct Node *head)
{
  struct Node *temp = head;
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
}

/* Driver program to test above function*/
int main()
{
  int T, n, l, firstdata;
  cin >> T;

  while (T--)
  {
    struct Node *head = NULL, *tail = NULL;

    cin >> n;

    cin >> firstdata;
    head = new Node(firstdata);
    tail = head;

    for (int i = 1; i < n; i++)
    {
      cin >> l;
      tail->next = new Node(l);
      tail = tail->next;
    }

    Solution ob;
    ob.mergeSort(&head);

    printList(head);
    cout << endl;
  }
  return 0;
}

// } Driver Code Ends