    #include <bits/stdc++.h>
    using namespace std;

    void update(vector<int>& tree, int ind, int l, int r, int i, int v) {
        if (i < l || i > r) return;
        if (l == r) {
            tree[ind] = v;
            return;
        }
        int m = (l + r) / 2;
        if (i <= m) {
            update(tree, 2 * ind, l, m, i, v);
        } else {
            update(tree, 2 * ind + 1, m + 1, r, i, v); 
        }
        tree[ind] = min(tree[2 * ind], tree[2 * ind + 1]);
    }

    int get(const vector<int>& tree, int ind, int l, int r, int i, int j) {
        if (j < l || r < i) {
            return INT_MAX; 
        }
        if (i <= l && r <= j) {
            return tree[ind];
        }
        int mid = (l + r) / 2;
        return min(get(tree, ind * 2, l, mid, i, j), 
                get(tree, ind * 2 + 1, mid + 1, r, i, j));
    }

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n;
        cin >> n;
        vector<int> a(n + 1);
        vector<int> st(4 * n, 0);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            update(st, 1, 1, n, i, a[i]); 
        }

        int m, t = 0;
        cin >> m;
        int sum=0;

        for (int i=0; i<m; i++) {
            int u,v;
            
            cin >> u >> v;
            if (u>v) swap(u,v);
            sum+=get(st, 1, 1, n, u+1, v+1);
        }
        cout << sum;
        return 0;
    }
