/**
Basic Operations of Stack
There are some basic operations that allow us to perform different actions on a
stack.

Push: Add an element to the top of a stack
Pop: Remove an element from the top of a stack
IsEmpty: Check if the stack is empty
IsFull: Check if the stack is full
Peek: Get the value of the top element without removing it
**/

#include <iostream>
#define MAX 10
int count = 0;

struct Stack
{
  int top;
  int element[MAX];
};

// Check if the stack is empty
bool is_stack_empty(Stack *s)
{
  if (s->top == -1)
    return true;
  else
    return false;
}

// Check if the stack is full
bool is_stack_full(Stack *s)
{
  if (s->top == MAX - 1)
    return true;
  else
    return false;
}

// create empty stack
void create_empty_stack(Stack *s) { s->top = -1; }

// push operation
void push_val(Stack *s, int val)
{
  if (!is_stack_full(s))
  {
    s->top++;
    s->element[s->top] = val;
    count++;
  }
}

// pop operation
void pop_val(Stack *s)
{
  if (!is_stack_empty(s))
  {
    std::cout << s->element[s->top] << "\n";
    s->top--;
    count--;
  }
}

// traverse
void stack_traverse(Stack *s)
{
  if (!is_stack_empty(s))
  {
    for (size_t i = 0; i < count; i++)
    {
      std::cout << "val: " << s->element[i] << std::endl;
    }
  }
}

// Driver code
int main()
{
  Stack *s = (Stack *)malloc(sizeof(Stack));
  create_empty_stack(s);
  push_val(s, 1);
  push_val(s, 10);
  push_val(s, 415);
  push_val(s, 65);

  stack_traverse(s);

  pop_val(s);
  pop_val(s);
  pop_val(s);
  pop_val(s);

  return 0;
}
