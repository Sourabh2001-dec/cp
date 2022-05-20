// 27.
// Rotate Doubly Linked list by N nodes.
// [Follow here: https://www.geeksforgeeks.org/rotate-doubly-linked-list-n-nodes/ ]

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
  int data;
  struct node *next, *prev;

  node(int x)
  {
    data = x;
    next = NULL;
    prev = NULL;
  }

} Node;

// } Driver Code Ends
// User function Template for C++

/*
typedef struct node
{
  int data;
  struct node*next,*prev;

  node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }

} Node;
*/

class Solution
{
public:
  Node *update(Node *start, int p)
  {
    Node *head = start;
    Node *tail = start;

    while (tail->next != NULL)
      tail = tail->next;

    Node *newHead;

    for (int i = 0; i < p-1; i++)
    {
      head = head->next;
    }

    newHead = head->next;
    newHead->prev = NULL;

    head->next = NULL;

    start->prev = tail;
    tail->next = start;

    return newHead;
  }
};

// { Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, p;
    cin >> n >> p;
    struct node *start = NULL;
    struct node *cur = NULL;
    struct node *ptr = NULL;

    for (int i = 0; i < n; i++)
    {
      int a;
      cin >> a;
      ptr = new node(a);
      ptr->data = a;
      ptr->next = NULL;
      ptr->prev = NULL;
      if (start == NULL)
      {
        start = ptr;
        cur = ptr;
      }
      else
      {
        cur->next = ptr;
        ptr->prev = cur;
        cur = ptr;
      }
    }
    Solution obj;
    struct node *str = obj.update(start, p);
    while (1)
    {
      cout << str->data << " ";
      if (str->next == NULL)
        break;
      str = str->next;
    }
    while (str != NULL)
    {
      cout << str->data << " ";
      str = str->prev;
    }
    cout << "\n";
  }
}

// } Driver Code Ends