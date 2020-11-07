#include <iostream>
#include "LinkedBag.hpp"
#include "BagInterface.hpp"
#include "ArrayBag.hpp"
#include <cctype>

using namespace std;

/*template<class ItemType>
void deleteSecondNode(Node<ItemType>* headPtr){
    // store the second node which headptr points.
Node<ItemType>* secondNode = headptr->getNext();

// break the link between second node and headptr
headPtr->setNext(nullptr);

// delete content of secondNode
delete secondNode;
// avoid to dangling pointer
secondNode = nullptr;
// decrease item size in bag via decrease itemcount
itemcount--;
} */

// now test time
void displayBag(BagInterface<int>* bagPtr){
    cout << "current size of bag is: " << bagPtr->getCurrentSize() << endl;

    vector<int> bagContents = bagPtr->toVector();

    for(int i=0 ; i<bagContents.size(); i++){
        cout << bagContents[i] << " " ;
    }

    cout << endl << endl;
    }

void bagTester(BagInterface<int>* bagPtr){
    cout << "isEmpty() returns: " << bagPtr->isEmpty() << "should be 1(true)" <<  endl;

    int items[] = {12,13,14,15,16};
    cout << "Adding 5 item to bag: " << endl;
    for(int i=0 ; i<5; i++){
        bagPtr->add(items[i]);
    }  // end for
    displayBag(bagPtr);
    cout << "isEmpty() returns: " << bagPtr->isEmpty() << " should be 0(false)" << endl << endl;

    cout << "getCurrentSize() returns: " << bagPtr->getCurrentSize() << " should be 5" << endl << endl;

    cout << "Trying to add another elements which is add('17')" << bagPtr->add(17) << endl << endl;

}

int main(){

  LinkedBag<int> bag;

  

    return 0;
}

 