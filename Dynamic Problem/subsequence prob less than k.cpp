#include <bits/stdc++.h>
using namespace std;



int main() {
    int n,k;
    cin>>n>>k;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int dp[k+1][n+1];
    for(int i=0;i<=k;i++){
        for(int j=0;j<=n;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
            else{
                int x,y;
                x=dp[i][j-1];
                if(array[j-1]>i){
                    y=0;
                }
                else{
                    y=dp[i/array[j-1]][j-1]+1;
                }
                dp[i][j]=x+y;
            }
        }
    }
    for(int i=0;i<=k;i++){
        for(int j=0;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<dp[k][n]<<endl;
}
