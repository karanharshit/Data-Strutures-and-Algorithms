// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int nCr(int n, int r){
        // code here
        if(n<r){
            return 0;
        }
        int mod=1e9+7;
        long long int dp[r+1][n+1];
        for(int i=0;i<=r;i++){
            for(int j=0;j<=n;j++){
                if(i==0||(i==j)){
                    dp[i][j]=1;
                }
                else{
                    dp[i][j]=(dp[i][j-1]%mod+dp[i-1][j-1]%mod)%mod;
                }
            }
        }
        //long long int ans= dp[r][n]%1000000007;
        return dp[r][n];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends
