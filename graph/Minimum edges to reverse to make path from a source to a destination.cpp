#include <bits/stdc++.h>
using namespace std;

int minReverse(int edge[][2], int V, int dst, int E){
    vector<vector<int>> adj[V];
    for(int i=0;i<E;i++){
            adj[edge[i][0]].push_back({edge[i][1], 0});
            adj[edge[i][1]].push_back({edge[i][0], 1});
    }

    vector<int> ans;
    for(int i=0;i<V;i++){
        ans.push_back(1e9);
    }
    ans[0]=0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    pq.push({0,0});

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

    return ans[dst];
}

int main() {
    int V = 7;
    int E = 7;
    int edge[7][2] = {{0, 1}, {2, 1}, {2, 3}, {5, 1},{4, 5}, {6, 4}, {6, 3}};
    cout<<minReverse(edge, V, 6, E);
}
