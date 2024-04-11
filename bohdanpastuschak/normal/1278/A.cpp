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
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cerr << #a << " = " << a << endl;

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
		string a, b;
		cin >> a >> b;
		sort(ALL(a));
		bool ok = false;
		
		FOR(l, 0, SZ(b))
		{
			int r = l + SZ(a) - 1;
			if (r >= SZ(b)) continue;
			
			string T(SZ(a), 0);
			FOR(i, l, r + 1) T[i - l] = b[i];
			sort(ALL(T));
			ok |= T == a;
		}
		
		if (ok) cout << "YES\n";
		else cout << "NO\n";		
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}