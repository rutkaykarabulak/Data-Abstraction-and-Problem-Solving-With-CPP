/** @file MemoryAllocationException.hpp */

#ifndef Memory_Allocation_Exception_hpp
#define Memory_Allocation_Exception_hpp

#include <stdexcept>
#include <string>
using namespace std;

class MemoryAllocationException : public logic_error{
    public:
    MemoryAllocationException();
};

#endif 

/* Implementation file */

MemoryAllocationException::MemoryAllocationException():
logic_error("Memory wasn't allocated properly")
{

}