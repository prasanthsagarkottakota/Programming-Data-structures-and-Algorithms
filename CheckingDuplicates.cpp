/*


Given an array A of N integers, and a number k which is smaller than the size of the array. Write a program in C++ which returns true if the array contains duplicates within k distance.

Input:
The first line contains the integers N and k separated by space.
The second line contains the N integers separated by space

Output:
Output "Yes" if it contains duplicates within distance k else output "No".

Constraints:
1 <= N <= 105
-1000 <= Ai <= 1000

Example:
Input:
6 3
1 2 3 1 4 5

Output:
Yes

Explanation:
1 is repeated at distance 3.


*/

#include<bits/stdc++.h>
using namespace std;
 
/* C++ program to Check if a given array contains duplicate
   elements within k distance from each other */
bool checkDuplicatesWithinK(int arr[], int n, int k)
{
    // Creates an empty hashset
    set<int> myset;
 
    // Traverse the input array
    for (int i = 0; i < n; i++)
    {
        // If already present n hash, then we found
        // a duplicate within k distance
        if (myset.find(arr[i]) != myset.end())
            return true;
 
        // Add this item to hashset
        myset.insert(arr[i]);
 
        // Remove the k+1 distant item
        if (i >= k)
            myset.erase(arr[i-k]);
    }
    return false;
}
 
// Driver method to test above method
int main ()
{
    int n,k,i;
    cin>>n;
    cin>>k; 
    int arr[n];

    for (i = 0; i < n; i++){
        cin >> arr[i];
    }    
    if (checkDuplicatesWithinK(arr, n, k))
        cout << "Yes";
    else
        cout << "No";
}
