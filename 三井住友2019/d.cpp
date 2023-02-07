#include <iostream>
#include <string>
using namespace std;

int N;
string S;

bool arr[999];

int main() {
    cin >> N >> S;

    int ans = 0;

    for (int i = 0; i < 10; i++) {
        if(S.find(to_string(i)) == string::npos) continue;
        int ipos = S.find(to_string(i));
        string nextString1 = S.substr(ipos+1);
        for(int j = 0; j < 10; j++) {
            if(nextString1.find(to_string(j)) == string::npos) continue;
            int jpos = nextString1.find(to_string(j));
            string nextString2 = nextString1.substr(jpos+1);
            for(int k = 0; k < 10; k++) {
                if(nextString2.find(to_string(k)) == string::npos) continue;
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}