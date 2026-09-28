
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
    int b[n];
    a.push_back(INT_MAX);
    stack<int> bignear;
    b[n-1]=n;
    bignear.push(n);
    for (int i=n-2; i>=0; i--) {
        if (a[i]<a[i+1]) {
            bignear.push(i+1);
            b[i]=i+1;
        } else {
            while (!bignear.empty() && a[bignear.top()]<a[i]) {
                bignear.pop();
            }
            b[i]=bignear.top();
            bignear.push(i);
        }
    }
    for (int i=0; i<n; i++) {
        cout << b[i] << ' ';
    }
    cout << '\n';
    /*int d[n];
    for (int i=n-1; i>=0; i--) {
        if (b[i]==n) d[i]=0;
        else d[i]=d[b[i]]+1;
    }*/
    vector<int> ans(n);
    ans[n-1]=0;
    for (int i=0; i<n-1; i++) {
        if (a[i]<a[i+1]) ans[i]=1;
        else {
            int temp=1;
            int index=i+1;
            while (a[b[index]]<a[i]) {
                temp++;
                index=b[index];
            }
            if (b[index]<n) temp++;
            ans[i]=temp;
        };
    }
    for (int i=0; i<n; i++) {
        cout << ans[i];
    }
    return 0;
}
