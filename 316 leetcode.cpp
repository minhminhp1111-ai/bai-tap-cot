/*Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.*/
#include <bits/stdc++.h>
using namespace std;

int main () {
    string s;
    cin >> s;
    int n=s.size();
    vector<int> last(26);
    for (int i=0; i<n; i++) {
        last[s[i]-'a']=i;
    }
    stack<char> letter;
    vector<int> app(26,0);
    for (int i=0; i<n; i++) {
        if (letter.empty()) {
            letter.push(s[i]);
            app[s[i]-'a']=1;
            continue;
        } 
        if (letter.top()>s[i] && last[letter.top()-'a']>i) {
            if (app[s[i]-'a']==1) continue;
            while (!letter.empty() && letter.top()>s[i] && last[letter.top()-'a']>i) {
                app[letter.top()-'a']=0;
                letter.pop();
            }
            letter.push(s[i]); 
            app[s[i]-'a']=1;
            
        } else if (letter.top()>s[i] && last[letter.top()-'a']<i) {
            if (app[s[i]-'a']==0) {
                letter.push(s[i]); 
                app[s[i]-'a']=1;
            }
        } else if (letter.top()==s[i]) {
            continue;
        } else if (letter.top()<s[i]) {
            if (app[s[i]-'a']==0) {
                letter.push(s[i]); 
                app[s[i]-'a']=1;
            }
        }
    }
    string ans;
    while (!letter.empty()) {
        ans.push_back(letter.top());
        letter.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}

