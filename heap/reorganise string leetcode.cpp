class Solution {
public:    
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        priority_queue<pair<int, char> > pq;
        
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        int max=-1e9;
        for(auto x:mp){
            pq.push({x.second, x.first});
            if(x.second>max){
                max=x.second;
            }
        }

        int temp;
        if(s.length()%2==0){
            temp=s.length()/2;
        }
        else{
            temp=s.length()/2 + 1;
        }
        if(max>temp){
            return "";
        }
        else{
            string ans="";
            char prev='0';
            while(!pq.empty()){
                char x = pq.top().second;
                ans= ans + x;
                pq.pop();
                if(prev!='0'){
                    pq.push({mp[prev], prev});
                }
                mp[x]--;
                if(mp[x]>0){
                prev=x;}
                else{
                    prev='0';
                }
            }
            return ans;
            
        }
    }
};
