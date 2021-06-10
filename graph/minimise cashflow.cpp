#include<bits/stdc++.h>
using namespace std;

void minCashflow(int amount[], int N){
    int mini=1e9;
    int maxi=-1e9;
    int minindex, maxindex;
    for(int i=0;i<N;i++){
        if(amount[i]<mini){
            mini=amount[i];
            minindex=i;
        }
        else if(amount[i]>maxi){
            maxi=amount[i];
            maxindex=i;
        }
    }

    int x = min(-mini, maxi);
    cout<<minindex<<" "<<"gives"<<" "<<x<<" "<<"to"<<" "<<maxindex<<endl;
    amount[minindex] = amount[minindex] + x;
    amount[maxindex] = amount[maxindex] - x;
    if(amount[minindex]==0 && amount[maxindex]==0){
        return;
    }

    minCashflow(amount, N);

}

int main(){
    int N = 3;
	int graph[N][N] = { {0, 1000, 2000},
                        {0, 0, 5000},
                        {0, 0, 0},};
    int amount[N]={0};
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            amount[i] = amount[i] + (graph[j][i]-graph[i][j]);
        }
    }

    minCashflow(amount,N);
}
