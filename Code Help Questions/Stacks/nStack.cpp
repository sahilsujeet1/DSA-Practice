#include<iostream>
using namespace std;

class NStack {

    int *arr, *top, *next;
    int s, n, freespot;

    public:
    NStack(int S, int N) {
        s = S;
        n = N;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        for(int i=0; i<n; i++) {
            top[i] = -1;
        }

        for(int i=0; i<s; i++) {
            next[i] = i+1;
        }
        next[s-1] = -1;
        freespot = 0;
    }

    int push(int x, int m) {
        if(freespot == -1) {
            cout << "Stack" << m << " overflow" << endl;
            return -1;
        }

        int index = freespot;
        freespot = next[index];
        arr[index] = x;
        next[index] = top[m-1];
        top[m-1] = index;

        cout << x << " pushed into stack"<< m << endl;
        return x;
    }

    int pop(int m) {
        if(top[m-1] == -1) {
            cout << "Stack" << m << " underflow" << endl;
            return -1;
        }

        int index = top[m-1];
        top[m-1] = next[index];
        next[index] = freespot;
        freespot = index;

        cout << arr[index] << " popped out from stack" << m << endl;
        return arr[index];
    }

    int peek(int m) {
        if(top[m-1] == -1) {
            cout << "Stack" << m << " underflow" << endl;
            return -1;
        }

        return arr[top[m-1]];
    }
};

int main() {
    NStack stacks(6,3);

    stacks.push(1,1);
    cout << stacks.peek(1) << endl << endl;

    stacks.push(2,1);
    cout << stacks.peek(1) << endl << endl;

    stacks.push(3,1);
    cout << stacks.peek(1) << endl << endl;

    stacks.push(4,1);
    cout << stacks.peek(1) << endl << endl;

    stacks.push(5,2);
    cout << stacks.peek(2) << endl << endl;

    stacks.push(6,3);
    cout << stacks.peek(3) << endl << endl;

    stacks.pop(2);
    cout << stacks.peek(2) << endl << endl;

    stacks.pop(1);
    cout << stacks.peek(1) << endl << endl;
    stacks.pop(1);
    cout << stacks.peek(1) << endl << endl;
    stacks.pop(1);
    cout << stacks.peek(1) << endl << endl;
    stacks.pop(1);
    cout << stacks.peek(1) << endl << endl;
}