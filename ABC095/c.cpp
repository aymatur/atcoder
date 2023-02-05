#include <iostream>
#include <cmath>
using namespace std;

int A, B, C, X, Y;

int main() {
    cin >> A >> B >> C >> X >> Y;

    int resta = X;
    int restb = Y;

    int buy = 0;
    long long ans = 0;
    if ((A + B) <= (C * 2)) {
       buy = min(resta, restb);
       ans += A * buy;
       ans += B * buy;
       resta -= buy;
       restb -= buy;
    }
    int cnum = 0;
    if ((A + B) > (C * 2)) {
       cnum = min(resta, restb);
       ans += 2 * C * cnum;
       resta -= cnum;
       restb -= cnum;
    }
    if(A <= C * 2) {
       ans += A * resta;
       resta = 0;
    }
    if(B <= C * 2) {
       ans += B * restb;
       restb = 0;
    }
    ans += 2 * C * resta;
    ans += 2 * C * restb;
    cout << ans << endl;
    
    return 0;
}