// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to return if the paranthesis are balanced or not
bool ispar(string x)
{
    stack <char> stack;
    int flag=0;
    for(int i=0;i<x.length();i++){
        if(x[i]=='{'||x[i]=='['||x[i]=='('){
            stack.push(x[i]);
        }
        if((x[i]==']'||x[i]==')'||x[i]=='}')&&stack.empty()){
            flag=1;
            break;
        }
        if(x[i]==']'){
            if(stack.top()=='['){
                stack.pop();
            }
        
            else if(stack.top()!='['){
               flag=1;
               break;
            }
        }
        if(x[i]=='}'){
            if(stack.top()=='{'){
                stack.pop();
            }
      
            else if(stack.top()!='{'){
               flag=1;
               break;
            }
        }
        if(x[i]==')'){
            if(stack.top()=='('){
                stack.pop();
            }
  
            else if(stack.top()!='('){
               flag=1;
               break;
            }
        }
    }
    if(flag==1){
        return false;
    }
    else{
    if(stack.empty()){
        return true;
    }
    else{
        return false;
    }}
}


// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       if(ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends
