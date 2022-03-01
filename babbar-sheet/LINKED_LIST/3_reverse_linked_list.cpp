// 3. Write a Program to reverse the Linked List. (Both Iterative and
// recursive)
// [Practice here: https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1 ]

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
  // Function to reverse a linked list.
  struct Node *reverseList(struct Node *head)
  {
    // code here
    // return head of reversed list
    Node *newHead = NULL;
    while (head != NULL)
    {
      Node *next = head->next;
      head->next = newHead;
      newHead = head;
      head = next;
    }

    return newHead;
  }

  struct Node *recurReverseList(struct Node *head)
  {
    if (head == NULL || head->next == NULL)
    {
      return head;
    }

    Node *newHead = recurReverseList(head->next);
    Node *headNext = head->next;
    headNext->next = head;
    head->next = NULL;
    return newHead;
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
    head = ob.recurReverseList(head);

    printList(head);
    cout << endl;
  }
  return 0;
}

// } Driver Code Ends