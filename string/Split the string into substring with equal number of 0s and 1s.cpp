#include <iostream>
#include <sstream>  // for string streams
#include <string>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
        string s;
        cin>>s;
        int ones,zeroes;
        ones=0;
        zeroes=0;
        int counts=0;
        for(int i=0;i<s.length();i++){
            if(ones==zeroes&&i>0){
                counts++;
                ones=0;
                zeroes=0;
            }
            if(s[i]=='0'){
                zeroes++;
            }
            if(s[i]=='1'){
                ones++;
            }
        }
        if(ones==zeroes){
            counts++;
            cout<<counts<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }
	}
	return 0;
}

