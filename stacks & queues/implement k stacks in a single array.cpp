#include <bits/stdc++.h>
using namespace std;

void push(int item, int sn, int array[], int top[], int next[], int &free){
    if(free==-1){
        cout<<"full"<<endl;
        return;
    } 
    int i= free;
    free=next[i];
    next[i]=top[sn];
    top[sn]=i;
    array[i]=item;
}

int pop(int sn, int array[], int top[], int next[], int &free){
    if(top[sn]==-1) return -1;
    int i=top[sn];
    top[sn]=next[i];
    next[i]=free;
    free=i;
    if(i==-1) return -1;
    return array[i];
}

int main() {
    int k=3, n=10;
    // cin>>k>>n;
    int array[n];
    int top[k];
    for(int i=0;i<k;i++) top[i]=-1;
    int next[n];
    int free=0;
    for(int i=0;i<n;i++){
        if(i==n-1) next[i]=-1;
        else next[i]=i+1;
    }
    push(100,0,array,top,next,free);
    push(200,0,array,top,next,free);
    push(300,1,array,top,next,free);
    push(400,2,array,top,next,free);
    push(600,2,array,top,next,free);
    push(800,2,array,top,next,free);
    push(800,2,array,top,next,free);
    push(800,2,array,top,next,free);
    push(800,2,array,top,next,free);
    push(800,2,array,top,next,free);
    push(800,2,array,top,next,free);
    cout<<pop(0,array,top,next,free)<<endl;
    // cout<<pop(1,array,top,next,free)<<endl;
    // cout<<pop(2,array,top,next,free)<<endl;
    // cout<<pop(1,array,top,next,free)<<endl;
    return 0;
}
