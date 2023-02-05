#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;
    int ans = 0;
    int temp = 0;
    for (int i = 0; i < (int)S.length(); i++) {
        if(S[i] == 'A' || S[i] == 'C' || S[i] == 'G' || S[i] == 'T') {
            temp++;
        } else {
            if(ans < temp) ans = temp;
            temp = 0;
        }
    }
    if(ans < temp) ans = temp;
    cout << ans << endl;
    return 0;
}