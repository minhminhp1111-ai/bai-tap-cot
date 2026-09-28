/*Given a string representing a math expression including operator + and * and operands which are positive integer and parentheses. Compute the value Q of this expression.
Input
Line 1: contains the string representing the expression (number of operators is upto 10000)
Output
Write the value Q modulo 10
9
+7 if the expression is mathematically correct in term of the syntax, and write NOT_CORRECT, otherwise*/
#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
int merge(stack<long long> &num, char c) {
    if (num.size()<2) return -1;
    if (c=='+') {
        long long x=num.top();
        num.pop();
        x=(x+num.top())%M;
        num.pop();
        num.push(x);
        return 0;
    } else if (c=='*') {
        long long x=num.top();
        num.pop();
        x=(x*num.top())%M;
        num.pop();
        num.push(x);
        return 0;
    } 
    return -1;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    getline(cin, s);
    int n=s.size();
    stack<char> op;
    stack<long long> num;
    long long tmp=0;
    int error=0;
    for (int i=0; i<n; i++) {
        if (isdigit(s[i])!=0) {
            tmp=10*tmp+(s[i]-'0');
        } else if (isdigit(s[i])==0) {
            if (i>0 && isdigit(s[i-1])) {
                num.push(tmp);
                tmp=0;
            }
            if (s[i]=='+') {
                if (op.empty()) {
                    op.push('+');
                    continue; }
                if (op.top()=='+') {
                    merge(num, '+');
                } else if (op.top()=='*') {
                    merge(num, '*');
                    op.pop();
                    op.push('+');
                } else {
                    op.push('+');
                }
                
            } else if (s[i]=='*') {
                if (op.empty()) {
                    op.push('*');
                    continue; }
                if (op.top()=='*') {
                    merge(num, '*');
                } else {
                    op.push('*');
                }

            } else if (s[i]=='(') {
                op.push('(');
            } else if (s[i]==')') {
                while (op.top()!='(') {
                    merge(num, op.top());
                    op.pop();
                }
                op.pop(); //cho mất nốt cái (
            } else {
                continue;
            }
        } 
    }
    if (isdigit(s[n-1])) {
        num.push(tmp);
        tmp=0;
    }
    while (!op.empty()) {
        merge(num, op.top());
        op.pop();
    }
    cout << num.top()%M;
    
    return 0;
}
