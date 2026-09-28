/*Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

*/
#include <bits/stdc++.h>
using namespace std;
string removeKdigits(string s, int k) {
        int n=s.size();
        int drop=k;
        string keep;
        if (n==k) return "0";
        for (int i=0; i<n; i++) {
            if (keep.empty() || (s[i]>=keep.back() && keep.size()<n-k)) {
                keep.push_back(s[i]);
            } else if (s[i]>=keep.back() && keep.size()==n-k) {
                drop--;
                continue;
            } else if (s[i]<keep.back()) {
                while (drop>0 && !keep.empty() && s[i]<keep.back()) {
                    keep.pop_back();
                    drop--;
                }
                if (keep.size()<n-k) {
                    keep.push_back(s[i]);
                }
                
            }
        }    
        string ans;
        int ok=0;
        for (int i=0; i<keep.size(); i++) {
            if (keep[i]!='0') {
                ok=1;
            }
            if (ok==1) {
                ans.push_back(keep[i]);
            }
        }
        if (ans.size()==0) return "0";
        return ans;
        
    }
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> k;
    string s;
    cin >> s;
    cout << removeKdigits(s,k);

    return 0;
}
