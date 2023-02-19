#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

int dy[] = {0, 1, 1, 0, -1, -1};
int dxForOdd[] = {1, 1, 0, -1, 0, 1}; 
int dxForEven[] = {1, 0, -1, -1, -1, 0}; 
int c[102][102];
int W, H;

int bfs() {

    queue<pair<int, int>> q;
    q.push(make_pair(0,0));

    vector<vector<int>> dist(H+2, vector<int>(W+2, -1));
    dist[0][0] = 0;

    int ret = 0;

    while(!q.empty()) {
        pair<int,int> v = q.front();
        q.pop();

        int vy = v.first;
        int vx = v.second;

        for (int i = 0; i < 6; i++) {
            int nexty = vy + dy[i];
            int nextx = vy % 2 != 0 ? vx + dxForOdd[i] : vx + dxForEven[i];
            if (nexty >= 0 && nexty <= H+1 && nextx >= 0 && nextx <= W+1) {
                if (c[nexty][nextx] == 1) {
                    ret++;
                    continue;
                }
                if (dist[nexty][nextx] != -1) continue;
                if (c[nexty][nextx] == 0) {
                    dist[nexty][nextx] = 1;
                    q.push(make_pair(nexty, nextx));
                    continue;
                }
            }
        }
    }
    return ret;
}

int main() {
    cin >> W >> H;
    for (int h = 1; h <= H; h++) {
        for (int w = 1; w <= W; w++) {
            cin >> c[h][w];
        }
    }

    int ans = bfs();
    cout << ans << endl;
    return 0;
}