#include <bits/stdc++.h>
using namespace std;

class Heap {
    public:
    int arr[100];
    int size;

    Heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val) {
        size = size+1;
        int i = size;
        arr[i] = val;

        while(i > 1) {
            int parent = i/2;

            if(arr[parent] < arr[i]) {
                swap(arr[parent], arr[i]);
                i = parent;
            } else {
                return;
            }
        }
    }

    void print() {
        for(int i=1; i<=size; i++) {
            cout << arr[i] << " ";
        } cout << endl;
    }

};

int main() {
    Heap h;
    h.insert(20);
    h.insert(10);
    h.insert(11);
    h.insert(54);
    h.insert(61);
    h.insert(7);

    h.print();
}