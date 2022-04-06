#include <iostream>
using namespace std;

class Stacks {
    int *arr;
    int size, top1, top2;

    public:
    Stacks(int m, int n) {
        this -> size = m + n;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    int push1(int d) {
        if(top2-top1 > 1) {
            top1++;
            arr[top1] = d;
            return arr[top1];
        } else {
            cout << "Stack Overflow" << endl;
            return -1;
        }
    }

    int push2(int d) {
        if(top2-top1 > 1) {
            top2--;
            arr[top2] = d;
            return arr[top2];
        } else {
            cout << "Stack Overflow" << endl;
            return -1;
        }
    }

    int pop1() {
        if(top1 >= 0) {
            return arr[top1--];
        } else {
            cout << "Stack1 Underflow" << endl;
            return -1;
        }
    }

    int pop2() {
        if(top2 < size) {
            return top2++[arr];
        } else {
            cout << "Stack2 Underflow" << endl;
            return -1;
        }
    }

    int peek1() {
        if(top1 >= 0)
            return arr[top1];
        else {
            cout << "No element in stack 1" << endl;
            return -1;
        }
    }

    int peek2() {
        if(top2 < size) {
            return arr[top2];
        } else {
            cout << "No element in stack 2" << endl;
            return -1;
        }
    }
};

int main() {
    Stacks st(4,3);

    st.push1(1);
    st.push2(9);
    st.push1(3);
    // st.push1(5);
    st.push1(2);
    st.push1(0);
    st.push2(12);
    st.push2(42);
    st.pop1();

    cout << st.peek1() << " ";
    cout << st.peek2() << " ";
    st.pop2();
    cout << st.peek2() << " ";

    return 0;
}