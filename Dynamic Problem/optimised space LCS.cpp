// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution{
    public:
        int lcs(int x, int y, string s1, string s2){
            int prev[x+1]={0};
            int curr[x+1];
            for(int i=0;i<y;i++){
                for(int j=0;j<=x;j++){
                    if(j==0){
                        curr[0]=0;
                    }
                    else{
                        if(s1[j-1]==s2[i]){
                            curr[j]=1+prev[j-1];
                        }
                        else{
                            curr[j]=max(curr[j-1], prev[j]);
                        }
                    }
                }
                for(int j=0;j<=x;j++){
                    prev[j]=curr[j];
                }
            }
            return curr[x];
        // your code here
        
        }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends
