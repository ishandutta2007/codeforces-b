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
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 9;
int n;
vector<LL> d;

vector<LL> gen(LL x)
{
	vector<LL> di;
	for(int i = 2; i *(LL)i <= x; ++i)
		if (x % i == 0)
		{
			di.PB(i);
			if (i *(LL) i < x)
				di.PB(x / i);
		}
	sort(ALL(di));
	return di;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		d.resize(n);
		FOR(i, 0, n)
			cin >> d[i];
		sort(ALL(d));
		LL tr = d[0] *(LL) d.back();
		auto lol = gen(tr);
		if (d == lol)
			cout << tr << endl;
		else
			cout << -1 << endl;
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}