// file:        stack.h
// author:      Geoff T
// date:        2017-10-08
// description: declaration of a stack class for CPSC 221 PA2
//              This file should not be modified
//              If you want to implement private helper functions,
//                you may do so in stackprivate.h

#ifndef _STACK_H_


#include "stack.h"
#include "arrayclass.h"
#include "stackprivate.h"

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
    ArrayClass<T> newStack = new ArrayClass();
    for (int index = 0; index < st.size(); index++)
    {
        newStack[index] = st[index];
    }
}

// assignment operator
template <typename T>
Stack<T> &Stack::operator=(const Stack &st)
{
    ac = st;
    return ac;

}

///////////////
// accessors //
///////////////

// Return true if the stack contains no items
template <typename T>
bool Stack<T>::isEmpty() const
{
    return ac.empty();
}

// Returns the number of items stored in the stack
template <typename T>
unsigned int Stack<T>::size() const
{
    if (isEmpty())
    {
        return 0;
    }
    else
    {
        return ac.size();
    }
}

// Return a reference to the top item of the stack
// Throws an out_of_range exception if the stack is empty
T& Stack<T>::peek()
{
    ac.back();
}

//////////////
// mutators //
//////////////

// Pushes an item to the top of the stack
template <typename T>
void Stack<T>::push(const T item)
{
    ac.pushBack(item);
}

// Removes and returns (a copy of) the top item of the stack
// Throws an out_of_range exception if the stack is empty
template <typename T>
T Stack<T>::pop()
{
    auto x = ac.back();
    ac.popBack();
    return x;
}

#endif