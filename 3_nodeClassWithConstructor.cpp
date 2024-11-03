#include<iostream>
using namespace std;
class Node { //Linked list Node 
public:
    int val;
    Node* next;
    //constructor 1 
    Node(int val) {
        this->val=val;
        this->next=NULL; //by default we are storing, can be overwritten with other addr also 
    }
};
int main() {
    //10 20 30 40 
    Node a(10);
    Node b(20);
    Node c(30);
    Node d(40);
    //forming ll 
    a.next=&b;
    b.next=&c;
    c.next=&d;
    //printing c without c 
    cout<<(b.next)->val<<endl;
    //printing d without d
    cout<<(c.next)->val<<endl;

    //printing c from a 
    cout<<((a.next)->next)->val<<endl;
    //printing d from a 
    cout<<(((a.next)->next)->next)->val<<endl;

    //by using temp 
    Node temp = a;
    while (temp.next!=NULL) {
        cout<<temp.val<<" ";
        temp=*(temp.next);

    }

}