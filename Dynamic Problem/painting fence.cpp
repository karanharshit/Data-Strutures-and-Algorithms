// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    long long countWays(int n, int k){
        long long int array[n+1];
        int mod = 1e9+7;
        array[1]=k;
        array[2]=k+k*(k-1);
        for(int i=3;i<=n;i++){
            array[i]=((k-1)*(array[i-1]%mod+array[i-2]%mod))%mod;
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
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends
