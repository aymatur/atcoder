#include <iostream>
#include <queue>
#include <vector>
#include <utility>

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int H, W;

char c[51][51];

using namespace std;

int bfs() {

    vector<vector<int>> dist(H+1, vector<int>(W+1, -1));
    dist[1][1] = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(1,1));

    while (!q.empty()) {
        pair<int, int> v = q.front();
        q.pop();

        int vy = v.first;
        int vx = v.second;

        for (int i = 0; i < 4; i++) {
            int nexty = vy + dy[i];
            int nextx = vx + dx[i];
            if (nexty >= 0 && nexty <= H && nextx >= 0 && nextx <= W) {
                if (dist[nexty][nextx] != -1) continue;
                if (c[nexty][nextx] == '.') {
                    dist[nexty][nextx] = dist[vy][vx] + 1;
                    q.push(make_pair(nexty, nextx));
                }
            }
        }
    }
    return dist[H][W];   
}

int main() {
    cin >> H >> W;
    int white = 0;
    for (int h = 1; h <= H; h++) {
        for (int w = 1; w <= W; w++) {
            cin >> c[h][w];
            if (c[h][w] == '.') white++;
        }
    }

    int cost = bfs();
    if (cost == -1) {
        cout << -1 << endl;
        return 0;
    }

    cout << white - cost - 1<< endl;
    return 0;

}