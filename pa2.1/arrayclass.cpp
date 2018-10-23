// file:        arrayclass.cpp
// author:      Geoff T
// date:        2017-10-13
// description: implementation of a dynamic array class for CPSC 221 PA2

#include "arrayclass.h"


// default constructor
// Creates an empty ArrayClass with DEFAULTCAPACITY
template <typename T>
ArrayClass<T>::ArrayClass()
{
  _capacity = DEFAULTCAPACITY;
  arr = new T[_capacity];
  _size = 0;
}

// parameterized constructor
// Creates an empty ArrayClass with capacity of n
template <typename T>
ArrayClass<T>::ArrayClass(unsigned int n)
{
  _capacity = n;
  arr = new T[_capacity];
  for (int i = 0; i < _capacity; i++)
  {
    arr[i] = 0;
  }
  _size = 0;
}

// copy constructor
// Creates an ArrayClass as a deep copy of the parameter
template <typename T>
ArrayClass<T>::ArrayClass(const ArrayClass &ac)
{
  _capacity = ac.size;
  arr = new T[_capacity];
  for (int i = 0; i < _capacity; i++)
  {
    arr[i] = ac.arr[i];
  }
}

// destructor
template <typename T>
ArrayClass<T>::~ArrayClass()
{
  delete[] arr;
}

// overloaded assignment operator
template <typename T>
ArrayClass<T> &ArrayClass<T>::operator=(const ArrayClass &ac)
{
  if (&ac != this)
  {
    if (_capacity != ac._size)
    {
      _capacity = ac._size;
    }
  }
  return *this;
}

////////////////////////
// capacity functions //
////////////////////////

// Returns the number of elements stored in the array
template <typename T>
unsigned int ArrayClass<T>::size() const
{
  return _size;
}

// Returns the maximum capacity of the array
template <typename T>
unsigned int ArrayClass<T>::capacity() const
{
  return _capacity;
}

// Resizes the array
// If n is smaller than the size, then only the
//   first n elements are copied to the new array
template <typename T>
void ArrayClass<T>::resize(unsigned int n)
{
  T *temp;
  temp = new T[n];
  for (int i = 0; i < n; i++)
  {
    temp[i] = arr[i];
  }
  delete[] arr;
  arr = temp;
  _capacity = n;
}

// Check if array is empty
// return true if array is empty
template <typename T>
bool ArrayClass<T>::empty() const
{
  if (_size == 0)
    return true;
  else
    return false;
}

// Resizes the array to fit exactly as many items
//   as are stored in the array
template <typename T>
void ArrayClass<T>::shrinkToFit()
{
  if (_size < _capacity)
  {
    _capacity = _size;
  }
}

//////////////////////////////
// element access functions //
//////////////////////////////

// Returns a reference to the element at position i
//   in the array.
// Throws an out_of_range exception if i is outside
//   the bounds of valid elements
template <typename T>
T &ArrayClass<T>::operator[](unsigned int i)
{
  if (i >= _capacity)
  {
    throw std::out_of_range("Out of Range!");
  }
  return arr[i];
}

// Returns a reference to the element at position i
//   in the array.
// Throws an out_of_range exception if i is outside
//   the bounds of valid elements
template <typename T>
T &ArrayClass<T>::at(unsigned int i)
{
  if (i >= _capacity)
  {
    throw std::out_of_range("Out of Range!");
  }
  return arr[i];
}

// Returns a reference to the first element in the array
// Calling this on an empty array throws out_of_range exception
template <typename T>
T &ArrayClass<T>::front()
{
  if (_size == 0)
  {
    throw std::out_of_range("Out of Range!");
  }
  else
  {
    for (int i = 0; i < _size; i++)
    {
      if (arr[i] != NULL)
      {
        return arr[i];
        break;
      }
    }
  }
}

// Returns a reference to the last element in the array
// Calling this on an empty array throws out_of_range exception
template <typename T>
T &ArrayClass<T>::back()
{
  if (_size == 0)
  {
    throw std::out_of_range("Out of Range!");
  }
  return arr[_size - 1];
}

