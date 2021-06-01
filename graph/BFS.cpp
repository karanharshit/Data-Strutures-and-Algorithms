vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    vector<int> ans;
	    int array[V];
	    for(int i=0;i<V;i++){
	        array[i]=0;
	    }
	    queue<int> q;
	    
	    int start=0;
	    q.push(start);
	    ans.push_back(start);
	    array[start]=1;
	    
	    while(!q.empty()){
	        start = q.front();
	        q.pop();
	        for(auto x : adj[start]){
	            if(array[x]==0){
	                q.push(x);
	                ans.push_back(x);
	                array[x]=1;
	            }
	        }
	       // q.pop();
	    }
	    return ans;
	}
