#pragma comment (linker, "/STACK:128000000")
#include <iostream> 
#include <cstdio> 
#include <fstream>
#include <functional>
#include <set> 
#include <map> 
#include <vector> 
#include <queue> 
#include <stack> 
#include <cmath> 
#include <algorithm> 
#include <cstring> 
#include <bitset> 
#include <ctime> 
#include <sstream>
#include <stack> 
#include <cassert> 
#include <list> 
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long long i64;
typedef pair <int, int> pi;
typedef vector <int> vi;
typedef double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();

//int timer = 0;
#define FILENAME ""

int main() {
    string s = FILENAME;
#ifdef YA
    //assert(!s.empty());
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //cerr<<FILENAME<<endl;
    //assert (s != "change me please");
    clock_t start = clock();
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen(FILENAME ".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout); 
    cin.tie(0);
#endif
    cout.sync_with_stdio(0);
    cout.precision(10);
    cout << fixed;
    int t = 1;

    //cin >> t;
    for (int i = 1; i <= t; ++i) {
        //++timer;
        //cout << "Case #" << i << ": ";
        solve();
    }
#ifdef YA
    cerr << "\n\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n\n";
#endif
    return 0;
}

#define int li

void print(bool x) {
    if (x) {
        cout << "Kevin\n";
    }
    else {
        cout << "Nicky\n";
    }
    exit(0);
}

int getval(int x) {
    if (x <= 3) {
        return x & 1;
    }
    if (x == 4) {
        return 2;
    }

    if (x & 1) {
        return 0;
    }
    int tmp = getval(x / 2);
    if (tmp == 2) {
        return 1;
    }
    return tmp + 1;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (k % 2 == 0) {
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] <= 2) {
                res ^= a[i];
            }
            else {
                if (a[i] % 2 == 0) {
                    res ^= 1;
                }
            }
        }
        print(res);
    }
    else {
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res ^= getval(a[i]);
        }
        print(res);
    }
}