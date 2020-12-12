#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    int A[n], B[m];
	    for(int i=0;i<n;i++){
	        cin>>A[i];
	    }
	    for(int i=0;i<m;i++){
	        cin>>B[i];
	    }
	    unordered_map<int, int> mp;
	    
	    for(int i=0;i<n;i++){
	        mp[A[i]]++;
	    }
	    int flag=0;
	    for(int i=0;i<m;i++){
	        if(mp[B[i]]==0){
	            flag=1;
	            break;
	        }
	    }
	    
	    
	    if(flag==1){
	        cout<<"No"<<endl;
	    }
	    else{
	        cout<<"Yes"<<endl;
	    }
	}
	return 0;
}
