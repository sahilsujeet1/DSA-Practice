#include<bits/stdc++.h>
#include <node.cpp>

class Solution {
  public:
  
    Node *createMapping(Node *root, int target, map<Node*, Node*> &nodeToParent) {
        queue<Node*> q;
        Node *res = NULL;
        q.push(root);
        nodeToParent[root] = NULL;
        
        while(!q.empty()) {
            Node *front = q.front();
            q.pop();
            
            if(front->data == target)
                res = front;
            
            if(front->left) {
                nodeToParent[front->left] = front;
                q.push(front->left);
            }
            
            if(front->right) {
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        
        return res;
    }
    
    void burnTree(Node *root, map<Node*, Node*> nodeToParent, int &ans) {
        map<Node*, bool> visited;
        queue<Node*> q;
        
        q.push(root);
        visited[root] = 1;
        
        while(!q.empty()) {
            bool flag = 0;
            int size = q.size();
            
            for(int i=0; i<size; i++) {
                Node *front = q.front();
                q.pop();
                
                if(front->left && !visited[front->left]) {
                    flag = 1;
                    visited[front->left] = 1;
                    q.push(front->left);
                }
                
                if(front->right && !visited[front->right]) {
                    flag = 1;
                    visited[front->right] = 1;
                    q.push(front->right);
                }
                
                if(nodeToParent[front] && !visited[nodeToParent[front]]) {
                    flag = 1;
                    visited[nodeToParent[front]] = 1;
                    q.push(nodeToParent[front]);
                }
            }
            
            if(flag == 1) {
                ans++;
            }
        }
    }
  
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        map<Node*, Node*> nodeToParent;
        Node *targetNode = createMapping(root, target, nodeToParent);
        int ans = 0;
        burnTree(targetNode, nodeToParent, ans);
        
        return ans;
    }
};
