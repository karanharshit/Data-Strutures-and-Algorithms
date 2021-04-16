// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    long long int count( int S[], int m, int n )
    {
        long long int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                //cout<<i<<" "<<j<<"haha"<<endl;
                if(i==0||j==0){
                    dp[i][j]=0;
                }
                else{
                    long long int x,y;
                    x=dp[i][j-1];
                    // if(i-j==0){
                    //     y=1;
                    // }
                    if(i-S[j-1]==0){
                        y=1;
                    }
                    else if(i-S[j-1]<0){
                        y=0;
                    }
                    else{
                        y=dp[i-S[j-1]][j];
                    }
                    //cout<<x<<" "<<y<<"hehe"<<endl;
                    dp[i][j]=x+y;
                }
            }
        }
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=m;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[n][m];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[m];
		for(int i=0;i<m;i++)
		    cin>>arr[i];
	    Solution ob;
		cout<<ob.count(arr,m,n)<<endl;
	}
    
    
    return 0;
}  // } Driver Code Ends
