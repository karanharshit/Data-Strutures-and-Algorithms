class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int key[V];
        int mst[V];
        int parent[V];
        for(int i=0;i<V;i++){
            key[i]=1e9;
            mst[i]=0;
            parent[i]=-1;
        }
        key[0]=0;
        mst[0]=0;
        priority_queue<pair<int, int> , vector<pair<int, int>>,greater<pair<int, int>> > pq;
        pq.push({0,0});
        while(!pq.empty()){
            int a = pq.top().first;
            int b = pq.top().second;
            mst[b] = 1;
            pq.pop();
            for(auto x:adj[b]){
                if(mst[x[0]]==0 && x[1]<key[x[0]]){
                    key[x[0]]=x[1];
                    pq.push({key[x[0]], x[0]});
                    parent[x[0]]=b;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<V;i++){
            ans= ans+key[i];
        }
        return ans;
    }
};
