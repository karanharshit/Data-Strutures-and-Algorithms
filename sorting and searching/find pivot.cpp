#include<bits/stdc++.h>
using namespace std;
int pivot(int array[],int low, int high){
    int mid=(low+high)/2;
    if(array[mid-1]<array[mid]&&array[mid+1]<array[mid]){
        return mid;
    }
    if(array[mid]>array[high-1]){
            return pivot(array,mid+1,high);
    }
    if(array[mid]<array[high-1]){
            return pivot(array,0,mid);
    }
}



int main(){
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    cout<<pivot(array,0,n)<<endl;
    return 0;
}
