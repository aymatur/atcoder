#include <iostream>
#include <vector>
#include <algorithm>
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
        x == root(x); y = root(y);

        if (x == y) return false;

        if (siz[x] < siz[y]) swap(x, y);

        par[y] = x;
        siz[x] += siz[y];
        return true;
    }
};

using Edge = pair<int, pair<int, int>>;

int main() {
    int V, E;
    cin >> V >> E;
    vector<Edge> edges(E;
    for (int i = 0; i < E; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        edges[i] = Edge(w, make_pair(s, t));
    }

    sort(edges.begin(), edges.end());

    long long res = 0;
    UnionFind uf(N);
    for (int i = 0; i < N; i++) {
        int w = edges[i].first;
        int s = edges[i].second.first;
        int t = edges[i].second.second;

        if (uf.issame(s, t)) continue;

        res += w;
        uf.unite(s, t);
    }
    cout << res << endl;
}