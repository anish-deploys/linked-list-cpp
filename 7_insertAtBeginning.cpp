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

    return 0;
}
