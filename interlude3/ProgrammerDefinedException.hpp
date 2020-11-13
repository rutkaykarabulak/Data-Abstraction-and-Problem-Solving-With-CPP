/** @file ProgrammerDefinedException.hpp */
#ifndef Programmer_Defined_Exception_hpp
#define Programmer_Defined_Exception_hpp

#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;
class ProgrammerDefinedException: public logic_error{
public:
    ProgrammerDefinedException(const string& message=""){

    }
};
#endif

/* Implementation file */

ProgrammerDefinedException::ProgrammerDefinedException(const string& message):
logic_error("Programmer defined exception: " + message)
{
// end
}