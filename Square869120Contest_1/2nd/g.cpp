#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <tuple>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<tuple<long long, long long, int>>> graph(N);
    vector<tuple<long long, long long, int>> to0_vec;
    for (int i = 0; i < M; ++i) {
        int s, t;
        long long d, time;
        cin >> s >> t >> d >> time;
        s--, t--;
        if (t != 0) graph.at(s).push_back({d, time, t});
        if (s != 0) graph.at(t).push_back({d, time, s});
        if (t == 0) to0_vec.push_back({d, time, s});
        if (s == 0) to0_vec.push_back({d, time, t});
    }
        // dp[S][v] 頂点0からスタートしてVの部分集合Sを巡回する経路のうち最短のものとその数。最後に頂点vに到達
    vector<vector<pair<long long, long long>>> dp(1 << N, vector<pair<long long, long long>>(N, {-1, 0}));
    dp[1][0] = {0, 1};
    for (int i = 0; i < (1 << N); i++) {
        bitset<20> bits(i);
        for (int s = 0; s < N; s++) {
            if (!bits.test(s)) continue;
            long long cost_s = dp[i][s].first;
            if (cost_s == -1) continue;
            for (auto tp : graph.at(s)) {
                long long d = get<0>(tp);
                long long time = get<1>(tp);
                int t = get<2>(tp);
                if (bits.test(t)) continue;
                long long cost_t = cost_s + d;
                if (cost_t > time) continue;
                int j = i | (1 << t);
                if (dp[j][t].first == -1 || dp[j][t].first > cost_t) {
                    dp[j][t].first = cost_t;
                    dp[j][t].second = dp[i][s].second;
                } else if (dp[j][t].first == cost_t) {
                    dp[j][t].second += dp[i][s].second;
                }
            }
        }
    }
    long long min_cost = -1;
    long long ans_num = 0;
    int all((1 << N) - 1);
    for (auto tp : to0_vec) {
        long long d = get<0>(tp);
        long long time = get<1>(tp);
        int s = get<2>(tp);
        long long cost_s = dp[all][s].first;
        if (cost_s == -1) continue;
        long long cost_t = cost_s + d;
        if (cost_t > time) continue;
        if (min_cost == -1 || min_cost > cost_t) {
            min_cost = cost_t;
            ans_num = dp[all][s].second;
        } else if (min_cost == cost_t) {
            ans_num += dp[all][s].second;
        }
    }
    if (ans_num == 0) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << min_cost << " " << ans_num << endl;
    }
}