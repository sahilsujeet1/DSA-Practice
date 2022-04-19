#include <bits/stdc++.h>
#include "node.cpp"
using namespace std;

bool isIdentical(Node *r1, Node *r2)
{
    //Your Code here
    if(!r1 && !r2)
        return true;
    if(!r1 && r2)
        return false;
    if(r1 && !r2) 
        return false;
        
    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);
    bool check = r1->data == r2->data;
    
    if(left && right && check)
        return true;
    else
        return false;
}