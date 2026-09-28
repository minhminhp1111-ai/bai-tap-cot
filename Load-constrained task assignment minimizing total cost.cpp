#include <bits/stdc++.h>
using namespace std;
int taken[11];
int minimum=INT_MAX;
int current=0;
void assign (int k, int n, int D, int m, vector<vector<int>> &c, vector<int> &cmin) {
    if (k>n) {
        if (current<minimum) minimum=current;
        return;
    }
    if (current+cmin[n-k]>=minimum) return;
    for (int j=1; j<=m; j++) {
        if (taken[j]<D && current+c[j-1][k-1]<minimum) {
            taken[j]++;
            current+=c[j-1][k-1];
            assign(k+1,n,D,m,c,cmin);
            taken[j]--;
            current-=c[j-1][k-1];
        }
    }
}
int findmin(vector<int> &v) {
    int n=v.size();
    int m=v[0];
    for (int i=1; i<n; i++) {
        if (m>v[i]) m=v[i];
    }
    return m;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m,n,D;
    cin >> m >> n >> D;
    vector<vector<int>> c(m, vector<int> (n,0));
    vector<int> mincol(n);
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            cin >> c[i][j];
        }
    }
    for (int i=0; i<n; i++) {
        vector<int> temp(m);
        for (int j=0; j<m; j++) {
            temp[j]=c[j][i];
        }
        mincol[i]=findmin(temp);
    }
    sort(mincol.begin(), mincol.end());
    vector<int> cmin(n+1);
    cmin[0]=0;
    for (int i=0; i<n; i++) {
        cmin[i+1]=cmin[i]+mincol[i];
    } // min tổng;
    for (int i=1; i<=10; i++) {
        taken[i]=0;
    }
    assign(1,n,D,m,c,cmin);
    cout << minimum;
}
