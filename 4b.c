#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class Deque {
private:
    Node* front;
    Node* rear;

public:
    Deque() {
        front = nullptr;
        rear = nullptr;
    }

    void insertFront(int data) {
        Node* newNode = new Node(data);
        if (front == nullptr) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        cout << data << " inserted at front\n";
    }

    void insertRear(int data) {
        Node* newNode = new Node(data);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
        cout << data << " inserted at rear\n";
    }

    void deleteFront() {
        if (front == nullptr) {
            cout << "Deque is empty, can't delete from front\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        } else {
            front->prev = nullptr;
        }
        delete temp;
        cout << "Deleted from front\n";
    }

    void deleteRear() {
        if (rear == nullptr) {
            cout << "Deque is empty, can't delete from rear\n";
            return;
        }
        Node* temp = rear;
        rear = rear->prev;
        if (rear == nullptr) {
            front = nullptr;
        } else {
            rear->next = nullptr;
        }
        delete temp;
        cout << "Deleted from rear\n";
    }

    void display() {
        if (front == nullptr) {
            cout << "Deque is empty\n";
            return;
        }
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Deque dq;
    dq.insertFront(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.display();
    dq.deleteFront();
    dq.display();
    dq.deleteRear();
    dq.display();
    
    return 0;
}
