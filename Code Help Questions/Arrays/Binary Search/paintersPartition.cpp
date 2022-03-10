#include<bits/stdc++.h>
using namespace std;

bool isPossible(int arr[], int n, int m, int mid) {
    int pageSum = 0, studentCount = 1;

    for(int i=0; i<n; i++) {
        if(pageSum+arr[i] <= mid) {
            pageSum += arr[i];
        } else {
            studentCount++;
            if(studentCount > m || arr[i] > mid) {
                return false;
            }
            pageSum = arr[i];
        }
    }

    return true;
}

int allocateBooks(int arr[], int n, int m) {
    int sum = 0, ans = -1;
    for(int i=0; i<n; i++)
        sum += arr[i];
    
    int s=0, e=sum, mid = s + (e-s)/2;

    while(s<=e) {
        if(isPossible(arr, n , m, mid)) {
            ans = mid;
            e = mid-1;
        } else {
            s = mid+1;
        }

        mid = s+ (e-s)/2;
    }

    return ans;
}

int main()
{
    int books[] = {12,34,67,90};
    int n = sizeof(books)/sizeof(books[0]);
    int persons = 2;

    cout << "Largest minimum distances alloted to a painter to paint : "
    << allocateBooks(books, n, persons) << endl;
}