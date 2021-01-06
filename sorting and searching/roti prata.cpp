#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
            int prata,n;
            cin>>prata>>n;
            int array[n];
            for(int i=0;i<n;i++){
                cin>>array[i];
            }
            sort(array,array+n);
            int l=1,h=1e8,mid,ans;
            while(l<=h){
                mid=l+(h-l)/2;
                int count=0;
                for(int i=0;i<n;i++){
                    int value=1,sum=0;
                    while(sum+value*array[i]<=mid){
                        sum=sum+value*array[i];
                        value++;
                    }
                    count=count+(value-1);
                }

                if(count>=prata){
                    ans=mid;
                    h=mid-1;
                }
                if(count<prata){
                    l=mid+1;
                }
            }
            cout<<ans<<endl;
    }
    return 0;
}
