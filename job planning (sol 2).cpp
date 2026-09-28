#include <bits/stdc++.h>
using namespace std;
auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    };
int main()
{
    int n;
    cin >> n;
    vector<pair<int,int>> job(n);
    for (int i=0; i<n; i++) {
        cin >> job[i].first >> job[i].second;
    }
    sort(job.begin(), job.end());
    priority_queue<int, vector<int>, greater<int>> shortlist;
    for (int i=0; i<n; i++) {
        if (shortlist.size()<job[i].first) {
            shortlist.push(job[i].second);
        } else if (!shortlist.empty()) {
            if (shortlist.top() < job[i].second) {
                shortlist.pop();
                shortlist.push(job[i].second);
            }
        }
    }
    int sum=0;
    while (!shortlist.empty()) {
        sum+=shortlist.top();
        shortlist.pop();
    }
    cout << sum;
    
    
}
