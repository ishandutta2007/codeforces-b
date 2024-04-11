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

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	FOR(i, 0, n) cin >> a[i];
	int m; cin >> m;
	vector<int> b(m);
	FOR(i, 0, m) cin >> b[i];
	sort(ALL(a));
	sort(ALL(b));

	int A = 2 * n, B = 2 * m;
	int diff = 0;
	FOR(i, 0, n){
		int tut = n - i;
		int tam = m - (lower_bound(ALL(b), a[i]) - b.begin());
		if (tut - tam > diff || (tut - tam == diff && A < 2 * n + tut)){
			diff = tut - tam;
			A = 2 * n + tut;
			B = 2 * m + tam;
		}
	}
	
	cout << A << ":" << B << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}