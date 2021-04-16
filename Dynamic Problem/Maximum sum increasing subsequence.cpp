// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    vector<int> A;
	    for(int i=0;i<n;i++){
	        A.push_back(arr[i]);
	    }
	    sort(A.begin(), A.end());
	    
	    vector<int>::iterator ip;
  
        ip = std::unique(A.begin(), A.begin() + n);

        A.resize(std::distance(A.begin(), ip));
        
        // for (ip = A.begin(); ip != A.end(); ++ip) {
        // cout << *ip << " ";
        // }
        // cout<<endl;
        int m=A.size();
	    int dp[m+1][n+1];
	    int sum=0;
	    for(int i=0;i<=m;i++){
	        for(int j=0;j<=n;j++){
	            //cout<<i<<" "<<j<<"haha"<<endl;
	            if(i==0||j==0){
	              //  cout<<"1st"<<endl;
	                dp[i][j]=0;
	            }
	            else{
	                //cout<<"2nd"<<endl;
	                if(A[i-1]!=arr[j-1]){
	                  //  cout<<"2 1st"<<endl;
	                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	                }
	                else if(A[i-1]==arr[j-1]){
	                    //cout<<"2 2nd"<<endl;
	                    //sum=sum+A[i];
	                    dp[i][j]=dp[i-1][j-1]+arr[j-1];
	                }
	            }
	        }
	    }
	   // for(int i=0;i<=m;i++){
	   //     for(int j=0;j<=n;j++){
	   //         cout<<dp[i][j]<<" ";
	   //     }
	   //     cout<<endl;
	   // }
	    return dp[m][n];
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends
