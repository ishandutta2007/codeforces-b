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


int x[2];
int y[2];

void print(int x) {
    if (x == 1) {
        cout << "Polycarp";
    }
    else {
        cout << "Vasiliy";
    }
    exit(0);
}

int win() {
    for (int i = 0; i < 2; ++i) {
        if (x[i] == 0 && y[i] == 0) {
            return i + 1;
        }
    }
    return 0;
}

void go(int t, int coord) {
    if (t == 1) {
        
    }
}

void solve() {
    cin >> x[0] >> y[0] >> x[1] >> y[1];
    

    if (x[0] + y[0] <= max(x[1], y[1])) {
        print(1);
    }

    //while (!win()) {
    if (x[0] <= x[1] && y[0] <= y[1]) {
        print(1);
    }
    else {
        print(2);
    }
    //}
    //print(win());
}