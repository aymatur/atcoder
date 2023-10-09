#include <iostream>
#include <vector>
using namespace std;

const long long INF = 1LL << 60;

template<class T> bool chmin(T& a, T b) { if(a > b) {a = b; return true;} else return false; }

struct Edge {
    int to;
    long long w;
    Edge(int to, long long w) : to(to), w(w) {}
};

using Graph = vector<vector<Edge>>;

int main() {
    int N;
    cin >> N;
    Graph G(N);
    vector<vector<long long>> A(N, vector<long long>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            long long in;
            cin >> in;
            A[i][j] = in;
            if (in != 0) G[i].push_back(Edge(j, in));
        }
    }

    vector<vector<long long>> dp(N, vector<long long>(N, INF));
    vector<vector<bool>> no_edge(N, vector<bool>(N, false));

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (A[i][j] > A[i][k] + A[k][j]) {
                    cout << "-1" << endl;
                    return 0;
                }

                if (A[i][j] == A[i][k] + A[k][j] && A[i][k] > 0 && A[k][j] > 0) {
                    no_edge[i][j] = true;
                }
            }
        }
    }

    long long ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (!no_edge[i][j]) {
                ans += A[i][j];
            }
        }
    }
    cout << ans << endl;
}