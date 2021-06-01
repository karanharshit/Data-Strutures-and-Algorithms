bool cycle(int index, int parent, vector<int> &visited, vector<int> adj[]){
        visited[index]=1;
        for(auto it:adj[index]){
            if(visited[it]==0){
                if(cycle(it, index, visited, adj)) return true;
            }
            else if(it!=parent) return true;
        }
        
        return false;
    }
    
    
	bool isCycle(int V, vector<int>adj[])
	{
	    vector<int> visited;
	    for(int i=0;i<V;i++){
	        visited.push_back(0);
	    }
	    for(int i=0;i<V;i++){
	        if(visited[i]==0){
	            if(cycle(i, -1, visited, adj)) return true;
	        }
	    }
	    return false;
	}
