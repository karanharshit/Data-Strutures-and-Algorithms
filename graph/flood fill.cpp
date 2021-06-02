class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<pair<int, int>> marked;
        int n = image.size();
        int m = image[0].size();
        // cout<<n<<" "<<m<<"??"<<endl;
        int mat[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mat[i][j]=0;
            }
        }
        
        queue<pair<int, int>> q;
        q.push({sr,sc});
        marked.push_back({sr,sc});
        mat[sr][sc] = 1;
        while(!q.empty()){
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            // cout<<a<<" "<<b<<"haha"<<endl;
            int x,y;
            x= a;
            y= b+1;
            if(x<n && y<m && x>=0 && y>=0 && image[x][y]==image[a][b]){
                // cout<<".."<<x<<" "<<y<<" "<<image[x][y]<<" "<<image[a][b]<<"hehe"<<endl;
                if(mat[x][y]==0){
                    q.push({x,y});
                    // cout<<" "<<x<<" "<<y<<"hehe"<<endl;
                    marked.push_back({x,y});
                    mat[x][y]=1;
                }
            }
            
            x= a;
            y= b-1;
            if(x<n && y<m && x>=0 && y>=0 && image[x][y]==image[a][b]){
                // cout<<".."<<x<<" "<<y<<" "<<image[x][y]<<" "<<image[a][b]<<"hehe"<<endl;
                if(mat[x][y]==0){
                    q.push({x,y});
                    // cout<<" "<<x<<" "<<y<<"hehe"<<endl;
                    marked.push_back({x,y});
                    mat[x][y]=1;
                }
            }
            
            x= a+1;
            y= b;
            if(x<n && y<m && x>=0 && y>=0 && image[x][y]==image[a][b]){
                // cout<<".."<<x<<" "<<y<<" "<<image[x][y]<<" "<<image[a][b]<<"hehe"<<endl;
                if(mat[x][y]==0){
                    q.push({x,y});
                    // cout<<" "<<x<<" "<<y<<"hehe"<<endl;
                    marked.push_back({x,y});
                    mat[x][y]=1;
                }
            }
            
            x= a-1;
            y= b;
            if(x<n && y<m && x>=0 && y>=0 && image[x][y]==image[a][b]){
                // cout<<".."<<x<<" "<<y<<" "<<image[x][y]<<" "<<image[a][b]<<" "<<mat[x][y]<<"hehe"<<endl;
                if(mat[x][y]==0){
                    q.push({x,y});
                    // cout<<" "<<x<<" "<<y<<"hehe"<<endl;
                    marked.push_back({x,y});
                    mat[x][y]=1;
                }
            }
        }
        // cout<<marked.size()<<".."<<endl;
        for(int i=0;i<marked.size();i++){
            // cout<<marked[i].first<<" "<<marked[i].second<<"//"<<endl;
            image[marked[i].first][marked[i].second]=newColor;
        }
        return image;
    }
};
