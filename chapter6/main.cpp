#include <iostream>
#include "LinkedStack.hpp"
#include <vector>
using namespace std;

char convertClosedBracket(char aBracket){
    switch (aBracket){
        case(')'):
        return '(';
        break;

        case ']':
        return '[';
        break;

        case '}':
        return '{';
        break;

        default:
        return '0';
        break;
    }
}

bool revisedIsBalanced(string aString){
    bool balancedSoFar = true;
    int i=0;
    LinkedStack<char> aStack; // stack that holds a opened brackets
    while(balancedSoFar && i<aString.length()){
        char ch = aString.at(i);

        if(ch=='(' || ch=='[' || ch=='{'){// if ch is a open bracket
            aStack.push(ch); // push opened bracket onto the stack
            i++;
        }
         else if(ch==')' || ch==']' || ch=='}'){

            if(aStack.isEmpty()){ // if there is no open bracket in the stack, string is not balanced
                balancedSoFar = false;
                break;
            } // end if

            // stack is not empty, let s convert closed bracket to opened bracket
            // and compare with top of the stack
            char newBracket = convertClosedBracket(ch);
            char top = aStack.peek();
            
            if(newBracket == top){
                aStack.pop();
                i++;
            }else{
                balancedSoFar = false;
                break;
            }
        }
        else{
            i++; // skip other characters 
        }
    }
    return balancedSoFar && aStack.isEmpty();
}

bool isPalindrome(string aString){
    string newString;
    LinkedStack<char> aStack;
    
    for(int i=0; i<aString.length();i++){
        aStack.push(aString.at(i));
    } // end for
    while(!aStack.isEmpty()){
        newString+=aStack.peek();
        aStack.pop();
    } // end while

    return newString == aString;
}

int main(){
    string aString = "(abba)";
    cout << isPalindrome(aString) << endl;
    return 0; 
} // end main