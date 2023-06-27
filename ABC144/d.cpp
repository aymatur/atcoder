#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double PI=3.141592653589;
    double a, b, x;
    cin >> a >> b >> x;
    double max = a * a * b;
    if (x > a * b / 2 * a) {
        double d = 2 * (b - (x / pow(a, 2.0)));
        cout << fixed << setprecision(10) << atan2(d, a)*360/2/PI << endl;
    } else if (x < a * b / 2 * a) {
        double a2 = 2 * x / a / b;
        cout << fixed << setprecision(10) << atan2(b, a2)*360/2/PI << endl;
    } else {
        cout << fixed << setprecision(10) << atan2(a, b)*360/2/PI << endl;
    }
}