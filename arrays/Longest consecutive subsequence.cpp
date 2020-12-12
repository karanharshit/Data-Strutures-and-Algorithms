#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int n);
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  cout<<findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}


int findLongestConseqSubseq(int arr[], int N)
{
  sort(arr,arr+N);
  int count=0;
  int count1=0;
  for(int i=0;i<N;i++){
      if(i==0){
          count1++;
      }
      else{
          if(arr[i]==arr[i-1]+1){
              count1++;
          }
          if(arr[i]==arr[i-1]){
              continue;
          }
          
          else if(arr[i]!=arr[i-1]+1){
              if(count1>count){
                  count=count1;
              }
              count1=1;
          }
      }
      
  }
  if(count1>count){
      count=count1;
  }
  return count;
}
