/** @file main.cpp*/
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

// Returns true if <s> is a legal C++ identifier'
// otherwise returns false
bool isId(string s){
    if(s.length() == 1){
        if(isalpha(s[0]))
            return true;
        else
            return false;
    }else if(isalpha(s[s.length()-1]) || isdigit(s[s.length()-1])){
        return isId(s.substr(0,s.length()-2));
    }else{
        return false;
    }
}

// Returns true if the given string <s> is a palindrome, otherwise returns false
bool isPalindrome(string s){
if(s.length() == 2){
    return (s[0] == s[1]); // base case
}
if(s[0] == s[s.length()-1]){
    return isPalindrome(s.substr(1,s.length()-2));
}else{
    return false;
    }
} // end isPalindrome
// Same logic
bool isAnBn(string s){
    if(s.length() == 2){
        return (s[0] == 'A' && s[1] == 'B');
    }
    if(s[0] == 'A' && s[s.length()-1] == 'B'){
        return isAnBn(s.substr(1,s.length()-2));
    }else{
        return false;
    }
} // end isAnBn

int findEnd(string s, int end){
    if(end < 0 || end > s.length()-1){
        return -1;
    } // if there is no end
    if(isalpha(s[end])){
        return end;
    }else if(s[end] == '+' || s[end] == '-' || s[end] == '/' || s[end] == '*'){
        int newEnd = findEnd(s, end+1);

        if(newEnd>-1){
            return findEnd(s, newEnd+1);
        }else{
            return -1;
        }
    }else{
        return -1;
    }
} // end findEnd

bool isPrefix(string s){
    int isValid = findEnd(s,0);
    return (isValid==s.length()-1 && isValid!=-1);
}

int main(){
    
    return 0;
} // end main