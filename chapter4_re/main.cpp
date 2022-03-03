#include <iostream>
#include "LinkedBag.hpp"
using namespace std;

void displayBag(BagInterface<string>* bagPtr)
{
   cout << "The bag contains " << bagPtr->getCurrentSize()
   << " items:" << endl;
	vector<string> bagItems = bagPtr->toVector();
   
   int numberOfEntries = (int)bagItems.size();
   for (int i = 0; i < numberOfEntries; i++)
   {
      cout << bagItems[i] << " ";
   }  // end for
   cout << endl << endl;
}  // end displayBag

void bagTester(BagInterface<string>* bagPtr)
{
   cout << "isEmpty: returns " << bagPtr->isEmpty()
   << "; should be 1 (true)" << endl;
   
   string items[] = {"one", "two", "three", "four", "five", "one"};
   cout << "Add 6 items to the bag: " << endl;
   for (int i = 0; i < 6; i++)
   {
      bagPtr->add(items[i]);
   }  // end for
   
   displayBag(bagPtr);
   cout << "isEmpty: returns " << bagPtr->isEmpty()
   << "; should be 0 (false)" << endl;
   cout << "getCurrentSize returns : " << bagPtr->getCurrentSize()
   << "; should be 6" << endl;
   cout << "Try to add another entry: add(\"extra\") returns "
   << bagPtr->add("extra") << endl;
}  // end bagTester


int main(){
   BagInterface<string>* bagPtr = new LinkedBag<string>();
   bagPtr->add("12");
   bagPtr->add("13");
   bagPtr->add("14");
   bagPtr->add("15");
   displayBag(bagPtr);
   return 0;
} // end main