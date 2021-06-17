#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }

    int sum[n];
    sum[0]=array[0];

    if(n>1){
        sum[1]=array[0]+array[1];
    }

    if(n>2){
        sum[2]=max(array[0]+array[1],max(array[1]+array[2], array[0]+array[2]));
    }

    for(int i=3;i<n;i++){
        sum[i]=max(sum[i-1], max(sum[i-2]+array[i], sum[i-3]+array[i-1]+array[i]));
    }
    cout<<sum[n-1]<<endl;

}
