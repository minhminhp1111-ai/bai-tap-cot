#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
void compress (vector<int> &a) {
    vector<pair<int,int>> awithorder(a.size());
    for (int i=0; i<a.size(); i++) {
        awithorder[i].first=a[i];
        awithorder[i].second=i;
    }
    sort(awithorder.begin(), awithorder.end());
    int idx=-1;
    for (int i=0; i<awithorder.size(); i++) {
        if (i>0 && awithorder[i].first==awithorder[i-1].first) {
            a[awithorder[i].second]=idx;
        } else {
            idx++;
            a[awithorder[i].second]=idx;
        }
    }
}

void update (vector<long long> &tree, int idx, int l, int r, int i, int v) {
    if (l > i || r < i) {//disjoint 
        return;
    } 
    if (l==r) {
        tree[idx]=(tree[idx]+v)%M;
        return;
    } 
    int m=(l+r)/2;
    if (i<=m) {
        update(tree,2*idx,l,m,i,v);
    } else {
        update(tree,2*idx+1,m+1,r,i,v);
    }
    tree[idx]=(tree[2*idx]+tree[2*idx+1])%M;
    
}
long long query (vector<long long> &tree, int idx, int l, int r, int i, int j) {
    if (l>j || r<i) return 0;
    if (l>=i && r <= j) {
        return tree[idx];
    }
    int m=(l+r)/2;
    return query(tree,2*idx,l,m,i,j)+query(tree,2*idx+1,m+1,r,i,j);
}
long long dp[100005][31];
int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    vector<long long> seg(4*n,0);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    compress(a);
    long long s=0;
    for (int i=0; i<n; i++) {
        dp[i][1]=1;
    }
    for (int k1=2; k1<=k; k1++) {
        for (int i=0; i<n; i++) {
            update(seg,1,0,n-1,a[i],dp[i][k1-1]);
            dp[i][k1]=query(seg,1,0,n-1,a[i]+1,n-1)%M;
            if (k1==k) s=(s+dp[i][k1])%M;
        }
        seg.assign(4 * n, 0);
    }
    cout << s;
}
