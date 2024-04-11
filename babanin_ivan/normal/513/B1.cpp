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

int n, m;

void solve() {
    cin >> n >> m;

    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }

    int maxval = -1;
    int cou = 0;
    vector <int> res;

    while (true) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int minv = n + 1;
            for (int j = i; j < n; ++j) {
                minv = min(minv, a[j]);
                sum += minv;
            }
        }

        if (maxval < sum) {
            maxval = sum;
            cou = 0;
        }
        if (maxval == sum) {
            ++cou;
            if (cou == m) {
                res = a;
            }
        }
        if (!next_permutation(a.begin(), a.end())) {
            break;
        }
    }

    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
}