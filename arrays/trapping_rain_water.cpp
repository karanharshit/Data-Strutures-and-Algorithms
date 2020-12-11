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
	    int left[n];
	    int right[n];
	    
	    
        left[0]=array[0];
	    for(int i=1;i<n;i++){
	        if(array[i]>=left[i-1]){
	            left[i]=array[i];
	        }
	        else{
	            left[i]=left[i-1];
	        }
	    }
	    
	    
	    right[n-1]=array[n-1];
	    for(int i=n-2;i>=0;i--){
	        if(array[i]>=right[i+1]){
	            right[i]=array[i];
	        }
	        else{
	            right[i]=right[i+1];
	        }
	    }
	    
	    
	    int area=0;
	    
	    for(int i=0;i<n;i++){
	        area=area+min(right[i],left[i])-array[i];
	    }
	    cout<<area<<endl;
	    
	}    
	return 0;
}
