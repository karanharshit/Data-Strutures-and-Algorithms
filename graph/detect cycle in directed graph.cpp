bool isCyclic(int V, vector<int> adj[]) 
	{
	   	vector<int> visited;
	    vector<int> dfsvisited;
	    for(int i=0;i<V;i++){
	        visited.push_back(0);
	        dfsvisited.push_back(0);
	    }
	    for(int i=0;i<V;i++){
	        if(visited[i]==0){
	            if(cycle(i, visited, dfsvisited, adj)) return true;
	        }
	    }
	    return false;
	}

bool cycle(int index, vector<int> &visited, vector<int> &dfsvisited, vector<int> adj[]){
        visited[index]=1;
        dfsvisited[index]=1;
        for(auto it:adj[index]){
            if(visited[it]==0){
                if(cycle(it, visited, dfsvisited, adj)) return true;
            }
            
            else if(visited[it]==1 && dfsvisited[it]==1) return true;
        }
        dfsvisited[index]=0;
        return false;
    }
