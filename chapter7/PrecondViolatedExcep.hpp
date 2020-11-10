/** @file PrecondViolatedExcep.hpp*/

#ifndef Precond_Violated_Excep_hpp
#define Precond_Violated_Excep_hpp

#include <stdexcept>
#include <string>
#include <iostream>
using namespace std;
class PrecondViolatedExcep: public logic_error{
    public:
    PrecondViolatedExcep(const string& message="");
};
#endif

/* IMPLEMENTATION FILE */

PrecondViolatedExcep::PrecondViolatedExcep(const string& message):logic_error("Precondition Violated Exception: " + message)
{
}