pair<int,int> findSmallestRange(int arr[][N], int n, int k)
{
      priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
      int index[k];
      for(int i=0;i<k;i++){
          index[i]=1;
      }

      int min = 1e9;
      int max = -1e9;
      for(int i=0;i<k;i++){
          if(arr[i][0]>max){
              max=arr[i][0];
          }
          if(arr[i][0]<min){
              min=arr[i][0];
          }
          pq.push({arr[i][0],i});
      }
      int min1, max1;
      min1=min;
      max1=max;
      while(1){
          int i = pq.top().second;
          if(index[i]>=n){
              break;
          }
          if(arr[i][index[i]]<=max1 ){
              pq.pop();
              pq.push({arr[i][index[i]],i});
              min1 = pq.top().first;
              max1=max1;
              index[i]++;
          }
          else{
              pq.pop();
              pq.push({arr[i][index[i]],i});
              min1 = pq.top().first;
              max1 = arr[i][index[i]];
              index[i]++;
          }
          if(max1-min1<max-min){
              min=min1;
              max=max1;
          }
      }
      
      pair<int, int> p (min, max) ;
      return p;
      
     
}
