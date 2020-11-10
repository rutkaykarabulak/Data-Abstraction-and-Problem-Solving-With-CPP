#include <iostream>
#include <vector>
#include "ArrayStack.hpp"
#include "LinkedStack.hpp"
using namespace std;

int main(){

    LinkedStack<int> aLinkedStack;
    try{
        aLinkedStack.peek();
    }
    catch(logic_error err){
        cout << err.what() << endl;
    }
    return 0;
} // end main