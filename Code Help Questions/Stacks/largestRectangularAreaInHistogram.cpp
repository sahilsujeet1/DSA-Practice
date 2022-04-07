#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElements(vector<int> arr, int n) {
    
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);

    for(int i=n-1; i>=0; i--) {
        while(st.top() != -1 && arr[st.top()] >= arr[i]) {
            st.pop();
        } 

        ans[i] = st.top();
        st.push(i);
    }

    return ans;
}

vector<int> prevSmallerElements(vector<int> arr, int n) {
    
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);

    for(int i=0; i<n; i++) {
        while(st.top() != -1 && arr[st.top()] >= arr[i]) {
            st.pop();
        } 

        ans[i] = st.top();
        st.push(i);
    }

    return ans;
}

int maxRectangularArea(vector<int> heights, int n) {

    vector<int> next(n);
    next = nextSmallerElements(heights, n);

    vector<int> prev(n);
    prev = prevSmallerElements(heights, n);

    int area = INT_MIN;

    for(int i=0; i<n; i++) {
        int l = heights[i];

        if(next[i] == -1)
            next[i] = n;

        int b = next[i]-prev[i]-1;
        int newArea = l*b;
        area = max(area, newArea);
    }

    return area;
}

int main() {
    vector<int> heights = {2,1,5,6,4,3,1};
    int n = heights.size();

    int ans = maxRectangularArea(heights, n);

    cout << "\nMax rectangular area in histogram: " << ans << endl;
}