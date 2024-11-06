#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void displayrec1(Node* head) {
    if(head == NULL) return;
    cout << head->val << " ";
    displayrec1(head->next);  
}

void displayrec2(Node* head) {
    if(head == NULL) return;    
    displayrec2(head->next);  
    cout << head->val << " ";
}

int main() {
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    // prints 10 20 30 40 50
    displayrec1(a);
    cout << endl;

    // prints 50 40 30 20 10
    displayrec2(a);
    cout << endl;

    return 0;
}
