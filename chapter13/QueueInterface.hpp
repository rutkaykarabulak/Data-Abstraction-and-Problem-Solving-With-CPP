/** @file QueueInterface.hpp
 * Interface for ADT queue.
 * FIFO: first in first served
*/

#ifndef QueueInterface_hpp
#define QueueInterface_hpp

template<class ItemType>
class QueueInterface {
public:
    /// @brief Checks whether the queue is empty or not.
    /// @return True if queue is empty, false otherwise.
    virtual bool isEmpty() const = 0;

    /// @brief Adds a new item to the back of this queue.
    /// @param newItem item to be added into queue.
    /// @return True if inserting is successfull, false otherwise.
    virtual bool enqueue(const ItemType& newItem) = 0;

    /// @brief Removes the first entry of the queue from the front.
    /// @return True if removal is successfull, false otherwise.
    virtual bool dequeue() = 0;

    /// @brief Returns the first item in this queue, aka item in front.
    /// @return The item in front of queue, throws an error if queue is empty.
    virtual ItemType peek() const = 0;
};

#endif