/** @file magicBox.cpp */

#ifndef magicBox_cpp
#define magicBox_cpp

#include "./plainBox.cpp"

template<class ItemType>
class MagicBox: public PlainBox<ItemType> {
private:
    bool firstItemStored;
public:
    MagicBox();
    MagicBox(const ItemType& anItem);
    void setItem(const ItemType& anItem);
}; // end MagicBox

#endif

// Implementation file

template<class ItemType>
MagicBox<ItemType>::MagicBox():firstItemStored(false){}

template<class ItemType>
MagicBox<ItemType>::MagicBox(const ItemType& anItem):firstItemStored(false){
    setItem(anItem);
}

template<class ItemType>
void MagicBox<ItemType>::setItem(const ItemType& anItem) {
    if (!firstItemStored) {
        PlainBox<ItemType>::setItem(anItem);
        firstItemStored = true;
    }
}
