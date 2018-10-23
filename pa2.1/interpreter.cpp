// file:        interpreter.h
// author:      Jack S-J, Geoff T
// date:        2017-10-17
// description: declaration of an postfix-like interpreter class for CPSC 221 PA2
//              This file should not be modified
//              If you want to implement private helper functions,
//                you may do so in interpreterprivate.h

////////////////////////////////////////////////////////////////////////////////
// Information about the operators and operands used in the Interpreter class //
////////////////////////////////////////////////////////////////////////////////
//
// Operators include postfix mathematical operators +, -, *, /, ^
// +: addition
// -: subtraction
// *: multiplication
// /: (integer) division
// ^: exponentiation, implemented recursively as repeated squares as in HW2
// ***IMPORTANT*** note that the result of the mathematical operators
//   is to be enqueued in tube, rather than pushed to bin.
// 
// Additionally, there are special operators RQ, PRINT, and #
// RQ: re-enqueues all bin contents into the tube (in order of stack removal),
//     but bin must remain unchanged after execution of RQ.
//     A space-delimited string is constructed from the removed bin contents
// PRINT: empties the tube, constructs and returns a space-delimited string
//        from the removed items
// #: This executes nothing and never explicitly appears in any instruction string,
//    but is added to the tube to indicate the end of a loaded instruction
//
// Operands are integers and can take positive or negative values.
// Note that they will be stored in the tube as strings, and therefore
// you must be able to distinguish the string "-3" as the operand -3,
// and "- 3" as the subtraction operator followed by the operand 3.
// 

#include "stack.h"
#include "queue.h"
#include "interpreter.h"
#include "interpretersecretfunctions.h"

// executes an operator, returns a string of execution result
// most operators will return the empty string "", except for RQ, PRINT
// If an operator causes a container exception, throw the caught exception
std::string execOp(std::string optr){
    if (optr == RQ){
        String removed;
        while !(bin.isEmpty()){
            removed = removed + bin.peek();
            tube.enqueue(bin.pop())           
        }
        return removed;
    }
    if (optr == PRINT) {
        String removed;
        while (!tube.isEmpty()){
            removed = removed + tube.dequeue();
        }
    }
    else {
        try {
            String result;
            while (!tube.isEmpty){
                result = result optr tube.dequeue(); 
            }
            catch (exception e){

            }
        }
    }
}

// Exponentiation function calculates x^y
//   by repeated squaring (refer to HW2)
// You may implement this either iteratively or recursively
// PRE: y >= 0
int recpow(int x, int y) {
    if (y == 0) {
        return 1;
    } else {
        for (int i = 0; i <= y; i++) {
            x = x + x;
        }
        return x;
    }
}

// converts an integer to a string
std::string toString(int num) {
    std::string result;
    std::ostringstream oss;
    oss << num;
    return oss.str();
}

// converts a string to an integer
int toInt(std::string s) {
    std::stringstream ss(s);
    int result = 0;
    ss >> result;
    return result;
}

// default constructor

Interpreter::Interpreter() {
    tube = new Queue();
    bin = new Stack();
    sparebin = new Stack<T>;

}

// copy constructor

Interpreter::Interpreter(const Interpreter &itpt){
    tube = itpt.tube;
    bin = itpt.bin;
    sparebin = itpt.sparebin;
}

// assignment operator

Interpreter &Interpreter::operator=(const Interpreter &itpt){

    tube = itpt.tube;
    bin = itpt.bin;
    sparebin = itpt.sparebin;
    return *this;
}

// Loads a single instruction into the tube
// Requires parsing the instruction into operators and operands
// If tube already contains items, the instruction is loaded
//   without clearing the tube contents
// This should inject a "#" operator at the end
void load(std::string instruction){
    tube.enqueue("#");
    std::string *instruction = tube.dequeue();
    bin.push(instruction);
}

// Returns whether there are still items in the tube to be processed
bool hasMoreInstructions(){
    if(tube.size == 0){
        return false;
    }
    return true;
}

// Remove and execute next instruction
// i.e. until a #, empty tube, print, or other error encountered
// The output of any operator(s) will be returned
// If an attempt to execute an operator causes an exception,
//   throw the caught exception
std::string next(){

  string curr = tube.dequeue();
  string result;

  if (isdigit(curr[0]) && !(curr.empty()) ) {
    int operand = std::stoi(curr);
    bin.push(operand);

    return "";
  } else if (curr[0] == '-' && isdigit(curr[1])) {
    int operand = std::stoi(curr);
    bin.push(operand);
    return "";
  } else {
    try {
      result = execOp(curr);
    } catch (exception e) {
    }

    return result;
  }

}

// Execute remaining instructions
// The outputs of each instruction will be
// appended into a single string, separated by the
// newline character '\n'. The last instruction
// will NOT be followed by a newline.
std::string run(){
  string result;
  while (hasMoreInstructions()) {
    result.append(next());
    if (hasMoreInstructions()) {
      result += "\n";
    }
  }

  return result;
}

// Clears the contents of all member containers (tube, bin, sparebin)
void clear(){
    for (int i = 0; i < tube.size(); i ++ ){
        tube.erase(i);
    }
    for (int i = 0; i < bin.size(); i ++ ){
        bin.erase(i);
    }
    for (int i = 0; i < sparebin.size(); i ++ ){
        sparebin.erase(i);
    }
}

// This function will only be used for testing.
// Do not remove this include header (it may cause your code to not compile while grading)
