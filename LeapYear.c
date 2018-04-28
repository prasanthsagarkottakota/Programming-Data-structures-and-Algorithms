/*


Write a program to find whether a given year N is Leap Year or not.
Definition of Leap Year:

A year, occurring once every four years, which has 366 days including 29 February as an intercalary day.


Constraint:
1<=N<=1,000,000 

Input: A single positive number  N

Output:
YES if given year N is a leap year

NO if given year N is not a year

Example 1:

Input: 1992

Output: YES

Example 2:

Input: 2011
Output: NO 
*/

#include<stdio.h>
 int main()
  {
    int n;
    scanf("%d",&n);
    if(n%4==0)
    {
      printf("YES");
    }
    else
    {
      printf("NO");
    }
    return 0;
  }
