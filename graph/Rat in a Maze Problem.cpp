class Solution{
    public:
    vector<string> ans;
    
    void dfs(int i, int j, int n, vector<vector<int>> &m, string s){
        if(i<0 || i>=n || j<0 || j>=n || m[i][j]==0) return;
        
        if(i==0 && j==0) s.clear();
        
        if(i==n-1 && j==n-1){
            ans.push_back(s);
            return;
        }
        
        m[i][j]=0;

        dfs(i+1,j,n,m,s+'D');
        dfs(i-1,j,n,m,s+'U');
        dfs(i,j+1,n,m,s+'R');
        dfs(i,j-1,n,m,s+'L');
    
        m[i][j]=1;
        
        return;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        ans.clear();
        
        string s;
        dfs(0,0,n,m,s);
 
        sort(ans.begin(),ans.end());
        return ans;
    }
};
