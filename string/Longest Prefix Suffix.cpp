#include <bits/stdc++.h>
using namespace std;

class Solution{
public:		

		
	int lps(string s)
	{
	    int j=s.length()-1;
	    int i=j-1;
	    int counts=0;
	    while(i>=0){
            if(s[i]==s[j]){
                i--;
                j--;
                counts++;
            }
            else if(s[i]!=s[j]){
                j=s.length()-1;
                counts=0;
                if(s[j]==s[i]){
                    i--;
                    j--;
                    counts++;
                }
                else{
                    i--;
                }
            }
	    }
	    return counts;
 
}
	
};


int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}  // } Driver Code Ends
