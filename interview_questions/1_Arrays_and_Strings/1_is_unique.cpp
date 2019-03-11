/*
Is Unique: Implement an algorithm to determine if a string 
has all unique characters. What if you cannot use additional data structures?
*/

#include <cstring> 
#include <iostream> 
using namespace std; 
  
const int MAX_CHAR = 256; 
  
bool uniqueCharacters(string str) 
{ 
  
    // If length is greater than 265, 
    // some characters must have been repeated 
    if (str.length() > MAX_CHAR) 
        return false; 
  
    bool chars[MAX_CHAR] = { 0 }; 
    for (int i = 0; i < str.length(); i++) { 
        if (chars[int(str[i])] == true) 
            return false; 
  
        chars[int(str[i])] = true; 
    } 
    return true; 
} 
  
// driver code 
int main() 
{ 
    string str = "GeeksforGeeks"; 
  
    if (uniqueCharacters(str)) { 
        cout << "The String " << str 
             << " has all unique characters\n"; 
    } 
    else { 
  
        cout << "The String " << str 
             << " has duplicate characters\n"; 
    } 
    return 0; 
} 

/*
Ask:
    Clarify if string only contains ASCII
Optimize:
    Check each char with each other O(N2) / O(0)
    Sort and then check has O(NlogN) / O(N)
    Hash set or bool array has O(N) time (<128) and O(N) <128
    Bit manipulate an integer to store booleans would offer O(N) / O(1) solution
*/