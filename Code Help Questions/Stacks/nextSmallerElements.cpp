#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElements(vector<int> arr) {
    
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);

    for(int i=n-1; i>=0; i--) {
        while(st.top() >= arr[i]) {
            st.pop();
        } 

        ans[i] = st.top();
        st.push(arr[i]);
    }

    return ans;
}

int main() {
    vector<int> arr = {4,2,1,3,7,4,3,9};

    vector<int> res = nextSmallerElements(arr);

    for(int i=0; i<res.size(); i++) {
        cout << arr[i] << " -> " << res[i] << endl;
    }
}