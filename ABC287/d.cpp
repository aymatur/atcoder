#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

string S, T;
bool front_match[300009];
bool back_match[300009];

int main() {
    cin >> S >> T;

    for(int i = 0; i <= (int)T.length(); i++) {
        front_match[i] = false;
        back_match[i] = false;
    }
    
    front_match[0] = true; back_match[0] = true;

    for(int i = 1; i <= (int)T.length(); i++) {
        if(front_match[i-1] &&
            ((S[i-1] == T[i-1]) || S[i-1] == '?' || T[i-1] == '?')) front_match[i] = true;
        if(back_match[i-1] &&
            ((S[S.length() - i] == T[T.length() - i]) || S[S.length() - i] == '?' || T[T.length() - i] == '?')) back_match[i] = true;
    }
    
    for(int i = 0; i <= (int)T.length(); i++) {
        if(front_match[i] && back_match[T.length() - i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}