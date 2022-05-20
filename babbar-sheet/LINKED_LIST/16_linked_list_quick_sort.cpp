// 16.
// Quicksort for Linked Lists.[Very Important]
// [Follow: https://www.geeksforgeeks.org/quicksort-on-singly-linked-list/ ]

// // { Driver Code Starts
// // Initial Template for C++// C program to find n'th Node in linked list
// #include <stdio.h>
// #include <stdlib.h>
// #include <iostream>
// using namespace std;

// /* Link list Node */
// struct Node
// {
//   int data;
//   struct Node *next;
//   Node(int x)
//   {
//     data = x;
//     next = NULL;
//   }
// };

// // } Driver Code Ends
// /* Linked List Node structure:

// struct Node
// {
//     int data;
//     struct Node *next;
// }

// */

// class Solution
// {
// public:
//   Node *partition(Node *head, Node *end, Node **newHead, Node **newEnd)
//   {
//     Node *pivot = end;
//     Node *prev = NULL,
//          *cur = head,
//          *tail = pivot;

//     while (cur != pivot)
//     {
//       if (cur->data < pivot->data)
//       {
//         if (*newHead == NULL)
//         {
//           *newHead = cur;
//         }

//         prev = cur;
//         cur = cur->next;
//       }
//       else
//       {
//         if (prev)
//         {
//           prev->next = cur->next;
//         }
//         Node *tmp = cur->next;
//         cur->next = NULL;
//         tail->next = cur;
//         tail = cur;
//         cur = tmp;
//       }
//     }

//     if (*newHead == NULL)
//     {
//       *newHead = pivot;
//     }

//     *newEnd = tail;

//     return pivot;
//   }

//   Node *getTail(Node *cur)
//   {
//     while (cur != NULL && cur->next != NULL)
//     {
//       cur = cur->next;
//     }

//     return cur;
//   }

//   Node *quickSortRecurr(Node *head, Node *end)
//   {
//     if (!head || head == end)
//     {
//       return head;
//     }

//     Node *newHead = NULL, *newEnd = NULL;

//     Node *pivot = partition(head, end, &newHead, &newEnd);

//     if (newHead != pivot)
//     {
//       Node *tmp = newHead;
//       while (tmp->next != pivot)
//       {
//         tmp = tmp->next;
//       }
//       tmp->next = NULL;

//       newHead = quickSortRecurr(newHead, tmp);

//       tmp = getTail(newHead);
//       tmp->next = pivot;
//     }

//     pivot->next = quickSortRecurr(pivot->next, newEnd);

//     return newEnd;
//   }

//   void quickSort(struct Node **headRef)
//   {
//     *headRef = quickSortRecurr(*headRef, getTail(*headRef));
//     return;
//   }
// };

// // { Driver Code Starts.

// void printList(struct Node *head)
// {
//   struct Node *temp = head;
//   while (temp != NULL)
//   {
//     printf("%d ", temp->data);
//     temp = temp->next;
//   }
// }

// /* Driver program to test above function*/
// int main()
// {
//   int T, n, l, firstdata;
//   cin >> T;

//   while (T--)
//   {
//     struct Node *head = NULL, *tail = NULL;

//     cin >> n;

//     cin >> firstdata;
//     head = new Node(firstdata);
//     tail = head;

//     for (int i = 1; i < n; i++)
//     {
//       cin >> l;
//       tail->next = new Node(l);
//       tail = tail->next;
//     }

//     Solution ob;
//     ob.quickSort(&head);

//     printList(head);
//     cout << endl;
//   }
//   return 0;
// }

// // } Driver Code Ends

// C++ program for Quick Sort on Singly Linled List
#include <cstdio>
#include <iostream>
using namespace std;

/* a node of the singly linked list */
struct Node {
	int data;
	struct Node* next;
};

/* A utility function to insert a node at the beginning of
* linked list */
void push(struct Node** head_ref, int new_data)
{
	/* allocate node */
	struct Node* new_node = new Node;

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* A utility function to print linked list */
void printList(struct Node* node)
{
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

// Returns the last node of the list
struct Node* getTail(struct Node* cur)
{
	while (cur != NULL && cur->next != NULL)
		cur = cur->next;
	return cur;
}

// Partitions the list taking the last element as the pivot
struct Node* partition(struct Node* head, struct Node* end,
					struct Node** newHead,
					struct Node** newEnd)
{
	struct Node* pivot = end;
	struct Node *prev = NULL, *cur = head, *tail = pivot;

	// During partition, both the head and end of the list
	// might change which is updated in the newHead and
	// newEnd variables
	while (cur != pivot) {
		if (cur->data < pivot->data) {
			// First node that has a value less than the
			// pivot - becomes the new head
			if ((*newHead) == NULL)
				(*newHead) = cur;

			prev = cur;
			cur = cur->next;
		}
		else // If cur node is greater than pivot
		{
			// Move cur node to next of tail, and change
			// tail
			if (prev)
				prev->next = cur->next;
			struct Node* tmp = cur->next;
			cur->next = NULL;
			tail->next = cur;
			tail = cur;
			cur = tmp;
		}
	}

	// If the pivot data is the smallest element in the
	// current list, pivot becomes the head
	if ((*newHead) == NULL)
		(*newHead) = pivot;

	// Update newEnd to the current last node
	(*newEnd) = tail;

	// Return the pivot node
	return pivot;
}

// here the sorting happens exclusive of the end node
struct Node* quickSortRecur(struct Node* head,
							struct Node* end)
{
	// base condition
	if (!head || head == end)
		return head;

	Node *newHead = NULL, *newEnd = NULL;

	// Partition the list, newHead and newEnd will be
	// updated by the partition function
	struct Node* pivot
		= partition(head, end, &newHead, &newEnd);

	// If pivot is the smallest element - no need to recur
	// for the left part.
	if (newHead != pivot) {
		// Set the node before the pivot node as NULL
		struct Node* tmp = newHead;
		while (tmp->next != pivot)
			tmp = tmp->next;
		tmp->next = NULL;

		// Recur for the list before pivot
		newHead = quickSortRecur(newHead, tmp);

		// Change next of last node of the left half to
		// pivot
		tmp = getTail(newHead);
		tmp->next = pivot;
	}

	// Recur for the list after the pivot element
	pivot->next = quickSortRecur(pivot->next, newEnd);

	return newHead;
}

// The main function for quick sort. This is a wrapper over
// recursive function quickSortRecur()
void quickSort(struct Node** headRef)
{
	(*headRef)
		= quickSortRecur(*headRef, getTail(*headRef));
	return;
}

// Driver code
int main()
{
	struct Node* a = NULL;
	push(&a, 5);
	push(&a, 20);
	push(&a, 4);
	push(&a, 3);
	push(&a, 30);

	cout << "Linked List before sorting \n";
	printList(a);

	quickSort(&a);

	cout << "Linked List after sorting \n";
	printList(a);

	return 0;
}
