#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<double> VD;
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

const int N = 1 << 17;
int n, m;
string s[N];
int r[N], c[N];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		FOR(i, 0, n)
			cin >> s[i];
		
		FOR(i, 0, n)
		{
			r[i] = 0;
			FOR(j, 0, m)
				r[i] += s[i][j] == '.';
		}
		
		FOR(j, 0, m)
		{
			c[j] = 0;
			FOR(i, 0, n)
				c[j] += s[i][j] == '.';
		}
		int ans = INF;
		FOR(i, 0, n)
			FOR(j, 0, m)
			{
				int tut = r[i] + c[j];
				if (s[i][j] == '.')
					tut--;
				ans = min(ans, tut);
			}
				
		cout << ans << '\n';
	}
		
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}