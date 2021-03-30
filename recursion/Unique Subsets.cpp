class Solution
{
    // vector<vector<int>> ans;
    vector<vector<int>> ans;
    public:
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        // code here 
        vector<int> output;
        vector<vector<int>> finalans;
        subset(arr, output);
        
        for(int i=0;i<ans.size();i++){
            sort(ans[i].begin(), ans[i].end());
        }
        
        //unordered_map< vector<int>, int> mp;
        for(int i=0;i<ans.size();i++){
            int j=0;
            for(j=i+1;j<ans.size();j++){
                if(ans[i]==ans[j]){
                    break;
                }
            }
            if(j==ans.size()){
                finalans.push_back(ans[i]);
            }
        }
        
        sort(finalans.begin(), finalans.end());
        
        return finalans;
    }
    
    void subset(vector<int> arr, vector<int> output){
        if(arr.size()==0){
            ans.push_back(output);
            return;
        }
        
         vector<int> op1 = output;
         vector<int> op2 = output;
         
         op2.push_back(arr[0]);
         arr.erase(arr.begin()+0);
         
         
         subset(arr, op1);
         subset(arr, op2);
         
         return;
    }
    
};
