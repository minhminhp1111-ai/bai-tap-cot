/* Có một tập hợp các tòa nhà với chiều cao được cho ở mảng bên dưới, các tòa đứng sát nhau nên nếu tòa cao hơn sẽ hạn chế tầm nhìn của tòa thấp hơn khi ngắm hoàng hôn. Mặt trời sẽ lặn bên phía tay phải (index cao nhất của mảng). Nhiệm vụ là tìm những ngôi nhà có thể ngắm được hoàng hôn.*/
    #include <bits/stdc++.h>
    using namespace std;

    int main () {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n;
        cin >> n;
        stack<pair<int,int>> high;
        vector<int> tower(n);
        for (int i=0; i<n; i++) {
            cin >> tower[i];
            if (high.empty() || tower[i]<(high.top()).first) {
                high.push({tower[i], i});
            } else {
                while (!high.empty() && tower[i]>=(high.top()).first) {
                    high.pop();
                }
                high.push({tower[i], i});
            }
        }
        while (!high.empty()) {
            cout << (high.top()).first << ' ' << (high.top()).second << '\n';
            high.pop();
        }
        return 0;
    }
