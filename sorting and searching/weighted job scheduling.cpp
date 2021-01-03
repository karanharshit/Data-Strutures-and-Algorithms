#include<bits/stdc++.h>
using namespace std;
struct Job
{
    int start, finish, profit;
};

bool comp(Job a, Job b)
{
    return (a.finish < b.finish);
}

int maxiprof(Job array[], int n){
    int result[n];
    for(int i=0;i<n;i++){
        result[i]=array[i].profit;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(array[i].start<array[j].finish){
                break;
            }
            if((result[j]+array[i].profit>result[i])&&(array[i].start>=array[j].finish)){
                result[i]=result[j]+array[i].profit;
            }
        }
    }
    int max=0;
    for(int i=0;i<n;i++){
        if(result[i]>max){
            max=result[i];
        }
    }
    return max;
}


int main(){
    int totjobs;
    cin>>totjobs;
    Job array[totjobs];
    for(int i=0;i<totjobs;i++){
        cin>>array[i].start>>array[i].finish>>array[i].profit;
    }
    sort(array,array+totjobs,comp);
    cout<<maxiprof(array,totjobs)<<endl;
    return 0;
}
