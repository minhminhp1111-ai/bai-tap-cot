#include <bits/stdc++.h>
using namespace std;
string t;
int Q=0;
void backtrack (string s, int k, int n) {
    if (k==n) {
        Q++;
        return;
    } 
    if ((t+'1').find(s)==string::npos) {
        t.push_back('1');
        backtrack(s,k+1,n);
        t.pop_back();
    }
    if ((t+'0').find(s)==string::npos) {
        t.push_back('0');
        backtrack(s,k+1,n);
        t.pop_back();
    }
    
}
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    backtrack(s,0,n);
    cout << Q;
}
