#include<bits/stdc++.h>
using namespace std;

void heapify(int array[], int n, int i){
    int largest=i;
    int l=(2*i)+1;
    int r=(2*i)+2;

    if(l<n && array[l]>array[largest]){
        largest=l;
    }

    if(r<n && array[r]>array[largest]){
        largest=r;
    }

    if(largest!=i){
        swap(array[i], array[largest]);
        heapify(array,n,largest);
    }
}

int main(){
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }

    for(int i=(n/2)-1;i>=0;i--){
        heapify(array,n,i);
    }

    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
}
