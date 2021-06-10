#include<bits/stdc++.h>
using namespace std;

void dfs(int index, vector<int> adj[], vector<int> &vis, vector<int> &intime, vector<int> &outtime, int &time){
	time++;
	vis[index]=1;
	intime[index]=time;
	for(auto x:adj[index]){
		if(vis[x]==0){
			dfs(x,adj,vis,intime,outtime,time);
		}
	}
	time++;
	outtime[index]=time;
}

int main(){
	int n;
	cin>>n;
	vector<int> adj[n];
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}

	vector<int> vis;
	vector<int> intime;
    vector<int> outtime;
	for(int i=0;i<n;i++){
		vis.push_back(0);
		intime.push_back(0);
		outtime.push_back(0);
	}

	int time=0;
    dfs(0, adj, vis, intime, outtime, time);

    /*for(int i=0;i<n;i++){
		cout<<intime[i]<<" "<<outtime[i]<<endl;
	}*/

	int q;
	cin>>q;
	while(q--){
		int x,y,z;
		cin>>x>>y>>z;
		int iny, inz, outy, outz;
		iny = intime[y-1];
		outy=  outtime[y-1];
		inz = intime[z-1];
		outz = outtime[z-1];

		if((iny < inz && outy < outz) || (iny > inz && outy > outz)){
			cout<<"NO"<<endl;
		}
		else{
			if(x==0){
				if(inz>iny && outy>outz){
					cout<<"YES"<<endl;
				}
				else{
					cout<<"NO"<<endl;
				}
			}
			else if(x==1){
				if(inz<iny && outy<outz){
					cout<<"YES"<<endl;
				}
				else{
					cout<<"NO"<<endl;
				}
			}
		}
	}
	return 0;
}
