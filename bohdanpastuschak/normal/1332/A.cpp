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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t;
	cin >> t;
	while(t--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int x, y, x1, x2, y1, y2;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;
		
		bool ok = 1;
		if (x + b - a < x1 || x + b - a > x2) ok = 0;
		if (y + d - c < y1 || y + d - c > y2) ok = 0;
		if (x1 == x2 && (a || b)) ok = 0;
		if (y1 == y2 && (c || d)) ok = 0;
		
		cout << (ok ? "YES\n" : "NO\n");
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}