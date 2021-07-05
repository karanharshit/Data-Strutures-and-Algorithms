#include <bits/stdc++.h>
using namespace std;
 
void insertatbottom(int a, stack<int> &s){
    if(s.empty()){
        s.push(a);
    }
    
    else{
        int x=s.top();
        s.pop();
        insertatbottom(a,s);
        s.push(x);
    }
}

void reverse(stack<int> &s){
    if(s.empty()) return;
    
    int a=s.top();
    s.pop();
    reverse(s);
    insertatbottom(a,s);
}

int main() {
    int n;
    cin>>n;
    stack<int> s;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        s.push(a);
    }
    
    reverse(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
