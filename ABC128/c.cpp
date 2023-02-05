#include <iostream>
#include <cmath>
using namespace std;

int N, M;
int k[11], s[11][11];
int p[11];

int main() {
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        cin >> k[i];
        for(int j = 0; j < k[i]; j++) {
            int sin = 0;
            cin >> sin;
            sin--;
            s[i][j] = sin;
        }
    }
    for(int i = 0; i < M; i++) cin >> p[i];

    int ans = 0;
    for(int bit = 0; bit < (1 << N); bit++) {
        int temp = 0;
        bool next = false;
        for(int i = 0; i < M; i++) {
            int onSwitchCount = 0;
            for(int j = 0; j < k[i]; j++) {
                if(bit & (1 << s[i][j])) onSwitchCount++;
            }
            if(onSwitchCount % 2 != p[i]) {
                next = true;
                break;
            }
            temp++;
        }
        if(next) continue;
        if(temp == M) ans++;
    }
    cout << ans << endl;
    return 0;
}