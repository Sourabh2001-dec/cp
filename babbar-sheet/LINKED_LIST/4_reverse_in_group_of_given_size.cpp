// 4. Reverse a Linked List in group of Given Size. [Very Imp]
// [Practice here : https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1 ]

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct node
{
  int data;
  struct node *next;

  node(int x)
  {
    data = x;
    next = NULL;
  }
};

/* Function to print linked list */
void printList(struct node *node)
{
  while (node != NULL)
  {
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");
}

// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element
  Return the node which points to the head of the new LinkedList
  Node is defined as
    struct node
    {
        int data;
        struct node* next;

        node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution
{
public:
  struct node *reverse(struct node *head, int k)
  {
    // Complete this method
    int len = 0;
    node *temp = head;
    while (temp != NULL)
    {
      len++;
      temp = temp->next;
    }

    if(len < 2 || k == 1) return head;

    int loops = len / k;

    node *dummy = new node(0);
    node *prev = dummy;
    node *curr = head;
    while (loops--)
    {
      node *newHead = NULL;
      node *temp = curr;
      for (int i = 0; i < (k); i++)
      {
        // if(i == (k-1)) temp->next = curr->next;
        node *next = curr->next;
        curr->next = newHead;
        newHead = curr;
        curr = next;
      }
      prev->next = newHead;
      prev = temp;
      // cout << curr->data << "\n";
    }


    if (len % k)
    {
      int remLoops = len % k;
      node *newHead2 = NULL;
      node *temp2 = curr;
      for (int i = 0; i < (remLoops); i++)
      {
        // if(i == (k-1)) temp2->next = curr->next;
        node *next = curr->next;
        curr->next = newHead2;
        newHead2 = curr;
        curr = next;
      }
      prev->next = newHead2;
      prev = temp2;
    }

    return dummy->next;
  }
};

// { Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
  int t;
  cin >> t;

  while (t--)
  {
    struct node *head = NULL;
    struct node *temp = NULL;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
      int value;
      cin >> value;
      if (i == 0)
      {
        head = new node(value);
        temp = head;
      }
      else
      {
        temp->next = new node(value);
        temp = temp->next;
      }
    }

    int k;
    cin >> k;

    Solution ob;
    head = ob.reverse(head, k);
    printList(head);
  }

  return (0);
}

// } Driver Code Ends