#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define MP make_pair
#define PB push_back
#define X first
#define Y second

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cout << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9;
const LL LINF = INF * INF;

const int mod = 1e9 + 7;

LL mult(LL x, LL y, LL w = mod)
{
	x %= w;
	y %= w;
	return x * (LL) y % w;
}

int power(LL x, LL y)
{
	LL r = 1;
	while(y)
	{
		if (y & 1)
			r = mult(r, x);
		x = mult(x, x);
		y >>= 1;
	}
	
	return r;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	LL n, m, k;
	cin >> n >> m >> k;
	if (k == -1 && ((n + m) & 1))
		cout << 0 << endl;
	else
		cout << power(2, mult(n - 1, m - 1, mod - 1)) << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}