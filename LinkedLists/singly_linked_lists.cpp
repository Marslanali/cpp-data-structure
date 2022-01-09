// singly linked lists

#include <iostream>

// Declare a struct for the Linked list nodes
struct Node
{
  int data;
  Node* next;
};


int main()
{
  // create the pointers for the linked list
  Node* head;
  Node* first = NULL;
  Node* second = NULL;
  Node* third = NULL;

  // assigned memory on the heap
  head = new Node();
  first = new Node();
  second = new Node();
  third = new Node();

  // assigned data to each node
  first->data = 10;
  second->data = 20;
  third->data = 30;

  // connect the nodes
  first->next = second;
  second->next = third;
  third->next = NULL;

  // nodes traversal
  head = first;
  while (head != NULL)
  {
    std::cout << head->data << "\n";
    head = head->next;
  }
  std::cout << "\n";

  // Insert node at the beginning
  Node* updated_first = new Node();
  updated_first->data = 100;
  updated_first->next = first;

  head = updated_first;
  // nodes traversal on updated linked list
  while (head != NULL)
  {
    std::cout << head->data << "\n";
    head = head->next;
  }

  // Insert node at the end
  Node* updated_last = new Node();
  updated_last->data = 200;
  third->next = updated_last;
  updated_last->next = NULL;

  std::cout << "\n";
  head = updated_first;
  // nodes traversal on updated linked list
  while (head != NULL)
  {
    std::cout << head->data << "\n";
    head = head->next;
  }

  // Insert node at the middle
  Node* updated_middle = new Node();
  updated_middle->data = 500;
  second->next = updated_middle;
  updated_middle->next = third;

  std::cout << "\n";
  head = updated_first;
  // nodes traversal on updated linked list
  while (head != NULL)
  {
    std::cout << head->data << "\n";
    head = head->next;
  }

  // delete the node from beginning
  std::cout << "\n";
  delete updated_first;
  head = first;
  // nodes traversal on updated linked list
  while (head != NULL)
  {
    std::cout << head->data << "\n";
    head = head->next;
  }

  // delete the node from end
  std::cout << "\n";
  delete updated_last;
  third->next = NULL;
  head = first;
  // nodes traversal on updated linked list
  while (head != NULL)
  {
    std::cout << head->data << "\n";
    head = head->next;
  }

  return 0;
}
