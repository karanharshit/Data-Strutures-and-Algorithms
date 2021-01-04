#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        int array[n];
        for(int i=0;i<n;i++){
            cin>>array[i];
        }
        sort(array, array+n);
        int l=1,h=array[n-1],mid;
        int ans;
        while(l<=h){
           mid=(h+l)/2;
           int count=0;
           int cowspos[c];
           cowspos[0]=array[0];
           count++;
           for(int i=1;i<n;i++){
               if((array[i]-cowspos[count-1])>=mid){
                    cowspos[count]=array[i];
                    count++;
               }
               if(count==c){
                    break;
               }
           }
           if(count==c){
                ans=mid;
                l=mid+1;
           }
           if(count<c){
                h=mid-1;
           }
        }
        cout<<ans<<endl;
    }
    return 0;
}
