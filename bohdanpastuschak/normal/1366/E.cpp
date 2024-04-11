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

namespace IntModulo
{
	const int mod = 998244353;

	inline int add(int x, int y, int m = mod)
	{
		if (x + y < m)
			return x + y;
		return x + y - m;
	}

	inline int sub(int x, int y, int m = mod)
	{
		if (x >= y)
			return x - y;
		return x - y + m;
	}

	inline int mult(int x, int y, int m = mod)
	{
		return x * (LL) y % m;
	}

	inline int power(int x, int y, int m = mod)
	{
		int r = 1;
		while(y)
		{
			if (y & 1)
				r = mult(r, x, m);
			x = mult(x, x, m);
			y >>= 1;
		}
		
		return r;
	}
	
	inline int inverse(int x, int m = mod)
	{
		return power(x, m - 2, m);
	}
	
	inline void ADD(int& x, int y, int m = mod)
	{
		x += y;
		if (x >= m) x -= m;
	}
	
	inline void SUB(int& x, int y, int m = mod)
	{
		x -= y;
		if (x < 0) x += m;
	}
	
	inline void MULT(int& x, int y, int m = mod)
	{
		x = (x * (LL) y) % m;
	}
};

using namespace IntModulo;

const int N = 1 << 21;
int n, m;
int a[N], b[N];

void no(){
	cout << 0 << endl;
	exit(0);
}	

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	if (n < m){
		no();		
	}
		
	FOR(i, 0, n) cin >> a[i];
	FOR(i, 0, m) cin >> b[i];
	set<pair<int, int>> S;
	FOR(i, 0, n) S.insert({a[i], i});
	
	if (S.begin()->X != b[0]){
		no();
	}
	
	if (m == 1){
		cout << 1 << endl;
		return 0;
	}
		
	int ans = 1;
	int last = -1;
	
	FOR(i, 0, m){
		int maje = b[i];
		
		int nlast = last;
		while(SZ(S) && S.begin()->X < maje){
			setmax(last, S.begin()->Y);
			S.erase(S.begin());
		}					
		
		FOR(j, nlast + 1, last + 1){
			S.erase({a[j], j});
		}		
		
		if (SZ(S) == 0 || S.begin()->X > maje){
			no();
		}
		
		int ost = -1;
		while(SZ(S) && S.begin()->X == maje){
			setmax(ost, S.begin()->Y);
			S.erase(S.begin());
		}
				
		if (ost <= last){
			no();
		}			
			
		if (i){			
			MULT(ans, ost - last);
		}
		
		last = ost;
	}
		
	cout << ans << endl;
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}