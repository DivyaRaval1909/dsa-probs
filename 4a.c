#include <iostream>
#define SIZE 5

using namespace std;

class QueueArray {
    int items[SIZE], front, rear;
    
public:
    QueueArray() {
        front = -1;
        rear = -1;
    }

   
    void enqueue(int value) {
        if (rear == SIZE - 1) {
            cout << "Queue is full\n";
        } else {
            if (front == -1) front = 0; 
            rear++;
            items[rear] = value;
            cout << "Inserted " << value << endl;
        }
    }

  
    void dequeue() {
        if (front == -1) {
            cout << "Queue is empty\n";
        } else {
            cout << "Removed " << items[front] << endl;
            front++;
            if (front > rear) {
                front = rear = -1;
            }
        }
    }

   
    void display() {
        if (front == -1) {
            cout << "Queue is empty\n";
        } else {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++) {
                cout << items[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    QueueArray q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}
