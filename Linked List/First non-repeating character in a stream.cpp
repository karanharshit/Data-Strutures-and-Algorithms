// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution {
    class Node{
    public:
    char data;
    Node *next;
    };

    void insert(Node* &head, char value){
    Node *a=new Node();
    a->data=value;
    a->next=NULL;
    if(head==NULL){
        head=a;
        return;
    }
    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=a;
}

void deletenode(Node* &head, char value){
    Node* temp=head;
    Node *temp1=head;
    if(temp1->data==value){
        temp=temp1->next;
        head=temp;
        delete temp1;
    }

    else{
    temp1=temp->next;


    while(temp1->data!=value){
        temp1=temp1->next;
        temp=temp->next;
    }
    Node *after;
    after=temp1->next;
    temp->next=after;

    delete temp1;}
}


	public:
		string FirstNonRepeating(string A){
		    Node *head=NULL;
            unordered_map<char, int> mp;
            string s="";
            for(int i=0;i<A.length();i++){
                mp[A[i]]++;
                if(mp[A[i]]==1){
                    insert(head,A[i]);
                }
                else if(mp[A[i]]==2){
                    deletenode(head,A[i]);
                }

                if(head==NULL){
                    s=s+'#';
                }
                else{
                    s=s+head->data;
                }
            }
            return s;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
