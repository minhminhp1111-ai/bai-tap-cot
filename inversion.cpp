#include <bits/stdc++.h>
using namespace std;
#define N 1000000007
long long mergesortwithinv (vector<int> &v, int l, int r) {
    int m=(l+r)/2;
    if (r==l) return 0;
    vector<int> c;
    long long u=mergesortwithinv(v,l,m);
    long long k=mergesortwithinv(v,m+1,r);
    int i=l, j=m+1;
    long long x=0;
    while (i<=m || j<=r) {
        if (j>r) {
            c.push_back(v[i]);
            i++;
            x+=r-m;
            continue;
        } else if (i>m) {
            c.push_back(v[j]);
            j++;
            continue;
        } else if (v[j]>=v[i]) {
            c.push_back(v[i]);
            i++;
            x+=j-m-1;
        } else if (v[j]<v[i]) {
            c.push_back(v[j]);
            j++;
        }
    }
    for (int i=l; i<=r; i++) {
        v[i]=c[i-l];
    }
    return (u%N+k%N+x%N)%N;
    
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    cout << mergesortwithinv(a,0,n-1);
}
