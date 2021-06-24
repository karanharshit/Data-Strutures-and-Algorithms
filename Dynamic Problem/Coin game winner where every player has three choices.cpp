#include <bits/stdc++.h>
using namespace std;

int dp[1001];
bool findWinner(int x, int y, int n){
    if(n==1 || n==x || n==y) return true;
    
    if(dp[n-1]!=-1) return dp[n-1];
    bool a=true,b=true,c=true;
    if(x<n){
        if(dp[n-x-1]!=-1) a=dp[n-1-x];
        else{
            a=findWinner(x,y,n-x);
            dp[n-x-1]=a;
        }
        
    }
    if(y<n){
        if(dp[n-y-1]!=-1) b=dp[n-y-1];
        else{
            b=findWinner(x,y,n-y);
            dp[n-y-1]=b;
        }
        
    }
    if(n>1){
        if(dp[n-2]!=-1) c=dp[n-2];
        else{
            c=findWinner(x,y,n-1);
            dp[n-2]=c;
        }
        
    }
    if(a==false||b==false||c==false) return true;
    return false;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    int x = 3, y = 4, n = 2;
    if (findWinner(x, y, n))
        cout << 'A';
    else
        cout << 'B';
 
    return 0;
}
