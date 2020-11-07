/** @file main.cpp */

#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// 6.2.1 Checking for balanced braces 
/** Checks whether given strick is balanced
 * returns true if string is blaanced, false otherwise.
*/
bool isBalanced(string aString){
    stack<char> aStack; // stack that will hold the characters
    bool balancedSoFar = true;
    int i=0; // counter

    while(balancedSoFar&&i<aString.length()){
        char ch = aString.at(i);
        i++;
        if(ch=='{'){
            aStack.push(ch);
        }else if(ch=='}'){
            if(aStack.empty()){
                return false;
            }else{
                aStack.pop();
            }
        }
    }
    if(balancedSoFar && aStack.empty()){
        return true;
    }else{
        return false;
    }
} // end isBalanced

//6.2.2 Recognizing Strings in a Language
// Checks the string aString to verify that it is in language L.
// Returns true if aString is in L, false otherwise.
bool stringRecognize(string aString){
    stack<char> aStack;// a new empty stack
    int i = 0; // counter
    char ch = aString.at(i);

    while(ch!='$'){
        aStack.push(ch);
        i++;
        ch = aString.at(i);
    } // end while
    // skip the $
    i++;

    bool inLanguage = true;
    while(inLanguage && i<aString.length()){
        if(!aStack.empty()){ // fail-safe programming
            char stackTop = aStack.top();
            aStack.pop();
            ch = aString.at(i);
            if(ch == stackTop){
                i++;
            }else{
                inLanguage = false;
            }
        }else{
            inLanguage = false; // first half of string shorter than second half
        }
    }
    if(inLanguage && aStack.empty()){
        return true;
    }else{
        return false;
    }
} // end stringRecognize

// Evaluate postfix expression with ADT stack
int evaluatePostfix(string aString){
    stack<int> aStack;
    int i = 0;

    while(i<aString.length()){
        char ch = aString.at(i);

        if(ch!='+' && ch!='*'){
            aStack.push(aString.at(i)-'0');
            i++;
        }else{
            int variable2 = aStack.top();
            aStack.pop();
            int variable1 = aStack.top();
            aStack.pop();

            if(ch=='*'){
                int result = variable1 * variable2;
                aStack.push(result);
                i++;
            }else{
                int result = variable1 + variable2;
                aStack.push(result);
                i++;
            }
        }
    }
    return aStack.top();
}

int precedence(char anOperator){
    
    switch (anOperator)
    {
    case '+':
    return 1;
    
    case '-':
    return 1;

    case '*':
    return 2;

    case '/':
    return 2;
    default:
        break;
    }

    return 0;
}

string infixToPostfix(string infixExpression){
    string postFix;
    stack<char> aStack;
    int i=0; // counter

    for(i=0;i<infixExpression.length();i++){
        char ch = infixExpression.at(i);
        switch (ch){
            case '(':
            aStack.push(ch);
            break;

            case '+': // operator
            while(!aStack.empty() && aStack.top()!='(' && precedence(ch)<=precedence(aStack.top())){
                postFix+=aStack.top();
                aStack.pop();
            } // end while
            // now it's time to push operator
            aStack.push(ch);
            break;

            case ')':
            while(aStack.top()!='('){
                postFix+=aStack.top();
                aStack.pop();
            } // end while
            // now encountered with '('
            aStack.pop();
            break;

            default: // operand
            postFix+=ch;
            break;
        } // end for
    }
    while(!aStack.empty()){
        postFix+=aStack.top();
        aStack.pop();
    }

    return postFix;
} 

/** EXERCISES */

/*6-b
The nature of the stack-based algorithm makes it simple to display the string in reverse order,
but somewhat harder to display it in its correct order.
Write a pseudocode algorithm that displays the string in its correct forward order.*/
void writeStringInStack(stack<char> aStack){
    string aString;
   while(!aStack.empty()){
       aString += aStack.top();
       aStack.pop();
   } // end while

   int length = aString.length();
   while(length!=0){
       cout << aString.at(length-1);
       length--;
   } // end while    
} // end writeStringInStack


// converts closed bracket to the opened version of its.
// returns opened bracket if given output is a closed bracket, '0' otherwise.
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

/*7 - Revised version of isBalanced*/
bool revisedIsBalanced(string aString){
    bool balancedSoFar = true;
    int i=0;
    stack<char> aStack; // stack that holds a opened brackets
    while(balancedSoFar && i<aString.length()){
        char ch = aString.at(i);

        if(ch=='(' || ch=='[' || ch=='{'){// if ch is a open bracket
            aStack.push(ch); // push opened bracket onto the stack
            i++;
        }
         else if(ch==')' || ch==']' || ch=='}'){

            if(aStack.empty()){ // if there is no open bracket in the stack, string is not balanced
                balancedSoFar = false;
                break;
            } // end if

            // stack is not empty, let s convert closed bracket to opened bracket
            // and compare with top of the stack
            char newBracket = convertClosedBracket(ch);
            char top = aStack.top();
            
            if(newBracket == top){
                aStack.pop();
                i++;
            }else{
                balancedSoFar = false;
                break;
            }
        }else{
            i++; // skip other characters 
        }
    }
    return balancedSoFar && aStack.empty();
}

/*10 - Write a function that uses a stack to determine whether a string is in the language L
 where L = {s s' : s is a string of characters, s'= reverse (s) }*/
 bool isLanguageRevised(string aString){
    stack<char> aStack;
    int i = 0;
    int length = aString.length();
    bool hasEncountered = false;
    while(!hasEncountered){
        if(aString.at(i) == aString.at(i+1)){
            aStack.push(aString.at(i));
            hasEncountered = true;
        }else{
            aStack.push(aString.at(i));
            i++;
        }
    } // end while 

    // now we've encountered with reverse (s)
    i++;
    // in language so far
    bool inLanguage = true;

    while(inLanguage && i<length){
        if(!aStack.empty()){
            char top = aStack.top();
            char ch = aString.at(i);
            aStack.pop();
            if(ch == top){
                i++;
            }else{
                inLanguage = false;
            }
        }else{
            inLanguage = false;
        }
    }

    return inLanguage && aStack.empty();
 }

bool isPalindrome(string aString){
    string newString;
    stack<char> aStack;
    
    for(int i=0; i<aString.length();i++){
        aStack.push(aString.at(i));
    } // end for
    while(!aStack.empty()){
        newString+=aStack.top();
        aStack.pop();
    } // end while

    return newString == aString;
}

int main(){
    string aString = "()";
    cout << revisedIsBalanced(aString) << endl;
} // end main
