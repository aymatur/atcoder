#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template<class T> bool chmax(T& a, T b) { if(a < b) {a = b; return true;} else return false; }
template<class T> bool chmin(T& a, T b) { if(a > b) {a = b; return true;} else return false; }
const long long INF = 1LL<<60;

int main() {
    int N, M, K, S;
    cin >> N >> M >> K >> S;
    long long P, Q;
    cin >> P >> Q;

    vector<int> zombitown;
    for (int i = 0; i < K; i++) {
        int c;
        cin >> c;
        --c;
        zombitown.push_back(c);
    }

    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<long long> price(N, P);

    // 宿の料金決め
    if (K != 0) {
        for (auto e : zombitown) {
            queue<int> q;
            q.push(e);
            vector<int> d(N, -1);
            d[e] = 0;
            while(!q.empty()) {
                int now = q.front();
                q.pop();
                for (auto v : G[now]) {
                    if (d[v] != -1) continue;

                    d[v] = d[now] + 1;
                    q.push(v);
                }
            }
            for (int i = 0; i < N; i++) {
                if (price[i] == Q) continue;
                if (d[i] > S) price[i] = P;
                else price[i] = Q;
            }
        }
    }
    price[0] = 0;
    price[N-1] = 0;
    if (K != 0) {
        for (auto e : zombitown) { price[e] = -1; }
    }

    //ダイクストラ法
    vector<bool> used(N, false);
    vector<long long> dist(N, INF);
    dist[0] = 0;
    // for (int iter = 0; iter < N; iter++) {
    //     long long min_dist = INF;
    //     int min_v = -1;
    //     for (int v = 0; v < N; v++) {
    //         if (price[v] == -1) continue;
    //         if (!used[v] && dist[v] < min_dist) {
    //             min_dist = dist[v];
    //             min_v = v;
    //         }
    //     }

    //     if (min_v == -1) continue;

    //     for (auto e : G[min_v]) {
    //         if (price[e] == -1) continue;
    //         chmin(dist[e], dist[min_v] + price[e]);
    //     }
    //     used[min_v] = true;
    // }

    // ヒープを用いたダイクストラ
    priority_queue<pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>> que;
    
    que.push(make_pair(dist[0], 0));

    while(!que.empty()) {
        int v = que.top().second;
        long long d = que.top().first;
        que.pop();

        if (d > dist[v]) continue;

        for (auto e : G[v]) {
            if (price[e] == -1) continue;
            if (chmin(dist[e], dist[v] + price[e])) {
                que.push(make_pair(dist[e], e));
            }
        }
    }

    cout << dist[N-1] << endl;
}