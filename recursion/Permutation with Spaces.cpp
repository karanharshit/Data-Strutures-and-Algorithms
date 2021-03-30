// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    vector<string> ans;
    vector<string> permutation(string S){
        // Code Here
        string op;
        op=op+S[0];
        S.erase(0, 1);
        spaces(S, op);
        
        sort(ans.begin(), ans.end());
        return ans;
    }
    
    void spaces(string S, string op ){
        if(S.length()==0){
            ans.push_back(op);
            return ;
        }
        
        string op1= op;
        string op2= op;
        
        op2= op2+S[0];
        op1= op1+" "+S[0];
        S.erase(0, 1);
        
        spaces(S, op1);
        spaces(S, op2);
    }
};

// { Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}
  // } Driver Code Ends
