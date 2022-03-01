// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        unordered_map<string,int> count;
        for(int i=0; i<n;i++){
            string s = arr[i];
            count[s]++;
        }
        int max1 = INT_MIN+1;
        int max2 = INT_MIN;
        string str1 = "";
        string str2 = "";
        string result;
        for(auto it=count.begin();it != count.end(); it++){
            int count = it->second;
            if(count > max1){
                max2 = max1;
                str2 = str1;
                max1 = count;
                str1 = it->first;
            }
            else if(count > max2){
                max2 = it->second;
                str2 = it->first;
            }
        }
        return str2;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends