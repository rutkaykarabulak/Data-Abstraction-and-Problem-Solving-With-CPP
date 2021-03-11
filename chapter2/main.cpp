/** @file main.cpp */
#include <iostream>
/**
 Note: Four questions for constructing recursive solutions
1. How can you define the problem in terms of a smaller problem of the same type?
2. How does each recursive call diminish the size of the problem?
3. What instance of the problem can serve as the base case?
4. As the problem size diminishes, will you reach this base case?
*/
#include <string>
using namespace std;
/** Writes string in reverse way
 @pre length of the given string must be greater than 0
 @post printed string in backward
 @return none
*/
void writeBackwards(string s){
    if(s.length()==1){
        cout << s << endl; // base case
    }else{
        cout << s[s.length()-1];
        writeBackwards(s.substr(0,s.length()-1));
    }
}

// Product of first n>=1 real number in array
#include <vector>
int product(vector<int> aVector, int firstN){
    if(firstN>=1){
        return aVector[firstN-1] * product(aVector,firstN-1);
    }else{
        return 1;
    }
}

// Binary search

/** Searches the array for a given value by using a binary search
 * @pre 0<=first and last<= SIZE - 1 where size is the maximum size of the array
 * @post anArray is unchanged and either anArray contains the given value or index == -1
 * @param anArray the array to search
 * @param first the low index to start searching from
 * @param last the high index to stop searching at
 * @param target the search key
 * @return either index, such that anArray[Index] == target or -1
*/
int binarySearch(const int anArray[], int first, int last, int target){
    int index;
    if (first > last)
    {
        return -1;
    }else{
        int mid = first + (last - first) / 2;
        if(anArray[mid] == target){
            return mid;
        }else if(target>anArray[mid]){
            index = binarySearch(anArray,mid+1,last,target);
        }else{
            index = binarySearch(anArray,first, mid-1,target);
        }
    }
    return index;
}

// Finding the largest value in array using recursion
// MUltipath recursion
int largestValueInArray(const int anArray[], int first, int last){
    int overallMax;
    if(first == last){
        return anArray[first];
    }else{
        int mid = first + (last - first) / 2;
        int maxLeft = largestValueInArray(anArray, first, mid);
        int maxRight = largestValueInArray(anArray, mid+1, last);
        
        overallMax = max(maxLeft, maxRight);
    }
    return overallMax;
}

// Finding the kth samllest value of an array using recursion
int kthSmalleshValue(const int anArray(), int first, int last){
     // To Do
     return 1;
}

// The Towers of Hanoi
// A: Source, B: Destination, C: The Spare
// Base Case: when n=1, move disk from source to detination 
void toh(const int& count, char source, char destination, char spare){
    if(count == 1){
        cout << "Move top disk from pole " << source << " to pole " << destination << endl;
    }else{
        toh(count-1, source, spare, destination);
        toh(1,source, destination, spare);
        toh(count-1, spare, destination, source);
    }
}

// The Fibonacci Sequence (Multiplying Rabbits)
// Base case rabbit(n): rabbit(n-1) + rabbit(n-2)
// rabbit(n) finds the amount of rabbit in given minth input
int rabbit(const int& month){
    if(month <= 2){
        return 1;
    }else{
        return rabbit(month-1) + rabbit(month-2);
    }
} // end rabbit 
// When recursive solution of problem is computing same value more than once
// (in this case rabbit(3)), we say that solution is inefficient.

// Choosing k out of n things
/** Computes the number of groups of k out of n things. @pre n and k are nonnegative integers.
@post None.
@param n The given number of things.
@param k The given number to choose.
@return g(n, k). */
int getNumberOfGroups(int n, int k) {
    if ( (k == 0) || (k == n) )
        return 1;
    else if (k > n)
        return 0;
    else
        return getNumberOfGroups(n - 1, k - 1) + getNumberOfGroups(n - 1, k);
} // end getNumberOfGroups

int iterativeRabbit(int n){
    int previous = 1;
    int current = 1;
    int next = 1; // Result when n is 1 or 2

    for(int i = 3; i<=n ; i++){
        next = current + previous;
        previous = current;
        current = next;
    } // end for
    return next;
}
int main(){
    cout << iterativeRabbit(6) << endl;
    return 0;
}
