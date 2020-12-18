#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int n=s.length();
	    int dp[n][n];
	     for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            dp[i][j]=0;
	        }
	    }
	    for(int i=0;i<n;i++){
	        dp[i][i]=1;
	    }
	    int l=0;
	    int r=0;
	    int length=1;
	    int i=0;
	    int j=1;
	    while(j<n){
	        if(s[i]==s[j]){
	            dp[i][j]=1;
	            if(j-i+1>length){
	                length=j-i+1;
	                l=i;
	                r=j;
	            }
	        }
	        else{
	            dp[i][j]=0;
	        }
	        i++;
	        j++;
	    }
	    int x=0;
	    int y=2;
	    while(y<n){
	        i=x;
	        j=y;
	        while(j<n){
	        if((s[i]==s[j])&&(dp[i+1][j-1]==1)){
	            dp[i][j]=1;
	            if(j-i+1>length){
	                length=j-i+1;
	                l=i;
	                r=j;
	            }
	        }
	        else{
	            dp[i][j]=0;
	        }
	        i++;
	        j++;
	        }
	        y++;
	    }

	    for(int i=l;i<=r;i++){
	        cout<<s[i];
	    }
	    cout<<endl;
	}
	return 0;
}
