int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    queue<vector<int>> q;
	    if(KnightPos[0]==TargetPos[0] && KnightPos[1]==TargetPos[1]){
	        return 0;
	    }
	    int mat[N][N];
	    for(int i=0;i<N;i++){
	        for(int j=0;j<N;j++){
	            mat[i][j]=0;
	        }
	    }
	    vector<int> v;
	    int a = KnightPos[0];
	    int b = KnightPos[1];
	    v.push_back(a);
	    v.push_back(b);
	    v.push_back(0);
	    q.push(v);
	    mat[a-1][b-1] = 1;
	    int ans = -1;
	    while(!q.empty()){
	        int a = q.front()[0];
	        int b = q.front()[1];
	        int c = q.front()[2];
	        q.pop();

	        c++;
	        int x,y;
	        x = a + 2;
	        y = b + 1;
	        if(x<=N && y<=N && x>=1 && y>=1){
	            if(mat[x-1][y-1]==0){
	            vector<int> v1;
	            v1.push_back(x);
	            v1.push_back(y);
	            v1.push_back(c);
	            q.push(v1);
	            mat[x-1][y-1]=1;}
	        }  
	        if(x == TargetPos[0] && y == TargetPos[1]){
	           ans = c;
	           break;
	        }
	        
	        x = a + 1;
	        y = b + 2;
	        if(x<=N && y<=N && x>=1 && y>=1){
	            if(mat[x-1][y-1]==0){
	            vector<int> v1;
	            v1.push_back(x);
	            v1.push_back(y);
	            v1.push_back(c);
	            q.push(v1);
	            mat[x-1][y-1]=1;}
	        } 
	        if(x == TargetPos[0] && y == TargetPos[1]){
	           ans = c;
	           break;
	        }
	        
	        x = a - 1;
	        y = b - 2;
	        if(x<=N && y<=N && x>=1 && y>=1){
	            if(mat[x-1][y-1]==0){
	            vector<int> v1;
	            v1.push_back(x);
	            v1.push_back(y);
	            v1.push_back(c);
	            q.push(v1);
	            mat[x-1][y-1]=1;}
	        } 
	        if(x == TargetPos[0] && y == TargetPos[1]){
	           ans = c;
	           break;
	        }
	        
	        x = a - 2;
	        y = b - 1;
	        if(x<=N && y<=N && x>=1 && y>=1){
	            if(mat[x-1][y-1]==0){
	            vector<int> v1;
	            v1.push_back(x);
	            v1.push_back(y);
	            v1.push_back(c);
	            q.push(v1);
	            mat[x-1][y-1]=1;}
	        } 
	        if(x == TargetPos[0] && y == TargetPos[1]){
	           ans = c;
	           break;
	        }
	        
	        x = a - 1;
	        y = b + 2;
	        if(x<=N && y<=N && x>=1 && y>=1){
	            if(mat[x-1][y-1]==0){
	            vector<int> v1;
	            v1.push_back(x);
	            v1.push_back(y);
	            v1.push_back(c);
	            q.push(v1);
	            mat[x-1][y-1]=1;}
	        } 
	        if(x == TargetPos[0] && y == TargetPos[1]){
	           ans = c;
	           break;
	        }
	        
	        x = a + 2;
	        y = b - 1;
	        if(x<=N && y<=N && x>=1 && y>=1){
	            if(mat[x-1][y-1]==0){
	            vector<int> v1;
	            v1.push_back(x);
	            v1.push_back(y);
	            v1.push_back(c);
	            q.push(v1);
	            mat[x-1][y-1]=1;}
	        } 
	        if(x == TargetPos[0] && y == TargetPos[1]){
	           ans = c;
	           break;
	        }
	        
	        x = a + 1;
	        y = b - 2;
	        if(x<=N && y<=N && x>=1 && y>=1){
	            if(mat[x-1][y-1]==0){
	            vector<int> v1;
	            v1.push_back(x);
	            v1.push_back(y);
	            v1.push_back(c);
	            q.push(v1);
	            mat[x-1][y-1]=1;}
	        } 
	        if(x == TargetPos[0] && y == TargetPos[1]){
	           ans = c;
	           break;
	        }
	        
	        x = a - 2;
	        y = b + 1;
	        if(x<=N && y<=N && x>=1 && y>=1){
	            if(mat[x-1][y-1]==0){
	            vector<int> v1;
	            v1.push_back(x);
	            v1.push_back(y);
	            v1.push_back(c);
	            q.push(v1);
	            mat[x-1][y-1]=1;}
	        } 
	        if(x == TargetPos[0] && y == TargetPos[1]){
	           ans = c;
	           break;
	        }
	    }
	    
	    return ans;
	}
