// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
int comparator(const void* p, const void* q)
{
    return (((struct val*)p)->first>
                  ((struct val*)q)->first);
}


int maxChainLen(struct val p[],int n)
{
    qsort(p, n, sizeof(struct val), comparator);
    // for(int i=0;i<n;i++){
    //     cout<<p[i].first<<" "<<p[i].second<<" ";
    // }
    // cout<<endl;
    int array[n];
    for(int i=0;i<n;i++){
        array[i]=1;
        //cout<<array[i]<<" ";
    }
    //  for(int i=0;i<n;i++){
    //     cout<<array[i]<<" ";
    // }
    // cout<<endl;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(p[j].second<p[i].first){
                 //cout<<i<<" "<<j<<"haha"<<endl;
                if((array[j]+1)>array[i]){
                   //  cout<<i<<" "<<j<<"hehe"<<endl;
                    array[i]=array[j]+1;
                   // cout<<i<<" "<<array[i]<<"hehe"<<endl;
                }
            }
        }
    }
    int max=0;
    for(int i=0;i<n;i++){
        //cout<<array[i]<<" ";
        if(array[i]>max){
            max=array[i];
        }
    }
    return max;
}
