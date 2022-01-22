/**
A queue is an object (an abstract data structure - ADT) that allows the following operations:

Enqueue: Add an element to the end of the queue
Dequeue: Remove an element from the front of the queue
IsEmpty: Check if the queue is empty
IsFull: Check if the queue is full
Peek: Get the value of the front of the queue without removing it
**/

#include <iostream>
#define MAX 5
int count = 0;

struct Queue
{
  int front;
  int rear;
  int queue[MAX];
};

// Check if the queue is empty
bool is_empty(Queue* q)
{
  if (q->front == -1 && q->rear == -1)
    return true;
  else
    return false;
}

// Check if the queue is full
bool is_full(Queue* q)
{
  if (q->front == 0 && q->rear == MAX - 1)
    return true;
  else
    return false;
}

// create empty queue
void create_queue(Queue* q)
{
  if (!is_full(q))
  {
    q->front = -1;
    q->rear = -1;
  }
}

// enqueue operation
void enqueue(Queue* q, int val)
{
  if (!is_full(q))
  {
    if (count != 0)
    {
      q->rear++;
      q->queue[q->rear] = val;
      std::cout << "front: " << q->front << " rear: " << q->rear << " enqueue: " << q->queue[q->rear] << std::endl;
    }
    else
    {
      q->front++;
      q->rear++;
      count++;
      q->queue[q->rear] = val;
      std::cout << "front: " << q->front << " rear: " << q->rear << " enqueue: " << q->queue[q->rear] << std::endl;
    }
  }
  else
  {
    std::cout << "Queue is full"
              << "\n";
  }
}

// dequeue operation
void dequeue(Queue* q)
{
  if (!is_empty(q))
  {
    std::cout << "front: " << q->front << " rear: " << q->rear << " dequeue: " << q->queue[q->front] << std::endl;
    if (q->front >= q->rear)
    {
      q->front = -1;
      q->rear = -1;
    }
    else
    {
      q->front++;
    }
  }
  else
  {
    std::cout << "Queue is empty"
              << "\n";
  }
}

// Driver code
int main()
{
  Queue* q = (Queue*)malloc(sizeof(Queue));
  create_queue(q);
  dequeue(q);  // queue is empty
  enqueue(q, 3);
  enqueue(q, 13);
  enqueue(q, 43);
  enqueue(q, 345);
  enqueue(q, 10);
  enqueue(q, 40);  // queue is full

  dequeue(q);
  dequeue(q);
  dequeue(q);
  dequeue(q);
  dequeue(q);
  dequeue(q);  // queue is empty
  dequeue(q);  // queue is empty

  return 0;
}