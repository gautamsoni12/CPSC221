

#include "kebab.h"

#ifndef _KEBAB_H_
#define _KEBAB_H_

//std::vector<char> skewer;

//const unsigned int maxlength = SKEWER_SIZE;

bool isValidIngredient(char item)
{
  return (item == 'b' || item == 'B' ||
          item == 't' || item == 'T' ||
          item == 'm' || item == 'M' ||
          item == 'p' || item == 'P' ||
          item == 's' || item == 'S');
}
// Adds item to the pointy end of the skewer
  //   and returns true if skewer has space to add
  //   and item is a valid ingredient
  // Returns false if skewer is full or ingredient is invalid
  bool addIngredient(char item){

    if (skewer.size() < maxlength && isValidIngredient(item)){
        skewer.push_back(item);
        return true;
    } else { 
        return false;
    }
  }
  
    // Adds the ingredients specified by s using addIngredient
    //   up to the capacity of the skewer
    void buildKebab(std::string s){
        const char* itm = s.c_str();
    
        while (skewer.size() < maxlength){
            //addIngredient(itm);
        }
    }
    
  
    // returns the number of meat items on this kebab
    unsigned int numMeats() {
        unsigned int meats = 0;
        for (unsigned int i =0; i < maxlength; i++ ){
            if (skewer[i] == 'b' || skewer[i] == 'B'){
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
    bool hasSameIngredients(Kebab& k){


    }
  
    // Returns a string representing the ingredients on this kebab
    //   in the order in which they are skewered
    std::string listIngredients(){
        std::string listIng;
        for (auto letter : skewer){
            listIng += letter;
        }
    }

    #endif