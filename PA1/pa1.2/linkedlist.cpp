#include "linkedlist.h"

void LinkedList::copyList(const LinkedList& ll)
{
  deleteList();
  for (unsigned int i = 0; i < ll.length; i++)
  {
    insertBack(ll.elementAt(i));
  }
}

void LinkedList::deleteList()
{
  Node *curr = front, *temp;
  while (curr)
  {
    temp = curr;
    curr = curr->next;
    delete temp;
  }
  length = 0;
  front = back = NULL;
}

void LinkedList::insertFront(Kebab *item)
{
  Node *temp = new Node(item);
  if (length > 0)
  {
    temp->next = front;
    front = temp;
  }
  else
  {
    front = back = temp;
  }
}

void LinkedList::insertBack(Kebab *item)
{
  Node *temp = new Node(item);
  if (length > 0)
  {
    back->next = temp;
    //temp = back->next;
    back = temp;
  }
  else
  {
    front = back = temp;
  }
}

bool LinkedList::insertAt(Kebab *item, unsigned int p)
{
  Node *temp1 = new Node(item);
  Node *temp2;
  if (p > 0 && p < length)
  {
    Node *curr = front;
    while (p > 1)
    {
      curr = curr->next;
      p--;
    }
    temp2 = curr->next;
    curr->next = temp1;
    temp1->next = temp2;
    length++;
    return true;
  }
  else if (p == 0)
  {
    insertFront(item);
    return true;
  }
  else if (p == length)
  {
    insertBack(item);
    return true;
  }
  else
  {
    return false;
  }
}

Kebab* LinkedList::removeAt(unsigned int p)
{

  if (p >= length){
    throw std::invalid_argument("invalid index");
  }
  length--;
  Node*temp = front;
  if (p == 0)
  {
    front = front->next;
    if (length == 0)
      back = NULL;
  }
  else if (p == length)
  {
    temp = back;
  }
  else
  {
    while (p--)
      temp = temp->next;
    
  }
  Kebab* d = temp->data;
  delete temp;
  return d;
  /*
  if (p < 0 || p >= length)
    throw std::invalid_argument("invalid index");
  length--;

  if (p >= 0 && p < length)
  {
    Node *curr = front;
    while (p--)
    {
      curr = curr->next;
    }
    temp->next = curr;
    curr->data;
    delete (curr->data);
  }
  else
  {
    return NULL;
  }
  */
}

unsigned int LinkedList::size() const
{
  return length;
}

bool LinkedList::isEmpty() const
{
  if (front == NULL && back == NULL)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool LinkedList::contains(Kebab& k) const
{
  Node* curr = front;
  while (curr)
  {
    if(curr->data == &k)
    {
      return true;
    }
    curr = curr->next;
  }
  return false;
}

Kebab* LinkedList::elementAt(unsigned int p) const
{
  if (p >= 0 && p < length)
  {
    Node *curr = front;
    while (p--)
    {
      curr = curr->next;
    }
    return curr->data;
  }
  else
  {
    return NULL;
  }
}

LinkedList& LinkedList::operator=(const LinkedList &ll)
{
  if (this != &ll)
  {
    copyList(ll);
  }
  return *this;
}
