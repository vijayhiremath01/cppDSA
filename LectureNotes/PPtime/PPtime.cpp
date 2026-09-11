#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(vector<int> &arr, int n, int m, int maxAllowedTime)
{
    int painterCount = 1, timeSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxAllowedTime) return false;

        if (timeSum + arr[i] <= maxAllowedTime)
        {
            timeSum += arr[i];
        }
        else
        {
            painterCount++;
            if (painterCount > m) return false;
            timeSum = arr[i];
        }
    }
    return true;
}

int allocatedTime(vector<int> &arr, int n, int m)
{
    if (m > n) return -1;

    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];

    int st = *max_element(arr.begin(), arr.end());
    int end = sum, ans = -1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (isValid(arr, n, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr;
    int n, m;
    cout << "Enter the number of boards : ";
    cin >> n;
    cout << "Enter the number of painters : ";
    cin >> m;
    cout << "Enter the time for each board : ";

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    cout << "Minimum time to paint all boards: " << allocatedTime(arr, n, m) << endl;
    return 0;
}
