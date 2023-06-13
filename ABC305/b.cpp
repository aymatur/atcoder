#include <iostream>

using namespace std;

int get_num(char c) {
    if (c == 'A') return 0;
    if (c == 'B') return 1;
    if (c == 'C') return 2;
    if (c == 'D') return 3;
    if (c == 'E') return 4;
    if (c == 'F') return 5;
    if (c == 'G') return 6;
}

int main() {
    char p, q;
    cin >> p >> q;
    int sum[8];
    sum[0] = 0;
    sum[1] = 3;
    sum[2] = 4;
    sum[3] = 8;
    sum[4] = 9;
    sum[5] = 14;
    sum[6] = 23;

    int pnum = get_num(p);
    int qnum = get_num(q);
    if (pnum < qnum) cout << sum[qnum] - sum[pnum];
    else cout << sum[pnum] - sum[qnum];

}