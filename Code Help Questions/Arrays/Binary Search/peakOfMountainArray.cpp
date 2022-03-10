#include <iostream>
using namespace std;

int peakOfMountain(int arr[], int n)
{
    int s = 0, e = n - 1, mid = s + (e - s) / 2;

    while (s < e)
    {
        if (arr[mid] < arr[mid + 1])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }

        mid = s + (e - s) / 2;
    }
    return s;
}

int main()
{
    int nums[] = {7, 8, 9, 10, 11, 12, 5, 4, 3, 2, 1};
    int n = sizeof(nums) / sizeof(nums[0]);
    int ansIdx = peakOfMountain(nums, n);
    cout << "Peak of mountain array: " << nums[ansIdx] << " at index " << ansIdx << endl;

    return 0;
}