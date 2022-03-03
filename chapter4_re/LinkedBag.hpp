/** @file LinkedBag.hpp*/

#ifndef Linked_bag_hpp
#define Linked_bag_hpp

#include "BagInterface.hpp"
#include "Node.hpp"
using namespace std;

template<class ItemType>
class LinkedBag: public BagInterface<ItemType>{
private:
    Node<ItemType>* headPtr; // points to the head
    Node<ItemType>* tailPtr;
    int             itemCount; // current item amount in bag

    Node<ItemType>* getPointerTo(const ItemType& anEntry) const;
public:
    LinkedBag();
    LinkedBag(const LinkedBag<ItemType>& aBag);
    ~LinkedBag();
    int getCurrentSize() const;
    bool isEmpty() const;
    bool add(const ItemType& newEntry);
    bool remove(const ItemType& anEntry);
    void clear();
    bool contains(const ItemType& anEntry) const;
    int getFrequencyOf(const ItemType& anEntry) const;
    vector<ItemType> toVector() const;
}; // end LinkedBag
#endif

/** Implementation File */

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(): headPtr(nullptr), tailPtr(nullptr), itemCount(0)
{

} // end default constructor

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag){
    // Main purpose is to create a same linked chain
    Node<ItemType>* currentNode = aBag.headPtr;
    itemCount = aBag.itemCount;
    headPtr = new Node<ItemType>(currentNode->getItem());
    
    Node<ItemType>* previousNode = headPtr;
    currentNode = currentNode->getNext();
    if(isEmpty()){
        headPtr = tailPtr = nullptr;
    }else if(itemCount == 1){
        headPtr = tailPtr;
        tailPtr->setNext(nullptr);
    }else{
        while(currentNode!=nullptr){
            Node<ItemType>* newNode = new Node<ItemType>(currentNode->getItem(), nullptr);
            // link previous node and newNode
            previousNode->setNext(newNode);
            // Change what previous node points to
            previousNode = newNode;
            // Advance current node to original nodes next node
            currentNode = currentNode->getNext();
            if(currentNode == nullptr)
                tailPtr = previousNode;
        } // end while
    }
} // end copy constructor

template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry){
    Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry,nullptr);
    if(isEmpty()){
        headPtr = tailPtr = newNodePtr;
        itemCount++;
    }else{
        tailPtr->setNext(newNodePtr);
        tailPtr = newNodePtr;
        itemCount++;
    }
    return true;
} // end add

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const{
    return itemCount==0;
} // end isEmpty

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const{
    return itemCount;
} // end getCurrentSize

template<class ItemType>
vector<ItemType> LinkedBag<ItemType>::toVector() const{
    Node<ItemType>* currentNode = headPtr;
    vector<ItemType> v;
    int counter = 0;
    while (currentNode!=nullptr && (counter < itemCount))
    {
        v.push_back(currentNode->getItem());
        currentNode = currentNode->getNext();
        counter++;
    } // end while
    return v;
} // end toVector

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry){
    if(isEmpty() || getPointerTo(anEntry) == nullptr){
        return false;
    }else if(itemCount == 1 && headPtr->getItem() == anEntry){
        delete headPtr;
        headPtr = tailPtr = nullptr;
        itemCount = 0;
    }else{
        Node<ItemType>* nodetoDelete = nullptr;
        Node<ItemType>* currentNode = headPtr;
        while(currentNode!=nullptr){
            if(currentNode->getNext()->getItem() == anEntry){
                nodetoDelete = currentNode->getNext();
                currentNode->setNext(nodetoDelete->getNext());
                nodetoDelete->setNext(nullptr);
                delete nodetoDelete;
                nodetoDelete = nullptr;
                itemCount--;
                break;
            }else{
                currentNode = currentNode->getNext();
            }
        } // end while
    }
    return true;
} // end remove

template<class ItemType>
void LinkedBag<ItemType>::clear(){
    while(headPtr!=nullptr && itemCount!=0){
        if(itemCount == 1){
            delete headPtr;
            headPtr = tailPtr = nullptr;
            itemCount--;
        }
        Node<ItemType>* nodeToDelete = headPtr;
        headPtr = headPtr->getNext();
        nodeToDelete->setNext(nullptr); // fail-safe programming
        delete nodeToDelete;
        nodeToDelete = nullptr;
        itemCount--;
    }
    itemCount = 0;
} // end clear

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const{
    return getPointerTo(anEntry) != nullptr;
} // end contains

template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const{
    int frequency = 0;
    int i = 0;
    Node<ItemType>* currentNode = headPtr; // traverse
    while(currentNode!=nullptr && i<itemCount){
        if(currentNode->getItem() == anEntry)
            frequency++;
        currentNode = currentNode->getNext();
    } // end while
    return frequency; // STUB
} // end getFrequencyOf

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag(){
    clear();
}

template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& anEntry) const{
    Node<ItemType>* nodeToBeReturned = headPtr;
    if(isEmpty()){
        nodeToBeReturned = nullptr;
    }else{
        while(nodeToBeReturned != headPtr){
            if(anEntry == nodeToBeReturned->getItem()){
                break;
            }else{
                nodeToBeReturned = nodeToBeReturned->getNext();
            }
        } // end while
    }
    return nodeToBeReturned;
}