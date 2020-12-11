#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n;
	    int array[n];
	    for(int i=0;i<n;i++){
	        cin>>array[i];
	    }
	    cin>>m;
	    sort(array,array+n);
	    
	    int A[n-m+1];
	    for(int i=0;i<=n-m;i++){
	        A[i]=array[i+m-1]-array[i];
	    }
	    
	    int min=A[0];
	    for(int i=1;i<=n-m;i++){
	        if(A[i]<=min){
	            min=A[i];
	        }
	    }
	    cout<<min<<endl;
	}
	return 0;
}
