#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        int findNum(int n)
        {
            long long int h=1000000000,l=1,mid,ans;
            while(l<=h){
                mid=l+(h-l)/2;
                long long int five=5,zeroes=0;
                while(1){
                    if(mid/five==0){
                        break;
                    }
                    zeroes=zeroes+(mid/five);
                    five=five*5;
                }
                if(zeroes<n){
                    l=mid+1;
                }
                if(zeroes>=n){
                    ans=mid;
                    h=mid-1;
                }
            }
            return ans;
        }
};


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}
