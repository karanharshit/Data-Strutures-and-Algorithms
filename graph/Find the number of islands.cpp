class Solution
{
    public:
    
    void dfs(vector<int> grid[], int n, int m, int i, int j){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0) return;
        
        grid[i][j]=0;
        dfs(grid, n, m, i-1, j);
        dfs(grid, n, m, i+1, j);
        dfs(grid, n, m, i, j-1);
        dfs(grid, n, m, i, j+1);
        dfs(grid, n, m, i+1, j+1);
        dfs(grid, n, m, i-1, j-1);
        dfs(grid, n, m, i+1, j-1);
        dfs(grid, n, m, i-1, j+1);
    }
    
    
    int numIslands(vector<vector<char>>& gri) 
    {
        int n=gri.size();
        int m=gri[0].size();
        
        vector<int> grid[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(gri[i][j]=='0'){
                    grid[i].push_back(0);
                }
                else if(gri[i][j]=='1'){
                    grid[i].push_back(1);
                }
            }
        }
        
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    count++;
                    dfs(grid, n, m, i, j);
                }
            }
        }
        return count;
    }
};
