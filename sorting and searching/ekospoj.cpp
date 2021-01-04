#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int array[n];
    int max=0;
    for(int i=0;i<n;i++){
        cin>>array[i];
        if(array[i]>max){
            max=array[i];
        }
    }
    long long int high=max, low=0,ans,mid;
    while(low<=high){
        mid=(high+low)/2;
        long long int length=0;
        for(int i=0;i<n;i++){
            if(array[i]>=mid){
                length=length+(array[i]-mid);
            }
        }
        if(length>=m){
            ans=mid;
            low=mid+1;
        }
        if(length<m){
            high=mid-1;
        }
    }
    cout<<ans<<endl;
}
