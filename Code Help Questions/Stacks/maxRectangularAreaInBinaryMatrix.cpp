#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

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

// Time Complexity: O(n x m)
int getArea(vector<vector<int>> M, int n, int m) {
    int area = maxRectangularArea(M[0], m);

    for(int i=1; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(M[i][j] != 0)
                M[i][j] = M[i][j] + M[i-1][j];
        }

        area = max(area, maxRectangularArea(M[i], m));
    }

    return area;
}

int main() {
    int n = 4, m =4;

    vector<vector<int>> arr = {
                                {0, 1, 1, 0},
                                {1, 1, 1, 1},
                                {1, 1, 1, 1},
                                {1, 1, 0, 0}
                            };

    cout << "\nMaximum rectangular area in the binary matrix: " << getArea(arr, n, m) << endl << endl;
 
}