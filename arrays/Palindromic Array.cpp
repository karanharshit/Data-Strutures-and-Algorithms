#include<iostream>
#include<string.h>
#include<sstream>

using namespace std;
int PalinArray(int a[], int n);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		cout<<PalinArray(a,n)<<endl;
	}
}

 
int PalinArray(int a[], int n){
    int flag=0;
    for(int i=0;i<n;i++){
        stringstream ss;  
        ss<<a[i];  
        string s;  
        ss>>s;
        int j=0;
        int z=s.length()-1;
        while(1){
            if(j>z){
                break;
            }
            if(s[j]!=s[z]){
                flag=1;
                break;
            }
            j++;
            z--;
        }
        if(flag==1){
            break;
        }
    }
    if(flag==1){
        return 0;
    }
    else{
        return 1;
    }
}
