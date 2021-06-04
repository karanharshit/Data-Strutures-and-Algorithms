class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];
        for(int i=1;i<N;i++){
            for(int j=0; j<min(dict[i].length(), dict[i-1].length()); j++){
                if(dict[i][j]!=dict[i-1][j]){
                    adj[dict[i-1][j]-97].push_back(dict[i][j]-97);
                    break;
                }
            }
        }
        int array[K]={0};
        for(int i=0;i<K;i++){
            for(auto x: adj[i]){
                array[x]++;
            }
        }
        
        vector<int> ans;
	    int stored[K];
	    for(int i=0;i<K;i++){
	        stored[i]=0;
	    }
	    
	    while(ans.size()<K){
	        int min=1e9, index;
	        for(int i=0;i<K;i++){
	            if(array[i]<min && stored[i]==0){
	                min=array[i];
	                index = i;
	            }
	        }
	        ans.push_back(index);
	        stored[index]=1;
	        for(auto x:adj[index]){
	            array[x]--;
	        }
	    }
	    string fin;
	    for(int i=0;i<ans.size();i++){
	        char c = ans[i] + 97;
	        fin = fin + c;
	       // cout<<ans[i]<<" ";
	    }

        return fin;
    }
};
