class Solution {
public:
    int kthGrammar(int N, int K) {
        
        if(N==1){
            return 0;
        }
       
        
        
        int k1;
        if(K%2==0){
            k1=K/2;
        }   
        else{
            k1=(K/2)+1;
        }
        
        int ans= kthGrammar(N-1,k1);
        int final;
        if(ans==1){
            if(K%2!=0){
                //return 1;
                final=1;
            }
            else{
                //return 0;
                final=0;
            }
        }
        if(ans==0){
            if(K%2!=0){
                //return 0;
                final=0;
            }
            else{
                //return 1;
                final=1;
            }
        }
        return final;
    }
};
