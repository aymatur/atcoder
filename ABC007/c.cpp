#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

using Graph = vector<vector<int>>;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

vector<int> bfs(const Graph &G, int s) {
    int N = (int)G.size();

    vector<int> dist(N, -1);
    queue<int> que;

    dist[s] = 0;
    que.push(s);

    while(!que.empty()) {
        int v = que.front();
        que.pop();

        for(int x : G[v]) {
            if(dist[x] != -1) continue;

            dist[x] = dist[v] + 1;
            que.push(x);
        }
    }

    return dist;
}

int main() {
    int R, C;
    cin >> R >> C;
    int sy, sx, gy, gx;
    cin >> sy >> sx;
    cin >> gy >> gx;

    char c[51][51];

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> c[i][j];
        }
    }

    Graph G((R+1)*(C+1));
    for (int i = 2; i <= R - 1; i++) {
        for (int j = 2; j <= C - 1; j++) {
            if (c[i][j] == '.') {
                for (int k = 0; k < 4; k++) {
                    if (c[i+dy[k]][j+dx[k]] == '.') {
                        G[(i-1)*C + j].push_back((i-1+dy[k])*C + j+dx[k]);
                        G[(i-1+dy[k])*C + j+dx[k]].push_back((i-1)*C + j);
                    }
                }
            }
        }
    }

    vector<int> d = bfs(G, (sy-1)*C + sx);
    cout << d[(gy-1)*C + gx] << endl;
}