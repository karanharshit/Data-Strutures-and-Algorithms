class Solution {
public:
    vector<string> v; 
    vector<string> letterCasePermutation(string S) {
        string ip=S;
        string op="";
        solve(ip,op);
        return v;
    }
    
    void solve(string ip,string op)
    {
        if(ip.length()==0)
        {
            v.push_back(op);
            return;
        }
        if(isalpha(ip[0]))
        {
            string op1=op;
            string op2=op;
            op1.push_back(toupper(ip[0]));
            op2.push_back(tolower(ip[0]));
            ip.erase(ip.begin()+0);
            solve(ip,op1);
            solve(ip,op2);
        }
        else
        {
            string op1=op;
            op1.push_back(ip[0]);
            ip.erase(ip.begin()+0);
            solve(ip,op1);
        }
        return;
    }
};