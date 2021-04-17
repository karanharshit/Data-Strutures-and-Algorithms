// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int longestSubsequence(int N, int A[])
    {
        int array[N]={1};
        for(int i=1;i<N;i++){
            int max=1;
            for(int j=0;j<i;j++){
                if(abs(A[i]-A[j])==1){
                    if(array[j]+1>max){
                        max=array[j]+1;
                    }
                }
            }
            array[i]=max;
        }
        // for(int i=0;i<N;i++){
        //     cout<<array[i]<<" ";
        // }
        // cout<<endl;
        int ans=0;
        for(int i=0;i<N;i++){
            if(array[i]>ans){
                ans=array[i];
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends
