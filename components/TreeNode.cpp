/** @file TreeNode.cpp
 * This file is used to represent tree node for array based impelementation of BinaryTreeInterface.cpp
 * @author rutkaykarabulak@gmail.com
*/

#ifndef TreeNode_cpp
#define TreeNode_cpp

template<class ItemType>
class TreeNode {
private:
    ItemType data; // data of the node.
    int leftChild; // index of left child.
    int rightChild; // index of right child.
public:
    TreeNode(); // default constructor
    TreeNode(const ItemType& newData, int left, int right);

    // getters
    ItemType getItem() const;
    int getLeftChild() const;
    int getRightChild() const;
    // setters
    void setItem(const ItemType& newData);
    void setLeftChild(int newIndex);
    void setRightChild(int newIndex);
}; // end TreeNode
#endif