#include "kebab.h"
#include "linkedlist.h"
#include "grill.h"

// Switches the kebabs at pos1 and pos2
// Returns true if positions are valid and swap can be performed
// Returns false if positions are invalid
Grill::Grill() : rack() {}

bool Grill::swap(unsigned int pos1, unsigned int pos2)
{
    if (pos1 <= (rack.size()) && pos2 <= (rack.size()))
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
Kebab *Grill::request(unsigned int pos)
{

    Kebab *returnKebab = NULL;

    if (pos <= rack.size())
    {

        returnKebab = rack.elementAt(pos - 1);
        rack.removeAt(pos - 1);
    }

    return returnKebab;
}

// remove and return the leftmost kebab matching
// at least the ingredients of r, in any order
// return NULL if no match found
Kebab *Grill::request(Kebab &r)
{
    Kebab *requestedKebab = &r;
    Kebab *matchingKebab;
    for (unsigned int i = 0; i < rack.size(); i++)
    {

        if (rack.elementAt(i)->hasSameIngredients(*requestedKebab))
        {

            matchingKebab = rack.elementAt(i);
            rack.removeAt(i);
        }
    }

    return NULL;
}

void Grill::addKebab(Kebab &n)
{
    rack.insertBack(&n);
}

// arrange in decreasing order of # of meat items
void Grill::sortByMeat()
{
    for (unsigned int i = 0; i < rack.size(); i++)
    {
        unsigned int smallest = i;
        for (unsigned int j = i + 1; j < rack.size(); j++)
        {
            if (rack.elementAt(i) < rack.elementAt(j))
            {
                smallest = j;
            }
        }

        rack.insertAt(rack.elementAt(smallest), i);
    }
}

// returns a vector containing the string representation of all
// kebabs on the grill
std::vector<std::string> Grill::showKebabs() const
{
    std::vector<std::string> kebabs;
    if (rack.size() > 0)
    {
        for (unsigned int i = 0; i < rack.size() + 1; i++)
        {

            kebabs.push_back(rack.elementAt(i)->listIngredients());
        }
        
    }
    return kebabs;
}
