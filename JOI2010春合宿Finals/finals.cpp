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
    int N, M, K;
    cin >> N >> M >> K;
    vector<Edge> edges(M);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = Edge(a, make_pair(b, c));
    }

    sort(edges.begin(), edges.end());

    long long res = 0;
    long long cnt = N;
    UnionFind uf(N);
    for (int i = 0; i < M; i++) {
        if (cnt == K) break;
        int a = edges[i].first;
        int b = edges[i].second.first;
        int c = edges[i].second.second;

        if (uf.issame(a, b)) continue;

        res += c;
        uf.unite(a, b);
        cnt--;
    }
}