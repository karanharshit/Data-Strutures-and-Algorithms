#include<bits/stdc++.h>
using namespace std;
int main() {
    while(1){
            int n,m;
            cin>>n;
            if(n==0){
                break;
            }
            int array1[n];
            for(int i=0;i<n;i++){
                cin>>array1[i];
            }
            cin>>m;
            int array2[m];
            for(int i=0;i<m;i++){
                cin>>array2[i];
            }

            int i=0,j=0,index=0;
            long long int sum1=0,sum2=0,ans=0;
            while(i<n&&j<m){
                if(array1[i]<array2[j]){
                    sum1=sum1+array1[i];
                    i++;
                }
                else if(array2[j]<array1[i]){
                    sum2=sum2+array2[j];
                    j++;
                }
                else if(array1[i]==array2[j]){
                    ans=ans+max(sum1,sum2)+array1[i];
                    sum1=0;
                    sum2=0;
                    i++;
                    j++;
                }
            }

            while(j<m){
                sum2=sum2+array2[j];
                j++;
            }
            while(i<n){
                sum1=sum1+array1[i];
                i++;
            }
            ans=ans+max(sum1,sum2);
            cout<<ans<<endl;
    }
    return 0;
}
