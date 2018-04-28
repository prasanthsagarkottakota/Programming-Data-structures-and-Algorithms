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
