#ifdef _LINKEDLIST_H_
#include <stdexcept>

//template <typename ItemType>
void LinkedList<Kebab>::copyList (const LinkedList& ll){
  deleteList();
  for (int i =0; i < ll.length; i++){
    insertBack(ll.elementAt[i]);
  }
}

//template <typename ItemType>
void LinkedList<ItemType>::deleteList(){
  Node<Kebab> * curr = front, *temp;
  while (curr){
    temp = curr;
    curr = curr->next;
    delete temp;
  }
  length = 0;
  front = back = NULL;
}

void LinkedList<Kebab>::insertFront(Kebab* item){
  Node<Kebab> * temp = new Node<Kebab>(item);
  if (length > 0){
    temp->next = front;
    front = temp->next;
    front = temp;
  }else{
    front = back = temp;
  }
}

void LinkedList<Kebab>::insertBack(Kebab* item){
  Node<Kebab>* temp = new Node<Kebab> (item);
  if (length > 0){
    back->next = temp;
    temp = back->next;
    back = temp;
  }
  else{
    front = back = temp;
  }
}

bool insertAt(Kebab* item, unsigned int p){
  Node<Kebab>* temp = new Node<Kebab> (item);
  if (p > 0 && p < length){
    Node<Kebab> * curr = front;
    while (p--){
      curr = curr->next;
    }
    curr->next = temp->data;
    return true;
  }
  else{
    return false;
  }
}

Kebab* removeAt(unsigned int p){
  f (p >= 0 && p < length){
    Node<Kebab>* curr = front;
    while (p--){
      curr = curr->next;
    }
    return curr->data;
    delete(curr->data);
  }else
  {
    return NULL;
  }

}

unsigned int size() {
  return length;
}


  bool isEmpty() {
    if (front == NULL && back == NULL){
      return true;
    } else {
      return false;
    }
  }

  bool contains(Kebab& k){
    Node<Kebab> * curr = front;
    while (curr){
      if (curr->data == k){
        return true;
      }
      curr = curr->next;
    }
    return false;
  }

  Kebab* elementAt(unsigned int p) {
    if (p >= 0 && p < length){
      Node<Kebab>* curr = front;
      while (p--){
        curr = curr->next;
      }
      return curr->data;
    }else{
      return NULL;
    }
  }

  LinkedList& operator=(const LinkedList& ll){
    if (this != ll) {
      copyList(ll);
    }
    return *this;
  }
#endif