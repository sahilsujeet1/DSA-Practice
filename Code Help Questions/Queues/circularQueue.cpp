#include <iostream>
using namespace std;

class CircularQueue {
    int *arr;
    int size;
    int front, rear;

    public:
    CircularQueue(int n) {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    bool isEmpty() {
        if(front == -1)
            return true;
        else
            return false;
    }

    bool isFull() {
        if( (front == 0 && rear == size-1) || (front != 0 && rear == (front-1)%(size-1) ) ) {
            return true;
        } else {
            return false;
        }
    }

    bool enqueue(int x) {
        if(isFull()) {
            cout << "Queue is full!" << endl;
            return false;
        } else if (isEmpty()) {
            front = rear = 0;
        } else if (front != 0 && rear == size-1) {
            rear = 0;
        } else {
            rear++;
        }

        arr[rear] = x;
        return true;
    }

    int dequeue() {
        if(isEmpty()) {
            cout << "Queue is already empty!" << endl;
            return false;
        } 

        int ans = arr[front];
        arr[front] = -1;

        if(front == rear) {
            front = rear = -1;
        } else if (front == size-1){
            front = 0;
        } else {
            front++;
        }

        return ans;
    }

    int frontQ() {
        if(isEmpty())
            return -1;
        return arr[front];
    }
};

int main() {
    CircularQueue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout << q.frontQ() << endl;

    q.dequeue();
    cout << q.frontQ() << endl;
    q.dequeue();

    q.enqueue(6);
    q.enqueue(7);
    cout << q.frontQ() << endl;


}