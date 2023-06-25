#include <iostream>
#include <vector>
using namespace std;
using II = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<II> stone_vec;
    int nc;
    cin >> nc;
    stone_vec.push_back({nc, 1});
    for (int i = 1; i < n; i++) {
        cin >> nc;
        auto pr = *stone_vec.rbegin();
        int c = pr.first, l = pr.second;
        if (c == nc) {
            *stone_vec.rbegin() = {c, l + 1};
            continue;
        }
        if (i % 2 == 0) {
            stone_vec.push_back({nc, 1});
        } else if (stone_vec.size() == 1) {
            *stone_vec.rbegin() = {nc, l + 1};
        } else {
            stone_vec.pop_back();
            auto pr2 = *stone_vec.rbegin();
            int l2 = pr2.second;
            *stone_vec.rbegin() = {nc, l2 + l + 1};
        }
    }
    int sum = 0;
    for (auto pr : stone_vec) {
        int c = pr.first, l = pr.second;
        if (c == 0)
            sum += l;
    }
    cout << sum << endl;
}