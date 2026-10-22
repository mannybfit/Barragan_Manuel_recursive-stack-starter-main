#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
#include <stdexcept>

using std::ostream;
using std::string;
using std::to_string;

template <class Type>
struct Node
{
  Type data;
  Node<Type>* next{nullptr};
};

template <class Type>
class Stack;

template <class Type>
ostream& operator<<(ostream&, const Stack<Type>& stack);

template <class Type>
class Stack
{
friend ostream& operator<< <>(ostream&, const Stack<Type>& list);
public:
  Stack();
  Stack(const Stack& other);
  Stack<Type>& operator=(const Stack<Type>& other);
  ~Stack();

  int size() const;
  bool empty() const;
  Type top() const;
  void push(const Type&);
  void pop();
  void pop(int);
  Type topPop();
  void clear();

private:
  Node<Type>* head{nullptr};
  int numItems{0};

  void printHelper(ostream& out, Node<Type>* curr) const;
};

template <class Type>
Stack<Type>::Stack() : head(nullptr), numItems(0)
{
}

template <class Type>
Stack<Type>::Stack(const Stack<Type>& other) : head(nullptr), numItems(0)
{
  if (other.head == nullptr) return;

  // copy head node
  head = new Node<Type>{other.head->data, nullptr};
  Node<Type>* currThis = head;
  Node<Type>* currOther = other.head->next;

  // copy the rest
  while (currOther != nullptr)
  {
    currThis->next = new Node<Type>{currOther->data, nullptr};
    currThis = currThis->next;
    currOther = currOther->next;
  }
  numItems = other.numItems;
}

template <class Type>
Stack<Type>& Stack<Type>::operator=(const Stack<Type>& other)
{
  if (this != &other)
  {
    clear();

    if (other.head != nullptr)
    {
      head = new Node<Type>{other.head->data, nullptr};
      Node<Type>* currThis = head;
      Node<Type>* currOther = other.head->next;

      while (currOther != nullptr)
      {
        currThis->next = new Node<Type>{currOther->data, nullptr};
        currThis = currThis->next;
        currOther = currOther->next;
      }
      numItems = other.numItems;
    }
  }
  return *this;
}

template <class Type>
Stack<Type>::~Stack()
{
  clear();
}

template <class Type>
int Stack<Type>::size() const
{
  return numItems;
}

template <class Type>
bool Stack<Type>::empty() const
{
  return numItems == 0;
}

template <class Type>
Type Stack<Type>::top() const
{
  if (empty())
  {
    throw std::logic_error("Stack is empty");
  }
  return head->data;
}

template <class Type>
void Stack<Type>::push(const Type& item)
{
  Node<Type>* temp = new Node<Type>{item, head};
  head = temp;
  numItems++;
}

template <class Type>
void Stack<Type>::pop()
{
  if (empty()) return;

  Node<Type>* temp = head;
  head = head->next;
  delete temp;
  numItems--;
}

template <class Type>
void Stack<Type>::pop(int count)
{
  while (count > 0 && !empty())
  {
    pop();
    count--;
  }
}

template <class Type>
Type Stack<Type>::topPop()
{
  if (empty())
  {
    throw std::logic_error("Stack is empty");
  }
  Type val = head->data;
  pop();
  return val;
}

template <class Type>
void Stack<Type>::clear()
{
  while (!empty())
  {
    pop();
  }
}

// recursive helper to print from bottom up
template <class Type>
void Stack<Type>::printHelper(ostream& out, Node<Type>* curr) const
{
  if (curr == nullptr) return;

  printHelper(out, curr->next);

  out << curr->data;
  if (curr != head)
  {
    out << "->";
  }
}

template <class Type>
ostream& operator<<(ostream& out, const Stack<Type>& list)
{
  list.printHelper(out, list.head);
  return out;
}

#endif // STACK_H