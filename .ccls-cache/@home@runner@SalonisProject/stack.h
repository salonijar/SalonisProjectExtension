#ifndef STACK_H
#define STACK_H

#include "detective.h"
#include <stack>
#include <string>
#include <iostream>

class Stack {
  std::stack<DPtr> stack;
  int stackSize;

public:
  void push(std::string n, DPtr x);
  void pop();
  void printStack();
  Stack();
  ~Stack(); // pop all
};

Stack::Stack() : stackSize(0) {}

Stack::~Stack() {
  int n = stackSize;
  for (int i = 0; i < n; i++)
    pop();
}

void Stack::push(std::string n, DPtr x) {
  if (x && x->getTarg() == "None") {
    stack.push(x);
    stackSize++;
    x->set_Targ(n);
    std::cout << "Your reservation has been made" << std::endl;
  } else {
    std::cout << "Your reservation was declined" << std::endl;
  }
}

void Stack::pop() {
  if (!stack.empty()) {
    DPtr t = stack.top();
    std::string targ = t->getTarg();
    t->set_Targ("None");
    stack.pop();
    stackSize--;
    std::cout << targ << " has been found" << std::endl;
  } else {
    std::cout << "Stack is empty" << std::endl;
  }
}

void Stack::printStack() {
  if (stackSize == 0) {
    std::cout << "Stack is empty." << std::endl;
    return;
  }

  std::cout << "The stack is:" << std::endl;
  printf("\n");

  std::stack<DPtr> tempStack = stack;

  int position = 1;
  while (!tempStack.empty()) {
    DPtr currentPtr = tempStack.top();
    std::cout << "Position " << position << ":" << std::endl;
    currentPtr->print(); 
    std::cout << std::endl;
    tempStack.pop();
    position++;
  }
}

#endif // STACK_H
#ifndef STACK_H
#define STACK_H

#include "detective.h"
#include <stack>
#include <string>
#include <iostream>

class Stack {
  std::stack<DPtr> stack;
  int stackSize;

public:
  void push(std::string n, DPtr x);
  void pop();
  void printStack();
  Stack();
  ~Stack(); // pop all
};

Stack::Stack() : stackSize(0) {}

Stack::~Stack() {
  int n = stackSize;
  for (int i = 0; i < n; i++)
    pop();
}

void Stack::push(std::string n, DPtr x) {
  if (x && x->getTarg() == "None") {
    stack.push(x);
    stackSize++;
    x->set_Targ(n);
    std::cout << "Your reservation has been made" << std::endl;
  } else {
    std::cout << "Your reservation was declined" << std::endl;
  }
}

void Stack::pop() {
  if (!stack.empty()) {
    DPtr t = stack.top();
    std::string targ = t->getTarg();
    t->set_Targ("None");
    stack.pop();
    stackSize--;
    std::cout << targ << " has been found" << std::endl;
  } else {
    std::cout << "Stack is empty" << std::endl;
  }
}

void Stack::printStack() {
  if (stackSize == 0) {
    std::cout << "Stack is empty." << std::endl;
    return;
  }

  std::cout << "The stack is:" << std::endl;
  printf("\n");

  std::stack<DPtr> tempStack = stack;

  int position = 1;
  while (!tempStack.empty()) {
    DPtr currentPtr = tempStack.top();
    std::cout << "Position " << position << ":" << std::endl;
    currentPtr->print(); 
    std::cout << std::endl;
    tempStack.pop();
    position++;
  }
}

#endif // STACK_H
