#include <bits/stdc++.h>
using namespace std;
vector<int> graph[100000];

int indegree[100000];

void addEdge(int u, int v)
{
    graph[u].push_back(v);
    indegree[v]++;
}

void printOrder(int n, int m){
    int answer[n];
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            answer[i-1]=1;
            q.push(i);
        }
    }

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto it: graph[curr]){
            indegree[it]--;
            if(indegree[it]==0){
                answer[it-1] = answer[curr-1]+1;
                q.push(it);
            }
        }
    }

    for(int i=0;i< n ;i++){
        cout<<answer[i]<<" ";
    }
    cout<<endl;

}

int main() {
    int n, m; //n-> nodes, m->edges
    n = 10;
    m = 13;
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(1, 5);
    addEdge(2, 3);
    addEdge(2, 8);
    addEdge(2, 9);
    addEdge(3, 6);
    addEdge(4, 6);
    addEdge(4, 8);
    addEdge(5, 8);
    addEdge(6, 7);
    addEdge(7, 8);
    addEdge(8, 10);
    printOrder(n,m);
}
