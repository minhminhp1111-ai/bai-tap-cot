/* You are given two integer arrays nums1 and nums2 of lengths m and n respectively. nums1 and nums2 represent the digits of two numbers. You are also given an integer k.

Create the maximum number of length k <= m + n from digits of the two numbers. The relative order of the digits from the same array must be preserved.

Return an array of the k digits representing the answer.*/

#include <bits/stdc++.h>
using namespace std;


vector<int> maxsubseq(vector<int>& a, int k) {
    int n = a.size();
    vector<int> c;
    int i = 0;

    while (c.size() < k) {
        int end = n - (k - c.size());  
        int maxpos = i;

        for (int j = i; j <= end; j++) {
            if (a[j] > a[maxpos]) maxpos = j;
        }

        c.push_back(a[maxpos]);
        i = maxpos + 1;
    }

    return c;
}
int cmp (vector<int> a, vector<int> b, int i, int j) {
    while (i<a.size() && j<b.size() && a[i]==b[j]) {
        i++;
        j++;
    }
    if (i==a.size() || j==b.size()) {
        return a.size()-i-b.size()+j;
    }
    return a[i]-b[j];
    
}
vector<int> mergemax(vector<int> a, vector<int> b) {
    int m=a.size();
    int n=b.size();
    if (m==0) return b;
    if (n==0) return a;
    vector<int> c;
    int i=0, j=0;
    while (i+j<m+n) {
        if (cmp(a,b,i,j)>=0) {
            c.push_back(a[i]);
            i++;
        } else {
            c.push_back(b[j]);
            j++;
        }
    }
    return c;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m,n;
    cin >> m >> n;
    vector<int> a(m),b(n);
    for (int i=0; i<m; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n; i++) {
        cin >> b[i];
    }
    int k;
    cin >> k;
    vector<int> c;
    for (int i=0; i<=k; i++) {
        if (i>m || k-i>n) continue;
        vector<int> a1=maxsubseq(a,i);
        vector<int> b1=maxsubseq(b,k-i);
        vector<int> c1=mergemax(a1,b1);
        if (c1>c) c=c1;
    }

    for (int i=0; i<c.size(); i++) {
        cout << c[i] << ' ';
    }
    return 0;
}
