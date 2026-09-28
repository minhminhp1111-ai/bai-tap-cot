#include <bits/stdc++.h>
using namespace std;
int valid (vector<int> x, int c, int m) {
    int count=1;
    int n=x.size();
    int l=0, r=0;
    while (r<n) {
        if (x[r]-x[l]<m) r++;
        else {
            count++;
            l=r;
            r++;
        }
    }
    if (count>=c) return 1;
    return 0;
}
int main()
{
    int T;
    cin >> T;
    for (int t=0; t<T; t++) {
        int n,c;
        cin >> n >> c;
        vector<int> x(n);
        vector<int> dist;
        for (int i=0; i<n; i++) {
            cin >> x[i];
        }
        sort(x.begin(), x.end());
        int l=0, r=x[n-1];
        while (l<r) {
            int m=(l+r)/2;
            if (valid(x,c,m)) {
                l=m;
                if (r==m+1) {
                    if (valid(x,c,r)) l=m+1;
                    r=m;
                }
            } else {
                r=m-1;
            }
        }
        cout << l << '\n';
    }


}
