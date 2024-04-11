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
//#include <unordered_set> 
using namespace std;
typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define mp make_pair 
#define pb push_back
#define y1 botva
#define all(s) s.begin(), s.end() 
void solve();

#define NAME "changemeplease"
int main() {
#ifdef YA 
    //cerr << NAME << endl;
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout); 
    clock_t start = clock();
#else 
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
#endif 
    ios_base::sync_with_stdio(false);
    cout << fixed;
    cout.precision(10);
    int t = 1;
    //cin >> t;  
    for (int i = 1; i <= t; ++i) {
        //cout << "Case #" << i << ": ";
        solve();
    }
#ifdef YA 
    //cout << "\n\n\nTime:" << ((clock() - start) / 1.0 / CLOCKS_PER_SEC);
#endif 
    return 0;
}

void solve() {
    int n;
    vector <pair <string, int> > a;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            string s;
            cin >> s;
            a.push_back(mp(s, i));
        }
    }
    sort(a.begin(), a.end());

    vector <int> perm(n);
    for (int i = 0; i < n; ++i) {
        cin >> perm[i];
        --perm[i];
    }

    int cur = 0;
    for (int i = 0; i < n; ++i) {
        while (cur < a.size() && a[cur].second != perm[i]) {
            ++cur;
        }
        if (cur == a.size()) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}