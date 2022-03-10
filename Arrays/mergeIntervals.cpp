#include <bits/stdc++.h>
using namespace std;

// class Solution {
//     public:
//         static bool compare(vector<int> a, vector<int> b) {
//             return a.front() < b.front();
//         }

//         vector<vector<int>> merge(vector<vector<int>>& intervals) {

//             sort(intervals.begin(), intervals.end(), compare);

//             for(auto it=intervals.begin(); it!=intervals.end(); it++) {
//                 if(next(it) < intervals.end() && (*next(it))[0] >= (*it)[0] && (*next(it))[1] >= (*it)[0] && (*next(it))[1] <= (*it)[1] && (*next(it))[0] <= (*it)[1]) {
//                     (*it)[1] = max((*it)[1], (*next(it))[1]);
//                     intervals.erase(next(it));
//                 }
//             }

//             for(auto x:intervals) {
//                 for(auto y:x) {
//                     cout << y << " ";
//                 } cout << endl;
//             }

//             return intervals;
//         }

// };

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {

        sort(intervals.begin(), intervals.end());
        int r = 0;

        for (auto i : intervals)
        {
            if (i[0] <= intervals[r][1])
            {
                intervals[r][1] = max(intervals[r][1], i[1]);
            }
            else
            {
                intervals[++r] = i;
            }
        }

        intervals.resize(r + 1);

        return intervals;
    }
};

int main()
{
    vector<vector<int>> intervals = {{2, 3}, {1, 4}};
    Solution s;

    intervals = s.merge(intervals);

    for (auto x : intervals)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}