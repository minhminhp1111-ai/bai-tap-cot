#include <bits/stdc++.h>
using namespace std;
int visited[13];
int step[5][13]; //step[i][j]=bước thứ j của xe i, step[i][0]=0;
int cap_now[5];
int cur=0;
int sol=INT_MAX;
int min_dist=INT_MAX;
int num_visited=0; // for branch and bound 
int min_d=INT_MAX;
void route_total (int t, int s, int &n, int &num_truck, int &capacity, vector<int> &d, vector<vector<int>> &dist) {
    if (t==num_truck) {
        if (cur<sol && num_visited == n) sol=cur;
        return;
    }
    if ((n-num_visited)*min_dist+cur>=sol) return;
    for (int i=1; i<=n; i++) {
        if (t>=1 && s==1 && i<=step[t-1][1]) continue;
        if (cap_now[t]+min_d>capacity) break;
        if (visited[i]==0 && cur+dist[step[t][s-1]][i]<sol && cap_now[t]+d[i]<=capacity) {
            step[t][s]=i;
            visited[i]=1;
            cap_now[t]+=d[i];
            num_visited++;
            int tmp=cur;
            cur+=dist[step[t][s-1]][i];
            route_total(t,s+1,n,num_truck,capacity,d,dist);
            visited[i]=0;
            cap_now[t]-=d[i];
            cur=tmp;
            num_visited--;
        }
    }
    if (cur+dist[step[t][s-1]][0]>=sol) return;
    int tmp=cur;
    cur+=dist[step[t][s-1]][0];
    route_total(t+1,1,n,num_truck,capacity,d,dist);
    cur=tmp;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,K,Q;
    cin >> n >> K >> Q;
    vector<int> d(n+1);
    for (int i=1; i<=n; i++) {
        cin >> d[i];
        if (d[i]<min_d) min_d=d[i];
    }
    vector<vector<int>> c(n+1, vector<int> (n+1,0));
    for (int i=0; i<n+1; i++) {
        for (int j=0; j<n+1; j++) {
            cin >> c[i][j];
            if (i!=j && min_dist>c[i][j]) min_dist=c[i][j];
        }
    }
    visited[0]=0;
    for (int i=0; i<5; i++) {
        step[i][0]=0;
        step[i][1]=0;
        cap_now[i]=0;
    }
    route_total(0,1,n,K,Q,d,c);
    cout << sol;
}
