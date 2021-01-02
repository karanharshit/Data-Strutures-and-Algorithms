#include<bits/stdc++.h>
using namespace std;
int binarySearch(int arr[], int l, int r, int x)
{
    if (r > l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }
    if(r==l){
            return r;
    }
}



int main(){
    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>
        c;
        int array[n];
        for(int i=0;i<n;i++){
            cin>>array[i];
        }
        sort(array, array+n);
        int cowspos[c];
        cowspos[0]=array[0];
        cowspos[c-1]=array[n-1];
        for(int i=1;i<c-1;i++){
            cowspos[i]=array[binarySearch(array,0,n-1,(i)*((array[0]+array[n-1])/(c-1)))];
        }
        int dis=cowspos[c-1]-cowspos[0];
        for(int i=1;i<c;i++){
            if((cowspos[i]-cowspos[i-1])<dis){
                dis=cowspos[i]-cowspos[i-1];
            }
        }
        cout<<dis<<endl;
    }
    return 0;
}
