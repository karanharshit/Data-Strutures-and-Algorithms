#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    for(int i=n-1;i>=0;i--){
        int l = 2*i + 1;
        int r = 2*i + 2;
        int largest = i;
        if(l < n && array[l]>array[largest]){
            int temp =  array[l];
            array[l]=array[largest];
            array[largest]=temp;

             int l1 = 2*l + 1;
             int r1 = 2*l + 2;
             int largest1= l;

             if(l1 < n && array[l1]>array[largest1]){
               int temp =  array[l1];
               array[l1]=array[largest1];
               array[largest1]=temp;
             }

             if(r1 < n && array[r1]>array[largest1]){
               int temp =  array[r1];
               array[r1]=array[largest1];
               array[largest1]=temp;
             }
        }

        if(r < n && array[r]>array[largest]){
            int temp =  array[r];
            array[r]=array[largest];
            array[largest]=temp;

            int l1 = 2*r + 1;
            int r1 = 2*r + 2;
            int largest1= r;

             if(l1 < n && array[l1]>array[largest1]){
               int temp =  array[l1];
               array[l1]=array[largest1];
               array[largest1]=temp;
             }

             if(r1 < n && array[r1]>array[largest1]){
               int temp =  array[r1];
               array[r1]=array[largest1];
               array[largest1]=temp;
             }
        }
    }

    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }

}
