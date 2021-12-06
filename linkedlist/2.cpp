#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *next = NULL;
};

class CircularLinkedList
{
private:
  Node *start = NULL;
  Node *temp = NULL;

public:
  CircularLinkedList(/* args */);
  ~CircularLinkedList();
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

CircularLinkedList::CircularLinkedList(/* args */)
{
}

Node *CircularLinkedList::createNewNode(int newData)
{
  Node *newNode = new Node();
  newNode->data = newData;
  return newNode;
}

void CircularLinkedList::addNodeAtBegin(int newData)
{
  Node *newNode = this->createNewNode(newData);
  if (start == NULL)
  {
    start = newNode;
    newNode->next = start;
  }
  else
  {
    newNode->next = start;
    temp = start;
    do
    {
      temp = temp->next;
    } while (temp->next != start);
    temp->next = newNode;
    start = newNode;
  }
}

void CircularLinkedList::addNodeAtEnd(int newData)
{
  Node *newNode = this->createNewNode(newData);
  if (start == NULL)
  {
    start = newNode;
    newNode->next = start;
  }
  else
  {
    temp = start;
    do
    {
      temp = temp->next;
    } while (temp->next != start);
    newNode->next = temp->next;
    temp->next = newNode;
  }
};

int CircularLinkedList::length()
{
  int count = 0;
  temp = start;
  if (temp == NULL)
  {
    return count;
  }
  while (temp->next != start)
  {
    count++;
    temp = temp->next;
  }
  count++;
  return count;
}

void CircularLinkedList::print()
{
  temp = start;
  if (temp == NULL)
  {
    cout << "NULL" << endl;
  }
  while (temp->next != start)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }

  cout << temp->data << " ";
  cout << endl;
}

bool CircularLinkedList::search(int data)
{
  temp = start;
  while (temp->next != start)
  {
    if (temp->data == data)
      return true;
    temp = temp->next;
  }
  if (temp->data == data)
    return true;
  return false;
}

void CircularLinkedList::deleteAny(int data)
{
  temp = start;
  Node *prev = start;
  while (temp->next != start)
  {
    if (temp->data == data)
    {
      if (temp == start)
      {
        start = temp->next;
        delete temp;
        return;
      }
      prev->next = temp->next;
      delete temp;
      return;
    }
    prev = temp;
    temp = temp->next;
  }
  if (temp->data == data)
  {
    if (temp == start)
    {
      start = temp->next;
      delete temp;
      return;
    }
    prev->next = temp->next;
    delete temp;
    return;
  }
}

Node *CircularLinkedList::getNthNode(int n)
{
  int index = 0;
  temp = start;
  while (index != n)
  {
    temp = temp->next;
    index++;
  }
  return temp;
}

void CircularLinkedList::printMinMax()
{
  int min = start->data;
  int max = start->data;
  temp = start;
  while (temp->next != start)
  {
    if (temp->data < min)
    {
      min = temp->data;
    }
    else if (temp->data > max)
    {
      max = temp->data;
    }
    temp = temp->next;
  }
    if (temp->data < min)
    {
      min = temp->data;
    }
    else if (temp->data > max)
    {
      max = temp->data;
    }
  cout << "MIN : " << min << " "
       << "MAX : " << max << endl;
}
CircularLinkedList::~CircularLinkedList()
{
}

int main()
{
  CircularLinkedList ll = CircularLinkedList();
  ll.addNodeAtEnd(1);
  ll.addNodeAtEnd(2);
  ll.addNodeAtEnd(4);
  ll.addNodeAtEnd(3);
  //  ll.deleteAny(3);
  ll.print();
  ll.printMinMax();
  cout << ll.search(1) << endl;
  cout << ll.length() << endl;
  cout << ll.getNthNode(1)->data;
  return 0;
}