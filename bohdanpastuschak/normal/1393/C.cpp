#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long double db;

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

template<typename T> void print(const T& a, ostream& out){	
	for(auto i: a) out << i << ' ';
	out << endl;
}

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//0, m + 1, 2 * m + 2, 3 * m + 3
//(k - 1) * (m + 1) <= n - 1
//m + 1 <= (n - 1) / (k - 1)
//x  x .... x
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> cnt(n, 0);
		int diff = 0;
		FOR(i, 0, n){
			int x; cin >> x;x--;			
			cnt[x]++;
			diff += cnt[x] == 1;
		}

		int mx = *max_element(ALL(cnt));
		int C = 0;
		FOR(i, 0, n) C += cnt[i] == mx;
		int ans = min(diff - 1, (n - C) / (mx - 1) - 1);
		assert(ans >= 0);
		cout << ans << endl;		
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}