#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

vector <int> binary(int x, int l) {
    vector <int> b;
    while(x) {
        b.push_back(x % 2);
        x = x/2;
    }
    while(b.size() < l) b.push_back(0);
    reverse(b.begin(), b.end());
    return b;
}

void solve() {
    int n, l;
    cin >> n >> l;
    vector<vector<int>> v;
    forn(i, 0, n) {
        int t; cin >> t;
        v.push_back(binary(t, l));
    }
    vector <int> ans(l);
    forn(i, 0, l) {
        int x = 0;
        forn(j, 0, n) {
            if(v[j][i] == 1) x++;
        }
        if(x < (n - x)) ans[i] = 0;
        else ans[i] = 1;
    }
    reverse(ans.begin(), ans.end());
    int y = 0;
    forn(i, 0, l) y += (ans[i] << i);
    cout << y << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}