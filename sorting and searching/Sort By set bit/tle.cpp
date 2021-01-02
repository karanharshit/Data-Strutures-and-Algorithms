#include <bits/stdc++.h>
using namespace std;

class Solution{
    int noof1s(int n){
        int count=0;
        for (int i = 31; i >= 0; i--) { 
        int k = n >> i; 
        if (k & 1) {
            count++;}
        } 
        
        return count;
    }
    
    
    void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
 
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 

    int i = 0;

    int j = 0;
 
    int k = l;
 
    while (i < n1 && j < n2) {
        if (noof1s(L[i]) >= noof1s(R[j])) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 

void mergeSort(int arr[],int l,int r){
    if(l>=r){
        return;
    }
    int m = (l+r-1)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}
    
    
    public:
    void sortBySetBitCount(int arr[], int n)
    {
        mergeSort(arr, 0, n - 1);
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
