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

const ld eps = 1e-10;

void solve() {
    li a, b;
    cin >> a >> b;

    
    ld res = -1;
    if (a == b) {
        res = b;
    }

    if (a >= b) {
        li tmp = a - b;
        
        ld tmpk = (a - b) / ld(2 * b);

        for (li k = (li)tmpk - 1; k <= li(tmpk) + 1; ++k) {
            if (k < 0) {
                continue;
            }
            if (k == 0 && a == b) {
                if (res == -1 || res > b) {
                    res = b;
                }
            }
            if (k == 0) {
                continue;
            }
            ld x = (a - b) / ld(2 * k);
            if (x <= 0) {
                continue;
            }
            if (x - b >= -eps) {
                if (res == -1 || res > x) {
                    res = x;
                }
            }
        }
    }

    if (a > b) {
        
        ld tmpk = (a / ld(b) - 1) / 2.0;

        for (li k = (li)tmpk - 1; k <= li(tmpk) + 1; ++k) {
            if (k < 0) {
                continue;
            }
            ld x = (a + b) / ld(2 * k + 2);
            if (x - b >= -eps) {
                if (res == -1 || res > x) {
                    res = x;
                }
            }
        }
    }
    
    if (res == -1) {
        cout << -1 << endl;
    }
    else {
        cout << res << endl;
    }
}