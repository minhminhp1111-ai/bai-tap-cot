/*Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.*/
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
    bool answer=false;
    stack<int> big;
    vector<int> m(n);
    m[0]=0;
    for (int i=1; i<n; i++) {
        m[i]=((a[m[i-1]]>a[i])?i:m[i-1]);
    }
    // cần tìm k,j: a[m[j]]<a[k]<a[j]
    for (int i=0; i<n; i++) {
        if (a[i]!=a[m[i]]) {
            while (!big.empty() && a[i]>=a[big.top()]) {
                big.pop();
            }
        if (big.empty()) {
            big.push(i);
            continue;
        }
        if (a[i]>a[m[big.top()]]) answer= true;
        big.push(i);

                
        }
    }
    cout << answer;
    return 0;
}
