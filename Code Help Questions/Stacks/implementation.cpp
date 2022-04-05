#include<iostream>
using namespace std;

class Stack {
    int *arr;
    int top;
    int size;

    public:

    Stack(int s) {
        this->size = s;
        arr = new int[s];
        top = -1;
    }

    void push(int val) {
        if(size-top > 1) {
            top++;
            arr[top] = val;
        } else {
            cout << "Stack Overflow" << endl;
        }
    }

    int pop() {
        if(top >= 0) {
            return arr[top--];
        } else {
            cout << "Stack Underflow" << endl;
            return -1;
        }
    }

    int peek() {
        if(top >= 0 && top < size) {
            return arr[top];
        } else {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        if(top >= 0) {
            return false;
        } else {
            return true;
        }
    }
};

int main() {

    Stack s(5);
    s.push(1);
    s.push(2);
    cout << "Popped element: " << s.pop() << endl;
    s.push(3);
    s.push(4);

    s.push(5);
    
    cout << "Top element: " << s.peek() << endl;
    cout << "Elements present in stack: " << endl;
    while(!s.isEmpty()) {
        cout << s.pop() << endl;
    }

}