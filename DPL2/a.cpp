#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // 入力
    cin >> V >> E;

    vector<vector<pair<int, int>>> graph(V);
    vector<pair<int, int>> to0_vec;

    for (int i = 0; i < E; ++i) {
        int s, t, d;
        cin >> s >> t >> d;
        graph.at(s).push_back({d, t});
        if (t == 0) to0_vec.push_back({d, s});
    }

    vector<vector<int>> dp(1 << V, vector<int>(V, -1));
    dp[1][0] = 0;
    for (int i = 0; i < (1 << V); i++) {
        bitset<15> bits(i);
        for (int s = 0; s < V; s++) {
            // sはbitsの集合に含まれている必要がある
            if (!bits.test(s)) continue;
            int cost_s = dp[i][s];
            // 到達できていない場合は次
            if (cost_s == -1) continue;
             for (auto pr : graph.at(s)) {
                 int d = pr.first;
                 int t = pr.second;
                 // これから訪問予定のtは訪問済みの集合bitsに含まれていてはいけない
                 if (bits.test(t)) continue;
                 int cost_t = cost_s + d;
                 int j = i | (1 << t);
                 if (dp[j][t] == -1 || dp[j][t] > cost_t) dp[j][t] = cost_t;
             }
        }
    }
    int min_cost = -1;
    int all((a << V) - 1);
    for (auto pr : to0_vec) {
        int d = pr.first;
        int s = pr.second;
        int cost_s = dp[all][s];
        if (cost_s == -1) continue;
        int cost_t = cost_s + d;
        if (min_cost == -1 || min_cost > cost_t) min_cost = cost_t;
    }
    cout << min_cost << endl;
}