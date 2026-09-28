#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001]; //dp[i][j]=số xu min cần biểu diễn i và chỉ số <=j
int main()
{
    int n,x;
    cin >> n >> x;
    vector<int> d(n);
    for (int i=0; i<n; i++) {
        cin >> d[i];
    }
    sort(d.begin(), d.end());
    for (int j=0; j<n; j++) {
        if (j==0) {
            dp[0][0]=0;
            for (int i=1; i<=x; i++) {
                if (i%d[0]==0) dp[i][0]=i/d[0];
                else dp[i][0]=2000;
            }
        } else {
            for (int i=1; i<=x; i++) {
            if (i==d[j]) dp[i][j]=1;
            if (i<d[j]) dp[i][j]=dp[i][j-1];
            if (i>d[j]) dp[i][j]=min(dp[i][j-1], dp[i-d[j]][j]+1);
        }
        }
        
    }
    if (dp[x][n-1]<2000) {
        cout << dp[x][n-1];
        return 0;
    }
    cout <<-1;
    return 0;
}
