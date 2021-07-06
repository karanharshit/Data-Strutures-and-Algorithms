#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    queue<int> q;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        q.push(x);
    }
    stack<int> s;
    for(int i=0;i<n/2;i++){
        s.push(q.front());
        q.pop();
    }
    
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    
    
    for(int i=0;i<n/2;i++){
        q.push(q.front());
        q.pop();
    }
    
    // while(!q.empty()){
    //     cout<<q.front()<<"..";
    //     q.pop();
    // }
    // cout<<endl;
  
    for(int i=0;i<n/2;i++){
        s.push(q.front());
        q.pop();
    }
    
    //  while(!q.empty()){
    //     cout<<q.front()<<" ";
    //     q.pop();
    // }
    
    
    for(int i=0;i<n;i++){
        if(i%2==0){
            q.push(s.top());
            s.pop();
        }
        else if(i%2!=0){
            q.push(q.front());
            q.pop();
        }
    }
    
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    
}
