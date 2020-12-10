
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int array[n];
    int negative=0;
    int positive=0;
    for(int i=0;i<n;i++){
        cin>>array[i];
        if(array[i]>=0){
            positive++;
        }
        else{
            negative++;
        }
    }
    sort(array, array + n);

    int temp;
    int index=negative;
    
    for(int i=0;i<n;i++){
        if(i%2!=0){
            temp=array[index];
            array[index]=array[i];
            array[i]=temp;
            index++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
	return 0;
}
