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
    int N;
    vector<pair<int, int>> x(N);
    vector<pair<int, int>> y(N);
    for (int i = 0; i < M; i++) {
        int xin, yin;
        cin >> xin >> yin;
        x.push_back(make_pair(xin, i));
        y.push_back(make_pair(yin, i));
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < N-1; i++) {
        edges.push_back(make_tuple(x[i+1].first-x[i].first, x[i].second, x[i+1].second));
        edges.push_back(make_tuple(y[i+1].first-y[i].first, y[i].second, y[i+1].second));
    }
    sort(edges.begin(), edges.end());
    UnionFind uf(N);
    long long res = 0;
    for (auto p : edges) {
        int x, y, c;
        tie(c, x, y) = p;
        if (uf.issame(x,y)) continue;
        uf.unite(x,y);
        res += c;
    }
}