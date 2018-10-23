
#include "kebab.h"
#include "linkedlist.h"


bool Kebab::addIngredient(char item)
{

    if (skewer.size() < maxlength && isValidIngredient(item))
    {
        skewer.push_back(item);
        return true;
    }
    else
    {
        return false;
    }
}

void Kebab::buildKebab(std::string s)
{
    //std::vector<char> itm = s.c_str();

    //for (int i = 0; i < itm.size(); ++i)
    

        if (skewer.size() < maxlength)
        {
            if (isValidIngredient(s.c_str())){
                skewer.addIngredient(s])
            }
            
        }
    
    // while (skewer.size() < maxlength){
    //     //addIngredient(itm);
}

// returns the number of meat items on this kebab
unsigned int Kebab::numMeats() const
{
    unsigned int meats = 0;
    for (unsigned int i = 0; i < maxlength; i++)
    {
        if (skewer[i] == 'b' || skewer[i] == 'B')
        {
            meats++;
        }
    }

    return meats;
}

// Returns true iff this kebab contains at least the same collection
// of ingredients as k, in any order
// Note that this kebab may contain more total ingredients than k,
// but will return true as long as this kebab's ingredients is
// a super-multiset of k's ingredients
bool Kebab::hasSameIngredients(Kebab& k) const
{

    const* char givenKebab = k;
    bool toggle = false;

    for (unsigned int i = 0; i < givenKebab.size(); i++)
    {
        for (unsigned int j = 0; j < skewer.size(); j++)
        {
            if (givenKebab[j] == skewer[j])
            {
                toggle = true;
            }
        }
        if (toggle == false)
        {
            return false;
        }
    }

    return true;
}

// Returns a string representing the ingredients on this kebab
//   in the order in which they are skewered
std::string Kebab::listIngredients() const
{
    std::string listIng;
    for (auto letter : skewer)
    {
        listIng += letter;
    }
}
