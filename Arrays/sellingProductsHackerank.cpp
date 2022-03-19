#include<bits/stdc++.h>
using namespace std;

int deleteProducts(vector<int> ids, int m)
{
    unordered_map<int, int> map;
    vector<pair<int, int> > v;
    int count = 0;
 
    for (int i = 0; i < ids.size(); i++)
        map[ids[i]]++;

    for (auto it = map.begin(); it != map.end(); it++)
        v.push_back(make_pair(it->second, it->first));
 
    sort(v.begin(), v.end());
 
    int size = v.size();
 
    for (int i = 0; i < size; i++) {
 
        if (v[i].first <= m) {
            m -= v[i].first;
            count++;
        }
        else
            return size - count;
    }
    return size - count;
}

int main() {
    vector<int> ids = {1,1,1,2,3,2};
    int m = 2;

    cout << endl << deleteProducts(ids, m) << endl;
}