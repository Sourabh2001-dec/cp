// 11.
// Add “1” to a number represented as a Linked List.
// [Practice here: https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1 ]

// { Driver Code Starts
// Initial template for C++

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

void printList(Node *node)
{
  while (node != NULL)
  {
    cout << node->data;
    node = node->next;
  }
  cout << "\n";
}

// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
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

  Node *addOne(Node *head)
  {
    // Your Code here
    // return head of list after adding one
    Node *reversed = reverse(head);
    int sum = reversed->data + 1;
    int carry = sum / 10;
    reversed->data = sum % 10;
    Node *temp = reversed->next;
    Node *prev = reversed;
    while (temp != NULL)
    {
      sum = temp->data + carry;
      temp->data = sum % 10;
      carry = sum / 10;
      prev = temp;
      temp = temp->next;
    }

    if (carry)
    {
      prev->next = new Node(carry);
    }

    return reverse(reversed);
  }
};

// { Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;

    Node *head = new Node(s[0] - '0');
    Node *tail = head;
    for (int i = 1; i < s.size(); i++)
    {
      tail->next = new Node(s[i] - '0');
      tail = tail->next;
    }
    Solution ob;
    head = ob.addOne(head);
    printList(head);
  }
  return 0;
}
// } Driver Code Ends