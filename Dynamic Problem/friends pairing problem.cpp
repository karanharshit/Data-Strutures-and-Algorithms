// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends

class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        // code here
    long long int array[n+1];
    int mod = 1e9+7;
    array[0]=1;
    array[1]=1;

    for(int i=2;i<=n;i++){
        array[i]=(array[i-1]%mod + ((i-1)*array[i-2])%mod)%mod;
    }

    return array[n];
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends
