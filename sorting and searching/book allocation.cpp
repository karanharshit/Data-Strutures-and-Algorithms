#include<bits/stdc++.h>
using namespace std;


int findPages(int arr[], int n, int m);

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        cout << findPages(A, n, m) << endl;
    }
    return 0;
}

int findPages(int *array, int n, int m) {
    long long int sum=0;
    int maxm=0;
    for(int i=0;i<n;i++){
        sum=sum+array[i];
        if(array[i]>maxm){
            maxm=array[i];
        }
    }
    int l=maxm,h=sum,mid,ans=0;
    while(l<=h){
        mid=l+(h-l)/2;
        int count=1;
        long long int sum1=0;
        for(int i=0;i<n;i++){
            sum1=sum1+array[i];
            if(sum1>mid){
                sum1=array[i];
                count++;
            }
        }
        if(count>m){
            l=mid+1;
        }
        if(count<=m){
            ans=mid;
            h=mid-1;
        }
    }

    int finans;
    if(ans==0){
        finans=-1;
    }

    else{
        finans=ans;
    }
    return finans;
}

