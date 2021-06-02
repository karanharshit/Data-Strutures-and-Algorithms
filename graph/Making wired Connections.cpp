class Solution {
public:
    void dfs(int index, vector<int> graph[], vector<int> &vis){
        vis[index]=1;
        for(auto it:graph[index]){
            if(vis[it]==0){
                dfs(it, graph, vis);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> vis;
        for(int i=0;i<n;i++){
            vis.push_back(0);
        }
        
        int components = 0;
        int edges = connections.size();
        
        vector<int> graph[n];
        for(int i=0;i<connections.size();i++){
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }
        
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                components++;
                dfs(i,graph,vis);
            }
        }   
        
        if(edges >= n-1){
            return components -1;
        }
        else{
            return -1;
        }
    }
};
