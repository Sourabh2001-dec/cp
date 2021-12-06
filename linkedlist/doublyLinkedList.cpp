#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next = NULL;
  Node *prev = NULL;
};

class DoublyLinkedList
{
private:
  Node *start = NULL;
  Node *temp = NULL;

public:
  DoublyLinkedList(/* args */);
  ~DoublyLinkedList();
  Node *createNewNode(int newData);
  void addNodeAtBegin(int newData);
  void addNodeAtEnd(int newData);
  int length();
  void print();
  bool search(int data);
  void deleteAny(int data);
  Node *getNthNode(int n);
  void printMinMax();
};

DoublyLinkedList::DoublyLinkedList(/* args */)
{
}

DoublyLinkedList::~DoublyLinkedList()
{
}

Node *DoublyLinkedList::createNewNode(int data)
{
  Node *newNode = new Node();
  newNode->data = data;
  return newNode;
}

void DoublyLinkedList::addNodeAtBegin(int newData)
{
  temp = createNewNode(newData);
  if (start != NULL)
  {
    start->prev = temp;
    temp->next = start;
    start = temp;
  }
  else
  {
    start = temp;
  }
};

void DoublyLinkedList::addNodeAtEnd(int newData)
{
  Node *newNode = createNewNode(newData);
  if (start == NULL)
  {
    start = temp;
  }
  else
  {
    temp = start;
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
  }
}

int main()
{
  DoublyLinkedList dll = DoublyLinkedList();
  dll.addNodeAtBegin(1);
  dll.addNodeAtEnd(2);
  dll.addNodeAtEnd(3);
  return 0;
}