#include <iostream>
#include <vector>
using namespace std;

using Graph = vector<vector<int>>;
vector<long long> dist;
int max_cnt;
vector<bool> seen;

void dfs(const Graph &G, int v, int cnt) {
    cout << "v " << v << endl;
    cnt++;
    cout << "cnt " << cnt << endl;
    seen[v] = true;
    int visited = 0;
    for (auto next_v : G[v]) {
        cout << "next_v " << next_v << endl;
        if(seen[next_v]) {
            visited++;
            if(visited == (int)G[v].size()) {
                if(cnt > max_cnt) {
                    max_cnt = cnt;
                    return;
                }
            } else {
                continue;
            }
        }
        dfs(G, next_v, cnt);
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    int in[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> in[i][j];
        }
    }
    Graph G(n*m);
    for (int i = 0; i < n; i++) {
        // cout << "i: " << i << endl;
        for (int j = 0; j < m; j++) {
            // cout << "j: " << j << endl;
            if(in[i][j] == 1) {
                if (m > j+1 && in[i][j+1] == 1) {
                    G[m*i+j].push_back(m*i+j+1);
                    G[m*i+j+1].push_back(m*i+j);
                }
                if (j-1 > 0 && in[i][j-1] == 1) {
                    G[m*i+j].push_back(m*i+j-1);
                    G[m*i+j-1].push_back(m*i+j);
                }
                if (n > i+1 && in[i+1][j] == 1) {
                    G[m*i+j].push_back(m*i+j+m);
                    G[m*i+j+m].push_back(m*i+j);
                }
                if (i-1 > 0 && in[i-1][j] == 1) {
                    G[m*i+j].push_back(m*i+j-m);
                    G[m*i+j-m].push_back(m*i+j);
                }
            }
        }
    }
    max_cnt = 0;
    for (int i = 0; i < n*m; i++) {
        seen.assign(n*m, false);
        int cnt = 0;
        cout << "i " << i << endl;
        dfs(G, i, cnt);
    }
    cout << max_cnt << endl;
}