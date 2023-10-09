#include <iostream>
#include <vector>
using namespace std;
bool kugi[5009][5009];
bool painted[5009][5009];
vector<pair<pair<int,int>,int>> painted;

void paint(int a, int b, int x) {
    if (painted[a][b][x] == true) return;
    for(int i = 0; i <= x; i++) {
        kugi[a+i][b+i] = true;
    }
    for(int i = 0; i <= x; i++) {
        kugi[a+i][b] = true;
    }
    for(int i = 0; i <= x; i++) {
        kugi[a+x][b+i] = true;
    }
    if (x >= 3) paint(a+2, b+1 ,x-3);
    painted[a][b][x] = true;
    return;
}

int main() {
    int N, M;
    cin >> N >> M;
    int A[M], B[M], X[M];
    vector<tuple<pair<int,int>,pair<int,int>,pair<int,int>>> dots;
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i] >> X[i];
        dots.push_back({{A[i],B[i]},{A[i]+X[i],B[i]},{A[i]+X[i],B[i]+X[i]}});
    }
    for (int i = 0; i < M; i++) {
        paint(A[i], B[i], X[i]);
    }
    long long ans = 0;
    for (int i = 1; i < 5009; i++) {
        for (int j = 1; j < i; j++) {
            if(kugi[i][j] == true) ans++;
        }
    }
    cout << ans << endl;
}