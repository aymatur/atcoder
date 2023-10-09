#include <iostream>
#include <vector>

using namespace std;

struct UnionFind {
    vector<int> par, siz;

    UnionFind(int n) : par(n, -1), siz(n, 1) {}

    int root(int x) {
        if (par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool unite(int x, int y) {
        x = root(x); y = root(y);

        if (x == y) return false;

        if (siz[x] < siz[y]) swap(x, y);

        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    int size(int x) {
        return siz[x];
    }
};

long long nc2(long long num) {
    return num * (num-1) / 2;
}

int main() {
    int n, m;
    cin >> n >> m;
    int a[m], b[m];
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
    }
    vector<long long> ans(m, 0);
    ans[m-1] = 1LL * n * (n-1) / 2;
    // cout << m-1 << endl;
    // cout << "ans[m-1]: " << ans[m-1] << endl;
    UnionFind uf(n);
    for (int i = m-1; i > 0; i--) {
        // cout << "i: " << i << endl;
        // cout << "a[i]: " << a[i] << endl;
        ans[i-1] = ans[i];
        // cout << "ans[i-1]: " << ans[i-1] << endl;
        if (ans[i-1] == 0) continue;
        long long asiz = uf.siz[uf.root(a[i])];
        // cout << "ans[i-1]: " << ans[i-1] << endl;
        long long bsiz = uf.siz[uf.root(b[i])];
        if (uf.unite(a[i], b[i])) {
            ans[i-1] -= 1LL * asiz * bsiz;
        }
    }
    for (int i = 0; i < m; i++) cout << ans[i] << endl;
}