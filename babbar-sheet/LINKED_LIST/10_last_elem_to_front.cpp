// 10.
// Write a Program to Move the last element to Front in a Linked
// List.
// [Follow: https://www.geeksforgeeks.org/move-last-element-to-front-of-a-given-linked-list/ ]


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

// } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution
{
public:
  // Function to remove duplicates from unsorted linked list.
  Node *moveToFront(Node *head)
  {
    Node* temp = head;
    while(temp->next->next != nullptr){
      temp = temp->next;
    }
    Node* lastNode = temp->next;
    temp->next = nullptr;
    lastNode->next = head;
    head = lastNode;

    return head;
  }
};

// { Driver Code Starts.

int main()
{
  // your code goes here
  int T;
  cin >> T;

  while (T--)
  {
    int K;
    cin >> K;
    struct Node *head = NULL;
    struct Node *temp = head;

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

    Solution ob;
    Node *result = ob.moveToFront(head);
    print(result);
    cout << endl;
  }
  return 0;
} // } Driver Code Ends