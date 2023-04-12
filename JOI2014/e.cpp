#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template<class T> bool chmax(T& a, T b) { if(a < b) {a = b; return true;} else return false; }
template<class T> bool chmin(T& a, T b) { if(a > b) {a = b; return true;} else return false; }
const long long INF = 1LL<<60;

int main() {
    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> taxi(N);
    for (int i = 0; i < N; i++) {
        int c, r;
        cin >> c >> r;
        taxi[i] = make_pair(c, r);
    }

    vector<vector<int>> G(N); 
    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<vector<pair<int, int>>> newG(N);

    for (int i = 0; i < N; i++) {
        vector<int> dis(N, -1);
        queue<int> q;
        q.push(i);
        dis[i] = 0;
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto e : G[v]) {
                if (dis[e] == -1) {
                    dis[e] = dis[v] + 1;
                    q.push(e);
                }
            }
        }
        for (int j = 0; j < N; j++) {
            if (0 < dis[j] && dis[j] <= taxi[i].second) {
                newG[i].push_back({j, taxi[i].first});
            }
        }

    }

    vector<bool> used(N);
    vector<long long> dist(N, INF);

    dist[0] = 0;

    for (int iter = 0; iter < N; iter++) {
        long long min_dist = INF;
        int min_v = -1;

        for (int v = 0; v < N; v++) {
            if (!used[v] && dist[v] < min_dist) {
                min_dist = dist[v];
                min_v = v;
            }
        }
        if (min_v == -1) continue;

        for (auto e : newG[min_v]) {
            chmin(dist[e.first], dist[min_v] + e.second);
        }
        used[min_v] = true;
    }
    cout << dist[N-1] << endl;
}