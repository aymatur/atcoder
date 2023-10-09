#include <iostream>
#include <cmath>
using namespace std;

int H, W;
long long A[126][126];
long long SUM[126][126];
long long K, V;

int main() {
    SUM[0][0] = 0;
    cin >> H >> W >> K >> V;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
            SUM[i+1][j+1] = SUM[i+1][j] + A[i][j];
            cout << SUM[i+1][j+1] << " ";
        }
        SUM[i+1][j+1] += SUM[i][j+1];
    }
    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            for (int k = i; k < H; k++) {
                for (int l = j; l < W; l++) {
                    int num = (k - i + 1) * (l - j + 1);
                    long long totalcost = SUM[k+1][l+1] - SUM[i][l+1] - SUM[k+1][j] + SUM[i][j] + num * K;
                    if (totalcost <= V) ans = max(ans, num);
                }
            }
        }
    }
    cout << ans << endl;
}