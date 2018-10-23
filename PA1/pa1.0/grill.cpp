#ifndef _GRILL_H_
#define _GRILL_H_

#include "linkedlist.h"

LinkedList rack;

// Switches the kebabs at pos1 and pos2
// Returns true if positions are valid and swap can be performed
// Returns false if positions are invalid
bool swap(unsigned int pos1, unsigned int pos2)
{
    if (pos1 < rack.size() && pos2 < rack.size())
    {
        unsigned int temp = pos1;
        pos1 = pos2;
        pos2 = temp;
        return true;
    }
    else
    {
        return false;
    }
}

// remove and return the kebab at a 1-indexed
// position on the grill
// return NULL if pos invalid
Kebab *request(unsigned int pos)
{
}

// remove and return the leftmost kebab matching
// at least the ingredients of r, in any order
// return NULL if no match found
Kebab *request(Kebab &r);

void addKebab(Kebab &n);

// arrange in decreasing order of # of meat items
void sortByMeat()
{
}

// returns a vector containing the string representation of all
// kebabs on the grill
std::vector<std::string> showKebabs()
{
}

#endif