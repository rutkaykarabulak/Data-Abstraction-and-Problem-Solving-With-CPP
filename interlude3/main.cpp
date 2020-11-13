#include <iostream>
#include <cassert>
#include <string>
#include <stack>
using namespace std;

// C3.4.2 Uncaught exceptions

void encodeChar(int i, string& str){
    int base = static_cast<int>('a'); if (isupper(str[i]))
    base = int('A');
    char newChar = (static_cast<int>(str[i]) - base + 3) % 26 + base;
    
    str.replace(i, 1, 1, newChar); // methof replace can throw exception
    
    
}
// Encodes numChar characters within a string.
void encodeString(int numChar, string& str) {
    try{
    for (int j = numChar - 1; j >= 0; j--)
    encodeChar(j, str);
    }catch(logic_error le){
    cout << le.what() << endl;
    }
    
} // end encodeString

int main(){
    string  rtk = "rutkay";
    encodeString(99,rtk);
} // end main