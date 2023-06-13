#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

char s[509][509];
bool sb[509][509];

int main() {
    int H, W;
    int left = 501;
    int right = 0;
    int top = 501;
    int bot = 0;
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> s[i][j];
            if (s[i][j] == '#') {
                sb[i][j] = true;
                left = min(left, j);
                right = max(right, j);
                top = min(top, i);
                bot = max(bot, i);
            }
        }
    }

    int cookie_x;
    int cookie_y;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (s[i][j] == '.') {
                if (i != top && i != bot) {
                    if(s[i-1][j] == '#' && s[i+1][j] == '#') {
                        cout << i+1 << " " << j+1 << endl;
                        return 0;
                    }
                }
                if (i == top && s[i+1][j] == '#') {
                    cout << i+1 << " " << j+1 << endl;
                    return 0;
                }
                if (i == bot && s[i-1][j] == '#') {
                    cout << i+1 << " " << j+1 << endl;
                    return 0;
                }
            }
        }
    }
}