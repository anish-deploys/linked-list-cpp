#include<iostream>
using namespace std;

class Node { // user-defined data type
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class LinkedList { // user-defined data structure
public:
    Node* head;
    Node* tail;
    int size = 0;
    
    LinkedList() {
        head = tail = NULL;
        size = 0;
    }
    
    void insertAtEnd(int val) {
        Node* temp = new Node(val);
        if (size == 0) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
    
    void insertAtBeg(int val) {
        Node* temp = new Node(val);
        if (size == 0) {
            head = tail = temp;
        } else {
            temp->next = head; // Point new node to the current head
            head = temp; // Update head to the new node
        }
        size++;
    }

    void insertAtIdx(int idx, int val) {
        if (idx < 0 || idx > size) {  // Correct index validation
            cout << "Invalid index" << endl; 
            return;
        }

        if (idx == 0) {
            insertAtBeg(val);
            return;
        }

        if (idx == size) {
            insertAtEnd(val);
            return;
        }
        
        Node* t = new Node(val);
        Node* temp = head; // Initialize temp on head 

        for (int i = 1; i <= idx - 1; i++) { // Bring temp to idx-1
            temp = temp->next;
        }
        t->next = temp->next;
        temp->next = t; 
        size++;
    }

    int getAtIdx(int idx) {
        if (idx<0 || idx>=size) {
            cout<<"invalid index";
            return -1;
        }
        else if (idx==0) return head->val;
        else if (idx==size-1) return tail->val;
        else {
            Node* temp=head;
            for(int i=1;i<=idx;i++) {
                    temp=temp->next;
            }
            return temp->val;
        }
    }

    void deleteAtHead() {
        if(size==0) {
             cout<<"list is empty";
             return;
        }
        head=head->next;
        size--;
    }

    void deleteAtTail() {
        if(size==0) {
            cout<<"list is empty";
             return;
        }
        Node* temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next=NULL;
        tail=temp;
        size--;

    }

    void deleteAtIdx(int idx) {
        if(size==0) {
            cout<<"list is empty";
            return;
        }
        else if (idx<0 || idx>=size) {
            cout<<"invalid idx";
            return;
        }
        else if (idx==0) return deleteAtHead();
        else if (idx==size-1) return deleteAtTail();
        else {
            Node* temp=head;
            for(int i=1;i<=idx-1;i++) {
                    temp=temp->next;
            }
            temp->next=temp->next->next;
            size--;
    }
    }
    
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList ll; // { }
    ll.insertAtEnd(10); // {10->NULL}
    ll.display();
    cout << "size is: " << ll.size << endl;
    
    ll.insertAtEnd(20); // {10->20->NULL}
    ll.display();
    cout << "size is: " << ll.size << endl;
    
    ll.insertAtEnd(30); // {10->20->30->NULL}
    ll.display();
    cout << "size is: " << ll.size << endl;
    
    ll.insertAtEnd(40); // {10->20->30->40->NULL}
    ll.display();
    cout << "size is: " << ll.size << endl;

    // Insert at head
    ll.insertAtBeg(50); // {50->10->20->30->40->NULL}
    ll.display();
    cout << "size is: " << ll.size << endl;

    ll.insertAtBeg(24); // {24->50->10->20->30->40->NULL}
    ll.display();
    cout << "size is: " << ll.size << endl;

    ll.insertAtIdx(4, 80); // {24->50->10->20->80->30->40->NULL}
    ll.display();
    cout << "size is: " << ll.size << endl;

    cout<<ll.getAtIdx(3)<<endl;
    cout<<ll.getAtIdx(-1)<<endl;

    ll.deleteAtHead(); //{50->10->20->80->30->40->NULL}
    ll.display();

    ll.deleteAtTail(); //{50->10->20->80->30}
    ll.display();

    ll.deleteAtIdx(3); //{50->10->20->30}
    ll.display();
    
    return 0;
}
