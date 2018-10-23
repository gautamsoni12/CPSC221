// file:        queue.cpp

#ifndef _QUEUE_H_

#include "queueprivate.h"
#include "arrayclass.h"
#include "queue.h"

template <typename T>
Queue<T>::Queue()
{
    ac = new ArrayClass<T>;
    front = 0;
    _size = 0;
}

// copy constructor
template <typename T>
Queue<T>::Queue(const Queue &qq)
{ 

    qq= ac;
    qq.size = ac.size;
    qq.front = ac.front;
}
// assignment operator
template <typename T>
Queue<T> &Queue<T>::operator=(const Queue &qq)
{
    this = qq;
    front = qq.front;
    return *this;
}

///////////////
// accessors //
///////////////

// Return true if the queue contains no items
template <typename T>
bool Queue<T>::isEmpty() const
{
    return (ac._size == 0 );
}

// Returns the number of items stored in the queue
template <typename T>
unsigned int Queue<T>::size() const
{
    return ac._size;
}

// Return a reference to the front item of the queue
// Throws an out_of_range exception if the queue is empty
template <typename T>

T &Queue<T>::peek()
{
    if (isEmpty()) 
        {
            throw std::out_of_range("Out of Range!");
        }
    else
    {
        return *this[front];
    }
}

//////////////
// mutators //
//////////////

// Inserts an item to the back of the queue
template <typename T>
void Queue<T>::enqueue(const T item)
{
    
}

// Removes and returns (a copy of) the front item of the queue
// Throws an out_of_range exception if the queue is empty
template <typename T>
T Queue<T>::dequeue()
{
    if (rear == front)
    {
        throw std::out_of_range("Out of Range!");
    }
    else
    {
        auto temp = this[front];
        for (int i = 0; i < rear; i++)
        {
            this[front] = this[front++];
        }
        front--;
        return temp;
    }
}

#endif
