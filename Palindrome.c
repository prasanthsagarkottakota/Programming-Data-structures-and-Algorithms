/*Write a program to find whether a number N is Palindrome or not. A number is a palindrome if the reverse of that number is equal to the original number.

Constraints:
N is a positive number less than 1000000.

Input: A number N
Output: YES if it is a Palindrome else NO


Example 1:

Input: 121
Output: YES


Example 2:

Input: 123
Output: NO
*/

#include <stdio.h>
int main()
{
    int n, reversedInteger = 0, remainder, originalInteger;

    
    scanf("%d", &n);

    originalInteger = n;

    // reversed integer is stored in variable 
    while( n!=0 )
    {
        remainder = n%10;
        reversedInteger = reversedInteger*10 + remainder;
        n /= 10;
    }

    // palindrome if orignalInteger and reversedInteger are equal
    if (originalInteger == reversedInteger)
        printf("YES");
    else
        printf("NO");
    
    return 0;
}
