#include <bits/stdc++.h>
using namespace std;
int able=0;
int material[11][11];
int mark (int &x, int &y, int num, int h, int w) { // x=num col, y=num row
    for (int i=x; i<x+w; i++) {
        for (int j=y; j<y+h; j++) {
            if (material[i][j]==num) {
                return 0;
            }
        }
    }
    for (int i=x; i<x+w; i++) {
        for (int j=y; j<y+h; j++) {
            material[i][j]=num;
        }
    }
    return 1;
}
void cutting (int &H, int &W, int k, int n, vector<pair<int,int>> &sub) {
    if (k==n) {
        able=1;
        return;
    }
    for (int i=0; i<= W- sub[k].second; i++) {
        for (int j=0; j<=H-sub[k].first; j++) {
            if (mark(i,j,1,sub[k].first,sub[k].second)) {
                cutting(H,W,k+1,n,sub);
                mark(i,j,0, sub[k].first, sub[k].second);
            } 
        }
    }
    for (int i=0; i<= W- sub[k].first; i++) {
        for (int j=0; j<=H-sub[k].second; j++) {
            if (mark(i,j,1,sub[k].second,sub[k].first)) {
                cutting(H,W,k+1,n,sub);
                mark(i,j,0, sub[k].second, sub[k].first);
            } 
        }
    }
}
int main()
{
    int H,W;
    cin >> H >> W;
    int n;
    cin >> n;
    vector<pair<int,int>> sub(n);
    for (int i=0; i<11; i++) {
        for (int j=0; j<11; j++) {
            material[i][j]=0;
        }
    }
    for (int i=0; i<n; i++) {
        cin >> sub[i].first >> sub[i].second; // first=h, second=w
    }
    cutting(H,W,0,n,sub);
    cout << able;
}
