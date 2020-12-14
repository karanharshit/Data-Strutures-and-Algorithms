#include<bits/stdc++.h>
using namespace std;

int minJumps(int arr[], int n){
    int jump[n]={-100};
    jump[0]=0;
    int flag=0;
    int i,j;
    j=0;
    for(i=1;i<n;i++){
        for(j=0;j<i;j++){
            if(arr[j]+j>=i){
                jump[i]=jump[j]+1;
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
       if(jump[i]==-100){
           flag=1;
       }
    }
    if(arr[0]==0){
        return -1;
    }
    else if(flag==1){
        return -1;
    }
    else if(jump[n-1]==0){
        return -1;
    }
    else{
    return jump[n-1];
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
            
        cout<<minJumps(arr, n)<<endl;
    }
    return 0;
}
