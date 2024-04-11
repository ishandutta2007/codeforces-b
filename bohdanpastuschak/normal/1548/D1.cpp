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

const int N = 6000 + 7;
int n, x[N], y[N];
int cnt[N][N];
bitset<N> A[N][4];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	n = 1000;
	FOR(i, 0, n){
		x[i] = rng() % 1000000;
		y[i] = rng() % 1000000;
		
	}
	
	cin >> n;
	FOR(i, 0, n) cin >> x[i] >> y[i];
	FOR(i, 0, n) FOR(j, 0, i){
	 
		cnt[i][j] = cnt[j][i] = __gcd(abs(x[i] - x[j]), abs(y[i] - y[j])) % 4;		
	}
	
	LL ans = 0, trp = 0;
	FOR(b, 0, n){
		int ca = 0, cc = 0;
		FOR(c, 0, b) ca += cnt[b][c] == 0;
		FOR(c, b + 1, n) cc += cnt[b][c] == 0;
		trp += ca * cc;
	}
	
	FOR(a, 0, n) FOR(b, 0, a) if (cnt[a][b] == 0) ans += n - 2;
	ans -= 2 * trp;
	
	cout << ans << endl;
	cerr << "Time elapsed: " << clock() / (double) CLOCKS_PER_SEC << endl;
	return 0;
}