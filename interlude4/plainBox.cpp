/** @file plainBox.cpp */

#ifndef plainBox_cpp
#define plainBox_cpp

template<class ItemType>
class PlainBox {
    private:
    ItemType item; // data that plain box holds
    public:
    PlainBox();
    PlainBox(const ItemType& anItem);
    virtual void setItem(const ItemType& anItem);
    ItemType getItem() const;
};

#endif

// Implementation file

template<class ItemType>
PlainBox<ItemType>::PlainBox(){}

template<class ItemType>
PlainBox<ItemType>::PlainBox(const ItemType& anItem): item(anItem) {

}

template<class ItemType>
void PlainBox<ItemType>::setItem(const ItemType& anItem) {
    item = anItem;
}

template<class ItemType>
ItemType PlainBox<ItemType>::getItem() const {
    return item;
}

