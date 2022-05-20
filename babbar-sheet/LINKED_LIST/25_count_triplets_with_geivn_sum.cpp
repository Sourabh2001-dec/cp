// 25.
// Count triplets in a sorted DLL whose sum is equal to given value
// “X”.
// [Follow here: https://www.geeksforgeeks.org/count-triplets-sorted-doubly-linked-list-whose-sum-equal-given-value-x/ ]

// C++ implementation to count triplets in a sorted doubly linked list
// whose sum is equal to a given value 'x'
#include <bits/stdc++.h>

using namespace std;

// structure of node of doubly linked list
struct Node
{
  int data;
  struct Node *next, *prev;
};

// function to count pairs whose sum equal to given 'value'
int countPairs(struct Node *first, struct Node *second, int value)
{
  int count = 0;
  while (first != NULL && second != NULL &&
         first != second && second->next != first)
  {
    int sum = first->data + second->data;
    if (sum > value)
    {
      second = second->prev;
    }
    else if (sum < value)
    {
      first = first->next;
    }
    else
    {
      count++;
      second = second->prev;
      first = first->next;
    }
  }

  return count;
}

// function to count triplets in a sorted doubly linked list
// whose sum is equal to a given value 'x'
int countTriplets(struct Node *head, int x)
{
  Node *curr = head;
  Node *tail = head;
  Node *first;
  Node *last;

  int pairs = 0;

  while (tail->next != NULL)
  {
    tail = tail->next;
  }

  last = tail;

  while (curr->next != NULL)
  {
    first = curr->next;
    last = tail;
    pairs += countPairs(first, last, x - curr->data);
    curr = curr->next;
  }

  return pairs;
}

// A utility function to insert a new node at the
// beginning of doubly linked list
void insert(struct Node **head, int data)
{
  // allocate node
  struct Node *temp = new Node();

  // put in the data
  temp->data = data;
  temp->next = temp->prev = NULL;

  if ((*head) == NULL)
    (*head) = temp;
  else
  {
    temp->next = *head;
    (*head)->prev = temp;
    (*head) = temp;
  }
}

// Driver program to test above
int main()
{
  // start with an empty doubly linked list
  struct Node *head = NULL;

  // insert values in sorted order
  insert(&head, 9);
  insert(&head, 8);
  insert(&head, 6);
  insert(&head, 5);
  insert(&head, 4);
  insert(&head, 2);
  insert(&head, 1);

  int x = 11;

  cout << "Count = "
       << countTriplets(head, x);
  return 0;
}
