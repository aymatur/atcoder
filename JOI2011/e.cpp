#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int H, W, N;
char c[1001][1001];

int bfs(int sy, int sx, int target) {

    int dist[1001][1001];
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            dist[i][j] = -1;
        }
    }
    queue<pair<int ,int>> q;
    dist[sy][sx] = 0;
    q.push(make_pair(sy, sx));

    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        int vy = p.first;
        int vx = p.second;

        for (int i = 0; i < 4; i++) {
            int nexty = vy + dy[i];
            int nextx = vx + dx[i];
            if (nexty >= 0 && nexty < H && nextx >= 0 && nextx < W) {
                if (dist[nexty][nextx] != -1) continue;
                char next = c[nexty][nextx];
                if(next == 'X') continue;
                else if(int(next-'0') == target) {
                    return dist[vy][vx] + 1;
                }
                else {
                    dist[nexty][nextx] = dist[vy][vx] + 1;
                    q.push(make_pair(nexty, nextx));
                    continue;
                }
            }
        }
    }
}

int main() {

    cin >> H >> W >> N;

    int sx, sy;
    vector<pair<int, int>> cheese(N+1);

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> c[i][j];
            if(c[i][j] == 'S') {
                sy = i;
                sx = j;
            }
            if(int(c[i][j] - '0') > 0 && int(c[i][j] - '0') <= N) cheese.at(int(c[i][j] - '0')) = make_pair(i, j);
        }
    }

    int ans = 0;
    int starty = sy;
    int startx = sx;
    ans += bfs(starty, startx, 1);
    for (int i = 1; i < N; i++) {
        starty = cheese[i].first;
        startx = cheese[i].second;
        ans += bfs(starty, startx, i+1);

    }

    cout << ans << endl;
    return 0;

}