#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    cin>>k;
    int dp[n+1][k+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<k+1;j++){
            if(i==0 || j==0) dp[i][j]=0;

            else{
                if(array[i-1]<=j){
                    //dp[i][j]=max(1+dp[i-1][j/(array[i]-1)], dp[i-1][j]);
                    dp[i][j]= 1+dp[i-1][j/(array[i-1])] + dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
    }
    cout<<dp[n][k]<<endl;
}
