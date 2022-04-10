#include <bits/stdc++.h>
using namespace std;

/*  
    Special type of stack that allows to push, pop and get minimum from the stack in
    O(1) time and O(1) extra space
 */

class SpecialStack {
	stack<int> s;
	int mini;

    public:
        
    void push(int data) {
		if(s.empty()) {
			s.push(data);
			mini = data;
		} else {
			if(data < mini) {
				s.push(2*data - mini);
				mini = data;
			} else {
				s.push(data);
			}
		}
    }

    int pop() {
		if(s.empty())
			return -1;
		
		int curr = s.top();
		s.pop();
		if(curr < mini) {
			int prevMin = mini;
			int val = 2*mini - curr;
			mini = val;
			return prevMin;
		} else {
			return curr;
		}
    }

    int top() {
		if(s.empty())
			return -1;
		
		int curr = s.top();
		if(curr < mini) {
			return mini;
		} else {
			return curr;
		}
    }

    bool isEmpty() {
		return s.empty();
    }

    int getMin() {
		if(s.empty())
			return -1;
		return mini;
    }  
};

int main() {
    SpecialStack s;

    s.push(9);
    cout << "Top: " << s.top() << " -> Min: " << s.getMin() << endl << endl;

    s.push(10);
    cout << "Top: " << s.top() << " -> Min: " << s.getMin() << endl << endl;

    s.push(5);
    cout << "Top: " << s.top() << " -> Min: " << s.getMin() << endl << endl;

    s.push(2);
    cout << "Top: " << s.top() << " -> Min: " << s.getMin() << endl << endl;

    s.push(3);
    cout << "Top: " << s.top() << " -> Min: " << s.getMin() << endl << endl;

    s.push(1);
    cout << "Top: " << s.top() << " -> Min: " << s.getMin() << endl << endl;

    s.pop();
    cout << "Top: " << s.top() << " -> Min: " << s.getMin() << endl << endl;
}