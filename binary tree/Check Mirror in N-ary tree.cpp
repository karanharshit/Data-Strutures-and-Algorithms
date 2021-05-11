class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        // code here
        vector<stack<int>> s(n+1);
        vector<queue<int>> q(n+1);
        for(int i=0;i<2*e;i=i+2){
            s[A[i]].push(A[i+1]);
            q[B[i]].push(B[i+1]);
        }
        for(int i=1;i<=n;i++){
            while(!q[i].empty()&&!s[i].empty()){
                int a=s[i].top();
                int b=q[i].front();
                if(a!=b){
                    return 0;
                }
                s[i].pop();
                q[i].pop();
            }
        }
        
        
        return 1;
    }
};
