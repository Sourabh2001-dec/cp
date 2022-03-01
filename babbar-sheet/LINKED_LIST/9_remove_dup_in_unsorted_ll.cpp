// 9. Remove Duplicates in a Unsorted Linked List.
// [Practice here: https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1 ]

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
  Node *removeDuplicates(Node *head)
  {
    unordered_map<int, int> count;
    Node *prev = head;
    count[head->data]++;
    Node *temp = head->next;
    while (temp != nullptr)
    {
      if (count[temp->data])
      {
        Node *next = temp->next;
        delete temp;
        prev->next = next;
        temp = next;
      }
      else
      {
        count[temp->data]++;
        prev = temp;
        temp = temp->next;
      }
    }
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
    Node *result = ob.removeDuplicates(head);
    print(result);
    cout << endl;
  }
  return 0;
} // } Driver Code Ends