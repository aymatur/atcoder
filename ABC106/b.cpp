#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    if( N < 105) {
        cout << 0 << endl;
        return 0;
    }
    if( N == 105) {
        cout << 1 << endl;
        return 0;
    }
    int ans = 1;
    for (int i = 107; i <= N; i += 2) {
        int num = 1;
        for(int j = 3; j <= i; j += 2) {
            if(i % j == 0) num++;
        }
        if(num == 8) ans++;
    }
    cout << ans << endl;
    return 0;
}