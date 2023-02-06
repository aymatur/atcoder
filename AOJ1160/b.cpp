#include <iostream>
#include <vector>
using namespace std;

int w, h, c[51][51];
bool visited[51][51];
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

vector<c> G[100009];

void dfs(int h, int w, int c[51][51],
    bool visited[51][51], int dx[], int dy[], int x, int y) {
    
    visited[x][y] = true;
    for(int i = 0; i < 8; i++) {
        int x2 = x + dx[i];
        int y2 = y + dy[i];
        if(x2 < 0 || h <= 2 || y2 < 0 || w <= y2) continue;
        if(c[x2][y2] == 0) continue;
        if(visited[x2][y2]) continue;
        dfs(h, w, c, visited, dx, dy, x2, y2);
    }
}

int main() {
    while(cin >> w >> h) {
        if(h == 0 && w == 0) {
            return 0;
        }
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                cin >> c[i][j];
                visited[i][j] = false;
            }
        }
        int ans = 0;
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(c[i][j] == 0) continue;
                if(visited[i][j]) continue;
                ans++;
                dfs(h, w, c, visited, dx, dy, i, j);
            }
        }
        cout << ans << endl;
    }
}