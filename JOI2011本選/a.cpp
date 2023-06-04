#include <iostream>
#include <vector>
using namespace std;

int main() {
    int M, N, K;
    cin >> M >> N >> K;
    char x[M][N];
    for (int m = 0; m < M; m++) {
        for (int n = 0; n < N; n++) {
            cin >> x[m][n];
        }
    }
    int a[K],b[K],c[K],d[K];
    for (int i = 0; i < K; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    vector<vector<int>> sumJ(M+1, vector<int>(N+1, 0));
    vector<vector<int>> sumO(M+1, vector<int>(N+1, 0));
    vector<vector<int>> sumI(M+1, vector<int>(N+1, 0));
    for(int m = 1; m < M+1; m++) {
        for (int n = 1; n < N+1; n++) {
            if (x[m-1][n-1] == 'J') sumJ[m][n] = sumJ[m][n-1] + 1;
            else sumJ[m][n] = sumJ[m][n-1];
            if (x[m-1][n-1] == 'O') sumO[m][n] = sumO[m][n-1] + 1;
            else sumO[m][n] = sumO[m][n-1];
            if (x[m-1][n-1] == 'I') sumI[m][n] = sumI[m][n-1] + 1;
            else sumI[m][n] = sumI[m][n-1];
        }
        for (int n = 1; n < N+1; n++) {
            sumJ[m][n] += sumJ[m-1][n];
            sumO[m][n] += sumO[m-1][n];
            sumI[m][n] += sumI[m-1][n];
        }
    }
    int ansJ[K];
    int ansO[K];
    int ansI[K];
    for (int i = 0; i < K; i++) {
        ansJ[i] = sumJ[c[i]][d[i]] - sumJ[a[i]-1][d[i]] - sumJ[c[i]][b[i]-1] + sumJ[a[i]-1][b[i]-1];
        ansO[i] = sumO[c[i]][d[i]] - sumO[a[i]-1][d[i]] - sumO[c[i]][b[i]-1] + sumO[a[i]-1][b[i]-1];
        ansI[i] = sumI[c[i]][d[i]] - sumI[a[i]-1][d[i]] - sumI[c[i]][b[i]-1] + sumI[a[i]-1][b[i]-1];
    }
    for (int i = 0; i < K; i++) {
        cout << ansJ[i] << " " << ansO[i] << " " << ansI[i] << endl;
    }
}