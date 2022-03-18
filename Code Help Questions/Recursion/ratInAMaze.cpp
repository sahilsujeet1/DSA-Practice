#include<bits/stdc++.h>
using namespace std;

bool isValidPath(int x, int y, vector<vector<int>> &m, int n, vector<vector<int>> visited) {
    if((x >= 0 && x < n) && (y >= 0 && y < n) && (m[x][y] == 1) && (visited[x][y] == 0)) {
        return true;
    } else {
        return false;
    }
}

void solve(int x, int y, vector<vector<int>> &m, int n, vector<vector<int>>& visited, vector<string> &ans, string path) {
    if((x == n-1) && (y == n-1)) {
        ans.push_back(path);
        return;
    }
    
    visited[x][y] = 1;
    
    // down
    int X = x+1;
    int Y = y;
        
    if(isValidPath(X,Y,m,n,visited)) {
        path.push_back('D');
        solve(X,Y,m,n,visited,ans,path);
        path.pop_back();
    }
    
    // right
    X = x;
    Y = y+1;
        
    if(isValidPath(X,Y,m,n,visited)) {
        path.push_back('R');
        solve(X,Y,m,n,visited,ans,path);
        path.pop_back();
    }
    
    // left
    X = x;
    Y = y-1;
        
    if(isValidPath(X,Y,m,n,visited)) {
        path.push_back('L');
        solve(X,Y,m,n,visited,ans,path);
        path.pop_back();
    }
    
    // up
    X = x-1;
    Y = y;
        
    if(isValidPath(X,Y,m,n,visited)) {
        path.push_back('U');
        solve(X,Y,m,n,visited,ans,path);
        path.pop_back();
    }
    
    visited[x][y] = 0;
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    // Your code goes here
    vector<string> ans;
    
    if(m[0][0] == 0) {
        return ans;
    }
    
    vector<vector<int>> visited = m;  
    int srcX = 0;
    int srcY = 0;
    
    
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            visited[i][j] = 0;
        }
    }
    
    string path = "";
    
    solve(srcX, srcY, m, n, visited, ans, path);
    sort(ans.begin(), ans.end());
    
    return ans;
}


int main()
{
    vector<vector<int>> maze = {
        {1,1,0,1},
        {0,1,0,0},
        {1,1,1,1},
        {1,0,1,1}
    };

    vector<string> ansPath = findPath(maze, 4);
    
    cout << endl << "Output: ";
    for(auto p:ansPath) {
        cout << p << " ";
    } cout << endl;
}