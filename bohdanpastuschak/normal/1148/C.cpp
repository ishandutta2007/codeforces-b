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

const int N = 1 << 19;
int n;
int p[N];
int pos[N];
vector<PII> ans;

void go(int x, int y)
{
	assert(abs(x - y) >= n / 2);
	ans.PB({x, y});
	swap(p[x], p[y]);
	pos[p[x]] = x;
	pos[p[y]] = y;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	cin >> n;
	FOR(i, 1, n + 1)
	{
		cin >> p[i];
		pos[p[i]] = i;
	}	
	
	int k = n >> 1;
	FOR(i, 1, k + 1)
	{
		if (pos[i] == i)
			continue;
				
		int m = pos[i];
		
		if (m - i >= k)
		{
			go(i, m);
			continue;
		}
		
		if (m <= k)
		{
			go(m, n);
			go(n, i);
			go(m, n);			
		}
		else
		{
			go(m, 1);
			go(1, n);
			go(n, i);
			go(m, 1);
		}
	}
	
	FOR(i, k + 1, n + 1)
	{
		if (pos[i] == i)
			continue;
		
		int m = pos[i];
		go(m, 1);
		go(1, i);
		go(m, 1);		
	}
	
	FOR(i, 1, n + 1)
		assert(p[i] == i);
	
	cout << SZ(ans) << endl;
	for(auto i: ans)
		cout << i.X << ' ' << i.Y << endl;
	
	cerr << SZ(ans) << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}