class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    int array[n];
	    for(int i=0;i<n;i++){
	        if(i==0){
	            array[i]=0;
	        }
	        else{
	            array[i]=1e9;
	        }
	    }
	    
	    for(int i=1;i<=n-1;i++){
	        for(auto x: edges){
	            // 1st node u x[0]
	            //2nd node v x[1]
	            //weight x[2]
	            if(array[x[0]]+x[2]<array[x[1]]){
	                array[x[1]]=array[x[0]]+x[2];
	            }
	        }
	    }

	    for(auto x:edges){
	        if(array[x[0]]+x[2]<array[x[1]]){
	           return 1;
	        }
	    }
	    return 0;
	}
};
