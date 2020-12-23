#include<bits/stdc++.h>
using namespace std;


class Solution
{
	public:
		int editDistance(string s, string t)
		{
		    int n=t.length(), m=s.length();
		    int array[n+1][m+1];
		    for(int i=0;i<=n;i++){
		        array[i][0]=i;
		    }
		    for(int i=0;i<=m;i++){
		        array[0][i]=i;
		    }

		    for(int i=1;i<=n;i++){
		        for(int j=1;j<=m;j++){
		            if(t[i-1]!=s[j-1]){
		                int x=min(array[i-1][j],array[i][j-1]);
		                int y=min(x,array[i-1][j-1]);
		                array[i][j]=y+1;
		            }
		            else{
		                array[i][j]=array[i-1][j-1];
		            }
		        }
		    }
		    return array[n][m];
		}
};


int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	int ans = ob.editDistance(s, t);
    	cout << ans <<"\n";
    }
	return 0;
}
