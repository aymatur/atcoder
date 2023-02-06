#include <iostream>
#include <string>
using namespace std;

int N;
string S;

bool arr[999];

int main() {
    cin >> N >> S;

    for (int i = 0; i < 999; i++) arr[i] = false;

    for (int i = 0; i < N - 2; i++) {
        for(int j = i + 1; j < N - 1; j++) {
            for(int k = j + 1; k < N; k++) {
                string s;
                if(S[i] != '0') s = {S[i],S[j],S[k]};
                else s = {S[j],S[k]};
                int index = stoi(s);
                arr[index] = true;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 999; i++) if(arr[i]) ans++;
    cout << ans << endl;
    return 0;

}