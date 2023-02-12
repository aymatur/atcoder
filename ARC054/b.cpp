#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double p;
    cin >> p;

    double x = log(-1.0 / p * log(pow(2.0, (-2.0/3.0)))) / log(pow(2.0, (-2.0/3.0)));

    double ans;
    if(x > 0) ans = x + p / (pow(2.0, 2.0 / 3.0 * x));
    else ans = p;

    cout << ans << endl;

}