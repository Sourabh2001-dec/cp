// 12.
// Add two numbers represented by linked lists.
// [Practice here: https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1 ]

// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
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

struct Node *buildList(int size)
{
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

void printList(Node *n)
{
  while (n)
  {
    cout << n->data << " ";
    n = n->next;
  }
  cout << endl;
}

// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
public:
  Node *reverse(Node *head)
  {
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
  // Function to add two numbers represented by linked list.
  struct Node *addTwoLists(struct Node *first, struct Node *second)
  {
    Node *ans = NULL;
    Node *temp = ans;
    int sum = 0;
    int carry = 0;
    first = reverse(first);
    second = reverse(second);
    while ((first != NULL && second == NULL) || (first == NULL && second != NULL) || (first != NULL && second != NULL))
    {
      sum = (first == NULL ? 0 : first->data) + (second == NULL ? 0 : second->data) + carry;
      carry = sum / 10;
      if (ans == NULL)
      {
        ans = new Node(sum % 10);
        temp = ans;
      }
      else
      {
        temp->next = new Node(sum % 10);
        temp = temp->next;
      }

      if (first != NULL)
        first = first->next;
      if (second != NULL)
        second = second->next;
    }

    if (carry)
    {
      temp->next = new Node(carry);
    }

    return reverse(ans);
  }
};

// { Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, m;

    cin >> n;
    Node *first = buildList(n);

    cin >> m;
    Node *second = buildList(m);
    Solution ob;
    Node *res = ob.addTwoLists(first, second);
    printList(res);
  }
  return 0;
}
// } Driver Code Ends