#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next=NULL;
    Node(int val) {
        this->val=val;
        this->next=NULL;
    }
};
int size(Node* head) {
    Node* temp=head;
    int n=0;
    while(temp!=NULL) {
        n++;
        temp=temp->next;
    }
    return n;
}
int main() {
    Node a(10);
    Node b(20);
    Node c(30);
    Node d(40);
    
    a.next=&b;
    b.next=&c;
    c.next=&d;
    
    Node* temp=&a;
    while(temp!=NULL) {
        cout<<temp->val<<" "<<endl;;
        temp=temp->next;
    }
    cout<<"size is : "<<size(&a)<<endl;
}






