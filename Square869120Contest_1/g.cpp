#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<pair<pair<long long, long long>, int>>> graph(N, vector<pair<pair<long long, long long>, int>>(N, {{0,0}, 0}));
    vector<pair<pair<long long, long long>, int>> to0_vec;
    for (int i = 0; i < M; i++) {
        int s, t; long long d, time;
        cin >> s >> t >> d >> time;
        s--;
        t--;
        if (t != 0) graph.at(s).push_back({{d, time}, t});
        if (s != 0) graph.at(t).push_back({{d, time}, s});
        if (t == 0) to0_vec.push_back({{d, time}, s});
        if (s == 0) to0_vec.push_back({{d, time}, t});
    }

    vector<vector<pair<long long, long long>>> dp(1 << N, vector<pair<long long, long long>>(N, {-1, 0}));

    dp[1][0] = make_pair(0, 1);

    for (int i = 0; i < (1 << N); i++) {
        bitset<20> bits(i);
        for (int s = 0; s < N; s++) {
            if (!bits.test(s)) continue;
            long long cost_s = dp[i][s].first;
            if (cost_s == -1) continue;
            for (auto pr : graph.at(s)) {
                long long d = pr.first.first;
                long long time = pr.first.second;
                long long t = pr.second;
                if (bits.test(t)) continue;
                long long cost_t = cost_s + d;
                long long j = i | (1 << t);
                if (cost_t > time) continue;
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
    long long ans = 0;
    int all((1 << N) - 1);
    for (auto pr : to0_vec) {
        long long d = pr.first.first;
        long long time = pr.first.second;
        int s = pr.second;
        long long cost_s = dp[all][s].first;
        if (cost_s == -1) continue;
        long long cost_t = cost_s + d;
        if (cost_t > time) continue;
        if (min_cost == -1 || min_cost > cost_t) {
            // cout << "min_cost " << min_cost << endl;
            // cout << "cost_t " << cost_t << endl;
            // cout << "s " << s << endl;
            min_cost = cost_t;
            ans = dp[all][s].second;
        } else if (min_cost == cost_t) {
            // cout << "min_cost " << min_cost << endl;
            // cout << "cost_t " << cost_t << endl;
            // cout << "s " << s << endl;
            ans += dp[all][s].second;
        }
    }
    if (ans == 0) cout << "IMPOSSIBLE" << endl;
    else cout << min_cost << " " << ans << endl;
}