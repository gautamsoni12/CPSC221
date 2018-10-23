// file:        stack.h
// author:      Geoff T
// date:        2017-10-08
// description: declaration of a stack class for CPSC 221 PA2
//              This file should not be modified
//              If you want to implement private helper functions,
//                you may do so in stackprivate.h

#ifndef _STACK_H_
#define _STACK_H_

#include <tkDecls.h>
#include "stack.h"
#include "arrayclass.h"

// default constructor
template <typename T>
Stack<T>::Stack()
{
    ac = new ArrayClass();
}

// copy constructor
template <typename T>
Stack<T>::Stack(const Stack<T> &st)
{
    ArrayClass<T> newStack = new ArrayClass(st.size());
    for (int index = 0; index < st.size(); index++)
    {
        newStack[index] = st[index];
    }
}

// assignment operator
template <typename T>
Stack<T> &Stack::operator=(const Stack &st)
{
    Stack temp = st;
    std::swap(st.size(), temp.size());
    std::swap(st.top, temp.top);
}

///////////////
// accessors //
///////////////

// Return true if the stack contains no items
template <typename T>
bool Stack<T>::isEmpty() const
{
    if (top == -1)
    {
        return true;
    }
    return false;
}

// Returns the number of items stored in the stack
template <typename T>
unsigned int Stack<T>::size() const
{
    if (top == -1)
    {
        return 0;
    }
    else
    {
        return this.top;
    }
}

// Return a reference to the top item of the stack
// Throws an out_of_range exception if the stack is empty
T& Stack<T>::peek()
{
    if (this.isEmpty())
    {
        throw("Out Of Range");
    }
    else
    {
        return &this[top];
    }
}

//////////////
// mutators //
//////////////

// Pushes an item to the top of the stack
template <typename T>
void Stack<T>::push(const T item)
{
    this[++this.size()] = item;
    top++;
}

// Removes and returns (a copy of) the top item of the stack
// Throws an out_of_range exception if the stack is empty
template <typename T>
T Stanck<T>::pop()
{
    int toBePopped = this.size()--;
    auto x = a[toBePopped];
    free(this[toBePopped]);
    return x;
}

#include "stack.cpp"

#endif