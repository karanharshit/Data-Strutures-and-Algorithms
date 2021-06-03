class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> ans;
        for(int i=0;i<V;i++){
            ans.push_back(1e9);
        }
        ans[S]=0;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        pq.push({0,S});
        
        while(!pq.empty()){
            int distance = pq.top().first;
            int point = pq.top().second;
            pq.pop();
            for(auto x:adj[point]){
                if(ans[x[0]] > distance + x[1]){
                    ans[x[0]] = distance + x[1];
                    pq.push({ans[x[0]], x[0]});
                }
            }
        }
        return ans;
    }
};