//////////////////////
// modify functions //
//////////////////////

// Add an element at the end
// If array is at capacity before adding, then
//   expand the array to double its capacity and
//   then add.
template <typename T>
void ArrayClass<T>::pushBack(const T &item)
{
  if (_size == _capacity)
  {
    _capacity += 1;
    T *temp = arr;
    arr = new T[_capacity];
    temp[_capacity] = item;
    for (int i = 0; i < _size + 1; i++)
    {
      arr[i] = temp[i];
    }
  }
  else
  {
    T *temp = arr;
    arr = new T[++_size];
    temp[_size] = item;

    for (int i = 0; i < _size + 1; i++)
    {
      arr[i] = temp[i];
    }
    delete[] temp;
  }
}

// Removes the last stored element in the array,
//   reducing container size by 1.
// No effect if called on an empty container
template <typename T>
void ArrayClass<T>::popBack()
{
  if (_size != 0)
  {
    arr[_size - 1] = NULL;
    _size = _size - 1;
  }
}

// Inserts an element before the element at specified position
// Expands the array if necessary
// Elements to the right of position (inclusive) must be shifted
// Throws out_of_range if position is > _size
// POST: item is at position, all elements formerly at position and beyond are shifted
template <typename T>
void ArrayClass<T>::insert(unsigned int position, const T &item)
{
  if (position > _size)
  {
    throw std::out_of_range("Out of Range!");
  }
  else if (_size == _capacity)
  {
    expandArray();
    T *temp = arr;

    for (int i = 0; i <= _capacity; ++i)
    {
      if (i < position)
      {
        temp[i] = arr[i];
      }

      if (i == position)
      {
        temp[i] = item;
      }

      if (i > position)
      {
        temp[i] = arr[i - 1];
      }
    }
    for (int i = 0; i < _capacity; i++)
    {
      arr[i] = temp[i];
    }
  }
}

// Removes an element from the array at specified position.
// Elements to the right of position will be shifted over to fill the gap
// Throws out_of_range if position is >= _size
template <typename T>
void ArrayClass<T>::erase(unsigned int position)
{

  if (position > _size)
  {
    throw std::out_of_range("Out of Range!");
  }
  else
  {
    T *temp = arr;

    for (int i = 0; i <= _capacity; ++i)
    {
      if (i < position)
      {
        temp[i] = arr[i];
      }

      if (i == position)
      {
        temp[i] = 0;
      }

      if (i > position)
      {
        temp[i] = arr[i + 1];
      }
    }

    for (int i = 0; i < _capacity; i++)
    {
      arr[i] = temp[i];
    }
  }
}

// Reallocates stored items into a new array of the same size,
//   starting from specified position
// No effect if position is 0 or >= _size
// e.g. startFrom(3) on {1, 2, 3, 4, 5, 6, 7}
//   produces {4, 5, 6, 7, 1, 2, 3}
template <typename T>
void ArrayClass<T>::startFrom(unsigned int position)
{
  if (position == 0 || position >= _size)
  {
    throw std::out_of_range("Out of Range!");
  }
  else
  {
    T *newArray = arr;
    int tempPosition = position;
    for (int i = 0; i < _size; i++)
    {
      if ((tempPosition >= i) && (tempPosition < _size))
      {
        newArray[i] = arr[tempPosition];
        tempPosition++;
      }
      else
      {
        tempPosition = 0;
        newArray[i] = arr[tempPosition];
        tempPosition++;
      }
    }

    for (int i = 0; i < _capacity; i++)
    {
      arr[i] = newArray[i];
    }
  }
}

//////////////////////
// helper functions //
//////////////////////

// helper method for deep copy
template <typename T>
void ArrayClass<T>::copyArray(const ArrayClass &ac)
{
  for (int i = 0; i < _size; i++)
  {
    ac[i] = arr[i];
  }

  ac._size = _size;
  ac._capacity = _capacity;
}

// helper method for expanding array
template <typename T>
void ArrayClass<T>::expandArray()
{
  _capacity = _capacity * EXPANSIONFACTOR;
}

