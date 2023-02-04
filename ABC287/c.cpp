#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M, U[200009], V[200009];
vector<int> G[200009];
bool visited[200009];

void dfs(int pos) {
    visited[pos] = true;
    for(int i : G[pos]) {
        if(visited[i] == false) {
            dfs(i);
        }
    }
}

int main() {
    cin >> N >> M;
    for(int i = 1; i<= M; i++) {
        cin >> U[i] >> V[i];
        G[U[i]].push_back(V[i]);
        G[V[i]].push_back(U[i]);
    }

    if(M != N-1) {
        cout << "No" << endl;
        return 0;
    }

    for(int i = 1; i <= N; i++) {
        if(G[i].size() > 2) {
            cout << "No" << endl;
            return 0;
        }
    }

    for(int i = 1; i <= N; i++) {
        visited[i] = false;
    }
    dfs(1);

    for(int i = 1; i <= N; i++) {
        if(visited[i] == false) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}