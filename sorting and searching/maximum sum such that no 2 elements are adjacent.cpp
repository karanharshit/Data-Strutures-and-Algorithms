#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int array[n];
	    for(int i=0;i<n;i++){
	        cin>>array[i];
	    }
	    int inc=array[0], exc=0,temp;

	    for(int i=1;i<n;i++){
	        temp=inc;
	        inc=max(inc,exc+array[i]);
	        exc=temp;
	    }
	    cout<<max(inc,exc)<<endl;
	}
	return 0;
}
