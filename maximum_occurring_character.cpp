/*
Given an input string S, write a program in C++ to find the maximum occurring character in S. For example, if the input string is "tushita" then the program should return t.

Input:
The first line contains an integer representing the size of S
The second line contains the string S

Output:
Maximum occurring character. If more than one character has maximum count then return the first character with the maximum count in the input string. 

Example:
Input:
test

Output:
t

*/

// C++ program to output the maximum occurring character
// in a string
#include<bits/stdc++.h>
#define ASCII_SIZE 256
using namespace std;
 
char getMaxOccuringChar(char* str)
{
    // Create array to keep the count of individual
    // characters and initialize the array as 0
    int count[ASCII_SIZE] = {0};
 
    // Construct character count array from the input
    // string.
    int len = strlen(str);
    for (int i=0; i<len; i++)
        count[str[i]]++;
 
    int max = -1;  // Initialize max count
    char result;   // Initialize result
 
    // Traversing through the string and maintaining
    // the count of each character
    for (int i = 0; i < len; i++) {
        if (max < count[str[i]]) {
            max = count[str[i]];
            result = str[i];
        }
    }
 
    return result;
}
 
// Driver program to test the above function
int main()
{
    int n;
    cin >> n;
    char str[n];
    cin >> str;    
    cout << getMaxOccuringChar(str);
}
