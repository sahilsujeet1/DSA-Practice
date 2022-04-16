#include<bits/stdc++.h>
using namespace std;

class kQueue {
    int n, k, freeSpot;
    int *arr, *next, *front, *rear;

    public:
    kQueue(int n, int k) {
        this->n = n;
        this->k = k;

        arr = new int[n];
        next = new int[n];
        for(int i=0; i<n; i++) {
            next[i] = i+1;
        }
        next[n-1] = -1;

        front = new int[k];
        rear = new int[k];

        for(int i=0; i<k; i++) {
            front[i] = -1;
            rear[i] = -1;
        }

        freeSpot = 0;
    }

    void enqueue(int x, int qn) {
        // Overflow
        if(freeSpot == -1) {
            cout << "Queue overflow" << endl;
            return;
        }

        // find free spot and update it
        int index = freeSpot;
        freeSpot = next[index];

        // first element
        if(front[qn-1] == -1) {
            front[qn-1] = index;
        } else {
            next[rear[qn-1]] = index;
        }

        // update next and rear and insert value
        next[index] = -1;
        rear[qn-1] = index;
        arr[index] = x;
    }

    int dequeue(int qn) {
        // Underflow
        if(front[qn-1] == -1) {
            cout << "Queue underflow" << endl;
            return -1;
        }
        // find index to pop
        int index = front[qn-1];
        // increment front
        front[qn-1] = next[index];
        // manage freespots
        next[index] = freeSpot;
        freeSpot = index;
        return arr[index];
    }
};

int main() {
    kQueue q(10, 3);
    q.enqueue(10, 1);
    q.enqueue(15,1);
    q.enqueue(20, 2);
    q.enqueue(25,1);

    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;

    cout << q.dequeue(1) << endl;

    return 0;
}