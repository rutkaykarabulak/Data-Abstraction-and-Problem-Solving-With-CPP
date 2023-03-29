/** Linked based implementation of ADT sorted list
 * @file LinkedSortedList.cpp
*/

#ifndef LinkedSortedList_cpp
#define LinkedSortedList_cpp

#include "./SortedListInterface.hpp"
#include "../components/DoublyNode.cpp"

template<class ItemType>
class LinkedSortedList: public SortedListInterface<ItemType> {
private:
    int itemCount;
    DoublyNode<ItemType>* head;
    DoublyNode<ItemType>* tail;

    /// @brief Searchs for a node that should be placed right after the given new entry.
    /// @param newEntry entry to be added right before the existing node in this list.
    /// @return Node that should be placed right after the new entry.
    DoublyNode<ItemType>* getNodeBefore(const ItemType& newEntry) const; 
public:
    LinkedSortedList();
    LinkedSortedList(const LinkedSortedList<ItemType>& aList);
    virtual ~LinkedSortedList();

    void insertSorted(const ItemType& newEntry);
    bool removeSorted(const ItemType& anItem);
    int getPosition(const ItemType& anItem) const;
    
    bool remove(int position);
    bool isEmpty() const;
    int getLength() const;
    void clear();
    ItemType getEntry(int position) const;
    /// @brief displays all item in this list. If there is any
    void display();

};
#endif

// Implementation file 
template<class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList(): itemCount(0), head(nullptr), tail(nullptr) 
{}

template<class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList(const LinkedSortedList<ItemType>& list) 
{
    if (list.head == nullptr && list.tail == nullptr) {
        // original list is empty so this 
        itemCount = 0;
        head = nullptr;
        tail = nullptr;
    } else {
        DoublyNode<ItemType>* currentNode = list.head;
        DoublyNode<ItemType>* lastNode = nullptr;

        head = new DoublyNode<ItemType>(currentNode->getItem());
        itemCount++;
        lastNode = head;

        while (currentNode != list.tail) {
            currentNode = currentNode->getNext();
            DoublyNode<ItemType>* newNode = new DoublyNode<ItemType>(currentNode->getItem());
            newNode->setPrevious(lastNode);
            lastNode->setNext(newNode);
            lastNode = newNode;
            itemCount++;
        } // current node is tail now
        tail = new DoublyNode<ItemType>(currentNode->getItem());
        tail->setPrevious(lastNode);
        itemCount++;
    } // end
}

template<class ItemType>
LinkedSortedList<ItemType>::~LinkedSortedList() {
    clear();
}

template<class ItemType>
void LinkedSortedList<ItemType>::clear() {
    // stub
}

template<class ItemType>
void LinkedSortedList<ItemType>::insertSorted(const ItemType& newItem) {
    DoublyNode<ItemType>* newNode = nullptr;
    // get the node before 
    DoublyNode<ItemType>* nodeBefore = getNodeBefore(newItem);
    if (nodeBefore == nullptr) {
        // add to beginning
        newNode = new DoublyNode<ItemType>(newItem);
        head = tail = newNode;
    } else {
        
        // initialize the new node
        newNode = new DoublyNode<ItemType>(newItem);
        // store the possible node of nodeBefore 
        DoublyNode<ItemType>* nextNodeOfBefore = nodeBefore->getNext(); // it can be nullptr
        // create the chain
        newNode->setPrevious(nodeBefore);
        nodeBefore->setNext(newNode);
        if (nextNodeOfBefore != nullptr) {
            nextNodeOfBefore->setPrevious(newNode);
        }
        newNode->setNext(nextNodeOfBefore);
    }
    itemCount++;
}

template<class ItemType>
bool LinkedSortedList<ItemType>::isEmpty() const {
    return itemCount == 0;
}

template<class ItemType>
bool LinkedSortedList<ItemType>::removeSorted(const ItemType& anEntry) {
    return false; // stub
}

template<class ItemType>
int LinkedSortedList<ItemType>::getLength() const {
    return itemCount;
}

template<class ItemType>
int LinkedSortedList<ItemType>::getPosition(const ItemType& newEntry) const {
    int position = 1;
    DoublyNode<ItemType>* currentNode = head;

    while (currentNode != nullptr && currentNode->getItem() < newEntry) {
        currentNode = currentNode->getNext();
        position++
    }
    return position;
}

template<class ItemType>
bool LinkedSortedList<ItemType>::remove(int position) {
    return false; // stub
}

template<class ItemType>
ItemType LinkedSortedList<ItemType>::getEntry(int position) const {
    ItemType item;
    return item; // stub
}

template<class ItemType>
DoublyNode<ItemType>* LinkedSortedList<ItemType>::getNodeBefore(const ItemType& anItem) const {
    // if (isEmpty()) {
    //     string errMessage = "Attempting to retreive from empty list";
    //     throw logic_error(errMessage);
    // }

    DoublyNode<ItemType>* currentNode = head;
    DoublyNode<ItemType>* result = nullptr;

    while (currentNode != nullptr && currentNode->getItem() < anItem) {
        result = currentNode;
        currentNode = currentNode->getNext();
    }

    return result;
}

template<class ItemType>
void LinkedSortedList<ItemType>::display() {
    if (!isEmpty()) {
        auto currentNode = head;
        while (currentNode != nullptr) {
            std::cout<< currentNode->getItem() << " ";
            currentNode = currentNode->getNext();
        }
    }
}