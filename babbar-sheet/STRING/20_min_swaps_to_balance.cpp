// Minimum number of swaps for bracket balancing.
// [Practice here: https://practice.geeksforgeeks.org/problems/minimum-swaps-for-bracket-balancing/0 ]

// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
int minimumNumberOfSwaps(string S){
       int x = 0 ,swaps = 0 , n = S.length();
       for(int i = 0 ; i<n ; i++)
       {
           if(S[i]=='[')
               x--;
           else
           {
               x++;
               if(x>0)
                   swaps+=x;
           }
       }
       return swaps;
   }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
}   // } Driver Code Ends