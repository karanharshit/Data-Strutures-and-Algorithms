#include <bits/stdc++.h> 
using namespace std; 

bool subArrayExists(int arr[], int n)
{
    //Your code here
    unordered_map<int, int> m;
    int sum=0;
    int flag=0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
        m[sum]++;
        if(m[sum]>1){
            flag=1;
            break;
        }
        if(sum==0){
            flag=1;
            break;
        }
    }
    if(flag==1){
        return true;
    }
    else{
        return false;
    }
}

int main() 
{ 
    int arr[] =  {-3, 2, 3, 1, 6}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    if (subArrayExists(arr, n)) 
        cout << "Found a subarray with 0 sum"; 
    else
        cout << "No Such Sub Array Exists!"; 
    return 0; 
} 
