/**
 * @file quackfun.cpp
 * This is where you will implement the required functions for the
 *  stacks and queues portion of the lab.
 */
#include<iostream>
using namespace std;


namespace QuackFun {

    /**
     * Sums items in a stack.
     * @param s A stack holding values to sum.
     * @return The sum of all the elements in the stack, leaving the original
     *  stack in the same state (unchanged).
     *
     * @note You may modify the stack as long as you restore it to its original
     *  values.
     * @note You may use only two local variables of type T in your function.
     *  Note that this function is templatized on the stack's type, so stacks of
     *  objects overloading the + operator can be summed.
     * @note We are using the Standard Template Library (STL) stack in this
     *  problem. Its pop function works a bit differently from the stack we
     *  built. Try searching for "stl stack" to learn how to use it.
     * @hint Think recursively!
     */
    template <typename T>
    T sum(stack<T>& s)
    {
        if (s.empty()){
            return T();
        } else {
            T temp = s.top();
            s.pop();
            T result = temp + sum(s);
            s.push(temp);
            return result;
        }
       
    }

    /**
     * Reverses even sized blocks of items in the queue. Blocks start at size
     * one and increase for each subsequent block.
     * @param q A queue of items to be scrambled
     *
     * @note Any "leftover" numbers should be handled as if their block was
     *  complete.
     * @note We are using the Standard Template Library (STL) queue in this
     *  problem. Its pop function works a bit differently from the stack we
     *  built. Try searching for "stl stack" to learn how to use it.
     * @hint You'll want to make a local stack variable.
     */
    template <typename T>
    void scramble(queue<T>& q)
    {
        stack<T> s;
         int r_size = 1;
         int sum = 0;
         int qSize = q.size();
         bool reverse = false;
         bool isScrambled = false;

         while (!isScrambled){
             if ((sum + r_size) > qSize){
                 r_size = qSize - sum;
                 if (reverse){
                     for (int i = 1; i <= r_size; i++){
                         s.push(q.front());
                         q.pop();
                     }
                     for (int i = 1; i <= r_size; i ++){
                         q.push(s.top());
                         s.pop();
                     }
                 }
             }else {
                 for (int i = 1; i <= r_size; i ++){
                     q.push(q.front());
                     q.pop();
                 }
             }
         }
         reverse = !reverse;
         sum += r_size;
         r_size++;

         if (sum == qSize){
             isScrambled = true;
         }


    }

    /**
     * @return true if the parameter stack and queue contain only elements of
     *  exactly the same values in exactly the same order; false, otherwise.
     *
     * @note You may assume the stack and queue contain the same number of items!
     * @note There are restrictions for writing this function.
     * - Your function may not use any loops
     * - In your function you may only declare ONE local boolean variable to use in
     *   your return statement, and you may only declare TWO local variables of
     *   parametrized type T to use however you wish.
     * - No other local variables can be used.
     * - After execution of verifySame, the stack and queue must be unchanged. Be
     *   sure to comment your code VERY well.
     */
    template <typename T>
    bool verifySame(stack<T>& s, queue<T>& q)
    {
        bool retval = true; // optional
        //T temp1; // rename me
        //T temp2; // rename :)

        return retval;
    }
}
