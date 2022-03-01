// 2. Write a Program to check whether the Singly Linked list is a
// palindrome or not.
// [Practice here: https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
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
/*
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
  // Function to check whether the list is palindrome.
  bool isPalindrome(Node *head)
  {
    int len = 0;
    Node *count = head;
    while (count != NULL)
    {
      len++;
      count = count->next;
    }

    if(len <= 1){
      return true;
    }

    Node *list1 = head;
    Node *list2 = head;

    int half = len / 2;
    while (half--)
    {
      list2 = list2->next;
    }

    // // odd len
    if (len % 2 != 0)
    {
      list2 = list2->next;
    }

    Node *newHead = NULL;
    while (list2 != NULL)
    {
      Node *next = list2->next;
      list2->next = newHead;
      newHead = list2;
      list2 = next;
    }

    list2 = newHead;

    // half list is reversed
    while (list2 != NULL)
    {
      if (list1->data != list2->data)
        return false;
      list1 = list1->next;
      list2 = list2->next;
    }

    return true;
  }
};

// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T, i, n, l, firstdata;
  cin >> T;
  while (T--)
  {

    struct Node *head = NULL, *tail = NULL;
    cin >> n;
    // taking first data of LL
    cin >> firstdata;
    head = new Node(firstdata);
    tail = head;
    // taking remaining data of LL
    for (i = 1; i < n; i++)
    {
      cin >> l;
      tail->next = new Node(l);
      tail = tail->next;
    }
    Solution obj;
    cout << obj.isPalindrome(head) << endl;
  }
  return 0;
}

// } Driver Code Ends