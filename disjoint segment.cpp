#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<int,int>> p(n);
    for (int i=0; i<n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p.begin(),p.end());
    stack<int> st;
    for (int i=0; i<n; i++) {
        if (i>0 && p[i].first==p[i-1].first) {
            p[i].first=-1;
            p[i].second=-1; //xóa
            continue;
        } 
        while (!st.empty() && (p[st.top()].second >= p[i].second)) {
            p[st.top()].first=-1;
            p[st.top()].second=-1;
            st.pop();
        }
        st.push(i);
    }// dãy (a_i) và (b_i) tăng
    int t=0;
    while (p[t].first==-1) t++; 
    int count=1;
    for (int i=0; i<n; i++) {
        if (p[i].first>p[t].second) {
            count++;
            t=i;
        }   
    }
    cout << count;
}
