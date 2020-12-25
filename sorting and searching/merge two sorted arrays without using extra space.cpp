#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	void merge(int arr1[], int arr2[], int n, int m) {
	    int k;
	    if((m+n)%2==0){
	        k=(m+n)/2;
	    }
	    else{
	        k=((m+n)/2)+1;
	    }
	    while(1){
	        int flag1=0, flag2=0;
	        int i=0,j;
	        if(i+k<=n-1){
	            j=i+k;
	        }
	        else{
	            j=i+k-n;
	            flag2=1;
	        }
	        while(1){
	            if(flag2==1&&j>=m){
	                break;
	            }
	            
	            if(flag1==0&&flag2==0){
	                if(arr1[i]>arr1[j]){
	                    swap(arr1[i],arr1[j]);
	                }
	            }
	            if(flag1==0&&flag2==1){
	                if(arr1[i]>arr2[j]){
	                    swap(arr1[i],arr2[j]);
	                }
	            }
	            if(flag1==1&&flag2==1){
	                if(arr2[i]>arr2[j]){
	                    swap(arr2[i],arr2[j]);
	                }
	            }
	            
	            if(i<n-1&&flag1==0){
	                i++;
	            }
	            else if(i==n-1&&flag1==0){
	                i=0;
	                flag1=1;
	            }
	            else if(flag1==1){
	                i++;
	            }
	            
	            if(j<n-1&&flag2==0){
	                j++;
	            }
	            else if(j==n-1&&flag2==0){
	                j=0;
	                flag2=1;
	            }
	            else if(flag2==1){
	                j++;
	            }
	            
	            if(flag2==1&&j>=m){
	                break;
	            }
	        }

	        if(k==1){
	            break;
	        }
	        else{
	        if(k%2==0){
	            k=k/2;
	        }
	        else{
	            k=(k/2)+1;
	        }}
	    }
	    
	    
	}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++) {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++) {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}  
