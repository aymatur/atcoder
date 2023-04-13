#include <iostream>
#include <vector>
using namespace std;

const long long INF = 1LL << 60;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> c(10, vector<int>(10, 0));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> c[i][j];
        }
    }

    for (int k = 0; k < 10; k++) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
            }
        }
    }

    vector<vector<int>> A(H, vector<int>(W, 0));
    long long ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int a;
            cin >> a;
            if (a != -1) ans = ans + c[a][1];
        }
    }
    cout << ans << endl;
}