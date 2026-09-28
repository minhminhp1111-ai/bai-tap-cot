#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int parent[100005];
int height[100005];
void reassign(int a[], int n) {
    for (int i=0; i<n; i++) {
        a[i]=0;
    }
}
void dfs (vector<vector<pii>> &adj, int r) {
    for (int i=0; i<adj[r].size(); i++) {
        int v=adj[r][i].first;
        if (v==parent[r]) continue;
        parent[v]=r;
        height[v]=height[r]+adj[r][i].second;
        dfs(adj,v);
    }
    return;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<pii>> adj(n+1);
    for (int i=0; i<n-1; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dfs(adj, 1);
    int m1=1;
    for (int i=1; i<=n; i++) {
        if (height[m1]<height[i]) m1=i;
    }
    reassign(parent, n+1);
    reassign(height, n+1);
    dfs(adj,m1);
    int m2=1;
    for (int i=1; i<=n; i++) {
        if (height[m2]<height[i]) m2=i;
    }
    cout << height[m2];
}
