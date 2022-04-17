#include<iostream>
#include<queue>
using namespace std;

int findSum(int arr[], int n, int k) {
    deque<int> maxi(k), mini(k);
    int sum = 0;

    // For first window
    for(int i=0; i<k; i++) {
        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();
        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();
        
        maxi.push_back(i);
        mini.push_back(i);
    }
    sum += arr[maxi.front()] + arr[mini.front()];

    // For next remaining windows
    for(int i=k; i<n; i++) {
        // removal
        while(!maxi.empty() && i-maxi.front() >= k)
            maxi.pop_front();

        while(!mini.empty() && i-mini.front() >= k)
            mini.pop_front();

        // addition
        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();
        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();
        
        maxi.push_back(i);
        mini.push_back(i);

        sum += arr[maxi.front()] + arr[mini.front()];
    }

    return sum;
}

int main() {
    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;

    cout << "Sum: " << findSum(arr, 7, k) << endl;
}