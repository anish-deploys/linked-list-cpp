#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;
    int size = 0;

    DoublyLinkedList() {
        head = tail = NULL;
        size = 0;
    }

    void insertAtTail(int val) {
        Node* temp = new Node(val);
        if (size == 0) 
            head = tail = temp;
        else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;  
        }
        size++;
    }

    void insertAtHead(int val) {
        Node* temp = new Node(val);
        if (size == 0) 
            head = tail = temp;
        else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++;
    }

    void insertAtIdx(int idx, int val) {
        if (idx < 0 || idx > size) {
            cout << "Invalid index" << endl;
            return;
        }
        if (idx == 0) {
            insertAtHead(val);
            return;
        }
        if (idx == size) {
            insertAtTail(val);
            return;
        } else {
            Node* t = new Node(val);
            Node* temp = head;
            for (int i = 1; i <= idx - 1; i++) {
                temp = temp->next;
            }
            t->next = temp->next;
            temp->next = t;

            t->prev = temp;
            t->next->prev = t;

            size++;
        }
    }

    void deleteAtHead() {
        if (size == 0) {
            cout << "List is empty" << endl;
            return;
        }
        head = head->next;
        if (head) head->prev = NULL;
        if (head == NULL) tail = NULL;
        size--;
    }

    void deleteAtTail() {
        if (size == 0) {
            cout << "List is empty" << endl;
            return;
        } else if (size == 1) {
            deleteAtHead();
            return;
        }
        Node* temp = tail->prev;
        temp->next = NULL;
        tail = temp;
        size--;
    }

    void deleteAtIdx(int idx) {
        if (idx < 0 || idx >= size) {
            cout << "Invalid index" << endl;
            return;
        }
        if (idx == 0) {
            deleteAtHead();
            return;
        }
        if (idx == size - 1) {
            deleteAtTail();
            return;
        }
        Node* temp = head;
        for (int i = 0; i < idx; i++) {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        size--;
    }

    int getAtIdx(int idx) {
        if (idx < 0 || idx >= size) {
            cout << "Invalid index" << endl;
            return -1;
        }
        Node* temp = head;
        for (int i = 0; i < idx; i++) {
            temp = temp->next;
        }
        return temp->val;
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
    DoublyLinkedList list;
    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.display();
    list.insertAtTail(40);
    list.display();
    list.insertAtHead(50);
    list.display();
    list.insertAtIdx(2, 60);
    list.display();
    cout << "Element at index 2: " << list.getAtIdx(2) << endl;
    list.deleteAtTail();
    list.display();
    list.deleteAtHead();
    list.display();
    list.deleteAtIdx(1);
    list.display();
    return 0;
}
