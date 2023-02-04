#include <iostream>
#include <string>
using namespace std;

int N, M;
string S[10009], T[10009];

int main() {
    cin >> N >> M;
    int forcount = 0;
    for(int i = 1; i<= N; i++) cin >> S[i];
    for(int i = 1; i<= M; i++) cin >> T[i];

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(S[i].substr(3) == T[j]) {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}