#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int a = N/5;
    int b = N%5;
    if(b<3) cout << a*5 << endl;
    else cout << a*5+5;
}