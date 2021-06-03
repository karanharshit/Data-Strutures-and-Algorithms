class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int parent[100000];
	int rank[100000];
	
    int findPar(int node){
        if(node==parent[node]) return node;
        
        return parent[node] = findPar(parent[node]);
    }
    
    void unions(int u, int v){
        u=findPar(u);
        v=findPar(v);
        
        if(rank[u]<rank[v]){
            parent[u]=v;
        }
        else if(rank[v]<rank[u]){
            parent[v]=u;
        }
        else{
            parent[v]=u;
            rank[u]++; 
        }
    }
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //making set
        vector<int> vis;
        for(int i=0;i<V;i++){
            vis.push_back(0);
        }
        
        for(int i=0;i<V;i++){
            parent[i]=i;
            rank[i]=0;
        }
        
        vector<vector<int>>edgelist;
        int edge, a, b;
        for(int i=0; i<V;i++){
            a = i;
            for(auto x: adj[i]){
                b = x[0];
                edge = x[1];

                edgelist.push_back({edge, a, b});
            }
        }
        sort(edgelist.begin(), edgelist.end());
        int ans = 0;
        for(auto it:edgelist){
            int x,y,z;
            x=it[0];
            y=it[1];
            z=it[2];
    
            if(findPar(y)!=findPar(z)){
                ans = ans + x;
                unions(y,z);
            }
        }
        return ans;
    }
};
