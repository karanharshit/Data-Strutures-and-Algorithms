#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int start, finish, profit;
};
 
bool jobComparataor(Job s1, Job s2)
{
    return (s1.finish < s2.finish);
}

int nonconflicting(Job arr[], int n, int i){
    int j;
    for(j=i-1;j>=0;j--){
        if(arr[j].finish<=arr[i].start) return j;
    }
    return -1;
}

int findMaxProfit(Job arr[], int n){
    sort(arr, arr+n, jobComparataor);
    int dp[n];
    dp[0]=arr[0].profit;
    for(int i=1;i<n;i++){
        int a=0,b=0;
        a=arr[i].profit;
        int j=nonconflicting(arr,n,i);
        if(j!=-1) a=a+dp[j];
        
        b=dp[i-1];
        dp[i]=max(a,b);
    }
    return dp[n-1];
}

int main()
{
    Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "The optimal profit is " << findMaxProfit(arr, n);
    return 0;
}
