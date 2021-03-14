#include <iostream>
#include "ArrayBag.hpp"
using namespace std;

void displayBag(const ArrayBag<int>& bagToDisplay){
    cout << "The bag contains " << bagToDisplay.getCurrentSize() << " items" << endl;

    vector<int> v = bagToDisplay.toVector();
    for(int i=0; i<v.size(); i++){
        cout<< v[i] << " ";
    }  // end for
    cout << endl << endl;
} // end displayBag

void testBag(ArrayBag<int>& bagToTest){
    cout << "isEmpty(): returns "<< bagToTest.isEmpty() << " should be 1 (true)" << endl;
    displayBag(bagToTest);

    int items[] = {12,13,14,15,16};
    cout << "Add 5 items to the bag: " << endl;
    for(int i=0; i<5; i++){
        bagToTest.add(items[i]);
    }
    displayBag(bagToTest);

    cout << "isEmpty(): returns "<< bagToTest.isEmpty() << " should be 0 (false)" << endl;
    cout << "getCurrentSize: returns " << bagToTest.getCurrentSize() << "; should be 5" << endl;
    cout << "Try to add another entry: add(\"extra\") returns " << bagToTest.add(17) << endl;
} // end bagTester

int main(){
    ArrayBag<int> aBag;
    aBag.add(12);
    aBag.add(12);
    aBag.add(13);
    aBag.add(14);

    cout << "Frequency of 12 is: " << aBag.getFrequencyOf(12) << endl;
    vector<int> v = aBag.toVector();
    for(int i=0; i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;
    aBag.remove(12);
    v = aBag.toVector();
     for(int i=0; i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;
    aBag.remove(12);
    v = aBag.toVector();
     for(int i=0; i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;
    cout << aBag.remove(14) << endl;
    v = aBag.toVector();
     for(int i=0; i<v.size();i++){
        cout << v[i] << " ";
    }
    return 0;
} // end main


// Question 3 What is an advantage and a disavantage of calling the method getFrequencyOf from contains
// Advantage: writing less code, do same thing
// Disadvantage: You don't need to traverse the all array