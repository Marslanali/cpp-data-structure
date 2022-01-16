// singly linked lists
#include <iostream>

// Declare a struct for the Linked list nodes
struct Node
{
  int data;
  Node* next;
};

// method to traverse linked list
void linked_list_traversal(Node* head)
{
  while (head != NULL)
  {
    std::cout << head->data << "\n";
    head = head->next;
  }
  std::cout << "\n";
}

int main()
{
  // create the pointers for the linked list with 3 nodes
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

  // traverse the linked list
  head = first;
  linked_list_traversal(head);

  // Insert a node at the beginning
  {
    Node* new_node_beginning = new Node();
    new_node_beginning->data = 5;
    new_node_beginning->next = first;
    head = new_node_beginning;
    // traverse the updated linked list
    head = new_node_beginning;
    linked_list_traversal(head);
  }

  // Insert a node at the end
  {
    Node* new_node_end = new Node();
    new_node_end->data = 40;
    third->next = new_node_end;
    new_node_end->next = NULL;
    // traverse the upated linked list
    linked_list_traversal(head);
  }

  // Insert a node at the middle
  {
    Node* new_node_middle = new Node();
    second->next = new_node_middle;
    new_node_middle->next = third;
    // traverse the upated linked list
    linked_list_traversal(head);
  }

  // delete from the beginning
  {
    Node* tmp = new Node();
    tmp = head;
    head = head->next;
    free(tmp);
    // traverse the updated linked list
    linked_list_traversal(head);
  }

  // delete node from the end
  {
    // create two tmp pointer holding head
    Node* tmp1 = head;
    Node* tmp2 = head;
    // traverse with the tmp pointer to reach second last node
    while (tmp1->next != NULL)
    {
      tmp2 = tmp1;
      tmp1 = tmp1->next;
    }
    // delete the last node
    tmp2->next = NULL;
    free(tmp1);
    tmp1 = NULL;
    // traverse the updated linked list
    linked_list_traversal(head);
  }

  return 0;
}
