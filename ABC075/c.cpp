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
};

int main() {
    int n, m;
    cin >> n >> m;

    int A[m], B[m];
    for (int i = 0; i < m; i++) {
        cin >> A[i] >> B[i];
        A[i]--, B[i]--;
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        UnionFind uf(n);
        for (int j = 0; j < m; j++) if (j != i) uf.unite(A[j], B[j]);
        int c = 0;
        for (int j = 0; j < n; j++) if (j == uf.root(j)) c++;
        if (1 < c) ans++;
    }
    cout << ans << endl;
}