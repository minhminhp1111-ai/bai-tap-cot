//Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.


#include <bits/stdc++.h>
using namespace std;
vector<int> b(9, 0);
vector<int> check(21, 0); // check[i]= số lần xuất hiện của -10+i
void backtrack(vector<int>& a, int k, vector<vector<int>> &ans, vector<int>& appear)
{
    if (k == a.size())
    {
        ans.push_back(b);
        return;
    }
    for (int j = -10; j <=10; j++)
    {
        if (check[j + 10] < appear[j + 10])
        {
            b[k] = j;
            check[j + 10]++;
            backtrack(a, k + 1, ans, appear);
            check[j + 10]--;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }
    b.resize(n);
    sort(a.begin(), a.end());
    vector<vector<int>> ans;
    vector<int> appear(21,0);
    for (int x : a) {
        appear[x+10]++;
    }
    backtrack(a,0,ans,appear);
    for (int i=0; i<ans.size(); i++) {
        for (int y: ans[i]) {
            cout << y << ' ';
        }
        cout << '\n';
    }
    return 0;
}
