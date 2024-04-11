#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()

#define equal equalll
#define less lesss
const int N = -1;
const long long INF = 1e9 + 19;
typedef long long ll;

int t;
int a, b;
void read() {
    scanf("%d%d:%d", &t, &a, &b);
    int b1 = b % 10;
    int b2 = b / 10;
    if (b2 > 5) {
        b2 = 0;
    }
    int l, r;
    if (t == 24) {
        l = 0;
        r = 23;
    }
    else {
        l = 1;
        r = 12;
    }

    int bestA = -1;
    int cost = 100; 
    int a1 = a % 10;
    int a2 = a / 10;
    for (int i = l; i <= r; i++) {
        int x1 = i % 10;     
        int x2 = i / 10;
        //db2(x1, x2);
        int tmp = ((int)(x1 != a1)) + (x2 != a2);
        if (tmp < cost) {
            cost = tmp;
            bestA = i;
        }
    }
    cout << bestA / 10 << bestA % 10 << ":" << b2 << b1 << endl;

}

void solve() {

}

void stress() {

}

int main(){
#ifdef MY_DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}