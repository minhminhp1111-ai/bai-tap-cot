


#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> a, pair<int,int> b) {
    if (a.second != b.second)
        return a.second > b.second; 
    return a.first > b.first;      
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> x(n);
    for (int i=0; i<n; i++) {
        cin >> x[i].first >> x[i].second;
    }
    int m=0;
    for (int i=0; i<n; i++) {
        if (m<x[i].first) {
            m=x[i].first;
        }
    }
    vector<int> check(m+1);
    int ans=0;
    sort(x.begin(), x.end(), cmp);
    for (int i=0; i<n; i++) {
        int flag=0;
        for (int j=x[i].first; j<=m; j++) {
            if (check[j]==j) {
                flag=1;
                break;
            }
        }
        if (flag==0) {
            for (int j=x[i].first; j<=m; j++) {
                check[j]++;
            }
            ans+=x[i].second;
        }
    }
    cout << ans;
}
