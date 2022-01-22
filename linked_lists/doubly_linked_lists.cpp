// doubly linked lists

#include <iostream>

// double linked list
struct Node
{
  int data;
  Node* next;
  Node* prev;
};

// traverse from right to left 
void traverse_front(Node* head)
{
  while (head != NULL)
  {
    std::cout << head->data << std::endl;
    head = head->next;
  }
}

// traverse from left to right
void traverse_back(Node* head)
{
  while (head != NULL)
  {
    std::cout << head->data << std::endl;
    head = head->prev;
  }
}

int main()
{
  Node* head = new Node();
  Node* first = new Node();
  Node* second = new Node();
  Node* third = new Node();

  first->data = 1;
  second->data = 2;
  third->data = 3;

  // connect nodes with links
  first->next = second;
  first->prev = NULL;

  // connect nodes with links
  second->next = third;
  second->prev = first;

  // connect nodes with links
  third->next = NULL;
  third->prev = second;

  head = first;
  traverse_front(head);
  head = third;
  traverse_back(head);

  return 0;
}