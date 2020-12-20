#include <iostream>
using namespace std;

void func(string t, int i, int j, string s){
	if(i==j){
		cout<<t<<endl;
	}
	else{
		func(t,i+1,j,s);
		t=t+s[i];
		func(t,i+1,j,s);
	}
}

int main() {
	string s;
	cin>>s;
	func("",0,s.length(),s);
	return 0;
}
