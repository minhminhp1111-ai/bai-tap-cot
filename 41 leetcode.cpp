/* Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.*/
#include <bits/stdc++.h>
using namespace std;
int abs(int x)
{
    return ((x > 0) ? x : -x);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int x : a)
    {
        cin >> x;
    }
    int ans;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > n || a[i] <= 0)
            a[i] = 0;
        else
            continue;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0 && abs(a[i]) <= n)
        {
            if (a[abs(a[i]) - 1] != 0)
                a[abs(a[i]) - 1] = -abs(a[abs(a[i]) - 1]); // cho <0
            else
                a[abs(a[i]) - 1] = -n - 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
        {
            cout << i + 1;
            return 0;
        }
    }
    cout << n + 1;
    return 0;
}
