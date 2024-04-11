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

const int N = 7000 + 47;
int n;
pair<LL, LL> a[N];
char taken[N];

bool nadmaska(LL x, LL y)
{
	return (x | y) == x;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	cin >> n;
	LL ans = 0;
	map<LL, VI> mp;
	FOR(i, 0, n)
		cin >> a[i].X;
	
	FOR(i, 0, n)
	{
		cin >> a[i].Y;
		mp[a[i].X].PB(a[i].Y);
	}
	
	vector<LL> ye;
	
	for(auto i: mp)
	{
		if (SZ(i.Y) == 1)
			continue;
		
		ye.PB(i.X);
		for(auto j: i.Y)
			ans += j;
	}
	
	FOR(i, 0, n)
		if (mp[a[i].X].size() > 1)
			taken[i] = 1;
	
	FOR(i, 0, n)
	{
		if (taken[i])	
			continue;
		
		for(auto j: ye)
			if (nadmaska(j, a[i].X))
			{
				ans += a[i].Y;
				taken[i] = 1;
				break;
			}
	}
	
	cout << ans << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}