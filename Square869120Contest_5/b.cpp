#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<double>> circle1;
    vector<vector<double>> circle2;
    for (int i = 0; i < n; i++) {
        double x, y, r;
        cin >> x >> y >> r;
        circle1.push_back({x, y, r});
    }
    for (int i = 0; i < m; i++) {
        double x, y;
        cin >> x >> y;
        circle2.push_back({x, y});
    }

    double ans = 100000;
    for (int i = 0; i < m; i++) {
        double temp = 100000;
        for (int j = 0; j < n; j++) {
            double dist = sqrt(pow((circle1[j][0] - circle2[i][0]), 2.0) + pow((circle1[j][1] - circle2[i][1]), 2.0));
            dist = abs(dist - circle1[j][2]);
            temp = min(dist, temp);
        }
        for (int j = 0; j < m; j++) {
            if (i == j) continue;
            double dist = sqrt(pow((circle2[j][0] - circle2[i][0]), 2.0) + pow((circle2[j][1] - circle2[i][1]), 2.0));
            dist = dist / 2;
            temp = min(dist, temp);
        }
        ans = min(ans, temp);
    }
    for (int j = 0; j < n; j++) {
        ans = min(ans, circle1[j][2]);
    }
    cout << fixed << setprecision(10) << ans << endl;
}