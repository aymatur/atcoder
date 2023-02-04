#include <iostream>
#include <string>
using namespace std;

int N;
string S[10009];

int main() {
    cin >> N;
    int forcount = 0;
    for(int i = 1; i<= N; i++) {
        cin >> S[i];
        if(S[i] == "For")  forcount++;
    }
    if (forcount >= (N+1)/2) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}