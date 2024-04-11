#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define MP make_pair
#define PB push_back
#define X first
#define Y second

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cerr << #a << " = " << a << endl;

template<typename T> void setmax(T& x, T y) {x = max(x, y);}
template<typename T> void setmin(T& x, T y) {x = min(x, y);}

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(58);

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m));
		FOR(i, 0, n) FOR(j, 0, m) cin >> a[i][j];
		int cnt_row = 0, cnt_col = 0;
		FOR(i, 0, n){
			bool ok = 1;
			FOR(j, 0, m) ok &= !a[i][j];
			cnt_row += ok;
		}
		
		FOR(i, 0, m){
			bool ok = 1;
			FOR(j, 0, n) ok &= !a[j][i];
			cnt_col += ok;
		}
		
		int mx = min(cnt_row, cnt_col);
		cout << (mx & 1 ? "Ashish" : "Vivek") << endl;
	}
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}