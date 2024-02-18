/** @file BinaryTreeInterface.hpp 
 * Interface file for binary tree.
 * @author rutkaykarabulak@gmail.com
*/

#ifndef BinaryTreeInterface_cpp
#define BinaryTreeInterface_cpp

#include <stdexcept>

template<class ItemType>
class BinaryTreeInterface {
public:
    /// @brief Checks whether this binary tree is empty or not.
    /// @return True if there is no element in this binary tree, false otherwise.
    virtual bool isEmpty() const = 0;

    /// @brief Gets the height of this binary tree.
    /// @return Height of this binary tree.
    virtual int getHeight() const = 0;

    /// @brief Gets the number of elements in this binary tree.
    /// @return Number of elements in this binary tree.
    virtual int getNumberOfNodes() const = 0;

    /// @brief Gets the root data of this binary tree.
    /// @return Data of the root. 
    virtual ItemType getRootData() const = 0;

    /// @brief Replaces the root data with given newData. 
    /// If the tree is empty, inserts a new node containing the given data,
    /// and set its as a root of this binary tree.
    virtual void setRootData(const ItemType& newData) = 0;

    /// @brief Adds a new node with given newData to this binary tree.
    /// @param newData The data to be added.
    /// @return True if inserting is successfull, false otherwise.
    virtual bool add(const ItemType& newData) = 0;

    /// @brief Removes the given data from the binary tree if it does exist.
    /// @param data to be removed from this binary tree.
    /// @return True if removal is successfull, false otherwise.
    virtual bool remove(const ItemType& data) = 0;

    /// @brief Removes all elements in this binary tree and de-allocate the memory.
    virtual void clear() = 0;
    
    /// @brief Searchs for a given entry in this binary tree.
    /// @param anEntry To be searched.
    /// @return The entry if it does exist in this binary tree. Throws an exception
    /// if it can't be found 
    // TODO EXCEPTION
    virtual ItemType getEntry(const ItemType& anEntry) const= 0;

    /** Tests whether a given entry occurs in this binary tree.
    @post The binary search tree is unchanged.
    @param anEntry The entry to find.
    @return True if the entry occurs in the tree, or false if not. */
    virtual bool contains(const ItemType& anEntry) const = 0;

    /// @brief Traverses this binary tree in three different way. 
    /// @param visit A client-defined function that performs an operation on or with the data in each visited node.
    virtual void preorderTraverse(void visit(ItemType&)) const = 0;
    virtual void inorderTraverse(void visit(ItemType&)) const = 0;
    virtual void postorderTraverse(void visit(ItemType&)) const = 0;
};
#endif

