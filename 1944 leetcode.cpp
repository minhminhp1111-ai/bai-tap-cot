/* There are n people standing in a queue, and they numbered from 0 to n - 1 in left to right order. You are given an array heights of distinct integers where heights[i] represents the height of the ith person.

A person can see another person to their right in the queue if everybody in between is shorter than both of them. More formally, the ith person can see the jth person if i < j and min(heights[i], heights[j]) > max(heights[i+1], heights[i+2], ..., heights[j-1]).

Return an array answer of length n where answer[i] is the number of people the ith person can see to their right in the queue.

 */
#include <bits/stdc++.h>
using namespace std;


int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    a.push_back(INT_MAX);
    stack<int> bignear;
    bignear.push(n);
    vector<int> ans(n,0);
    for (int i=n-1; i>=0; i--) {
            while (!bignear.empty() && a[bignear.top()]<a[i]) {
                bignear.pop();
                ans[i]++;
            }
            if (bignear.top()!=n) ans[i]++;
            bignear.push(i);
        
    }
    
    for (int i=0; i<n; i++) {
        cout << ans[i];
    }
    return 0;
}
