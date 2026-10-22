#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <string>

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
};

template <class Type>
Stack<Type>::Stack()
{
}

template <class Type>
Stack<Type>::Stack(const Stack<Type>& other)
{
}

template <class Type>
Stack<Type>& Stack<Type>::operator=(const Stack& other)
{
  return *this;
}

template <class Type>
Stack<Type>::~Stack()
{
}

template <class Type>
int Stack<Type>::size() const
{
  return -1;
}

template <class Type>
bool Stack<Type>::empty() const
{
  return -1;
}

template <class Type>
Type Stack<Type>::top() const
{
  Type ret;
  return ret;
}

template <class Type>
void Stack<Type>::push(const Type& item)
{
}

template <class Type>
void Stack<Type>::pop()
{
}

template <class Type>
void Stack<Type>::pop(int count)
{
}

template <class Type>
Type Stack<Type>::topPop()
{
  Type ret;
  return ret;
}

template <class Type>
void Stack<Type>::clear()
{
}

template <class Type>
ostream& operator<<(ostream& out, const Stack<Type>& list)
{
}
#endif // STACK_H
