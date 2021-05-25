class Solution
{
    public:
    // typedef pair<int, int> pi;
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

        int index[K];
        for(int i=0;i<K;i++){
            index[i]=1;
        }
        for(int i=0;i<K;i++){
            pq.push({arr[i][0],i});
        }
        
        vector<int> ans;
        while(!pq.empty()){
            int i=pq.top().second;
            ans.push_back(pq.top().first);

            pq.pop();
            if(index[i]<K){
                pq.push({arr[i][index[i]],i});
                index[i]++;
            }
        }
        return ans;
    }
};
