vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    vector<int> ans;
	    int array[V]={0};
	    stack<int> s;
	    int start = 0;
	    s.push(start);
	    
	    while(!s.empty()){
	        start = s.top();
	        if(array[start]==0){
	            ans.push_back(start);
	            array[start]=1;
	        }
	        s.pop();
	        
	        for(int i = adj[start].size()-1; i>=0;i--){
	            if(array[adj[start][i]]==0){
	                s.push(adj[start][i]);
	            }
	        }
	    }
	    return ans;
	}
