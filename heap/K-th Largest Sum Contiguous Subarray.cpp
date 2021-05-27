#include <bits/stdc++.h>
using namespace std;

int kthlargest(int array[], int k, int n){
    priority_queue<int, vector<int>,greater<int> > pq;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum=sum+array[j];
            if(pq.size()<k){
                pq.push(sum);
                //cout<<pq.top()<<"1st"<<endl;
            }
            else if(sum>pq.top()){
                pq.pop();
                pq.push(sum);
                //cout<<pq.top()<<"2nd"<<endl;
            }
        }
    }
    return pq.top();
}

int main() {
    int n,k;
    cin>>n>>k;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    cout<<kthlargest(array,k,n)<<endl;
}
